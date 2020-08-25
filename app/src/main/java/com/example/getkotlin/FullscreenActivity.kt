package com.example.getkotlin

import android.annotation.SuppressLint
import android.content.Context
import android.content.SharedPreferences
import android.os.AsyncTask
import android.os.Build
import android.os.Bundle
import android.os.Handler
import android.view.MotionEvent
import android.view.View
import android.view.inputmethod.InputMethodManager
import android.webkit.WebView
import android.widget.Button
import android.widget.LinearLayout
import android.widget.TextView
import androidx.annotation.RequiresApi
import androidx.appcompat.app.AppCompatActivity
import androidx.fragment.app.Fragment
import kotlinx.android.synthetic.main.webview.*
import org.json.JSONObject
import java.net.HttpURLConnection
import java.net.URL
import java.util.*


/**
 * An example full-screen activity that shows and hides the system UI (i.e.
 * status bar and navigation/system bar) with user interaction.
 */
/*
*  Global variable
*  used to save info
 */
lateinit var spref: SharedPreferences

class FullscreenActivity : AppCompatActivity() {
    private lateinit var fullscreenContent: TextView
    private lateinit var fullscreenContentControls: LinearLayout
    private val hideHandler = Handler()

    private lateinit var fullscreenWebView: WebView

    private var isFragmenPrelode = true
    private val framemaneger = supportFragmentManager

    @SuppressLint("InlinedApi")
    private val hidePart2Runnable = Runnable {
        // Delayed removal of status and navigation bar

        // Note that some of these constants are new as of API 16 (Jelly Bean)
        // and API 19 (KitKat). It is safe to use them, as they are inlined
        // at compile-time and do nothing on earlier devices.
        fullscreenContent.systemUiVisibility =
                View.SYSTEM_UI_FLAG_LOW_PROFILE or
                        View.SYSTEM_UI_FLAG_FULLSCREEN or
                        View.SYSTEM_UI_FLAG_LAYOUT_STABLE or
                        View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY or
                        View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION or
                        View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
    }
    private val showPart2Runnable = Runnable {
        // Delayed display of UI elements
        supportActionBar?.show()
        fullscreenContentControls.visibility = View.VISIBLE
    }
    private var isFullscreen: Boolean = false

    private val hideRunnable = Runnable { hide() }

    /**
     * Touch listener to use for in-layout UI controls to delay hiding the
     * system UI. This is to prevent the jarring behavior of controls going away
     * while interacting with activity UI.
     */
    private val delayHideTouchListener = View.OnTouchListener { view, motionEvent ->
        when (motionEvent.action) {
            MotionEvent.ACTION_DOWN -> if (AUTO_HIDE) {
                delayedHide(AUTO_HIDE_DELAY_MILLIS)
            }
            MotionEvent.ACTION_UP -> view.performClick()
            else -> {
            }
        }
        false
    }

