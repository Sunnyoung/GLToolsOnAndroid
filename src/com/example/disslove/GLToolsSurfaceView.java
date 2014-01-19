package com.example.disslove;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.text.StaticLayout;
import android.util.Log;
import android.view.MotionEvent;

public class GLToolsSurfaceView extends GLSurfaceView {
	private GLToolsRenderer mRenderer;
	private float mPreviousX, mPreviousY;
	
	public GLToolsSurfaceView(Context context) {
		super(context);
		// TODO Auto-generated constructor stub
		this.setEGLContextClientVersion(2);
		mRenderer = new GLToolsRenderer(context);
		this.setRenderer(mRenderer);
		
	}
	@Override
	public boolean onTouchEvent(MotionEvent event) {
		// TODO Auto-generated method stub
		
		float x = event.getX();
		float y = event.getY();
		
		mRenderer.mDistanceX = -(x - mPreviousX) * mRenderer.mDelta * 0.0005f;
		mRenderer.mDistanceY = (y - mPreviousY) * mRenderer.mDelta * 0.0005f;
		
		mPreviousX = x;
		mPreviousY = y;
		return true;
	}
	
	
	

}
