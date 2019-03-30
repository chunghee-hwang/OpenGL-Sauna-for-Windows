#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "sauna.h"
#include "light.h"
#include "CameraMove.h"
#include "util.h"
#pragma warning (disable:4305)
#pragma warning (disable:4244)
float tx=0,ty=0,tz=0,angX=0,angY=0,angZ=0;
const double rotate = 1.0f;
const double PI = 3.141592;
float vertex[100][3];
float mbsVertex[200][3];
double showerHeadVertex[20][3] =
{
	{-0.25, 0.38, 0.00},
	{-0.23, 0.36, 0.00},
	{-0.22, 0.34, 0.00},
	{-0.21, 0.32, 0.00},
	{-0.22, 0.29, 0.00},
	{-0.23, 0.26, 0.00},
	{-0.25, 0.23, 0.00},
	{-0.28, 0.20, 0.00},
	{-0.31, 0.16, 0.00},
	{-0.35, 0.13, 0.00},
	{-0.39, 0.09, 0.00},
	{-0.44, 0.05, 0.00},
	{-0.50, 0.02, 0.00},
	{-0.55, -0.02, 0.00},
	{-0.62, -0.06, 0.00},
	{-0.68, -0.10, 0.00},
	{-0.74, -0.15, 0.00},
	{-0.81, -0.19, 0.00},
	{-0.88, -0.23, 0.00},
	{-0.95, -0.27, 0.00}
};

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glColor3f(0.0f, 1.0f, 0.0f);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glMatrixMode(GL_MODELVIEW);
	
	glPushMatrix();
		cameraMove();
		wholeFloor();
		wall1();
		wall2();
		wall3();
		wall4();
		desk();
		
		desk2();
		glPushMatrix();
		glTranslatef(5.4f,0.00f,0.00f);
		desk2();
		glTranslatef(5.4f,0.00f,0.00f);
		desk2();
		glPopMatrix();
		bigMirror();
		locker();
		
		tub();

	glPushMatrix();
		glTranslatef(9.00,0.00,0.00);
		tub();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(18.00,0.00,0.00);
		tub();
	glPopMatrix();
		
		//door2();
	glPushMatrix();
		glTranslatef(12.90f,2.10f,-8.10f);
		glRotated(90, 0,1,0);
		chair12();
	glPopMatrix();
		
	glTranslatef(21.30f,1.80f,-17.70f);
	glPushMatrix();
		glTranslatef(13.90f,2.10f,-7.10f);
		glRotated(90, 0,1,0);
		glScalef(0.8f, 1.0f,1.0f);
	glPopMatrix();
	
	glPushMatrix();
		glScalef(0.8f,1.0f,1.0f);
		chair12();
	glPopMatrix();


	woodFence();
	wall5();
	basket();
	
	
	door2();
	wall6();

	glPushMatrix();
	wall7();
		
	glTranslatef(7.5,0.00,0.00);
	wall7();

	glTranslatef(7.5,0.00,0.00);
	wall7();
	glPopMatrix();
	wall8();
	wall9();

	showerHead();
	glPushMatrix();
		glTranslatef(7.40f,0.00f,0.00f);
		showerHead();
		glTranslatef(7.50,0.00,0.00);
		showerHead();
	glPopMatrix();

	smallMirror();
	glPushMatrix();
		glTranslatef(7.40f,0.00f,0.00f);
		smallMirror();
		glTranslatef(7.50,0.00,0.00);
		smallMirror();
	glPopMatrix();
	
	prop();
	glPushMatrix();
		glTranslatef(7.40f,0.00f,0.00f);
		prop();
		glTranslatef(7.50,0.00,0.00);
		prop();
	glPopMatrix();

	door();

	wall10();
	wall11();

	door3();
	wall12();
	wall13();
	roof();

	
		temperature20();
		temperature39();
		temperature42();
		temperature59();

		glPushMatrix();
	
		glTranslatef(6.5,0,-18);
		glScalef(1.2f,1.0f,1.0f);
		door3();
		glPopMatrix();
		wall14();
		wall15();
		grass();
		//translatedObject(tx,ty,tz,angX,angY,angZ, forest);

		glBindTexture(GL_TEXTURE_2D, texture[19]);
		glPushMatrix();
		glTranslatef(0,0,200);
		glRotatef(-90,1,0,0);
		sphere(500,40,21);
		glPopMatrix();
	glPopMatrix();

	
	
	glutSwapBuffers();
}

void myReshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat) w/h, 1.0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 5.0,  0, 0, 0,  0, 1.0, 0);
	glClearColor(0,0,0,0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	initLight();
	initMackBanSeock();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //rgb, depth를 쓰겠다. glut_double : 버퍼를 두개(메모리, 스크린)를 쓰겠다
	//glFlush대신 glSwapBuffer()를 씀. 메모리 버퍼에 있는 내용을 스크린 버퍼에 옮긴다. --> 화면이 끊기지 않고 부드럽게 된다.
	
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("Globe");
	//glutIdleFunc(myDisplay);
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutPassiveMotionFunc(myMotion);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKey);
	LoadGLTextures(); // load texture.

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glClearDepth(1.0);

	glutMainLoop();
}


