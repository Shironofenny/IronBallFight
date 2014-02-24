#include "Shader.h"

Shader::Shader()
{

}

Shader::~Shader()
{

}

void Shader::initialize(std::string _runDir)
{
	unsigned addtionPath = _runDir.find_last_of('/');

	m_ProgramHandle = glCreateProgram();
	m_VertexHandle = glCreateShader(GL_VERTEX_SHADER);
	m_FragmentHandle = glCreateShader(GL_FRAGMENT_SHADER);

	loadShader(m_VertexHandle, _runDir.substr(0, addtionPath) + ConstantHandler::getInstance().vertexShader);
	loadShader(m_FragmentHandle, _runDir.substr(0, addtionPath) + ConstantHandler::getInstance().fragmentShader);

	glAttachShader(m_ProgramHandle, m_VertexHandle);
	glAttachShader(m_ProgramHandle, m_FragmentHandle);
	
	glLinkProgram(m_ProgramHandle);
	glUseProgram(m_ProgramHandle);
}

void Shader::attributeFloat(char const * _name, GLfloat const _value)
{
	GLint location = glGetAttribLocation(m_ProgramHandle, _name);
	glVertexAttrib1f(location, _value);
}

void Shader::attributeVec3(char const * _name, Vector const & _value)
{
	GLint location = glGetAttribLocation(m_ProgramHandle, _name);
	glVertexAttrib3f(location, (GLfloat)_value[0], (GLfloat)_value[1], (GLfloat) _value[2]);
}

void Shader::loadShader(GLuint _shader, std::string _filename)
{
	std::fstream infile;
	infile.open(_filename, std::ios::in);
	if(!infile.is_open())
	{
		std::cout<<"Fatal error: can't open shader "<<_filename<<" !"<<std::endl;
		return;
	}

	std::string line;
	std::string filetext;

	while(infile.good())
	{
		std::getline(infile, line);
		filetext.append(line + '\n');
	}

	GLchar const * shaderSource = filetext.c_str();
	GLint const shaderLength = filetext.size();

	glShaderSource(_shader, 1, &shaderSource, &shaderLength);

	glCompileShader(_shader);

	// Check whether the compile succeed or not
	int Flag;
	glGetShaderiv(_shader, GL_COMPILE_STATUS, &Flag);

	if(Flag == GL_FALSE)
	{
		std::cout<<"Error: shader file "<<_filename<<" compile failed."<<std::endl;
		int Length;
		int maxLength = 256;
		char * Log = new char[256];

		glGetShaderInfoLog(_shader, maxLength, &Length, Log);
		std::cout<<Log<<std::endl;
	}

	infile.close();
}
