#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif


// the window's width and height
int width, height;

float gx = 0.0f;
float gy = 0.0f;

void init(void)
{
	// initialize the size of the window
	width = 600;
	height = 600;
}

// called when the GL context need to be rendered
void display(void)
{
	// clear the screen to white, which is the background color
	glClearColor(1.0, 1.0, 1.0, 0.0);

	// clear the buffer stored for drawing
	glClear(GL_COLOR_BUFFER_BIT);


	// this is to define in which transformed space / coordinate system (in a matrix form) the objects will be drawn. 
	// (we'll learn matrix-based transformation in later classes.) 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	// Specify another color for the following object(s)
	glColor3f(0.0, 0.0, 1.0);

	// We draw a point at the origin of the drawing canvas; thus, its coordinates should be (0, 0).
	glPointSize(30.0f); // define the size of the point - the diameter of rasterized points. the default value is 1.
	glBegin(GL_POINTS);
	glVertex2f(gx, gy);
	glEnd();
	glPointSize(1.0f); // set the point size back to default, so that the size of later points won't be affected.  

	glutSwapBuffers(); // This example uses double framebuffers. This instructs the app that the current frame is finished and ready to display.
	// The app then knows to swap it with the other buffer which was just displayed so that the display function can begin working on that buffer
}

// called when window is first created or when window is resized
void reshape(int w, int h)
{
	// update thescreen dimensions
	width = w;
	height = h;

	//do an orthographic parallel projection, limited by screen/window size
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5.0, 5.0, -5.0, 5.0); // Define the size of the canvas left =-5, right =-5, bottom =-5, top=5,
	// so the orgin is at the center of the canvas.  

/* tell OpenGL to use the whole window for drawing */
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		exit(0);
	}

	if (key == 'd') {
		gx += 0.1;
	}

	else if (key == 'a') {
		gx -= 0.1;
	}

	else if (key == 'w') {
		gy += 0.1;
	}

	else if (key == 's') {
		gy -= 0.1;
	}


	glutPostRedisplay();

}


int main(int argc, char* argv[])
{
	// before create a glut window,
	// initialize stuff not opengl/glut dependent
	init();

	//initialize GLUT, let it extract command-line GLUT options that you may provide
	//NOTE that the '&' before argc
	glutInit(&argc, argv);

	// specify as double bufferred can make the display faster
	// Color is speicfied to RGBA, four color channels with Red, Green, Blue and Alpha(depth)
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	//set the initial window size */
	glutInitWindowSize((int)width, (int)height);

	// create the window with a title
	glutCreateWindow("First OpenGL Program");

	/* --- register callbacks with GLUT --- */

	//register function to handle window resizes
	glutReshapeFunc(reshape);

	//register function that draws in the window
	glutDisplayFunc(display);

	glutKeyboardFunc(keyboard);

	//start the glut main loop
	glutMainLoop();

	return 0;
}