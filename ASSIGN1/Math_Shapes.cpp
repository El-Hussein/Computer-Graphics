#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include <math.h>
#include <iostream>

using namespace std;

#define PI 3.14159265


void drawPolygon(int y){
    glTranslated(0.0f, -15.0f*y, 0.0f);
    glPushMatrix();
    for(int d= 3*y; d<3*y+3; d++){
        glTranslated(+50.0f, 0.0f, 0.0f);
        float angle = (180.0/d);
        float main_side = 5 * sin (angle*PI/180);
        float bisector = 5 * cos (angle*PI/180);
        for (int i = 0; i < d; ++i) {
            glRotatef((360.0/d), 0.0f, 0.0f, 1.0f);

            glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
            glBegin(GL_TRIANGLES); //Begin quadrilateral coordinates
            glVertex3f(bisector, main_side, -130.0f);
            glVertex3f(bisector, -1*main_side, -130.0f);
            glVertex3f(0.0f, 0.0f, -130.0f);

            glEnd(); //End quadrilateral coordinates
        }   
    }
    glPopMatrix();
}

void drowCircle(){
    int d = 1000;
    float angle = (180.0/d);
    float main_side = 30 * sin (angle*PI/180);
    float bisector = 30 * cos (angle*PI/180);
    for (int i = 0; i < d; ++i) {
        glRotatef((360.0/d), 0.0f, 0.0f, 1.0f);

        glBegin(GL_TRIANGLES); 
            glColor4f(1.0f, 0.0f, 0.0f, 0.7f);
            glVertex3f(bisector, main_side, -150.0f);
            glVertex3f(bisector, -1*main_side, -150.0f);
            glVertex3f(0.0f, 0.0f, -150.0f);
        glEnd(); 
    }  
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drowCircle();

    glTranslated(-100.0f, 55.0f, 0.0f);

    drawPolygon(1);
    drawPolygon(2);
    drawPolygon(3);

    glutSwapBuffers();
}

void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}

void handleKeypress(unsigned char key, //The key that was pressed
	int x, int y) {    //The current mouse coordinates

	switch (key) {
	case 27: //Escape key
		exit(0); //Exit the program
	}
}

void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    ///Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400); //Set the window size

	//Create the window
	glutCreateWindow("Basic Shapes - videotutorialsrock.com");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
return 0; //This line is never reached
}
