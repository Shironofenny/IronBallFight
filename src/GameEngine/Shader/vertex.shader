attribute float isOuterLightSource;
attribute vec3 lightSource;

vec3 lightDir = vec3(0.707, 0.707, 0);
varying float intensity;

void main()
{
	if(isOuterLightSource == 0.0)
	{
		gl_Position = ftransform();
		intensity = dot(lightDir, gl_Normal);
	}
	else
	{

	}
	gl_FrontColor = gl_Color;
}
