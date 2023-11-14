// Course:			IGME 309
// Student Name:	Madeline Boussa
// Assignment Number: 04


//Usage:
//Hold down the number keys , 1-7, to select one or multiple circles.
//While circle(s) are selected, use the left mouse button to translate and use the right mouse button to rotate.

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include <math.h>
using namespace std;


#define MAX_NUM_JOINTS 16

//#define MAX_NUM_CIRCLE 7
//#define CIRCLE_RADIUM 2.0

int win_width = 600, win_height = 600;
float canvas_width = 20.0f; float canvas_height = 20.0f;


bool keyStates[256];
int buttonState;
float colors[3 * MAX_NUM_JOINTS];
float translations[2 * MAX_NUM_JOINTS];
float rotations[MAX_NUM_JOINTS];

float curMouse[2];
float preMouse[2];

int activeID = 14; // start activeID at the lower torso (has an id of 6)


void init(void)
{
    for (int i = 0; i < 256; i++) {
        keyStates[i] = false;
    }
    for (int i = 0; i < MAX_NUM_JOINTS; i++) {
        colors[i * 3 + 0] = 0.0f; // red
        colors[i * 3 + 1] = 0.0f; // green
        colors[i * 3 + 2] = 0.0f; // blue

        translations[i * 2 + 0] = 0.0f; // x
        translations[i * 2 + 1] = 0.0f; // y

        rotations[i] = 0.0f;
    }

    buttonState = -1;
}

// draws a rectangle based on a given x and y coordinate of the center, and values given for width and height
void drawRect(float x, float y, float width, float height, const float* c)
{
    glColor3fv(c);
    glLineWidth(3.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x - (width / 2), y - (height / 2));   // top left
    glVertex2f(x + (width / 2), y - (height / 2));   // top right
    glVertex2f(x + (width / 2), y + (height / 2));   // bottom right
    glVertex2f(x - (width / 2), y + (height / 2));   // bottom left
    glVertex2f(x - (width / 2), y - (height / 2));   // connect to top left
    glEnd();
}

void display(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // draw robot
    
    // the index of current joint
    int jid;

    // _____ lower body _____

    // lower torso
    jid = 6;
    
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);

    glPushMatrix();

    drawRect(0, 0, 3, 2, colors + jid * 3);

    // _____ left leg _____


    // left thigh
    jid = 5;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);

    drawRect(-1, -2.5, 1, 2, colors + jid * 3);

    // left leg
    jid = 4;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);

    drawRect(-1, -5, 1, 2, colors + jid * 3);

    // left foot
    jid = 3;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);
    drawRect(-1.5, -7, 2, 1, colors + jid * 3);

    // _____ right leg _____

    glPopMatrix();

    // right thigh
    jid = 2;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);

    drawRect(1, -2.5, 1, 2, colors + jid * 3);

    // right leg
    jid = 1;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);
    drawRect(1, -5, 1, 2, colors + jid * 3);
    
    // right foot
    jid = 0;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);
    drawRect(1.5, -7, 2, 1, colors + jid * 3);

    // _____ upper torso _____

    // upper torso
    jid = 7;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);

    glPushMatrix();

    drawRect(0, 3, 3.5, 3, colors + jid * 3);

    // _____ left arm _____

    // left arm
    jid = 8;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);
    drawRect(-3.25, 4, 2, 1, colors + jid * 3);

    // left forearm
    jid = 9;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);
    drawRect(-5.75, 4, 2, 1, colors + jid * 3);

    // left hand
    jid = 10;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);
    drawRect(-7.75, 4, 1, 1, colors + jid * 3);

    // _____ right arm _____

    glPopMatrix();

    // right arm
    jid = 11;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);
    drawRect(3.25, 4, 2, 1, colors + jid * 3);
    
    // right forearm
    jid = 12;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);
    drawRect(5.75, 4, 2, 1, colors + jid * 3);
   
    // right hand
    jid = 13;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);
    drawRect(7.75, 4, 1, 1, colors + jid * 3);

    // _____ head _____

    // neck
    jid = 14;
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);
    drawRect(0, 5.5, 1, 1, colors + jid * 3);

    // head
    jid = 15;
    //glTranslatef(0, 7.5, 1);
    glRotatef(rotations[jid], 0.0f, 0.0f, 1.0f);
    //glTranslatef(0, 0, 1);
    drawRect(0, 7.5, 2.25, 2.25, colors + jid * 3);

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    win_width = w;
    win_height = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-canvas_width / 2.0f, canvas_width / 2.0f, -canvas_height / 2.0f, canvas_height / 2.0f);
    glViewport(0, 0, (GLsizei)win_width, (GLsizei)win_height);

    glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) // 'esc' key
        exit(0);

    //unsigned char asciiOffset = 49; // see an ascii table
    //for (unsigned char i = '1'; i < '7'; i++) {
    //    if (key == i) {
    //        keyStates[i] = true;
    //        colors[(i - asciiOffset) * 3 + 0] = 1.0f;
    //        colors[(i - asciiOffset) * 3 + 1] = 0.0f;
    //        colors[(i - asciiOffset) * 3 + 2] = 0.0f;
    //    }
    //}

    // rotate based on keyboard press
    // if a key is pressed, increment rotation by 1
    if (key == 97 || key == 65)
    {
        rotations[activeID] += 1;
    }
    // if d key is pressed, decrement rotation by 1
    if (key == 100 || key == 68)
    {
        rotations[activeID] -= 1;
    }

    cout << activeID << endl;

    // alter selection based on keyboard press
    // if w key is pressed, increment current joint index by 1
    //if (key == 119 || key == 87)
    //{
    //    // increment selected joint
    //    incrementJointIndex();

    //    // change joint color to red
    //    colors[jid * 3 + 0] = 1.0f;
    //    colors[jid * 3 + 1] = 0.0f;
    //    colors[jid * 3 + 2] = 0.0f;
    //    
    //    cout << "w" << endl;
    //    cout << jid << endl;
    //}

    
    glutPostRedisplay();
}

