#include "pixel_functions.h"

Pixel create_pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	Pixel temp;
	temp.red = r;
	temp.green = g;
	temp.blue = b;
	temp.alpha = a;
	
	return temp;	
}	

void black_and_white(Pixel *p) {
	Pixel temp;

	double rounding_constant = 0.5;
	double average =( (double) (p->red + p->blue + p->green) )/3 + rounding_constant;
	int rounded_average = (int) average;

	temp.red = temp.blue = temp.green = average;
	*p = temp;
}

void overlay(Pixel *a, Pixel *b) {
	Pixel temp;

	temp.red =   calculate_color(a->red, b->red, a->alpha, b->alpha);
	temp.blue =  calculate_color(a->blue, b->blue, a->alpha, b->alpha);
	temp.green = calculate_color(a->green, b->green, a->alpha, b->alpha);
	temp.alpha = b->alpha + a->alpha * (255- b->alpha) / 255;

	*a = temp;
}


unsigned char calculate_color(unsigned char r1, unsigned char r2, unsigned char a1, unsigned char a2) {
	return (r2 * a2)/255 + a1 * (255 - a2) * r1 / 255 / 255;
}

