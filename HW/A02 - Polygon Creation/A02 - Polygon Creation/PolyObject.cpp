#include "PolyObject.h"
#include <GL/freeglut.h>

// constructor
PolyObject::PolyObject()
{
}

// destructor
PolyObject::~PolyObject()
{
}

// adds new vertex to the end of the vector (list)
void PolyObject::addVertex(vec2 p_vert)
{
	vertices.push_back(p_vert);
}

// sets current polygon color to a new color
void PolyObject::setColor(vec3 p_color)
{
	color = p_color;
}

// returns the number of vertices of the polygon
unsigned int PolyObject::getVertNum()
{
	return vertices.size();
}

// draw completed polygon
void PolyObject::draw()
{
	switch (getVertNum())
	{
	case 1:
		// if polygon contains one vertex, draw a point
		glBegin(GL_POINTS);
		//glVertex2fv();
		glEnd();
		break;

	case 2:
		// if polygon contains two vertices, draw a line
		glBegin(GL_LINES);
		glEnd();
		break;

	case 3:
		// if polygon contains 3 or more vertices, draw a polygon
		glBegin(GL_POLYGON);
		glEnd();
		break;
	}
}

// draw polygon mid-creation
void PolyObject::draw(vec2 p_mousePos)
{
}
