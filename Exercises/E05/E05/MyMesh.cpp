#include "MyMesh.h"
#include <GL/freeglut.h>

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;

MyMesh::MyMesh()
{
	vertNum = triNum = 0;
	vertices = NULL;
	indices = NULL;
	vertColors = NULL;
}

MyMesh::~MyMesh()
{
	if (vertices != NULL)
		delete[] vertices;
	if (indices != NULL)
		delete[] indices;

	if (vertColors != NULL)
		delete[] vertColors;
}

void MyMesh::load(char* fileName)
{
	vertNum = 0;
	triNum = 0;

	vertices = new float[100 * 2];
	indices = new unsigned int[100 * 3];
	vertColors = new float[100 * 3];

	// string to store initial file contents
	string value;

	ifstream file(fileName);

	if (!file.is_open()) {
		// Handle error
		cout << "file not open" << endl;
	}

	/****************************************/
	// Write your code below

	// indicates which array to add to based on number
	// 1 indicates vertices, 2 indicates indices
	unsigned int activeArrayNum = 1;

	// tracks where in each array we are adding to
	unsigned int currentVertIndex = 0;
	unsigned int currentTriIndex = 0;

	// while there are lines in the file,
	// read each line separated by space
	while (getline(file, value, ' '))
	{
		// print the line contents to console for debugging
		cout << value << "\n";

		// if character is a v,
		// switch active array to vertices array
		if (value == "v")
		{
			activeArrayNum = 1;

			// skip to next iteration
			continue;
		}

		// if character is an f, 
		// switch active array to indices array
		if (value == "f")
		{
			activeArrayNum = 2;

			// skip to next iteration
			continue;
		}

		switch (activeArrayNum)
		{
			case 1:
				// if vertices array is active,
				// add value to vertices array
				vertices[currentVertIndex] = stof(value);	// convert string to float

				break;

			case 2:
				// if indices array is active,
				// add value to vertices array

				break;
		}

	}
	file.close();



	// Write your code above
	/****************************************/

	// generate random vertex colors
	for (unsigned int i = 0; i < vertNum; i++) {
		vertColors[i * 3 + 0] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 1] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 2] = float(rand()) / (RAND_MAX + 1);
	}
}

void MyMesh::load(const unsigned int p_vertNum, const unsigned int p_triNum, const float* p_vertices, const unsigned int* p_indices)
{
	vertNum = p_vertNum;
	triNum = p_triNum;

	vertices = new float[vertNum * 2];
	indices = new unsigned int[triNum * 3];
	vertColors = new float[vertNum * 3];

	for (unsigned int i = 0; i < vertNum * 2; i++) {
		vertices[i] = p_vertices[i];
	}

	for (unsigned int i = 0; i < triNum * 3; i++) {
		indices[i] = p_indices[i];
	}

	// generate random vertex colors
	for (unsigned int i = 0; i < vertNum; i++) {
		vertColors[i * 3 + 0] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 1] = float(rand()) / (RAND_MAX + 1);
		vertColors[i * 3 + 2] = float(rand()) / (RAND_MAX + 1);
	}

}

void MyMesh::update()
{
	// we will use this for transformations later.... 
}

void MyMesh::draw()
{
	for (int i = 0; i < triNum; ++i) {
		glBegin(GL_TRIANGLES);
		glColor3fv(vertColors + indices[i * 3 + 0] * 3);
		glVertex2fv(vertices + indices[i * 3 + 0] * 2);

		glColor3fv(vertColors + indices[i * 3 + 1] * 3);
		glVertex2fv(vertices + indices[i * 3 + 1] * 2);

		glColor3fv(vertColors + indices[i * 3 + 2] * 3);
		glVertex2fv(vertices + indices[i * 3 + 2] * 2);
		glEnd();
	}
}