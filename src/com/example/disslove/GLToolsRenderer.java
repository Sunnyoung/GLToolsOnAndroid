package com.example.disslove;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.R.integer;
import android.content.Context;
import android.opengl.GLSurfaceView.Renderer;
import android.util.Log;

public class GLToolsRenderer implements Renderer {
	
	private Context mContext;
	public float mDistanceX, mDistanceY;
	public long mStamp, mDelta;
	
	public GLToolsRenderer (Context context) {
		super();
		mContext = context;
	}
	@Override
	public void onDrawFrame(GL10 gl10) {
		// TODO Auto-generated method stub
		long now = System.currentTimeMillis();
		mDelta = now - mStamp;
		mStamp = now;
		display(mDistanceX, mDistanceY);
	}

	@Override
	public void onSurfaceChanged(GL10 gl10, int width, int height) {
		// TODO Auto-generated method stub
		reshape(width, height);
	}

	@Override
	public void onSurfaceCreated(GL10 gl10, EGLConfig config) {
		// TODO Auto-generated method stub
		init();
	}
	
	private static native void init();
	private static native void reshape(int w, int h);
	private static native void display(float dx, float dy);
	
	static {
		System.loadLibrary("Disslove");
	}
}
