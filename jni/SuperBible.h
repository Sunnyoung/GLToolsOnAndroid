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
	/* 1.����������ɫ(��ʵ��)
	   2.������Ч ����Ȳ��� ģ����� ��
	   3.��ʼ��ͼԪ����*/
	/************************************************************************/
	virtual void init();
	/************************************************************************/
	/* 1.�����ӿ�(��ʵ��)
	   2.����͸��ģʽ
	   3.��ʼ��ģ����ͼ����(��ѡ)��ͶӰ����(��ѡ)
	   4.��ʼ���任����(TransformPipeline)��ģ����ͼ�����ͶӰ����*/
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

