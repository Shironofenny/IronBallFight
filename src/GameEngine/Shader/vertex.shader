# version 130

attribute vec3 lightSource;

attribute int isCollided;
attribute vec3 raySource;
attribute vec3 rayDirection;

varying float spotlightIntensity;
varying float rayIntensity;

vec4 vertexNew;
vec3 normalNew;

float charactLength = 0.3;

void main()
{
	gl_Position = ftransform();

	vertexNew = gl_ModelViewMatrix * gl_Vertex;
	normalNew = gl_NormalMatrix * gl_Normal;

	vec3 distance = lightSource - (vertexNew.xyz / vertexNew.w);
	vec3 dv = normalize(distance);

	float attenuation = (dv.x + dv.y + dv.z) / (distance.x + distance.y + distance.z);

	spotlightIntensity = dot(distance, normalNew) * attenuation;

	if (isCollided == 1)
	{
		vec3 diff = (vertexNew.xyz / vertexNew.w) - raySource;
		float projection = dot(diff, rayDirection);

		if(projection > 0.0)
		{
			vec3 resVector = diff - rayDirection * projection;
			float norm = sqrt(dot(resVector, resVector));
			
			if(norm < charactLength)
			{
				rayIntensity = 1.0 / (norm + 1.0);
			}
			else
			{
				rayIntensity = 0.0;
			}
		}
		else
		{
			rayIntensity = 0.0;
		}
	}
	else
	{
		rayIntensity = 0.0;
	}
	gl_FrontColor = gl_Color;
}
