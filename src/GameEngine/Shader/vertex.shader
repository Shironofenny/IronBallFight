# version 130

attribute vec3 lightSource;

varying float spotlightIntensity;

vec4 vertexNew;
vec3 normalNew;

void main()
{
	gl_Position = ftransform();

	vertexNew = gl_ModelViewMatrix * gl_Vertex;
	normalNew = gl_NormalMatrix * gl_Normal;

	vec3 distance = lightSource - (vertexNew.xyz / vertexNew.w);
	vec3 dv = normalize(distance);

	float attenuation = 0.5 * (dv.x + dv.y + dv.z) / (distance.x + distance.y + distance.z);

	spotlightIntensity = dot(distance, normalNew) * attenuation;
	
	gl_FrontColor = gl_Color;
}
