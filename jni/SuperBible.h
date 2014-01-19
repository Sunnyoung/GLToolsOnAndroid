#pragma once
#include <GLTools.h>
#include <GLShaderManager.h>
#include <GLFrustum.h>
#include <GLBatch.h>
#include <GLMatrixStack.h>
#include <GLGeometryTransform.h>
#include <StopWatch.h>

#include <cmath>

using namespace std;

class SuperBible{
public:
	SuperBible(void);
	~SuperBible(void);
	/************************************************************************/
	/* 1.设置清屏颜色(已实现)
	   2.开启特效 如深度测试 模板测试 等
	   3.初始化图元批次*/
	/************************************************************************/
	virtual void init();
	/************************************************************************/
	/* 1.设置视口(已实现)
	   2.设置透视模式
	   3.初始化模型视图矩阵(可选)和投影矩阵(必选)
	   4.初始化变换管线(TransformPipeline)的模型视图矩阵和投影矩阵*/
	/************************************************************************/
	virtual void reshape(int w, int h);
	virtual void display() = 0;
	virtual void specialKey(int key, int x, int y);
	virtual void specialKeyUp(int key, int x, int y);
	virtual void keyboard(unsigned char key, int x, int y);
	virtual void keyboardUp(unsigned char key, int x, int y);
	virtual void mouse(int button, int state, int x, int y);
	virtual void motion(int x, int y);

protected:
	bool loadTGATexture(const char *filename, GLenum minfilter, GLenum magfilter, GLenum wrapmode);
};

