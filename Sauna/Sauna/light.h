#ifndef light_h
#define light_h
#include<GL/glut.h>
;
#define WHITE	0
#define RED		1
#define	YELLOW	2
#define GREEN	3
#define CYAN	4
#define BLUE	5
#define MAGENTA	6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define BLACK	9
#define DARKGOLD 10
extern GLfloat light_pos[];
extern GLfloat shininess[];
extern GLfloat Colors[][4];
void initLight();
#endif