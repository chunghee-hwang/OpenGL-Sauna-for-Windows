#include<GL/glut.h>
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CameraMove.h"
float angle = 0.0f;
double x = 0.0f, y = 7.0f, z = 50.0f;
double dx = 0.0f, dz = -1.0f, Y = 0;
float MOVE_SPEED = 0.5f;
int oldX = 0, oldY = 0;
void cameraMove()
{
	gluLookAt(x, y, z,
		x + dx, y + Y, z + dz,
		0.0f, 1.0f, 0.0f);
	//printf("camera : %.2f, %.2f, %.2f\n",x,y,z);
}

void keyboard(unsigned char key, int x1, int y1)
{

	switch (key)
	{
	case 'a':
		angle -= 0.05f;
		dx = sin(angle);
		dz = -cos(angle);
		break;
	case 'd':
		angle += 0.05f;
		dx = sin(angle);
		dz = -cos(angle);
		break;
	case 'w':
		x += dx * MOVE_SPEED;
		z += dz * MOVE_SPEED;
		break;
	case 's':
		x -= dx * MOVE_SPEED;
		z -= dz * MOVE_SPEED;
		break;
	case ' ': //spacebar
		y += 0.15f;
		break;
	case 'v':
		y -= 0.15f;
		break;
	}
	glutPostRedisplay();
}



void myMotion(int x, int y)
{
	int deltaX = oldX - x;
	int deltaY = oldY - y;
	if (deltaX > 0)
	{
		angle -= 0.01f;
		dx = sin(angle);
		dz = -cos(angle);
	}
	else
	{
		angle += 0.01f;
		dx = sin(angle);
		dz = -cos(angle);
	}

	if (deltaY > 0.5)
	{
		Y += 0.01f;

	}
	else if (deltaY < -0.5)
	{
		Y -= 0.01f;
	}

	glutPostRedisplay();
	oldX = x;
	oldY = y;

}