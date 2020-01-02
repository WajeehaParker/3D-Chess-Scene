#include <Windows.h>
#include <iostream>
#include <glut.h>
#include "RGBA.h"
#include "RGBApixMap.h"
#include "camera.h"

static GLubyte my_texels[1][1][1];
static GLuint texName;
//Camera cam;
RGBApixmap pix[1];
mRGBApixmap bcg[1];
Camera cam;

float dr = 0.6f, dg = 0.6f, db = 0.6f;

void texturing()
{
	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, my_texels);


	glBindTexture(GL_TEXTURE_2D, texName);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4.0, -1.0, -4.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-4.0, -1.0, 4.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(4.0, -1.0, 4.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(4.0, -1.0, -4.0);
	glEnd();
}

void wall(double thickness)
{
	glPushMatrix();
	//texturing();
	glTranslated(0.5 - 2, 0.5*thickness - 2, 0.5 - 2);
	glScaled(1.0, thickness, 1.0);
	glutSolidCube(8.0);
	glPopMatrix();
}

GLUquadricObj * qobj;
void cylinder(float baseradius, float topradius, float height, int slices, int stacks)
{
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_LINE);
	glRotated(-90, 1, 0, 0);
	gluCylinder(qobj, baseradius, topradius, height, slices, stacks);
}

void base()
{
	glPushMatrix();
	glScaled(1.0, 0.3, 1.0);
	glutSolidSphere(0.8, 18, 18);
	glPushMatrix();
	glTranslated(0, 0.6, 0);
	glutSolidSphere(0.7, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0.3, 0);
	cylinder(0.7, 0.4, 2, 10, 100);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0.7, 0);
	glScaled(1.0, 0.3, 1.0);
	glutSolidSphere(0.5, 18, 18);
	glPopMatrix();
}

void rook()
{
	glPushMatrix();
	glPushMatrix();
	glTranslated(0, 0.6, 0);
	cylinder(0.45, 0.4, 2, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.6, 0);
	cylinder(0.4, 0.55, 0.25, 10, 100);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.85, 0);
	cylinder(0.55, 0.6, 0.3, 10, 100);
	glPopMatrix();
	base();
	glPopMatrix();
}

void knight()
{
	glPushMatrix();
	glPushMatrix();
	glTranslated(0, 0.6, 0);
	cylinder(0.45, 0.45, 0.3, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.15, 1.65, 0);
	glutSolidSphere(0.8, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-1.4, 1.4, 0);
	glRotated(-90, 1, 0, 0);
	cylinder(0, 0.6, 1, 10, 500);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0, 1.9, 0);
	glutSolidSphere(0.7, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.15, 2.0, 0);
	glutSolidSphere(0.65, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.15, 2.1, 0);
	glutSolidSphere(0.6, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.3, 2.2, 0);
	glutSolidSphere(0.6, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.4, 2.3, 0);
	glutSolidSphere(0.55, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.45, 2.4, 0);
	glutSolidSphere(0.5, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.55, 2.5, 0);
	glutSolidSphere(0.5, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.65, 2.8, 0);
	glutSolidSphere(0.5, 18, 18);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.5, 3.4, 0);
	glutSolidSphere(0.6, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.2, 3.3, 0);
	glRotated(-105, 1, 0, 0);
	cylinder(0.5, 0.3, 1, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(1.0, 3, 0);
	glutSolidSphere(0.3, 18, 18);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.5, 2, 0);
	glScaled(1.0, 0.3, 1.0);
	glutSolidSphere(0.3, 18, 18);
	glPopMatrix();

	base();
	glPopMatrix();
}

void bishop()
{
	glPushMatrix();
	glPushMatrix();
	glTranslated(0, 0.6, 0);
	cylinder(0.45, 0.25, 1.3, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 1.9, 0);
	cylinder(0.25, 0.3, 1, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.6, 0);
	glScaled(1.0, 0.3, 1.0);
	glutSolidSphere(0.5, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.75, 0);
	glScaled(1.0, 0.3, 1.0);
	glutSolidSphere(0.43, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.9, 0);
	cylinder(0.3, 0.35, 0.2, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.05, 0);
	glScaled(1.0, 0.3, 1.0);
	glutSolidSphere(0.4, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.9, 0);
	cylinder(0.3, 0.5, 0.6, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.65, 0);
	cylinder(0.5, 0.3, 0.4, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.55, 0);
	glutSolidSphere(0.5, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 4.05, 0);
	cylinder(0.3, 0.1, 0.2, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 4.3, 0);
	glutSolidSphere(0.2, 18, 18);
	glPopMatrix();
	base();
	glPopMatrix();
}

