

// Group(6) Abdelrahman Ramzy (The God Father), //Bassel Samer (Beselaaaaaaa3333333aaa), //Mohamed Essam (Ex.Mandoob)

#include <math.h>
#include <stdlib.h>
#include <windows.h>  // for MS Windows
#include <glut.h>// GLUT, include glut.h
#include "ObjLibrary/ObjModel.h"
#include "ObjLibrary/TextureManager.h"
#include "ObjLibrary/DisplayList.h" 
// angle of rotation for the camera direction
float angle = 0.0f;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
float ly = 0.0f; //Vector for Looking up & Down
				 // XZ position of the camera
float x = 0.0f, z = 1.9f, y = 0.0f;
int door = -1;
// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0.0f;
float open = 0.0f;
float spin = 0.0f;
int Openned = 0;
////////////////////////////////////////////////////////////////////////////////////////////////
ObjModel Object1;
ObjModel Object2;
ObjModel Object3;
ObjModel Object4;
ObjModel Object5;
DisplayList OB1_list;
DisplayList OB2_list;
DisplayList OB3_list;
DisplayList OB4_list;
DisplayList OB5_list;
///////////////////////////////////////////////////////////////////////////////////////////////

//GLfloat Light_Position0[] = { 0,0,3, 1.0 };

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(60.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}


void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle) {

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}
/////////////////////////////////////////////***********************************************************************
void Edeny_Berweta(int s)
{
	if (spin < 360.0)
		spin = spin + 11.0;
	if (spin >= 360.0)
		spin = 0;
	glutPostRedisplay();
	glutTimerFunc(50, Edeny_Berweta, 0);
}
/////////////////////////////////////////////////////////////////////////////////


