// Course:			IGME 309
// Student Name:	Madeline Boussa
// Assignment:      01

#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif
#include <math.h>

// establish pi as a constant
const float pi = 3.1415926;

// the window's width and height
int width, height;

// stores number of circle vertices
int numVertices = 100;


void init(void)
{
    // initialize the size of the window
    width = 800;
    height = 800;
}

void drawFilledCircle(float red, float green, float blue, float center_x, float center_y, float radius)
{
    // set drawing color
    glColor3f(red, blue, green);

    glBegin(GL_POLYGON);
    
    // for every vertex on the circle, calulate the angle (t) of its position relative to the center
    for (unsigned int i = 0; i < numVertices; i++)
    {
        // calculate angle (t)
        float t = 2.0f * pi * float(i) / numVertices;

        // using this t value, draw the correlating vertex
        float vx = center_x + radius * cos(t);
        float vy = center_y + radius * sin(t);
        glVertex2f(vx, vy);
    }

    glEnd();
}

void drawWireframeCircle(float red, float green, float blue, float center_x, float center_y, float radius, float lineWidth)
{
    // set drawing color
    glColor3f(red, blue, green);

    // set line width
    glLineWidth(lineWidth);

    glBegin(GL_LINE_LOOP);

    // for every vertex on the circle, calulate the angle (t) of its position relative to the center
    for (unsigned int i = 0; i < numVertices; i++)
    {
        // calculate angle (t)
        float t = 2.0f * pi * float(i) / float(numVertices);

        // using this t value, draw the correlating vertex
        float vx = center_x + radius * cos(t);
        float vy = center_y + radius * sin(t);
        glVertex2f(vx, vy);
    }

    glEnd();
}

// called when the GL context need to be rendered
void display(void)
{
    // light blue background color
    glClearColor(0.7, 0.8, 0.9, 1.0);

    // clear the buffer stored for drawing
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // draw panda here
    drawFilledCircle(1, 0, 0, 5, 5, 2);
    drawWireframeCircle(0.5, 0.5, 0, 2, 2, 1, 5);


    glutSwapBuffers();
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
    gluOrtho2D(0.0, 10.0, 0.0, 10.0);

    /* tell OpenGL to use the whole window for drawing */
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

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
    glutCreateWindow("A01 Panda");

    /* --- register callbacks with GLUT --- */

    //register function to handle window resizes
    glutReshapeFunc(reshape);

    //register function that draws in the window
    glutDisplayFunc(display);

    //start the glut main loop
    glutMainLoop();

    return 0;
}