void king()
{
	glPushMatrix();
	glPushMatrix();
	glTranslated(0, 0.6, 0);
	cylinder(0.45, 0.3, 0.9, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 1.5, 0);
	cylinder(0.3, 0.25, 0.65, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.15, 0);
	cylinder(0.25, 0.25, 0.3, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.45, 0);
	cylinder(0.25, 0.3, 0.65, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.1, 0);
	glScaled(1.0, 0.2, 1.0);
	glutSolidSphere(0.6, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.25, 0);
	glScaled(1.0, 0.2, 1.0);
	glutSolidSphere(0.45, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.4, 0);
	cylinder(0.3, 0.35, 0.2, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.6, 0);
	cylinder(0.35, 0.55, 0.65, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.55, 0);
	glScaled(1.0, 0.3, 1.0);
	glutSolidSphere(0.4, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 4.0, 0);
	glutSolidSphere(0.45, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 4.4, 0);
	glScaled(1.0, 0.5, 1.0);
	glutSolidSphere(0.2, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 4.5, 0);
	cylinder(0.17, 0.05, 0.15, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 4.65, 0);
	cylinder(0.05, 0.05, 0.15, 10, 500);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 4.8, 0);
	cylinder(0.05, 0.15, 0.2, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 4.8, 0);
	glRotated(90, 1, 0, 0);
	cylinder(0.05, 0.15, 0.2, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 4.8, 0);
	glRotated(-90, 1, 0, 0);
	cylinder(0.05, 0.15, 0.2, 10, 500);
	glPopMatrix();

	base();
	glPopMatrix();
}

void queen()
{
	glPushMatrix();
	glPushMatrix();
	glTranslated(0, 0.6, 0);
	cylinder(0.45, 0.3, 0.9, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 1.5, 0);
	cylinder(0.3, 0.25, 0.55, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.05, 0);
	cylinder(0.25, 0.25, 0.3, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.35, 0);
	cylinder(0.25, 0.3, 0.55, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.9, 0);
	glScaled(1.0, 0.2, 1.0);
	glutSolidSphere(0.53, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.05, 0);
	glScaled(1.0, 0.2, 1.0);
	glutSolidSphere(0.4, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.1, 0);
	cylinder(0.3, 0.35, 0.2, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.3, 0);
	cylinder(0.35, 0.35, 0.15, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.25, 0);
	glScaled(1.0, 0.3, 1.0);
	glutSolidSphere(0.37, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.45, 0);
	cylinder(0.32, 0.5, 0.4, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.85, 0);
	cylinder(0.5, 0.5, 0.1, 10, 500);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 3.7, 0);
	glutSolidSphere(0.4, 18, 18);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 4.3, 0);
	glutSolidSphere(0.15, 18, 18);
	glPopMatrix();
	base();
	glPopMatrix();
}

void pawn()
{
	glPushMatrix();
	glPushMatrix();
	glTranslated(0, 0.6, 0);
	cylinder(0.4, 0.3, 0.8, 10, 100);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 1.4, 0);
	cylinder(0.3, 0.25, 0.4, 10, 100);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 1.8, 0);
	cylinder(0.25, 0.25, 0.4, 10, 100);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.2, 0);
	cylinder(0.4, 0.15, 0.2, 10, 100);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2.7, 0);
	glutSolidSphere(0.4, 18, 18);
	glPopMatrix();
	base();
	glPopMatrix();
}