float deltaMove = 0.1f;
void specialKey(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_LEFT:
		tx-=deltaMove;
		break;
	case GLUT_KEY_RIGHT:
		tx+=deltaMove;
		break;
	case GLUT_KEY_UP:
		tz-=deltaMove;
		break;
	case GLUT_KEY_F12:
		tz-=1;
		break;
	case GLUT_KEY_DOWN:
		tz+=deltaMove;
		break;
	case GLUT_KEY_HOME:
		ty+=deltaMove;
		break;
	case GLUT_KEY_END:
		ty-=deltaMove;
		break;

	case GLUT_KEY_F5:
		angX-=5;
		break;
	case GLUT_KEY_F6:
		angX+=5;
		break;

	case GLUT_KEY_INSERT:
		angY-=5;
		break;
	case GLUT_KEY_PAGE_UP:
		angY+=5;
		break;
	case GLUT_KEY_F7:
		angZ-=5;
		break;
	case GLUT_KEY_F8:
		angZ+=5;
		break;
	}

	glutPostRedisplay();
}
void desk()
{
	float v[][5] =
	{
		//옆면 네 개

		{0,0	,-4,0,0},
		{0,1	,-4,3,0},
		{0.3,0	,-2,0,2},
		{0.3,1  ,-2,3,2},
		{0.7,0	,2,0,2},
		{0.7,1	,2,3,2},
		{1,0	,4,0,0},
		{1,1	,4,3,0},
		{0.7,0,	-4,0,0},
		{0.7,1,	-4,3,0},


		//윗면
		{0,1,		-4,3,0},
		{0.3,1,		-2,3,2},
		{0.3,1,		4,3,0},
		{0.3,0,		2,3,2}
	};


	glPushMatrix();
	glTranslatef(7.90, 0.30, 30);
	glRotated(-90, 0, 1, 0);
	glScalef(2.0, 2.0, 2.0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glInterleavedArrays(GL_T2F_V3F, 0, v); //텍스쳐와 버텍스의 쌍을 명시하여 그려줌
	glDrawArrays(GL_QUAD_STRIP, 0, 14);
	glPopMatrix();
}
void locker()
{
		glPushMatrix();
			glTranslatef(-6.40f,7.60f,11.20f);
			glRotated(90, 0,1,0);
			lockerMid();

			translatedObject(4,0,0,0,0,0, lockerMid);

			translatedObject(4,0,0,0,0,0, lockerMid);

			translatedObject(4,0,0,0,0,0, lockerMid);

			translatedObject(4,0,0,0,0,0, lockerMid);

			translatedObject(-8.1f,-6.4f,0.0f,0.0f,0.0f,0.0f,lockerBot);
		glPopMatrix();
}

void lockerMid()
{
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTranslatef(-0.5f,0.0f,2.35f);
		glScalef(0.5f,0.7f,0.1f);
		cube2();
	glPopMatrix();

	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[1]);
		glScalef(0.7f,2.0f,0.7f);
		glScalef(3,3,3);
		cube2();
	glPopMatrix();
}

void lockerBot()
{
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glPushMatrix();
	 glScalef(9.9f, 0.5f, 2.6f);
	 cube2();
	glPopMatrix();
}

