#include "Planet.h"
#include <cmath>

#define _USE_MATH_DEFINES

// In order to use static private value, I need an extra definition here.
GLuint Planet::ms_Shape;

Planet::Planet():
	Sprite()
{
	m_Radius = 1.0;
}

Planet::Planet(Vector const & _position):
	Sprite(_position)
{
	m_Radius = 1.0;
}

Planet::Planet(double _radius, Vector const & _position):
	Sprite(_position), 
	m_Radius(_radius)
{
}

Planet::~Planet()
{

}

void Planet::initializeShape()
{
	// Initialize eight triangles and six points:
	Triangle triangleInit[8];
	Vector vec[6];
	
	// Refine the mesh using queue
	std::queue<Triangle> mesh;

	// Use this vector to restore all vertices
	std::vector <Vector> vertices;

	for (int i = 0; i <= 5; i++)
	{
		// Six vertex for the simplest sphere
		vec[i] = Vector(( i == 0 ? 1 : (i == 1 ? -1 : 0)), \
										(	i == 2 ? 1 : (i == 3 ? -1 : 0)), \
										( i == 4 ? 1 : (i == 5 ? -1 : 0)) );
		vertices.push_back(vec[i]);
	}
	for (int i = 0; i <= 7; i++)
	{
		// Eight triangles for the simplest sphere
		switch (i)
		{
			case 0:
				triangleInit[i].vertex[0] = 2;
				triangleInit[i].vertex[1] = 1;
				triangleInit[i].vertex[2] = 4;
				break;
			case 1:
				triangleInit[i].vertex[0] = 2;
				triangleInit[i].vertex[1] = 4;
				triangleInit[i].vertex[2] = 0;
				break;
			case 2:
				triangleInit[i].vertex[0] = 2;
				triangleInit[i].vertex[1] = 0;
				triangleInit[i].vertex[2] = 5;
				break;
			case 3:
				triangleInit[i].vertex[0] = 2;
				triangleInit[i].vertex[1] = 5;
				triangleInit[i].vertex[2] = 1;
				break;
			case 4:
				triangleInit[i].vertex[0] = 3;
				triangleInit[i].vertex[1] = 4;
				triangleInit[i].vertex[2] = 1;
				break;
			case 5:
				triangleInit[i].vertex[0] = 3;
				triangleInit[i].vertex[1] = 0;
				triangleInit[i].vertex[2] = 4;
				break;
			case 6:
				triangleInit[i].vertex[0] = 3;
				triangleInit[i].vertex[1] = 5;
				triangleInit[i].vertex[2] = 0;
				break;
			case 7:
				triangleInit[i].vertex[0] = 3;
				triangleInit[i].vertex[1] = 1;
				triangleInit[i].vertex[2] = 5;
				break;
			default:
				break;
		}
		mesh.push(triangleInit[i]);
	}
	
	// Initialization finished here
	// Start to refine the mesh of the simplest sphere:
	for (int i = 0; i < ConstantHandler::getInstance().planetMeshRefineTime; i++)
	{
		// Remember the size of the queue at the beginning of each turn.
		std::queue <Triangle>::size_type size = mesh.size();
		for (std::queue <Triangle>::size_type j = 0; j < size; j++)
		{
			Triangle process = mesh.front();
			Vector newVec[3];
			newVec[0] = (vertices[process.vertex[0]] + vertices[process.vertex[1]]) / 2;
			newVec[1] = (vertices[process.vertex[1]] + vertices[process.vertex[2]]) / 2;
			newVec[2] = (vertices[process.vertex[2]] + vertices[process.vertex[0]]) / 2;

			int numberOfVertices[3];
			for (int k = 0; k <= 2; k++)
			{
				numberOfVertices[k] = vertices.size();
				vertices.push_back(newVec[k]);
			}

			// Break this triangle into four
			Triangle newTri[4];

			newTri[0].vertex[0] = process.vertex[0];
			newTri[0].vertex[1] = numberOfVertices[0];
			newTri[0].vertex[2] = numberOfVertices[2];

			newTri[1].vertex[0] = process.vertex[1];
			newTri[1].vertex[1] = numberOfVertices[1];
			newTri[1].vertex[2] = numberOfVertices[0];

			newTri[2].vertex[0] = process.vertex[2];
			newTri[2].vertex[1] = numberOfVertices[2];
			newTri[2].vertex[2] = numberOfVertices[1];

			newTri[3].vertex[0] = numberOfVertices[0];
			newTri[3].vertex[1] = numberOfVertices[1];
			newTri[3].vertex[2] = numberOfVertices[2];

			// Push broken triangles back into the queue.
			for (int k = 0; k <= 3; k++) mesh.push(newTri[k]);

			// Pop the used triangle.
			mesh.pop();
		}
	}

	// Now change this shape into sphere:
	for (std::vector <Vector>::size_type i = 0; i < vertices.size(); i++)
	{
		vertices[i].normalize();
	}

	// Compile this shape into display list
	Planet::ms_Shape = glGenLists(1);
	glNewList(Planet::ms_Shape, GL_COMPILE);
	{
		glBegin(GL_TRIANGLES);
		while(mesh.size() != 0)
		{
			double dotProductY[3], dotProductX[3], theta[3], phi[3];
			Vector resVec[3];
			for (int i = 0; i <= 2; i++)
			{
				dotProductY[i] = dot(vertices[mesh.front().vertex[i]], Vector(0., 1., 0.));
				theta[i] = acos(dotProductY[i]);
				resVec[i] = vertices[mesh.front().vertex[i]] - Vector(0., 1., 0.) * dotProductY[i];
				if (resVec[i].norm() == 0)
				{
					phi[i] = 0;
				}
				else
				{
					resVec[i].normalize();
					dotProductX[i] = dot(resVec[i], Vector(0., 0., 1.));
					phi[i] = acos(dotProductX[i]);
					if (dot(resVec[i], Vector(1., 0., 0.)) < 0) phi[i] = -phi[i] + 2 * M_PI;
				}
			}

			if (phi[0] == 0 || phi[1] == 0 || phi[2] == 0) 
			{
				if (phi[0] > M_PI || phi[1] > M_PI || phi[2] > M_PI)
				{
					phi[0] = phi[0] == 0 ? 2 * M_PI : phi[0];
					phi[1] = phi[1] == 0 ? 2 * M_PI : phi[1];
					phi[2] = phi[2] == 0 ? 2 * M_PI : phi[2];
				}
			}

			if ((phi[0] == 0 || phi[1] == 0 || phi[2] == 0) && (theta[0] == M_PI / 2 || theta[1] == M_PI/2 || theta[2] == M_PI / 2))
			{
				//std::cout <<vertices[mesh.front().vertex[0]]<<std::endl;
				//std::cout <<vertices[mesh.front().vertex[1]]<<std::endl;
				//std::cout <<vertices[mesh.front().vertex[2]]<<std::endl<<std::endl;

				//std::cout <<phi[0] / 2 / M_PI <<'\t'<< 1-theta[0] / M_PI<<std::endl;
				//std::cout <<phi[1] / 2 / M_PI <<'\t'<< 1-theta[1] / M_PI<<std::endl;
				//std::cout <<phi[2] / 2 / M_PI <<'\t'<< 1-theta[2] / M_PI<<std::endl<<std::endl<<std::endl;
				
			}
			
			glTexCoord2f( phi[0] / (2 * M_PI), 1 - theta[0] / M_PI);
			glNormal3f(vertices[mesh.front().vertex[0]][0], \
								 vertices[mesh.front().vertex[0]][1], \
								 vertices[mesh.front().vertex[0]][2]);
			glVertex3f(vertices[mesh.front().vertex[0]][0], \
								 vertices[mesh.front().vertex[0]][1], \
								 vertices[mesh.front().vertex[0]][2]);
			glTexCoord2f( phi[1] / (2 * M_PI), 1 - theta[1] / M_PI);
			glVertex3f(vertices[mesh.front().vertex[1]][0], \
								 vertices[mesh.front().vertex[1]][1], \
								 vertices[mesh.front().vertex[1]][2]);
			glNormal3f(vertices[mesh.front().vertex[1]][0], \
								 vertices[mesh.front().vertex[1]][1], \
								 vertices[mesh.front().vertex[1]][2]);
			glTexCoord2f( phi[2] / (2 * M_PI), 1 - theta[2] / M_PI);
			glNormal3f(vertices[mesh.front().vertex[2]][0], \
								 vertices[mesh.front().vertex[2]][1], \
								 vertices[mesh.front().vertex[2]][2]);
			glVertex3f(vertices[mesh.front().vertex[2]][0], \
								 vertices[mesh.front().vertex[2]][1], \
								 vertices[mesh.front().vertex[2]][2]);

			mesh.pop();
		}
		glEnd();
	}
	glEndList();
}

void Planet::update(double dt)
{

}

void Planet::setTexture(GLuint _texture)
{
	m_Texture = _texture;
}

void Planet::render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_Texture);

	glPushMatrix();
		
		Shader::getInstance().attributeInt("isTextured", 1);
		
		glTranslatev(m_Position);
		glScalef(m_Radius, m_Radius, m_Radius);
		glRotated(180, 0., 1., 0.);
		glCallList(Planet::ms_Shape);

		Shader::getInstance().attributeInt("isTextured", 0);

	glPopMatrix();
}
