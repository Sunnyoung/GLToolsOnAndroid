precision mediump float;

//varying vec4 vFragColor;

uniform vec4 ambientColor;
uniform vec4 diffuseColor;
uniform vec4 specularColor;
uniform sampler2D cloudTexture;
uniform float dissolveFactor;

varying vec3 vVaryingNormal;
varying vec3 vVaryingLightDir;
varying vec2 vVaryingTexCoords;

void main(){
	vec4 vColorSample = texture2D(cloudTexture, vVaryingTexCoords);
	if(vColorSample.r < dissolveFactor)
		discard;
	float diff = max(0.0, dot(normalize(vVaryingNormal),
		normalize(vVaryingLightDir)));
	vec4 vFragColor = diff * diffuseColor;
	vFragColor += ambientColor;
	vec3 vReflection = normalize(reflect(-normalize(vVaryingLightDir), 
		normalize(vVaryingNormal)));
	float spec = max(0.0, dot(normalize(vVaryingNormal), vReflection));
	if(diff != 0.0){
		float fSpec = pow(spec, 128.0);
		vFragColor.rgb += vec3(fSpec, fSpec, fSpec);
	}
	
	gl_FragColor = vFragColor;
}