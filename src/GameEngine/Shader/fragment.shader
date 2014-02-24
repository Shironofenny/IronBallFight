# version 130

varying float spotlightIntensity;
vec3 colorBase = vec3(0.1, 0.1, 0.1);

void main()
{
	vec4 addedColor = vec4(colorBase * spotlightIntensity, 1.0);
	gl_FragColor = gl_Color * 0.3 + 10 * addedColor;
}
