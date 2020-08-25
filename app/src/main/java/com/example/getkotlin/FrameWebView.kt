package com.example.getkotlin

import android.content.Context
import android.content.SharedPreferences
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.webkit.WebView
import androidx.fragment.app.Fragment
import kotlinx.android.synthetic.main.webview.*

class FrameWebView : Fragment(){

    override fun onAttach(context: Context) {
        super.onAttach(context)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {

        return inflater!!.inflate(R.layout.webview,container,false)
    }

    override fun onActivityCreated(savedInstanceState: Bundle?) {
        super.onActivityCreated(savedInstanceState)
    }
    override fun onStart() {
        super.onStart()
        // Check the value of "FirstOpen" (boolean)
        if(spref.getBoolean("FirstOpen",false)){
            webvieww.loadUrl(spref.getString("link","error"))

            spref.edit()
            .putBoolean("FirstOpen",false)
            .commit()

            //DEBUG
            //println(spref.getString("link","error"))
            //println(spref.getString("home","error"))
            //println(spref.getBoolean("FirstOpen",true))
        }else {
            webvieww.loadUrl(spref.getString("home","error"))
        }
    }

    override fun onResume() {
        super.onResume()
    }

    override fun onPause() {
        super.onPause()
    }

    override fun onStop() {
        super.onStop()
    }

    override fun onDestroyView() {
        super.onDestroyView()
    }

    override fun onDestroy() {
        super.onDestroy()
    }

    override fun onDetach() {
        super.onDetach()
    }
}