void keyboardUp(unsigned char key, int x, int y)
{
    //unsigned char asciiOffset = 49; // see an ascii table
    //for (unsigned char i = '1'; i < '7'; i++) {
    //    if (key == i) {
    //        keyStates[i] = false;
    //        colors[(i - asciiOffset) * 3 + 0] = 0.0f;
    //        colors[(i - asciiOffset) * 3 + 1] = 0.0f;
    //        colors[(i - asciiOffset) * 3 + 2] = 0.0f;
    //    }
    //}

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    /*if (state == GLUT_DOWN) {
        buttonState = button;
        curMouse[0] = ((float)x / win_width - 0.5f) * canvas_width;
        curMouse[1] = ((float)(win_height - y) - 0.5f) / win_height * canvas_height;
        preMouse[0] = ((float)x / win_width - 0.5f) * canvas_width;
        preMouse[1] = ((float)(win_height - y) - 0.5f) / win_height * canvas_height;
    }
    else if (state == GLUT_UP)
        button = -1;*/
}

void motion(int x, int y)
{
    //unsigned char asciiOffset = 49; // see an ascii table

    //curMouse[0] = ((float)x / win_width - 0.5f) * canvas_width;
    //curMouse[1] = ((float)(win_height - y) - 0.5f) / win_height * canvas_height;

    //if (buttonState == GLUT_LEFT_BUTTON) {
    //    for (unsigned char i = '1'; i < '7'; i++) {
    //        if (keyStates[i]) {
    //            translations[(i - asciiOffset) * 2 + 0] += curMouse[0] - preMouse[0];
    //            translations[(i - asciiOffset) * 2 + 1] += curMouse[1] - preMouse[1];
    //        }
    //    }
    //    glutPostRedisplay();
    //}

    //else if (buttonState == GLUT_RIGHT_BUTTON) {
    //    for (unsigned char i = '1'; i < '7'; i++) {
    //        if (keyStates[i]) {
    //            rotations[i - asciiOffset] += curMouse[0] - preMouse[0];
    //        }
    //    }
    //    glutPostRedisplay();
    //}

    //preMouse[0] = curMouse[0];
    //preMouse[1] = curMouse[1];

}

int main(int argc, char* argv[])
{
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(win_width, win_height);
    glutCreateWindow("2D Transformation Tree");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;

}