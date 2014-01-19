attribute vec4 vVertex;
attribute vec3 vNormal;
attribute vec2 vTexCoords0;

uniform mat4 mvp;
uniform mat4 mv;
uniform mat3 nm;
uniform vec3 vLightPos;

varying vec3 vVaryingNormal;
varying vec3 vVaryingLightDir;
varying vec2 vVaryingTexCoords;

void main(){
	vVaryingTexCoords = vTexCoords0;
	vVaryingNormal = nm * vNormal;
	vec4 vPosition4 = mv * vVertex;
	vec3 vPosition3 = vPosition4.xyz / vPosition4.w;
	vVaryingLightDir = normalize(vLightPos - vPosition3);

	gl_Position = mvp * vVertex;
}
