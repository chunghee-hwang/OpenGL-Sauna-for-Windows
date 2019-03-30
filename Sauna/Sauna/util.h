#ifndef util_h
#define util_h
#include<GL/GLAUX.H>
#define TEXTURE_NUM 22 //image °³¼ö
extern float g_fSpinX;
extern float g_fSpinY;
extern GLuint texture [TEXTURE_NUM]; //texture ID
extern char texture_name[TEXTURE_NUM][20];
static POINT ptLastMousePosit;
static POINT ptCurrentMousePosit;
static bool bMousing;
AUX_RGBImageRec * LoadBMP(char *filename);
int LoadGLTextures();
#endif