void door()
{
	glPushMatrix();
		glTranslatef(-11.20f,4.60f,29.30f);
		glRotated(-90, 0,1,0);
		glScalef(1.0,1.5,1.0);

		//문
		glPushMatrix();
		 glScalef(2.0f, 4.0f, 0.5f);
		  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		   glBindTexture(GL_TEXTURE_2D, texture[3]);
		  cube2();
		glPopMatrix();


		//문 왼쪽벽
		glPushMatrix();
	

		 glTranslatef(-5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		glBindTexture(GL_TEXTURE_2D, texture[18]);
		 cube2();
		glPopMatrix();


		//glColor4f(0,0,0,0);

		//문 오른쪽벽
		glPushMatrix();
		
		 glTranslatef(5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		glBindTexture(GL_TEXTURE_2D, texture[18]);
		 cube2();
		glPopMatrix();

		//문 위쪽벽
		glPushMatrix();
		 glTranslatef(0, 6,0);
		 glScalef(2.3f, 2.0f, 0.8f);
		 glBindTexture(GL_TEXTURE_2D, texture[18]);
		 cube2();
		glPopMatrix();
		//앞 문고리 
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTranslatef(1, 0,0.5);
		glScalef(0.1f,0.1f,0.1f);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		 glTranslatef(-5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		 cube2();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1, 0,0.5);
		glScalef(0.1f,0.1f,0.1f);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		 glTranslatef(5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		 cube2();
		glPopMatrix();
	
		glPushMatrix();
		glTranslatef(1, 0,0.5);
		glScalef(0.1f,0.1f,0.1f);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		 glTranslatef(0, 6,0);
		 glScalef(2.3f, 2.0f, 0.8f);
		 cube2();
		glPopMatrix();

		//뒷 문고리
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTranslatef(1, 0,-0.5);
		glScalef(0.1f,0.1f,0.1f);
		glRotatef(90,0,0,1);
		glRotatef(-90,1,0,0);
		 glTranslatef(-5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		 cube2();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1, 0,-0.5);
		glScalef(0.1f,0.1f,0.1f);
		glRotatef(90,0,0,1);
		glRotatef(-90,1,0,0);
		 glTranslatef(5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		 cube2();
		glPopMatrix();
	
		glPushMatrix();
		glTranslatef(1, 0,-0.5);
		glScalef(0.1f,0.1f,0.1f);
		glRotatef(90,0,0,1);
		glRotatef(-90,1,0,0);
		 glTranslatef(0, 6,0);
		 glScalef(2.3f, 2.0f, 0.8f);
		 cube2();
		glPopMatrix();
	glPopMatrix();
}

void door2()
{
	glPushMatrix();
		glTranslatef(-22.10f,-1.80f,19.20f);
		glTranslatef(19.50f,6.30f,-0.10f);
		glScalef(1.0,1.5,1.0);
		//문
		glPushMatrix();
		 glScalef(2.0f, 4.0f, 0.5f);
		  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		   glBindTexture(GL_TEXTURE_2D, texture[3]);
		  cube2();
		glPopMatrix();


		//문 왼쪽벽
		glPushMatrix();
		 glTranslatef(-5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		glBindTexture(GL_TEXTURE_2D, texture[18]);
		 cube2();
		glPopMatrix();


		//glColor4f(0,0,0,0);

		//문 오른쪽벽
		glPushMatrix();
		
		 glTranslatef(5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		glBindTexture(GL_TEXTURE_2D, texture[18]);
		 cube2();
		glPopMatrix();

		//문 위쪽벽
		glPushMatrix();
		 glTranslatef(0, 6,0);
		 glScalef(2.3f, 2.0f, 0.8f);
		 glBindTexture(GL_TEXTURE_2D, texture[18]);
		 cube2();
		glPopMatrix();





		//앞 문고리 
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTranslatef(1, 0,0.5);
		glScalef(0.1,0.1,0.1);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		 glTranslatef(-5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		 cube2();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1, 0,0.5);
		glScalef(0.1,0.1,0.1);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		 glTranslatef(5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		 cube2();
		glPopMatrix();
	
		glPushMatrix();
		glTranslatef(1, 0,0.5);
		glScalef(0.1,0.1,0.1);
		glRotatef(90,0,0,1);
		glRotatef(90,1,0,0);
		 glTranslatef(0, 6,0);
		 glScalef(2.3f, 2.0f, 0.8f);
		 cube2();
		glPopMatrix();

		//뒷 문고리
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTranslatef(1, 0,-0.5);
		glScalef(0.1,0.1,0.1);
		glRotatef(90,0,0,1);
		glRotatef(-90,1,0,0);
		 glTranslatef(-5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		 cube2();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1, 0,-0.5);
		glScalef(0.1,0.1,0.1);
		glRotatef(90,0,0,1);
		glRotatef(-90,1,0,0);
		 glTranslatef(5, 2,0);
		 glScalef(3.0f, 6.0f, 0.8f);
		 cube2();
		glPopMatrix();
	
		glPushMatrix();
		glTranslatef(1, 0,-0.5);
		glScalef(0.1,0.1,0.1);
		glRotatef(90,0,0,1);
		glRotatef(-90,1,0,0);
		 glTranslatef(0, 6,0);
		 glScalef(2.3f, 2.0f, 0.8f);
		 cube2();
		glPopMatrix();
	glPopMatrix();
}
void door3()
{
	glPushMatrix();
		glTranslatef(-20.60,0.00,37.90);
		glPushMatrix();
			glTranslatef(-22.10,-1.80,19.20);
			glTranslatef(19.50,6.30,-0.10);
			glScalef(1.0,1.5,1.0);
			//문
			glPushMatrix();
			 glScalef(2.0f, 4.0f, 0.5f);
			  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			   glBindTexture(GL_TEXTURE_2D, texture[3]);
			  cube2();
			glPopMatrix();


			//문 왼쪽벽
			glPushMatrix();
			 glTranslatef(-5, 2,0);
			 glScalef(3.0f, 6.0f, 0.8f);
			glBindTexture(GL_TEXTURE_2D, texture[4]);
			 cube2();
			glPopMatrix();


			//glColor4f(0,0,0,0);

			//문 오른쪽벽
			glPushMatrix();
		
			 glTranslatef(5, 2,0);
			 glScalef(3.0f, 6.0f, 0.8f);
			glBindTexture(GL_TEXTURE_2D, texture[4]);
			 cube2();
			glPopMatrix();

			//문 위쪽벽
			glPushMatrix();
			 glTranslatef(0, 6,0);
			 glScalef(2.3f, 2.0f, 0.8f);
			 glBindTexture(GL_TEXTURE_2D, texture[4]);
			 cube2();
			glPopMatrix();





			//앞 문고리 
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, texture[0]);
			glTranslatef(1, 0,0.5);
			glScalef(0.1,0.1,0.1);
			glRotatef(90,0,0,1);
			glRotatef(90,1,0,0);
			 glTranslatef(-5, 2,0);
			 glScalef(3.0f, 6.0f, 0.8f);
			 cube2();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1, 0,0.5);
			glScalef(0.1,0.1,0.1);
			glRotatef(90,0,0,1);
			glRotatef(90,1,0,0);
			 glTranslatef(5, 2,0);
			 glScalef(3.0f, 6.0f, 0.8f);
			 cube2();
			glPopMatrix();
	
			glPushMatrix();
			glTranslatef(1, 0,0.5);
			glScalef(0.1,0.1,0.1);
			glRotatef(90,0,0,1);
			glRotatef(90,1,0,0);
			 glTranslatef(0, 6,0);
			 glScalef(2.3f, 2.0f, 0.8f);
			 cube2();
			glPopMatrix();

			//뒷 문고리
				glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, texture[0]);
			glTranslatef(1, 0,-0.5);
			glScalef(0.1,0.1,0.1);
			glRotatef(90,0,0,1);
			glRotatef(-90,1,0,0);
			 glTranslatef(-5, 2,0);
			 glScalef(3.0f, 6.0f, 0.8f);
			 cube2();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(1, 0,-0.5);
			glScalef(0.1,0.1,0.1);
			glRotatef(90,0,0,1);
			glRotatef(-90,1,0,0);
			 glTranslatef(5, 2,0);
			 glScalef(3.0f, 6.0f, 0.8f);
			 cube2();
			glPopMatrix();
	
			glPushMatrix();
			glTranslatef(1, 0,-0.5);
			glScalef(0.1,0.1,0.1);
			glRotatef(90,0,0,1);
			glRotatef(-90,1,0,0);
			 glTranslatef(0, 6,0);
			 glScalef(2.3f, 2.0f, 0.8f);
			 cube2();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

//화장대 거울
void bigMirror()
{
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glPushMatrix();
	glTranslatef(-0.50,0.00,-66.20);
	glTranslatef(0.00,8.20,46.90);
	 glScalef(4,5,5);
	 glScalef(2.0f, 0.5f, 0.01f);
	 cube2();
	glPopMatrix();
}

//화장대
void desk2()
{
	glPushMatrix();
	glTranslatef(-5.90,-6.20,-66.50);
	glTranslatef(0.00,9.30,50.80);
	glScalef(5,5,5);
	drawDesk2Top(-0.3);

	drawDesk2Top(0.0);

	drawDesk2Bottom(0.0);

	drawDesk2Bottom(0.3);
	drawDesk2Top(0.3);
	drawDesk2Bottom(0.55);
	glPopMatrix();
}
void drawDesk2Top(float z)
{
	//상판
	glBindTexture(GL_TEXTURE_2D, texture[1]);

	glPushMatrix();
	 glTranslatef(0,-z,0);
	 glScalef(0.5f, 0.03f, 0.5f);
	 cube2();
	glPopMatrix();
}
void drawDesk2Bottom(float z)
{
	//층 추가

	//왼쪽 판
	glPushMatrix();
	 glTranslatef(-0.455,0.15-z,0);
	 glRotatef(90,0,0,1);
	 glScalef(0.12f, 0.03f, 0.5f);
	 cube2();
	glPopMatrix();

	//오른쪽 판
	glPushMatrix();
	 glTranslatef(0.455,0.15-z,0);
	 glRotatef(90,0,0,1);
	 glScalef(0.12f, 0.03f, 0.5f);
	 cube2();
	glPopMatrix();
}

//등받이
void chair2()
{
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glPushMatrix();
	 glRotatef(-90,0,0,1);
	 glScalef(0.1f, 2.0f, 0.01f);
	 cube3();
	glPopMatrix();
}

//의자
void chair1()
{
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glPushMatrix();
	 glRotatef(-90,0,0,1);
	 glScalef(0.5f, 2.0f, 0.5f);
	 cube3();
	glPopMatrix();
	
}

//의자+등받이
void chair12()
{
	glPushMatrix();
		glScalef(3,3,3);
		chair1();

		glPushMatrix();
			glTranslatef(0,0.8,-0.6);
			glRotated(15,1,0,0);
			chair2();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,1.05,-0.55);
			chair2();
		glPopMatrix();

	
		glPushMatrix();
			glTranslatef(0.00,1.30,-0.55);
			chair2();
		glPopMatrix();

		 glPushMatrix();
			glTranslatef(0.00,1.55,-0.60);
			glRotated(-15,1,0,0);
			chair2();
		glPopMatrix();


		glPushMatrix();
			glTranslatef(-1.25,1.17,-0.65);
			glRotated(-90,0,0,1);
			glScalef(0.24,1.7,1.5);
			chair2();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-1.25+2.5,1.17,-0.65);
			glRotated(-90,0,0,1);
			glScalef(0.24,1.7,1.5);
			chair2();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,1.17,-0.65-0.05);
			glRotated(-90,0,0,1);
			glScalef(0.24,1.7,1.5);
			chair2();
		glPopMatrix();
	glPopMatrix();
}

//맥반석바구니를 감싸는 울타리
void woodFence()
{
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	
	glPushMatrix();
		glTranslatef(-0.10,0.00,0.00);
		glTranslatef(-1.30,0.00,0.00);
		glTranslatef(-8.60,-6.50,-36.00);
		glTranslatef(0.00,6.40,38.00);
		glScalef(2.8,5,2.8);
		glPushMatrix();
			glScalef(0.1,0.5,0.1);
			cube3();
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(0.6,0.4,0);
			glRotatef(-90,0,0,1);
			glScalef(0.1,0.5,0.1);
			cube3();
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(0.60,-0.40,0.00);
			glRotated(-90, 0,0,1);
			glScalef(0.1,0.5,0.1);
			cube3();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.20,0.00,-0.00);
			glScalef(0.1,0.5,0.1);
			cube3();
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(1.20,0.40,-0.60);
			glRotated(90, 1,0,0);
			glScalef(0.1,0.5,0.1);
			cube3();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.20,-0.40,-0.60);
			glRotated(-90, 1,0,0);
			glScalef(0.1,0.5,0.1);
			cube3();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.20,0.00,-1.20);
			glScalef(0.1,0.5,0.1);
			cube3();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.40,0.00,-0.00);
			glScalef(0.1,0.3,0.1);
			cube3();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.80,0.00,0.00);
			glScalef(0.1,0.3,0.1);
			cube3();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.20,0.00,-0.4);
			glScalef(0.1,0.3,0.1);
			cube3();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(1.20,0.00,-0.8);
			glScalef(0.1,0.3,0.1);
			cube3();
		glPopMatrix();
	glPopMatrix();
}


