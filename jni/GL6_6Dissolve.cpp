#include "GL6_6Dissolve.h"


GL6_6::GL6_6(void){
}


GL6_6::~GL6_6(void){
}

bool GL6_6::loadTGATexture( const char *filename, GLenum minfilter, GLenum magfilter, GLenum wrapmode ){
	GLint width, height, conpoments;
	GLenum format;
	GLbyte *pByte = NULL;
	pByte = gltReadTGABits(filename, &width, &height, &conpoments, &format);
	if(!pByte)
		return false;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minfilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magfilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapmode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapmode);
	glTexImage2D(GL_TEXTURE_2D, 0, conpoments, width, height, 0, format, GL_UNSIGNED_BYTE, pByte);

	free(pByte);

	if(minfilter == GL_LINEAR_MIPMAP_LINEAR || minfilter == GL_LINEAR_MIPMAP_NEAREST || 
		minfilter == GL_NEAREST_MIPMAP_LINEAR || minfilter == GL_NEAREST_MIPMAP_NEAREST)
		glGenerateMipmap(GL_TEXTURE_2D);

	return true;
}

void GL6_6::init(){
	glClearColor(0 ,0 ,0, 1);

	glEnable(GL_DEPTH_TEST);
	
	mShaderManager.InitializeStockShaders();
	gltMakeTorus(mTorus, 0.8f, 0.25f, 52, 26);

	mShaderProgram = gltLoadShaderPairWithAttributes("/sdcard/Irrlicht/GL6_6Dissolve.vert", "/sdcard/Irrlicht/GL6_6Dissolve.frag",
		3, GLT_ATTRIBUTE_VERTEX, "vVertex", GLT_ATTRIBUTE_NORMAL, "vNormal", 
		GLT_ATTRIBUTE_TEXTURE0, "vTexCoords0");
	mvpLoc = glGetUniformLocation(mShaderProgram, "mvp");
	mvLoc = glGetUniformLocation(mShaderProgram, "mv");
	nmLoc = glGetUniformLocation(mShaderProgram, "nm");
	lightPosLoc = glGetUniformLocation(mShaderProgram, "vLightPos");

	ambientLoc = glGetUniformLocation(mShaderProgram, "ambientColor");
	diffuseLoc = glGetUniformLocation(mShaderProgram, "diffuseColor");
	specularLoc = glGetUniformLocation(mShaderProgram, "specularColor");
	cloudLoc = glGetUniformLocation(mShaderProgram, "cloudTexture");
	dissolveLoc = glGetUniformLocation(mShaderProgram, "dissolveFactor");

	glGenTextures(1, &mCloudTexture);
	glBindTexture(GL_TEXTURE_2D, mCloudTexture);
	loadTGATexture("/sdcard/Irrlicht/Clouds.tga", GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_LINEAR, GL_CLAMP_TO_EDGE);
}

void GL6_6::reshape( int w, int h ){
	glViewport(0, 0, w, h);
	mViewFrustum.SetPerspective(35, float(w) / float(h), 0.1f, 100);
	mProjectionStack.LoadMatrix(mViewFrustum.GetProjectionMatrix());
	mTransformPipeline.SetMatrixStacks(mModelViewStack, mProjectionStack);
}
GLfloat GL6_6LightPos[] = {-100, 100, 100};
GLfloat GL6_6AmbientColor[] = {0.1f, 0.1f, 0.1f, 1};
GLfloat GL6_6DiffuseColor[] = {0.1f, 1.0f, 0.1f, 1.0f};
GLfloat GL6_6SpecularColor[] = {1, 1, 1, 1};

void GL6_6::display(){
	static CStopWatch timer;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	mModelViewStack.PushMatrix();
		M3DMatrix44f cameraMatrix;
		mCamera.GetCameraMatrix(cameraMatrix);
		mModelViewStack.MultMatrix(cameraMatrix);
		mModelViewStack.Translate(0, 0, -4);
		mModelViewStack.Rotate(timer.GetElapsedSeconds() * 10, 0, 1, 0);

		glUseProgram(mShaderProgram);
		glUniform4fv(ambientLoc, 1, GL6_6AmbientColor);
		glUniform4fv(diffuseLoc, 1, GL6_6DiffuseColor);
		glUniform4fv(specularLoc, 1, GL6_6SpecularColor);
		glUniform3fv(lightPosLoc, 1, GL6_6LightPos);
		glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, 
			mTransformPipeline.GetModelViewProjectionMatrix());
		glUniformMatrix4fv(mvLoc, 1, GL_FALSE, 
			mTransformPipeline.GetModelViewMatrix());
		glUniformMatrix3fv(nmLoc, 1, GL_FALSE, 
			mTransformPipeline.GetNormalMatrix());
		glUniform1i(mCloudTexture, 1);

		float factor = fmod(timer.GetElapsedSeconds(), 10);
		factor /= 10; //factorÖð½¥´Ó0.0ÔöÖÁ1.0
		glUniform1f(dissolveLoc, factor);
		mTorus.Draw();
	mModelViewStack.PopMatrix();
}


