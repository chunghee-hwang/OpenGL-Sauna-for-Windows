#include<GL/glut.h>
#include<stdio.h>
#include <stdlib.h>
#include "util.h"
#pragma comment(lib, "legacy_stdio_definitions.lib")
// 5개 변수를 프로그램 상단에 추가
float g_fSpinX = 0.0f;
float g_fSpinY = 0.0f;

GLuint texture[TEXTURE_NUM]; //texture ID
char texture_name[TEXTURE_NUM][20] = { "desk.bmp", "bright_wood.bmp", "lock.bmp", "glass.bmp", "wall.bmp","mirror.bmp","chair.bmp","saunaWall.bmp","darkWood.bmp","mackbanseock.bmp",
"stainless.bmp","showerHeadHole.bmp", "marble.bmp","water.bmp", "temp20.bmp", "temp39.bmp", "temp42.bmp", "temp59.bmp", "saunaWall2.bmp", "background.bmp","grass.bmp", "forest.bmp"
};

AUX_RGBImageRec * LoadBMP(char *filename) {
	if (!filename) return NULL;
	FILE * file;
	errno_t err;
	err = fopen_s(&file, filename, "r");

	if (file) {
		fclose(file);
		return auxDIBImageLoad(filename);
	}
	return NULL;
}

int LoadGLTextures()
{
	int Status = TRUE, i;
	AUX_RGBImageRec *TextureImage;

	for (i = 0; i < TEXTURE_NUM; i++) {
		TextureImage = NULL;
		if (TextureImage = LoadBMP(texture_name[i])) {
			glGenTextures(1, &texture[i]);
			glBindTexture(GL_TEXTURE_2D, texture[i]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
			glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX,
				TextureImage->sizeY, 0,
				GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);

			
		}
		else {
			MessageBox(NULL, "Image file has a error !", texture_name[i], MB_ICONERROR);
			Status = false;
		}

		if (TextureImage) {
			if (TextureImage->data) free(TextureImage->data);
			free(TextureImage);
		}
	}
	return Status;
}