void plate()
{
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glPushMatrix();
		glScalef(0.3,0.3,0.03);
		cube3();
	glPopMatrix();
}

//맥반석 바구니
void basket()
{
	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glPushMatrix();
		glTranslatef(-2.90,-7.40,-3.30);
		glTranslatef(-5.80,0.00,-48.80);
		glTranslatef(0.10,7.00,53.30);
		glScalef(5,7,5);
		glPushMatrix();
			glScalef(0.3,0.3,0.03);
			cube3();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.30,0.00,-0.30);
			glRotated(-90, 0,1,0);
			glScalef(0.3,0.3,0.03);
			cube3();
		glPopMatrix();

	
		glPushMatrix();
			glTranslatef(-0.25,0.00,-0.30);
			glRotated(-95, 0,1,0);
			glScalef(0.3,0.3,0.03);
			cube3();
		glPopMatrix();

	
		glPushMatrix();
		glTranslatef(0.05,0.00,-0.55);
			glScalef(0.3,0.3,0.03);
			cube3();
		glPopMatrix();

		//맥반석 200개 담기
		for(int i = 0; i<200;i++)
		{
			glPushMatrix();

				glTranslatef(mbsVertex[i][0],mbsVertex[i][1],mbsVertex[i][2]);
				mackBanSeock();
			glPopMatrix();
		}
	glPopMatrix();
}

//맥반석 한 개
void mackBanSeock()
{
	glBindTexture(GL_TEXTURE_2D, texture[9]);

	glScalef(0.2,0.2,0.2);
	glScalef(0.33,0.2,0.3);
	sphere(1.0,7,10);
}


//맥반석 200개 translate될 위치 저장
void initMackBanSeock()
{
	//float xMin = -0.15, xMax = 0.20, yMin=-0.25, yMax = 0.45, zMax = -0.1, zMin = -0.45
	
	//채울 범위
	int xMin = -21, xMax = 24, yMin = -26, yMax = 30, zMax = -5, zMin=-46;

	for(int i = 0; i<200;i++)
	{
		float x = (float)( rand() % (xMax + 1 - xMin) + xMin );
		float y = (float)( rand() % (yMax + 1 - yMin) + yMin );
		float z = (float)(rand() % (zMax + 1 - zMin) + zMin );
		x*=0.01f;
		y*=0.01f;
		z*=0.01f;
		mbsVertex[i][0] =x; mbsVertex[i][1] =y; mbsVertex[i][2] =z;
	}
}

void showerHead()
{
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glPushMatrix();
			glTranslatef(0.00,-1.00,-6.40);
			glTranslatef(8.90,13.70,7.90);
			glRotated(-55, 1,0,0);
			glPushMatrix();
			
				for(int theta = 0; theta<=360; theta++)
				{
					glPushMatrix();
						glRotatef(theta,0.0f,1.0f,0.0f);
						glBegin(GL_LINE_STRIP);
						 for(int i = 0; i<=20;i++)
						 {
							 glNormal3f(showerHeadVertex[i][0],showerHeadVertex[i][1],0.0f);
							 glTexCoord2f(0.0f, 1.0f);
							 glVertex3f(showerHeadVertex[i][0],showerHeadVertex[i][1],0.0f);
						 }
						glEnd();
					glPopMatrix();
			
				}
			glPopMatrix();

			glPushMatrix();
			
			cylinder();
			cylinderHole();
			pipe();

			glPushMatrix();
				glRotatef(60,1,0,0);
				pipeFixer();
			glPopMatrix();
			glPopMatrix();
			
		glPopMatrix();
	
}

