#include <jni.h>
#include "Disslove.h"
#include "SuperBible.h"
#include "GL6_6Dissolve.h"

SuperBible *sb = new GL6_6();

JNIEXPORT void JNICALL Java_com_example_disslove_GLToolsRenderer_init
  (JNIEnv *, jclass){
	sb->init();
}

JNIEXPORT void JNICALL Java_com_example_disslove_GLToolsRenderer_reshape
  (JNIEnv *, jclass, jint w, jint h){
	sb->reshape(w, h);
}

JNIEXPORT void JNICALL Java_com_example_disslove_GLToolsRenderer_display
  (JNIEnv *, jclass, jfloat, jfloat){
	sb->display();
}
