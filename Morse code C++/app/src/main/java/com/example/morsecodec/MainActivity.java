package com.example.morsecodec;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.Context;
import android.media.MediaPlayer;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

import android.view.inputmethod.InputMethodManager;
import android.view.inputmethod.InputMethodSubtype;

import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;
import java.util.Locale;
import java.util.Objects;

import static android.provider.Telephony.Mms.Part.TEXT;

public class MainActivity extends AppCompatActivity {


    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    private TextView textView_Language,textView_Language2,textView_translate;
    private EditText editText;
    private Button button_Translate ,button_Switch_Tr;
    private Boolean switch_state = Boolean.TRUE;
    private ClipboardManager myClipboard;
    private ClipData myClip;

    private InputMethodManager imm;
    private String currentLanguage;

    private static final String TAG = "Debug";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //imm = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);

        // TextView
        textView_Language = (TextView)findViewById(R.id.textView_Language);
        textView_Language2 = (TextView)findViewById(R.id.textView_Language2);
        textView_translate = (TextView)findViewById(R.id.textView_Transleted_Text);

        // EditText
        editText = (EditText) findViewById(R.id.editText);

        // Button
        button_Translate = (Button) findViewById(R.id.button_Translate);
        button_Switch_Tr = (Button) findViewById(R.id.button_Switch_Tr);

        // Example of a call to a native method
        //TextView tv = findViewById(R.id.sample_text);
        //tv.setText(stringFromJNI());
    }

    public void switch_metod(View view){
        String change = textView_Language.getText().toString();
        if(switch_state)
            switch_state=Boolean.FALSE;
        else
            switch_state=Boolean.TRUE;

        textView_Language.setText(textView_Language2.getText());
        textView_Language2.setText(change);
    }

    public void closeKeyBoard(){
        View view = this.getCurrentFocus();
        if (view != null) {
            InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
            imm.hideSoftInputFromWindow(view.getWindowToken(), 0);
        }
    }

    //@RequiresApi(api = Build.VERSION_CODES.N)
    @org.jetbrains.annotations.NotNull
    private String getKeyboardLanguage() {
            InputMethodManager imm = (InputMethodManager) getSystemService(this.INPUT_METHOD_SERVICE);

            InputMethodSubtype ims = imm.getCurrentInputMethodSubtype();
            String localeString = ims.getLocale();
            Locale locale = new Locale(localeString);
            String currentLanguagee = locale.getDisplayLanguage();
            
        return currentLanguagee;
        //Log.d(TAG, new Locale(imm.getCurrentInputMethodSubtype().getLanguageTag()).toLanguageTag());
        //Log.d(TAG, new Locale(imm.getCurrentInputMethodSubtype().getLocale()).toString());

        //return new Locale(imm.getCurrentInputMethodSubtype().getLanguageTag()).getLanguage();
        // return new Locale(imm.getCurrentInputMethodSubtype().getLocale()).getDisplayLanguage();

        /*InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
            InputMethodSubtype ims = imm.getCurrentInputMethodSubtype();
            String localeString = ims.getLocale();

            return new Locale(localeString).getDisplayLanguage();*/
    }

    @RequiresApi(api = Build.VERSION_CODES.N)
    public void Push_Translete(View view){

        String transleted;
        currentLanguage = getKeyboardLanguage();

        //currentLanguage = java.util.Locale.getDefault().getDisplayName();
       // String currentLanguage = new Locale(imm.getCurrentInputMethodSubtype().getLocale()).getDisplayLanguage();
        /*
        /////////////////////////////////////////////////////////////////////////////////////////////
        InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
        InputMethodSubtype ims = imm.getCurrentInputMethodSubtype();
        String localeString = ims.getLocale();
        Locale locale = new Locale(localeString);
        currentLanguage = locale.getDisplayLanguage();
        /////////////////////////////////////////////////////////////////////////////////////////////
        */
        closeKeyBoard();

        if(switch_state)
            transleted=Transelete(editText.getText().toString());
        else
        {
            if(currentLanguage == "en_us") {
                transleted=Translete_backtoEng(editText.getText().toString());//From Morse code To english
            }
            else{
                transleted=Translete_backtoRus(editText.getText().toString());//From Morse code To rus
            }
        }

        textView_translate.setText(transleted);

        myClipboard = (ClipboardManager)getSystemService(CLIPBOARD_SERVICE);
        myClip = ClipData.newPlainText("text", transleted);
        myClipboard.setPrimaryClip(myClip);

        Toast.makeText(getApplicationContext(),"Translation is Copy in " + currentLanguage,Toast.LENGTH_LONG).show();

    }
    public native String Transelete( String transel_jstr);
    public native String Translete_backtoEng(String transel_jstr);
    public native String Translete_backtoRus(String transel_jstr);
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
