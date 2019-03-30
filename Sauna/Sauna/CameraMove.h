#ifndef cameramove_h
#define cameramove_h
extern float angle;
extern double x, y, z;
extern double dx,dz,Y;
extern float MOVE_SPEED;
extern int oldX, oldY;
void cameraMove();
void keyboard(unsigned char key, int x1, int y1);
void myMotion(int x, int y);
#endif