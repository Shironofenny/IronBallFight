#ifndef __SHADER_H__
#define __SHADER_H__

#include "../../GLHeader.h"
#include "../Utilities/ConstantHandler.h"

#include <string>
#include <fstream>
#include <iostream>

class Shader
{
	public:
		
		// Singleton.
		static Shader & getInstance()
		{
			static Shader instance;
			return instance;
		}

		// Create the program and link two corresponding shaders
		void initialize(std::string _runDir);
	
	private:

		// Constructor
		Shader();

		// Destructor
		~Shader();

		// Prevent any external implementaion
		Shader(Shader const &);
		void operator = (Shader const &);

		// Load and compile the shader with given handle _shader
		void loadShader(GLuint _shader, std::string _filename);

		// The handle of program
		GLuint m_ProgramHandle;

		// The handle of vertex shader
		GLuint m_VertexHandle;
		
		// The handle of fragment shader
		GLuint m_FragmentHandle;
};

#endif