    @RequiresApi(Build.VERSION_CODES.N)
    @SuppressLint("ClickableViewAccessibility")

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_fullscreen)
        supportActionBar?.setDisplayHomeAsUpEnabled(true)

        isFullscreen = true

        // Set up the user interaction to manually show or hide the system UI.
        fullscreenContent = findViewById(R.id.fullscreen_content)
        fullscreenContent.setOnClickListener { toggle() }

        fullscreenContentControls = findViewById(R.id.fullscreen_content_controls)

        // Upon interacting with UI controls, delay any scheduled hide()
        // operations to prevent the jarring behavior of controls going away
        // while interacting with the UI.
        findViewById<Button>(R.id.dummy_button).setOnTouchListener(delayHideTouchListener)


        spref = getPreferences(Context.MODE_PRIVATE)

        // Check the existence of "FirstOpen" (boolean)
        if( !spref.contains("FirstOpen") ){
            val url = "https://efs5i1ube5.execute-api.eu-central-1.amazonaws.com/prod"
            //asynchronous fun
            AsyncTaskGetServerJson().execute(url)
        }else{
            ChangeFragment(FrameWebView())
        }
    }

    //Save Data on the device
    //Work with AmazonawsProd (data class)
    fun SaveData( trueRes:AmazonawsProd){
        spref = getPreferences(Context.MODE_PRIVATE)
        val  ed :SharedPreferences.Editor = spref.edit()
        ed.putString("link",trueRes.link)
        ed.putString("home",trueRes.home)
        ed.putBoolean("FirstOpen",true)
        ed.commit()
    }

    //Load Data from the device
    //Return String
    fun LoadData(flag:String):String?{
        spref = getPreferences(Context.MODE_PRIVATE)
        return spref.getString(flag,"error")
    }

    //Change Fragment on View
    //Work with Fragment (data class)
    fun ChangeFragment( fragment: Fragment){
        val transaction = framemaneger.beginTransaction()
        transaction.replace(R.id.FramePreloader ,fragment)
        transaction.addToBackStack(null)
        transaction.commit()
        isFragmenPrelode=!isFragmenPrelode
    }
    ////////////////////////////////////////////////////////////////
    //Asynchronous Task
    inner class AsyncTaskGetServerJson: AsyncTask<String, String, String>() {
        override fun doInBackground(vararg url: String?): String {
            val text: String
            val connection = URL(url[0]).openConnection() as HttpURLConnection
            try {
                connection.connect()
                text   = connection.inputStream.use { it.reader().use { reader-> reader.readText() } }
            }finally {
                connection.disconnect()
            }
            return text
        }

        //Post Execute ))))
         override fun onPostExecute(result: String?) {
            super.onPostExecute(result)
            UseJson(result)
            ChangeFragment(FrameWebView())

             //DEBUG
             //Check the info
             //println(LoadData("link"))
             //println(LoadData("home"))
        }
    }
    //result processing / saving
    private fun UseJson(result: String?) {
        val jsonObject = JSONObject(result)

        val trueRes = AmazonawsProd(jsonObject.getString("link"),
            jsonObject.getString("home"))

        SaveData(trueRes)
    }
    //////////////////////////////////////////////////////////////////////////////
    //the ability to go back through the webview when pressing the system back button
    override fun onBackPressed() {
        when {
            //val view: View = LayoutInflater.from(this).inflate(R.layout.activity_fullscreen,parent,false)
            webvieww?.canGoBack() == true -> webvieww.goBack()
            else -> super.onBackPressed()
        }
    }

    override fun onPostCreate(savedInstanceState: Bundle?) {
        super.onPostCreate(savedInstanceState)

        // Trigger the initial hide() shortly after the activity has been
        // created, to briefly hint to the user that UI controls
        // are available.
        delayedHide(100)
    }

    private fun toggle() {
        if (isFullscreen) {
            hide()
        } else {
            show()
        }
    }

    private fun hide() {
        // Hide UI first
        supportActionBar?.hide()
        fullscreenContentControls.visibility = View.GONE
        isFullscreen = false

        // Schedule a runnable to remove the status and navigation bar after a delay
        hideHandler.removeCallbacks(showPart2Runnable)
        hideHandler.postDelayed(hidePart2Runnable, UI_ANIMATION_DELAY.toLong())
    }

    private fun show() {
        // Show the system bar
        fullscreenContent.systemUiVisibility =
                View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN or
                        View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
        isFullscreen = true

        // Schedule a runnable to display UI elements after a delay
        hideHandler.removeCallbacks(hidePart2Runnable)
        hideHandler.postDelayed(showPart2Runnable, UI_ANIMATION_DELAY.toLong())
    }

    /**
     * Schedules a call to hide() in [delayMillis], canceling any
     * previously scheduled calls.
     */
    private fun delayedHide(delayMillis: Int) {
        hideHandler.removeCallbacks(hideRunnable)
        hideHandler.postDelayed(hideRunnable, delayMillis.toLong())
    }

    companion object {
        /**
         * Whether or not the system UI should be auto-hidden after
         * [AUTO_HIDE_DELAY_MILLIS] milliseconds.
         */
        private const val AUTO_HIDE = true

        /**
         * If [AUTO_HIDE] is set, the number of milliseconds to wait after
         * user interaction before hiding the system UI.
         */
        private const val AUTO_HIDE_DELAY_MILLIS = 3000

        /**
         * Some older devices needs a small delay between UI widget updates
         * and a change of the status and navigation bar.
         */
        private const val UI_ANIMATION_DELAY = 300
    }
}