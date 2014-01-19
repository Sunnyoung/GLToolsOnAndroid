package com.example.disslove;

import java.io.IOException;

import android.os.Bundle;
import android.R.layout;
import android.app.Activity;
import android.view.Menu;

public class MainActivity extends Activity {

	GLToolsSurfaceView mSurfaceView;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		try {
			Utils.unpackOnSdCard(getAssets());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		super.onCreate(savedInstanceState);
		mSurfaceView = new GLToolsSurfaceView(this);
		this.setContentView(mSurfaceView);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