void renderScene(void) {

	if (deltaMove)
		computePos(deltaMove);
	if (deltaAngle)
		computeDir(deltaAngle);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f); //lookAt Function Call//
	GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat qaLightPosition[] = { 1, 0, -3, 1.0 };
	GLfloat light_position1[] = { 0, 0, -1, 1.0 };
	// Material Properties
	GLfloat Rmat_amb_diff[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat Rmat_specular[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat Rshininess[] = { 10.0 }; // specular highlight 
	glEnable(GL_COLOR_MATERIAL);// to draw colored objects
	glEnable(GL_LIGHTING);
	//	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	// light0
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);    //illuminates all surfaces equally
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);    //Irradiance equally in all directions
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);  //Irradiance in only a single direction
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
	// light1
	glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	// Material Properties         
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, Rmat_amb_diff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Rmat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Rshininess);
	//Automatically normalize normals i.e glNormal()
	glEnable(GL_NORMALIZE);

	//right wall
	glPushMatrix();
	glColor3f(0, 0.5, 0.5);
	glTranslatef(.375, 0, 0);
	glScalef(0.01, 5, 15);
	glutSolidCube(0.25);
	glPopMatrix();
	//Ceiling
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glTranslatef(-0.25, .62, 0);
	glScalef(5, .01, 15);
	glutSolidCube(0.25);
	glPopMatrix();

	//Left Wall
	glPushMatrix();
	glColor3f(0, 0.5, 0.5);
	glTranslatef(-0.872, 0, 0);
	glScalef(.01, 5, 15);
	glutSolidCube(0.25);
	glPopMatrix();
	//Floor
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glTranslatef(-0.25, -.62, 0);
	glScalef(5, .01, 15);
	glutSolidCube(0.25);
	glPopMatrix();
	// Back wall
	glPushMatrix();
	glColor3f(0, 0.5, 0.5);
	glTranslatef(-0.248889, 0, -1.8755);
	glScalef(5, 5, .01);
	glutSolidCube(0.25);
	glPopMatrix();

	// Middle wall
	glPushMatrix();
	glTranslatef(-.67, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 0.5, 0.5);
	glVertex3f(0.21, .62, 0);
	glVertex3f(0.21, -.62, 0);
	glVertex3f(-0.2, -.62, 0);
	glVertex3f(-0.2, .62, 0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-.25, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 0.5, 0.5);
	glVertex3f(0.21, .62, 0);
	glVertex3f(0.21, -.0, 0);
	glVertex3f(-0.21, -.0, 0);
	glVertex3f(-0.21, .62, 0);
	glEnd();
	glPopMatrix();

	// Door
	glPushMatrix();
	glTranslatef(-0.46, 0, 0);
	glRotatef(open, 0, 1, 0);
	glTranslatef(0.42, 0, 0);

	glTranslatef(-0.21, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex3f(0.21, .0, 0);
	glVertex3f(0.21, -.62, 0);
	glVertex3f(-0.21, -.62, 0);
	glVertex3f(-0.21, .0, 0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(.35, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 0.5, 0.5);
	glVertex3f(0.025, .62, 0);
	glVertex3f(0.025, -.62, 0);
	glVertex3f(-.39, -.62, 0);
	glVertex3f(-.39, .62, 0);
	glEnd();
	glPopMatrix();
	

	//front wall
	glPushMatrix();
	glColor3f(0, 0.5, 0.5);
	glTranslatef(-.25, 0, 1.8755);
	glScalef(5, 5, .01);
	glutSolidCube(0.25);
	glPopMatrix();
	// table
	glPushMatrix();
	glColor3f(0, 0.5, 0);
	glScalef(2, 0.1, 1);
	glTranslatef(.06, -1, -1.75);
	glutSolidCube(.25);
	glPopMatrix();
	// teapots
	glPushMatrix();
	GLfloat mat_diff[] = { 1,1,1, 1.0 };
	GLfloat mat_amb[] = { 1,1,1, 1.0 };
	GLfloat mat_specular[] = { 1,1,1, 1.0 };
	GLfloat shininess[] = { 5.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glColor3f(1, 1, 0);
	glTranslatef(.28, -0.05, -1.7);
	glutSolidTeapot(0.05);
	glPopMatrix();

	glPushMatrix();
	GLfloat Teapot1_mat_diff[] = { 0,0,0, 1.0 };
	GLfloat Teapot1_mat_amb[] = { 0,0,0, 1.0 };
	GLfloat Teapot1_mat_specular[] = { 1,1,1, 1.0 };
	GLfloat Teapot1_shininess[] = { 5 }; // specular highlight 

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Teapot1_mat_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Teapot1_mat_diff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Teapot1_mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Teapot1_shininess);
	glColor3f(1, 0, 0);
	glTranslatef(.12, -0.05, -1.7);
	glutSolidTeapot(0.05);
	glPopMatrix();

	glPushMatrix();
	GLfloat Teapot2_mat_diff[] = { 1,1,1, 1.0 };
	GLfloat Teapot2_mat_amb[] = { 0,0,0, 1.0 };
	GLfloat Teapot2_mat_specular[] = { 0, 0, 0, 1.0 };
	GLfloat Teapot2_shininess[] = { 50.0 }; // specular highlight 

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Teapot2_mat_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Teapot2_mat_diff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Teapot2_mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Teapot2_shininess);
	glColor3f(1, 1, 0);
	glTranslatef(-0.0455, -.05, -1.7);
	glRotatef(spin, 0.0, 1.0, 0.0);
	glutSolidTeapot(0.05);
	glPopMatrix();

	/////////////////////////////////////////////////////////////El-Zohrea///////////////////////////////////////////////////////////////
	glPushMatrix();
	glColor3f(0.7, 0.2, 0.1);
	glTranslatef(.28, -0.05, -1.7);
	glutSolidTeapot(0.05);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.3, -0.02, -1.5);
	glScalef(0.007, 0.007, 0.007);
	//Object4.draw();
	OB4_list.draw();
	glPopMatrix();

	////////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(0.0, -0.25, -0.50);
	glScalef(0.03, 0.03, 0.03);
	glPushMatrix();
	glTranslatef(-4.0, 9.0, -0.75);
	//Object1.draw();
	OB1_list.draw();
	glPopMatrix();
	glScalef(0.009, 0.009, 0.009);
	glTranslatef(0.0, 0.0, 2.0);
	glTranslatef(0.0, 0.0, 0.9);
	//Object2.draw();
	OB2_list.draw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -0.3, 1.0);
	glScalef(0.001, 0.001, 0.001);
	//Object3.draw();
	OB3_list.draw();
	glPushMatrix();
	glScalef(10.0, 10.0, 10.0);
	glTranslatef(15.0, -1.0, 0.0);
	OB5_list.draw();
	glPopMatrix();
	glPopMatrix();
	////////////////////////////////////////////////////////////////////////////

	// Swap between the two buffers

	glutSwapBuffers();
}