void init(void)
{
	//set properties of surface material
	GLfloat mat_ambient[] = { 0.8f, 0.8f, 0.8f, 1.0f };    //background
	/*GLfloat mat_diffuse[] = { dr, dg, db, 1.0f };*/    //object
	/*GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };*/   //highlight
	GLfloat mat_shininess[] = { 50.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	/*glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);*/
	/*glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);*/
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	//set light source properties
	GLfloat lightintensiity[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	//GLfloat light_position[] = { 2.0f, 6.0f, 3.0f, 0.0f };
	GLfloat light_position[] = { 8.0f, 3.0f, 4.0f, 0.0f };

	
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightintensiity);

	//set camera
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-6, 6, -5, 5, 0.1, 15.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(2.3, 1.3, 2, 0, 0, 0, 0.0, 1.0, 0.0);
	cam.set(2.3, 1.3, 2, 0, 0, 0, 0, 1, 0);
	//gluLookAt(2.3, 0, 2, 0, 0, 0, 0.0, 1.0, 0.0);

}

void myDisplay(void)
{
	//start drawing
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	//GLfloat mat_diffuse[] = { 1, 1, 1, 1.0f };
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	wall(0.02);                      //xz-plane
	glDisable(GL_TEXTURE_2D);
	//glPushMatrix();
	//glRotated(90.0, 0.0, 0.0, 1.0);
	//wall(0.02);                      //yz-plane
	//glPopMatrix();
	//glPushMatrix();
	//glRotated(-90.0, 1.0, 0.0, 0.0);
	//wall(0.02);                      //xy-plane
	//glPopMatrix();

	GLfloat mat_diffuse[] = { 1, 0.5f, 0, 1.0f };
	/*mat_diffuse[1] = 0;
	mat_diffuse[2] = 0;
	mat_diffuse[3] = 0;*/
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	GLfloat mat_specular[] = { 1, 1, 1, 1.0f };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

	//RED
	glPushMatrix();
	glTranslated(-5, -1.9, -5);
	glScaled(0.35, 0.3, 0.35);
	rook();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, -1.9, -5);
	glScaled(0.35, 0.3, 0.35);
	rook();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2, -1.9, -5);
	glScaled(0.4, 0.35, 0.4);
	queen();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, -1.9, -5);
	glScaled(0.4, 0.35, 0.4);
	king();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -1.9, -5);
	glScaled(0.3, 0.3, 0.3);
	bishop();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-3, -1.9, -5);
	glScaled(0.3, 0.3, 0.3);
	bishop();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-4, -1.9, -5);
	glScaled(0.4, 0.4, 0.4);
	//knight();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1, -1.9, -5);
	glScaled(0.4, 0.4, 0.4);
	//knight();
	glPopMatrix();

	for (int i = -5; i <= 2; i++)
	{
		glPushMatrix();
		glTranslated(i, -1.9, -4);
		glScaled(0.3, 0.3, 0.3);
		pawn();
		glPopMatrix();
	}
	//0.255, 0.244, 0.141
	mat_diffuse[0] = 1;
	mat_diffuse[1] = 1;
	mat_diffuse[2] = 0.5;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	mat_specular[0] = 1;
	mat_specular[1] = 1;
	mat_specular[2] = 1;
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

	//FAWN
	glPushMatrix();
	glTranslated(-5, -1.9, 2);
	glScaled(0.35, 0.3, 0.35);
	rook();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, -1.9, 2);
	glScaled(0.35, 0.3, 0.35);
	rook();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, -1.9, 2);
	glScaled(0.4, 0.35, 0.4);
	queen();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2, -1.9, 2);
	glScaled(0.4, 0.35, 0.4);
	king();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-3, -1.9, 2);
	glScaled(0.3, 0.3, 0.3);
	bishop();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -1.9, 2);
	glScaled(0.3, 0.3, 0.3);
	bishop();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-4, -1.9, 2);
	glScaled(0.4, 0.4, 0.4);
	//knight();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1, -1.9, 2);
	glScaled(0.4, 0.4, 0.4);
	//knight();
	glPopMatrix();

	for (int i = -5; i <= 2; i++)
	{
		glPushMatrix();
		glTranslated(i, -1.9, 1);
		glScaled(0.3, 0.3, 0.3);
		pawn();
		glPopMatrix();
	}

	//lines on board
	mat_diffuse[0] = 0;
	mat_diffuse[1] = 0;
	mat_diffuse[2] = 0;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	mat_specular[0] = 0;
	mat_specular[1] = 0;
	mat_specular[2] = 0;
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

	for (float i = -4.5; i <= 2.5; i++)
	{
		glPushMatrix();
		glTranslated(i, -1.9, -1.5);
		glScaled(0, 0.01, 1);
		glutSolidCube(8);
		glPopMatrix();
	}

	for (float i = -4.5; i <= 2.5; i++)
	{
		glPushMatrix();
		glTranslated(-1.5, -1.9, i);
		glScaled(1, 0.01, 0);
		glutSolidCube(8);
		glPopMatrix();
	}

	/*glPushMatrix();
	glTranslated(-4.5, -1.9, -1.5);
	lines();
	glPopMatrix();*/

	glutSwapBuffers();
	glFlush();
	
}



void myKeyboard(unsigned char theKey, int mousex, int mousey)
{
	switch (theKey)
	{
	case 'f': cam.slide(0, 0, -0.1); break; // slide camera forward
	case 'b': cam.slide(0, 0, 0.1);  break; // slide camera back
	case 'l': cam.slide(-0.1, 0, 0); break;
	case 'r': cam.slide(0.1, 0, 0);  break;
	case 'u': cam.slide(0, 0.1, 0);  break;
	case 'd': cam.slide(0, -0.1, 0); break;
	//case 'm': cam.roll(-1.0); break; // roll counter-clockwise
	//case 'n': cam.roll(1.0); break; // roll clockwise
	case 'Q': exit(0);
	default: break;
	}
	glutPostRedisplay();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D Chess");

	/*pix[0].readBMPFile("chessBoard.bmp", texName);
	pix[0].setTexture(texName);*/

	bcg[0].readBMPFile("background.bmp");
	bcg[0].mDraw();

	init();
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyboard);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(0.114f, 0.237f, 0.255f, 0.0f);
	glViewport(0, 0, 640, 480);
	glutMainLoop();
}