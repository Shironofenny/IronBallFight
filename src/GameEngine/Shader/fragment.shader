varying float intensity;

void main()
{
	gl_FragColor = gl_Color * (0.5 + 0.5 * intensity);
}