void Timer(int x)
{
	if (door == 1)
	{
		Openned = 1;
		if (open < 90)
			open = open + 0.5;
	}
	if (door == -1)
	{
		Openned = 0;
		if (open > 0)
			open = open - 0.5;
	}
	// Refresh and redraw
	glutPostRedisplay();
	glutTimerFunc(30, Timer, 0);
}


void El72_El_3asfora(unsigned char key, int xx, int yy) {

	switch (key) {
	case ' ':
		if (door == -1)
		{
			door = 1;
			glutTimerFunc(30, Timer, 0);
			return;
		}
		if (door == 1)
		{
			door = -1;
			glutTimerFunc(30, Timer, 0);
			return;

		}
	case 'f':  //Move Forwards
		if (Openned == 0)
		{
			if (z <= 2.0&&z > 0.5)
				deltaMove = 0.1f;
			else 
				deltaMove = 0.0f;
		}
		if (Openned == 1)
		{
			if (z >= -1.6)
				deltaMove = 0.1;
			else
				deltaMove = 0.0;
		}
		break;
	case 'b':  //Move Backwards
		deltaMove = -0.1f;
		break;
	case 'r':
		Edeny_Berweta(1);
		break;
	case 27:  //Press Esc to close the window
		exit(0);
	default:
		break;
	}

}


void pressKey(int key, int xx, int yy) {

	switch (key) {
	case GLUT_KEY_LEFT: deltaAngle = -0.01f; break;
	case GLUT_KEY_RIGHT: deltaAngle = 0.01f; break;
	case GLUT_KEY_UP:
		if (ly <= 0.5)
		{
			ly += 0.5;
		}
		break;
	case GLUT_KEY_DOWN:
		if (ly >= -0.5)
		{
			ly -= 0.5;
		}
		break;
	}
}

void releaseKey(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT: deltaAngle = 0.0f; break;

	}
}
void Ra7et_El_3asfora(unsigned char key, int xx, int yy)
{
	switch (key) {
	case 'f':
	case 'b': deltaMove = 0; break;
	}

}


int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Thanos' House");

	//Imported Objects 
	Object1.load("f-16.obj");
	Object2.load("dolphins.obj");
	Object3.load("porsche.obj");
	Object4.load("rose+vase.obj");
	Object5.load("MaleLow.obj");
	OB1_list = Object1.getDisplayList();
	OB2_list = Object2.getDisplayList();
	OB3_list = Object3.getDisplayList();
	OB4_list = Object4.getDisplayList();
	OB5_list = Object5.getDisplayList();


	// register callbacks
	glutReshapeFunc(changeSize);
	glutDisplayFunc(renderScene);

	glutIdleFunc(renderScene);
	glutSpecialFunc(pressKey);
	glutKeyboardFunc(El72_El_3asfora);
	glutKeyboardUpFunc(Ra7et_El_3asfora);
	// here are the new entries
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);
	Timer(0);
	Edeny_Berweta(1);
	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();
	return 1;
}