void cylinder()
{
	float r = 1.0f;
	glBindTexture(GL_TEXTURE_2D, texture[10]);

	glPushMatrix();
	glTranslatef(0.00,0.45,0.00);
	glTranslatef(-0.00,-1.20,0.05);
	glRotated(10, 0,1,0);
	glRotated(-90, 1,0,0);
	glBegin(GL_QUAD_STRIP);
		for(int i = 0; i<=360; i=i+10)
		{
			//각도는 라디안으로 놓자
			glTexCoord2f(0,0.5);
			glVertex3f(r*cos(i*3.141592f/180.0f),r*sin(i*3.141592f/180.0f),0.0f);

			glTexCoord2f(0.5,1);
			glVertex3f(r*cos(i*3.141592f/180.0f),r*sin(i*3.141592f/180.0f),0.5f);
		}
		glEnd();
	glPopMatrix();

	
}
void cylinderHole()
{
		float r = 1.0f;
		glBindTexture(GL_TEXTURE_2D, texture[11]);

		glPushMatrix();
		glTranslatef(0.00,0.45,0.00);
		glTranslatef(-0.00,-1.20,0.05);
		glRotated(10, 0,1,0);
		glRotated(-90, 1,0,0);
		glBegin(GL_QUAD_STRIP);
		for(int i = 0; i<=360; i=i+10)
		{
			//각도는 라디안으로 놓자
			glTexCoord2f(0,0.5);
			glVertex3f(r*cos(i*3.141592f/180.0f),r*sin(i*3.141592f/180.0f),0.0f);

			glTexCoord2f(0.5,1);
			glVertex3f(0,0,-0.1f);
		}

		glEnd();
			glPopMatrix();
}

void cylinder2()
{
	float r = 1.0f;
	int angle=0;
	glBindTexture(GL_TEXTURE_2D, texture[10]);

	glPushMatrix();
	glScalef(0.2,0.2,1);
	glBegin(GL_QUAD_STRIP);
		for(int i = 0; i<=360; i=i+10)
		{
			//각도는 라디안으로 놓자
			
			glTexCoord2f(0,0.5);
			glVertex3f(r*cos(i*3.141592f/180.0f),r*sin(i*3.141592f/180.0f),0.0f);

			glTexCoord2f(0.5,1);
			glVertex3f(r*cos(i*3.141592f/180.0f),r*sin(i*3.141592f/180.0f),2.0f);
		}
		glEnd();
	glPopMatrix();
}


//도넛을 그리기 위한 원 하나 그리기
void circle()
{
	glBegin(GL_POLYGON);
		for (float theta = 0; theta <= 360; theta += 10)
		{
			glVertex3f
			(
				0.1*Cos(theta),
				0.1*Sin(theta),
				0
			);
		}
	glEnd();
}


void pipe()
{
	glPushMatrix();
	glTranslatef(-0.05,0.00,-0.10);
	glTranslatef(0.25,-0.00,-1.95);
	glTranslatef(0.05,0.30,-0.95);
	glRotated(5, 0,0,1);
	glRotated(265, 0,1,0);
	glRotated(445, 1,0,0);
	for (float theta = 0; theta <= 60; theta++)
	{
		glPushMatrix();
		glRotatef(theta, 0.0f, 1.0f, 0.0f);
		glTranslatef(3.0, 0.0f, 0.0f);
		circle();
		glPopMatrix();
	}
	glPopMatrix();
}

void pipeFixer()
{
	glBindTexture(GL_TEXTURE_2D, texture[10]);
	glPushMatrix();
	 glTranslatef(0.10,0.40,-3.25);
	 glScalef(0.5f, 0.6f, 0.03f);
	 cube2();
	glPopMatrix();
}

void smallMirror()
{
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glPushMatrix();
	 glTranslatef(9.10,9.80,-1.70);
     glScalef(5,5,5);
	 glScalef(0.5f, 0.6f, 0.01f);
	 cube2();
	glPopMatrix();
}

//샤워기 및 받침대
void prop()
{
	glBindTexture(GL_TEXTURE_2D, texture[10]);
	glPushMatrix();
	 glTranslatef(9.00,3.20,-1.10);
	 glScalef(0.7,0.7,0.7);
	 glRotatef(90,1,0,0);
	 glTranslatef(0.10,0.40,-3.25);
	 glScalef(3, 1.5f, 0.1f);
	 cube2();
	glPopMatrix();
}

//욕조
void tub()
{
	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glPushMatrix();
		glTranslatef(19.50,3.30,38.20);
		glScalef(15,10,30);
		
		glPushMatrix();
			glScalef(0.3,0.3,0.03);
			cube3();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.30,0.00,-0.30);
			glRotated(-90, 0,1,0);
			glScalef(0.3,0.3,0.03);
			cube3();
		glPopMatrix();

	
		glPushMatrix();
			glTranslatef(-0.25,0.00,-0.30);
			glRotated(-95, 0,1,0);
			glScalef(0.3,0.3,0.03);
			cube3();
		glPopMatrix();

	
		glPushMatrix();
		glTranslatef(0.04,0.00,-0.57);
			glScalef(0.3,0.3,0.03);
			cube3();
		glPopMatrix();

		
	
		glPopMatrix();

		glPushMatrix();
		glTranslatef(19.50,3.30,38.20);
		tubBottom();

		water();
		glPopMatrix();
	
}

void tubBottom()
{
	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glPushMatrix();
		glTranslatef(0.00,0.95,0.00);
		glTranslatef(-0.10,-2.25,4.75);
		glScalef(15,10,30);
		glPushMatrix();
			
			glTranslatef(0.04,-0.09,-0.48);
			glRotatef(90,1,0,0);
			glScalef(0.3,0.3,0.03);
		
			cube3();
		glPopMatrix();
	glPopMatrix();
}

//욕조 물
void water()
{
	glBindTexture(GL_TEXTURE_2D, texture[13]);
	glPushMatrix();
		glTranslatef(0.12,0.00,-2.55);
		glTranslatef(0.00,0.00,-5.65);
		glScalef(4,2.0,8);
		cube3();
	glPopMatrix();
}

