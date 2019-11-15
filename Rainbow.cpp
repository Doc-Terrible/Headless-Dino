#include<stdio.h>
#include"Rainbow.h"

enum color { RED, GREEN, BLUE };

Rainbow::Rainbow(int red, int green,int blue, double speed){
	R = red;
	G = green;
	B = blue;
	if (speed != 0) SPEED = speed;
	else SPEED = 1;
}

void Rainbow::Change() {
	if (R == 0 && G == 0 && B == 255)RGB[RED] = true;
	else if (R == 255 && G == 0 && B == 255)RGB[BLUE] = false;
	if (R == 255 && G == 0 && B == 0)RGB[GREEN] = true;
	else if (R == 255 && G == 255 && B == 0)RGB[RED] = false;
	if (R == 0 && G == 255 && B == 0)RGB[BLUE] = true;
	else if (R == 0 && G == 255 && B == 255)RGB[GREEN] = false;

	if (!RGB[RED] && !RGB[GREEN] && !RGB[BLUE])RGB[RED] = true;
	if (RGB[RED] && R < 255)R += SPEED;
	else if (!RGB[RED] && R > 0)R -= SPEED;
	if (RGB[GREEN] && G < 255)G += SPEED;
	else if (!RGB[GREEN] && G > 0)G -= SPEED;
	if (RGB[BLUE] && B < 255)B += SPEED;
	else if (!RGB[BLUE] && B > 0)B -= SPEED;
}

int Rainbow::getColor(char Color){
	switch (Color){
	case 'R':
		return R;
		break;
	case 'G':
		return G;
		break;
	case 'B':
		return B;
		break;
	default:
		printf("'%c' is not an accepted Leter, use 'R', 'G', or 'B'", Color);
		return NULL;
		break;
	}
}
