# version 130

varying float spotlightIntensity;
varying float rayIntensity;

vec3 colorBase = vec3(0.1, 0.1, 0.1);
vec3 buringColor = vec3(0.3, 0.3, 0.0);

float spotlightAttenuate = 5.5;
float rayAttenuate = 5.0;

void main()
{
	vec4 addedColor = vec4(colorBase * spotlightIntensity * spotlightAttenuate, 1.0) + vec4(buringColor * rayIntensity * rayAttenuate, 1.0);
	gl_FragColor = gl_Color * 0.3 + addedColor;
}