//온도 표시 전광판
void temperature20()
{
	glBindTexture(GL_TEXTURE_2D, texture[14]);
	glPushMatrix();
		glTranslatef(-1.50,12.40,57.50-0.10);
		glRotated(180, 0,1,0);
		glScalef(3,3,3);
		glBegin(GL_QUADS);
		 glTexCoord2f(0,1);
		 glVertex3f(	-1,0.6,	0);

		 glTexCoord2f(0,0);
		 glVertex3f(	-1,0,	0);

		 glTexCoord2f(1,0);
		 glVertex3f(	1,0,	0);

		 glTexCoord2f(1,1);
		 glVertex3f(	1,0.6,	0);
		glEnd();
	glPopMatrix();
}
void temperature39()
{
	glBindTexture(GL_TEXTURE_2D, texture[15]);
	glPushMatrix();
		glTranslatef(9.20,0.00,-0.10);
		glTranslatef(-1.50,12.40,57.50);
		glRotated(180, 0,1,0);
		glScalef(3,3,3);
		glBegin(GL_QUADS);
		 glTexCoord2f(0,1);
		 glVertex3f(	-1,0.6,	0);

		 glTexCoord2f(0,0);
		 glVertex3f(	-1,0,	0);

		 glTexCoord2f(1,0);
		 glVertex3f(	1,0,	0);

		 glTexCoord2f(1,1);
		 glVertex3f(	1,0.6,	0);
		glEnd();
	glPopMatrix();
}
void temperature42()
{
	glBindTexture(GL_TEXTURE_2D, texture[16]);
	glPushMatrix();
		glTranslatef(17.90,0.00,0.00);
		glTranslatef(-1.50,12.40,57.50-0.10);
		glRotated(180, 0,1,0);
		glScalef(3,3,3);
		glBegin(GL_QUADS);
		 glTexCoord2f(0,1);
		 glVertex3f(	-1,0.6,	0);

		 glTexCoord2f(0,0);
		 glVertex3f(	-1,0,	0);

		 glTexCoord2f(1,0);
		 glVertex3f(	1,0,	0);

		 glTexCoord2f(1,1);
		 glVertex3f(	1,0.6,	0);
		glEnd();
	glPopMatrix();
}
void temperature59()
{
	glBindTexture(GL_TEXTURE_2D, texture[17]);
	glPushMatrix();
		glTranslatef(-2.50,12.40,20.00);
		glScalef(3,3,3);
		glBegin(GL_QUADS);
		 glTexCoord2f(0,1);
		 glVertex3f(	-1,0.6,	0);

		 glTexCoord2f(0,0);
		 glVertex3f(	-1,0,	0);

		 glTexCoord2f(1,0);
		 glVertex3f(	1,0,	0);

		 glTexCoord2f(1,1);
		 glVertex3f(	1,0.6,	0);
		glEnd();
	glPopMatrix();
}

void wholeFloor()
{
	floorLeft(); 
	floorRight();
}

//사우나 밖 바닥
void floorLeft()
{
	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glPushMatrix();
		glPushMatrix();
			glTranslatef(0.00,0.00,10.00);
			glScalef(10.0f,0.3f,30.0f);
			cube3();
		glPopMatrix();
	glPopMatrix();
}

//사우나 안 바닥
void floorRight()
{
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glPushMatrix();
			glTranslatef(30.00,0.00,0.00);
			glTranslatef(0.00,0.00,10.00);
			glScalef(20.0f,0.3f,30.0f);
			cube2();
	glPopMatrix();
}

