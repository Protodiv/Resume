package com.example.getkotlin

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.webkit.WebView
import android.widget.BaseAdapter

class WebViewAdapt(
    val context: FullscreenActivity,
    val amazonawsprod: AmazonawsProd):BaseAdapter() {
    override fun getView(position: Int, convertView: View?, parent: ViewGroup?): View {
        val view: View = LayoutInflater.from(context).inflate(R.layout.activity_fullscreen,parent,false)

        val webView = view.findViewById<WebView>(R.id.webvieww)

        webView.loadUrl(amazonawsprod.link)

        return view
    }

    override fun getItem(position: Int): Any {
        return position
    }

    override fun getItemId(position: Int): Long {
        return position.toLong()
    }

    override fun getCount(): Int {
        return 1
    }
}