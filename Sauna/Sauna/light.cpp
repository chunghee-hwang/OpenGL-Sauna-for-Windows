#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "light.h"
GLfloat light_pos[] = { 0.0f, 0, 0, 5 }; //yz��鿡�� ���� ��
GLfloat shininess[] = { 127 };
GLfloat Colors[][4] =
{
	//RGBA ����
	{1.0f, 1.0f, 1.0f, 1.0f}, //0 - white
	{0.8f, 0.0f, 0.0f, 1.0f}, //1 - red
	{0.8f, 0.8f, 0.0f, 1.0f}, //2 - yellow
	{0.0f, 0.8f, 0.0f, 1.0f}, //3 - green
	{0.0f, 0.8f, 0.8f, 1.0f}, //4 - cyan
	{0.0f, 0.0f, 0.8f, 1.0f}, //5 - blue
	{0.8f, 0.0f, 0.8f, 1.0f}, //6 - magenta
	{0.8f, 0.8f, 0.8f, 1.0f}, //7 - light gray
	{0.3f, 0.3f, 0.3f, 1.0f}, //7 - dark gray
	{0.0f, 0.0f, 0.0f, 1.0f}, //9 - black
	{0.5f, 0.4f, 0.3f, 1.0f} //10 - dark gold

};

void initLight()
{
	glEnable(GL_LIGHTING); //���� ���ڴ�
	glEnable(GL_LIGHT0); //������ ������ 0~7���� �ִµ� 0�� ��

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW); //GL_CCW : ������ �ݴ����(�ĸ� ����)���� �����Ͽ� ���� material�� ���´�. -->���� material�� ���´�.=
	glEnable(GL_DEPTH_TEST); //�̰� �� ���� �������� ������ �ʴ� ���� �����ϰ� �� �׸���. vertex�� ���� ������ �׸���.

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, Colors[RED]); //ambient�� ����(�ֺ� �繰���� �ݻ�Ǿ� �� �� ��)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Colors[WHITE]); //���ݻ��(���� ��¥ ���� ��) //blue
	glLightfv(GL_LIGHT0, GL_SPECULAR, Colors[MAGENTA]); //���ݻ�� //white

	glMaterialfv(GL_FRONT, GL_AMBIENT, Colors[CYAN]); //black
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Colors[WHITE]); //(material�� ��¥ ���� ��)yellow -->�ּ�ó�� ���� �� ���������� ���´�.
	glMaterialfv(GL_FRONT, GL_SPECULAR, Colors[WHITE]); //������� �ݻ�
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);//���(��¦��) ������ 127
}

