#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "light.h"
GLfloat light_pos[] = { 0.0f, 0, 0, 5 }; //yz평면에서 빛을 쏨
GLfloat shininess[] = { 127 };
GLfloat Colors[][4] =
{
	//RGBA 설정
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
	glEnable(GL_LIGHTING); //빛을 쓰겠다
	glEnable(GL_LIGHT0); //전등의 종류가 0~7까지 있는데 0을 씀

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW); //GL_CCW : 법선을 반대방향(후면 방향)으로 설정하여 안쪽 material이 나온다. -->안쪽 material이 나온다.=
	glEnable(GL_DEPTH_TEST); //이걸 안 쓰면 가려져서 보이지 않는 것을 무시하고 다 그린다. vertex를 찍은 순으로 그린다.

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, Colors[RED]); //ambient는 없음(주변 사물에서 반사되어 온 빛 색)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Colors[WHITE]); //난반사색(빛의 진짜 색이 됨) //blue
	glLightfv(GL_LIGHT0, GL_SPECULAR, Colors[MAGENTA]); //정반사색 //white

	glMaterialfv(GL_FRONT, GL_AMBIENT, Colors[CYAN]); //black
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Colors[WHITE]); //(material의 진짜 색이 됨)yellow -->주석처럼 했을 때 검정색으로 나온다.
	glMaterialfv(GL_FRONT, GL_SPECULAR, Colors[WHITE]); //흰색으로 반사
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);//밝기(반짝임) 정도는 127
}

