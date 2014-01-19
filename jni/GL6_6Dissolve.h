#pragma once
#include "superbible.h"
class GL6_6 :
	public SuperBible
{
public:
	GL6_6(void);
	~GL6_6(void);
	bool loadTGATexture(const char *filename, GLenum minfilter, GLenum magfilter, GLenum wrapmode);
	virtual void init();
	virtual void reshape(int w, int h);
	virtual void display();
private:
	GLint mvpLoc, mvLoc, nmLoc, lightPosLoc;
	GLint ambientLoc, diffuseLoc, specularLoc, dissolveLoc;
	GLuint cloudLoc;
	GLuint mShaderProgram;
	GLShaderManager mShaderManager;
	GLFrame mCamera;
	GLTriangleBatch mTorus;
	GLuint mCloudTexture;
	GLFrustum mViewFrustum;
	GLMatrixStack mModelViewStack, mProjectionStack;
	GLGeometryTransform mTransformPipeline;
};

