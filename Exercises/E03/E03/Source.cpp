// Course:			IGME 309
// Student Name:	Madeline Boussa
// Friday Exercise: 03

#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif

// the window's width and height
int width, height;

// create verticies of shapes

// triangle 1
float t1v1[2];
float t1v2[2];
float t1v3[2];

// triangle 2
float t2v1[2];
float t2v2[2];
float t2v3[2];

// create rectangle verticies
float r1[2];
float r2[2];
float r3[2];
float r4[2];


// instantiate shape vertex values
void createShapes()
{
    // bottom triangle;
    t1v1[0] = 3.0;
    t1v1[1] = 3.0;

    t1v2[0] = 5.0;
    t1v2[1] = 5.0;

    t1v3[0] = 7.0;
    t1v3[1] = 3.0;

    // top triangle;
    t2v1[0] = 4.0;
    t2v1[1] = 5.0;

    t2v2[0] = 5.0;
    t2v2[1] = 6.0;

    t2v3[0] = 6.0;
    t2v3[1] = 5.0;

    // rectangle
    // top left
    r1[0] = 4.5;
    r1[1] = 3.0;

    // top right
    r2[0] = 5.5;
    r2[1] = 3.0;

    // bottom right
    r3[0] = 5.5;
    r3[1] = 1.0;

    // bottom left
    r4[0] = 4.5;
    r4[1] = 1.0;
}


void init(void)
{
    // initialize the size of the window
    width = 600;
    height = 600;
    createShapes();
}


// called when the GL context need to be rendered
void display(void)
{
    // light blue background color
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // clear the buffer stored for drawing
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // draw tree here

    glColor3f(0.0, 1.0, 0.0);

    // bottom triangle
    glBegin(GL_TRIANGLES);
    glVertex2fv(t1v1);
    glVertex2fv(t1v2);
    glVertex2fv(t1v3);
    glEnd();

    // top triangle
    glBegin(GL_TRIANGLES);
    glVertex2fv(t2v1);
    glVertex2fv(t2v2);
    glVertex2fv(t2v3);
    glEnd();

    // rectangle

    glColor3f(0.4, 0.28, 0.0);
    
    glBegin(GL_POLYGON);
    glVertex2fv(r1);
    glVertex2fv(r2);
    glVertex2fv(r3);
    glVertex2fv(r4);
    glEnd();
    
    // ornament point
    
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(20.0);

    glBegin(GL_POINTS);
    glVertex2f(5.0, 4.9);
    glEnd();

    // star point

    glColor3f(1.0, 1.0, 0.0);
    glPointSize(40.0);

    glBegin(GL_POINTS);
    glVertex2f(5.0, 6.3);
    glEnd();

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
    glutCreateWindow("E03 Christmas Tree");

    /* --- register callbacks with GLUT --- */

    //register function to handle window resizes
    glutReshapeFunc(reshape);

    //register function that draws in the window
    glutDisplayFunc(display);

    //start the glut main loop
    glutMainLoop();

    return 0;
}