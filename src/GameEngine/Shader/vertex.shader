# version 130

// The point light source
attribute vec3 lightSource;

// Collided switch and light sources
attribute int isCollided;
attribute vec3 raySource;
attribute vec3 rayDirection;

// Texture switch
attribute int isTextured;

// Send point light information to fragment shader
varying float spotlightIntensity;

// Send ray information to fragment shader
varying float rayIntensity;

// Send texture switch to fragment shader
varying float isRenderTexture;

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
	
	// Set up texture
	
	if(isTextured != 0)
	{
		isRenderTexture = 1.0;
		gl_TexCoord[0] = gl_MultiTexCoord0;
	}
	else
	{
		isRenderTexture = 0.0;
	}

	gl_FrontColor = gl_Color;
}