//맨 왼쪽 벽
void wall1()
{
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glPushMatrix();
		glTranslatef(0.00,0.00,10.00);
		glTranslatef(0.00,2.00,-0.00);
		glTranslatef(-9.65,7.30,-0.00);
		glPushMatrix();
			glScalef(0.3f,9.0f,30.0f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}

//맨 뒤 벽1(사우나 밖)
void wall2()
{
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glPushMatrix();
		glTranslatef(0.00,2.00,-0.00);
		glTranslatef(0.00,7.30,-19.75);
		glPushMatrix();
			glScalef(10.0f,9.0f,0.3f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}

//맨 뒤 벽2(사우나)
void wall3()
{
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glPushMatrix();
		glTranslatef(29.95,9.30,-19.95);
		glPushMatrix();
			glScalef(20.0f,9.0f,0.3f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}


//맨 오른쪽 벽(사우나)
void wall4()
{
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glPushMatrix();
		glPushMatrix();
			glTranslatef(0.00,0.00,10.00);
			glTranslatef(49.70,9.30,0.00);
			glScalef(0.3f,9.0f,30.0f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}



//중간 벽(사우나)
void wall5()
{
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glPushMatrix();
		glTranslatef(-10.40,7.60,8.20);
		glRotated(180, 0,1,0);
		glPushMatrix();
			glScalef(0.15f,9.0f,10.0f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}

//중간 벽(사우나2)
void wall6()
{
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glPushMatrix();
		glTranslatef(5.20,7.40,8.00);
		glPushMatrix();
			glScalef(0.15f,9.0f,10.0f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}


//샤워 부스 칸막이
void wall7()
{
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glPushMatrix();
		glTranslatef(0.30,-0.10,0.30);
		glTranslatef(5.20,7.40,8.00);
		glPushMatrix();
			glScalef(0.15f,9.0f,10.0f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}

//샤워부스 뒷면
void wall8()
{
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glPushMatrix();
		glTranslatef(1.40,0.00,0.00);
		glTranslatef(15.30,7.40,-1.90);
		glRotated(90, 0,1,0);
		glPushMatrix();
			glScalef(0.18f,9.0f,11.5f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}

//샤워부스 바닥
void wall9()
{
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glPushMatrix();
		
		glScalef(1,1,1.18);
		glTranslatef(0.10,-1.60,0.00);
		glTranslatef(0.00,0.00,0.10);
		glRotated(90, 1,0,0);
		glTranslatef(16.50,7.30,0.00);
		glRotated(180, 0,0,1);
		glRotated(90, 0,1,0);
		glPushMatrix();
			glScalef(0.18f,9.0f,11.5f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}

//중간벽 1(안쪽)
void wall10()
{
	glBindTexture(GL_TEXTURE_2D, texture[18]);
	glPushMatrix();
		glTranslatef(-0.30,-0.20,0.00);
		glTranslatef(-16.10,0.40,1.50);
		glTranslatef(5.20,7.40,8.00);
		glPushMatrix();
			glScalef(0.8f,9.0f,11.9f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}


//중간벽 2(앞쪽)
void wall11()
{
	glBindTexture(GL_TEXTURE_2D, texture[18]);
	glPushMatrix();
		glTranslatef(0.00,0.00,-1.50);
		glTranslatef(0.00,0.00,39.60);
		glTranslatef(-0.30,-0.20,0.00);
		glTranslatef(-16.10,0.40,1.50);
		glTranslatef(5.20,7.40,8.00);
		glPushMatrix();
			glScalef(0.8f,9.0f,10.3);
			cube2();
		glPopMatrix();
	glPopMatrix();
}

//맨 앞 벽(바깥벽)
void wall12()
{
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glPushMatrix();
		glTranslatef(0.00,-0.30,-0.50);
		glTranslatef(5.80,0.00,0.50);
		glTranslatef(0.00,7.50,58.20);
		glRotated(90, 0,1,0);
		glPushMatrix();
			glScalef(0.5f,9.5f,23.0f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}

//맨 앞 안 벽(사우나 벽)
void wall13()
{
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glPushMatrix();
		glTranslatef(2.80,0.00,-0.60);
		glTranslatef(0.00,-0.10,-0.50);
		glTranslatef(5.80,0.00,0.50);
		glTranslatef(0.00,7.50,58.20);
		glRotated(180, 0,1,0);
		glRotated(90, 0,1,0);
		glPushMatrix();
			glScalef(0.1f,9.0f,20.0f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}

void roof()
{
	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glPushMatrix();
		glTranslatef(0.00,5.10,0.00);
		glTranslatef(-1.20,0.00,-2.30);
		glTranslatef(0.00,16.60,29.00);
		glRotated(-90, 0,0,1);
		glScalef(1,1,1.18);
		glPushMatrix();
			glScalef(5,35,28);
			cube2();
		glPopMatrix();
	glPopMatrix();
}
//맨 오른 바깥쪽 벽
void wall14()
{
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glPushMatrix();
		glTranslatef(0.00,-2.30,17.90);
		glScalef(1,1.3,1.0);
		glTranslatef(-9.90,0,0);
		glTranslatef(48.70,0.00,0.00);
		glTranslatef(0.00,0.00,10.00);
		glTranslatef(0.00,2.00,-0.00);
		glTranslatef(-9.65,7.30,-0.00);
		glPushMatrix();
			glScalef(0.3f,9.0f,30.0f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}

//맨 뒤 바깥쪽벽
void wall15()
{
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glPushMatrix();
		glTranslatef(-0.70,9.30,-2.50);
		glRotated(-90, 0,1,0);
		glScalef(1,1.3,1.0);
		glPushMatrix();
			glScalef(0.3f,9.0f,30.0f);
			cube2();
		glPopMatrix();
	glPopMatrix();
}


void grass()
{
	glBindTexture(GL_TEXTURE_2D, texture[20]);
	glPushMatrix();
			glTranslatef(0.00,21.90,0.00);
			glTranslatef(0.00,-25,0.00);
			glScalef(1000,1,1000);
			cube4();
	glPopMatrix();
}

void translatedObject(float tx, float ty, float tz, float angleX, float angleY, float angleZ, void(*object)())
{

	glTranslatef(tx, ty, tz);
	glRotated(angleZ, 0, 0, 1);
	glRotated(angleY, 0, 1, 0);
	glRotated(angleX, 1, 0, 0);
	object();

	//printf("\n\nglTranslatef(%.2f,%.2f,%.2f);\n",tx,ty,tz);

	if (angleZ != 0)
	{
		//printf("glRotated(%d, 0,0,1);\n",angleZ);
	}
	if (angleY != 0)
	{
		//	printf("glRotated(%d, 0,1,0);\n",angleY);
	}
	if (angleX != 0)
	{
		//printf("glRotated(%d, 1,0,0);\n",angleX);
	}
}


double Sin(double angle)
{
	return sin(angle*3.141592f / 180.0f);
}
double Cos(double angle)
{
	return cos(angle*3.141592f / 180.0f);
}
void cube2()
{
	//면에 대한 법선
	GLfloat Normal[6][3] =
	{
		{-1.0f, 0.0f, 0.0f}, //left
		{0.0f,1.0f,0.0f}, //top
		{1.0f, 0.0f, 0.0f}, //right
		{0.0f, -1.0f, 0.0f}, //bottom
		{0.0f, 0.0f, -1.0f}, //back
		{0.0f, 0.0f, 1.0f} //front
	};


	GLfloat v[][5] =
	{
		//오른면
		{0, 0.0f, 1.0f, -1.0f, 1.0f}, //4
		{0.1, 0, 1.0f, -1.0f, -1.0f}, //5
		{0.1,1, 1.0f, 1.0f, -1.0f}, //6
		{0, 1, 1.0f, 1.0f, 1.0f}, //7

		//왼면
		{1, 1,  -1.0f, 1.0f, 1.0f}, //3
		{0, 1, -1.0f, 1.0f, -1.0f}, //2
		{0, 0, -1.0f, -1.0f, -1.0f}, //1
		{1, 0, -1.0f, -1.0f, 1.0f}, //0

		//앞면
		{0.0f, 0.0f, -1.0f, -1.0f, 1.0f}, //0
		{1, 0.0f, 1.0f, -1.0f, 1.0f}, //4
		{1, 1, 1.0f, 1.0f, 1.0f}, //7
		{0, 1, -1.0f, 1.0f, 1.0f}, //3

		//뒷면
		{0.684f, 0.5f, 1.0f, 1.0f, -1.0f}, //6
		{1.0, 0.5, 1.0f, -1.0f, -1.0f}, //5
		{1, 1, -1.0f, -1.0f, -1.0f}, //1
		{0.684, 1.0f, -1.0f, 1.0f, -1.0f}, //2

		//윗면
		{1, 1, 1.0f, 1.0f, -1.0f}, //6
		{0, 1, -1.0f, 1.0f, -1.0f}, //2
		{0, 0.9,  -1.0f, 1.0f, 1.0f}, //3
		{1, 1.0f, 1.0f, 1.0f, 1.0f}, //7

		//아랫면
		{1, 1.0f, 1,-1.0f, 1.0f}, //4
		{1, 1, -1.0f, -1.0f, 1.0f}, //0
		{0, 1, -1.0f, -1.0f, -1.0f}, //1
		{0, 0.9,  1.0f, -1.0f, -1.0f}, //5

	};

	for (int i = 0; i < 6; i++)
	{
		//법선 설정
		glNormal3fv(Normal[i]);
	}

	glInterleavedArrays(GL_T2F_V3F, 0, v); //텍스쳐와 버텍스의 쌍을 명시하여 그려줌
	glDrawArrays(GL_QUADS, 0, 24);
}

void cube3()
{
	GLfloat v[][5] =
	{
		//오른면
		{0, 0, 1.0f, -1.0f, 1.0f}, //4
		{0.2, 0, 1.0f, -1.0f, -1.0f}, //5
		{0.2,1, 1.0f, 1.0f, -1.0f}, //6
		{0, 1, 1.0f, 1.0f, 1.0f}, //7

		//왼면
		{0.2, 1,  -1.0f, 1.0f, 1.0f}, //3
		{0, 1, -1.0f, 1.0f, -1.0f}, //2
		{0, 0, -1.0f, -1.0f, -1.0f}, //1
		{0.2, 0, -1.0f, -1.0f, 1.0f}, //0

		//앞면
		{0.0f, 0.0f, -1.0f, -1.0f, 1.0f}, //0
		{0.2, 0.0f, 1.0f, -1.0f, 1.0f}, //4
		{0.2, 1, 1.0f, 1.0f, 1.0f}, //7
		{0, 1, -1.0f, 1.0f, 1.0f}, //3

		//뒷면
		{0.0f, 1, 1.0f, 1.0f, -1.0f}, //6
		{0, 0.0f, 1.0f, -1.0f, -1.0f}, //5
		{0.2, 0, -1.0f, -1.0f, -1.0f}, //1
		{0.2, 1, -1.0f, 1.0f, -1.0f}, //2

		//윗면
		{0.0f, 0.0f, 1.0f, 1.0f, -1.0f}, //6
		{0.2, 0.0f, -1.0f, 1.0f, -1.0f}, //2
		{0.2, 1,  -1.0f, 1.0f, 1.0f}, //3
		{0, 1, 1.0f, 1.0f, 1.0f}, //7

		//아랫면
		{0.2, 1,   1,-1.0f, 1.0f}, //4
		{0, 1,    -1.0f, -1.0f, 1.0f}, //0
		{0, 0,    -1.0f, -1.0f, -1.0f}, //1
		{0.2, 0,  1.0f, -1.0f, -1.0f} //5

	};

	glInterleavedArrays(GL_T2F_V3F, 0, v); //텍스쳐와 버텍스의 쌍을 명시하여 그려줌
	glDrawArrays(GL_QUADS, 0, 24);
}

void cube4()
{
	GLfloat v[][5] =
	{
		//오른면
		{0, 0, 1.0f, -1.0f, 1.0f}, //4
		{1000, 0, 1.0f, -1.0f, -1.0f}, //5
		{1000,1000, 1.0f, 1.0f, -1.0f}, //6
		{0, 1000, 1.0f, 1.0f, 1.0f}, //7

		//왼면
		{1000, 1000,  -1.0f, 1.0f, 1.0f}, //3
		{0, 1000, -1.0f, 1.0f, -1.0f}, //2
		{0, 0, -1.0f, -1.0f, -1.0f}, //1
		{1000, 0, -1.0f, -1.0f, 1.0f}, //0

		//앞면
		{0.0f, 0.0f, -1.0f, -1.0f, 1.0f}, //0
		{1000, 0.0f, 1.0f, -1.0f, 1.0f}, //4
		{1000, 1000, 1.0f, 1.0f, 1.0f}, //7
		{0, 1000, -1.0f, 1.0f, 1.0f}, //3

		//뒷면
		{0.0f, 1000, 1.0f, 1.0f, -1.0f}, //6
		{0, 0.0f, 1.0f, -1.0f, -1.0f}, //5
		{1000, 0, -1.0f, -1.0f, -1.0f}, //1
		{1000, 1000, -1.0f, 1.0f, -1.0f}, //2

		//윗면
		{0.0f, 0.0f, 1.0f, 1.0f, -1.0f}, //6
		{1000, 0.0f, -1.0f, 1.0f, -1.0f}, //2
		{1000, 1000,  -1.0f, 1.0f, 1.0f}, //3
		{0, 1000, 1.0f, 1.0f, 1.0f}, //7

		//아랫면
		{1000, 1000,   1,-1.0f, 1.0f}, //4
		{0, 1000,    -1.0f, -1.0f, 1.0f}, //0
		{0, 0,    -1.0f, -1.0f, -1.0f}, //1
		{1000, 0,  1.0f, -1.0f, -1.0f} //5

	};

	glInterleavedArrays(GL_T2F_V3F, 0, v); //텍스쳐와 버텍스의 쌍을 명시하여 그려줌
	glDrawArrays(GL_QUADS, 0, 24);
}


//구 그리기
void sphere(GLfloat r, int slice, int stack)
{
	GLfloat **vertex; //[n][3]
	vertex = (GLfloat**)malloc(sizeof(GLfloat*)*((slice + 1)*(stack + 1)));

	GLfloat **texelArr; //[n][2]
	texelArr = (GLfloat**)malloc(sizeof(GLfloat*)*((slice + 1)*(stack + 1)));

	for (int i = 0; i < ((slice + 1)*(stack + 1)); i++)
	{
		vertex[i] = (GLfloat*)malloc(sizeof(GLfloat) * 3);
		texelArr[i] = (GLfloat*)malloc(sizeof(GLfloat) * 2);
	}
	int i = 0;

	float maxCountX = slice;
	float maxCountY = stack;
	float countX = 0;
	float countY = 0;
	for (GLfloat pi = -90; pi <= 90; pi += 180 / (float)stack)
	{
		for (GLfloat seta = 0; seta <= 360; seta = seta + 360 / (float)slice)
		{

			vertex[i][0] = r * Cos(pi)*Cos(seta); texelArr[i][0] = seta / 360.0f; //x
			vertex[i][1] = r * Cos(pi)*Sin(seta); texelArr[i][1] = pi / 180.0f + 0.5;//y
			vertex[i][2] = r * Sin(pi); //z
			i++;
		}
	}

	glBegin(GL_QUAD_STRIP);
	for (int j = 0; j < stack + 1; j++)
	{
		for (int i = 0; i < slice + 1; i++)
		{
			if (j <= stack - 1)
			{

				glNormal3fv(vertex[i + j * (slice + 1)]);

				glTexCoord2fv(texelArr[i + j * (slice + 1)]);
				glVertex3f(vertex[i + j * (slice + 1)][0], vertex[i + j * (slice + 1)][1], vertex[i + j * (slice + 1)][2]);

				glTexCoord2fv(texelArr[i + (j + 1) * (slice + 1)]);
				glVertex3f(vertex[i + (j + 1) * (slice + 1)][0], vertex[i + (j + 1) * (slice + 1)][1], vertex[i + (j + 1) * (slice + 1)][2]);
			}
		}
	}
	glEnd();
	for (int i = 0; i < ((slice + 1)*(stack + 1)); i++)
	{
		free(vertex[i]);
		free(texelArr[i]);
	}
	free(vertex);
	free(texelArr);
}

