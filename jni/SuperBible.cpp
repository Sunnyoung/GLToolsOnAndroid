#include "SuperBible.h"


SuperBible::SuperBible(void){
}


SuperBible::~SuperBible(void){
}

void SuperBible::init(){
	//…Ë÷√«Â∆¡—’…´
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
}

void SuperBible::reshape(int w, int h){
	glViewport(0, 0, w, h);
}

void SuperBible::specialKey( int key, int x, int y ){
	//cout << "specialKey " << key << " " << x << " " << y << endl;
}

void SuperBible::specialKeyUp( int key, int x, int y ){
	//cout << "specialKeyUp " << key << " " << x << " " << y << endl;
}

void SuperBible::keyboard( unsigned char key, int x, int y ){
	//cout << "keyboard " << key << " " << x << " " << y << endl;
}

void SuperBible::keyboardUp( unsigned char key, int x, int y ){
	//cout << "keyboardUp " << key << " " << x << " " << y << endl;
}

bool SuperBible::loadTGATexture( const char *filename, GLenum minfilter, GLenum magfilter, GLenum wrapmode )
{
	GLbyte *pBits;
	int width, height, depth;
	GLenum format;

	pBits = gltReadTGABits(filename, &width, &height, &depth, &format);
	if(!pBits)
		return false;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minfilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magfilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapmode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapmode);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, depth, width, height, 0, format, GL_UNSIGNED_BYTE, pBits);

	free(pBits);

	if(minfilter == GL_LINEAR_MIPMAP_LINEAR || minfilter == GL_LINEAR_MIPMAP_NEAREST || 
		minfilter == GL_NEAREST_MIPMAP_LINEAR || minfilter == GL_NEAREST_MIPMAP_NEAREST)
		glGenerateMipmap(GL_TEXTURE_2D);

	return true;
}

void SuperBible::mouse( int button, int state, int x, int y ){
	//cout << "button = " << button << " state = " << state << " x = " << x << " y = " << y <<endl;
}

void SuperBible::motion( int x, int y ){
	//cout << " mouse pos = " << x << " " << y <<endl;
}


