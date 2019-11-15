#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<iostream>
#include"Rainbow.h"
using namespace std;

int main() {
	al_init();
	al_init_image_addon();
	ALLEGRO_DISPLAY* screen = al_create_display(1000, 500);
	ALLEGRO_BITMAP* DinoPic1 = al_load_bitmap("Clear-Dino.png");
	ALLEGRO_BITMAP* DinoPic2 = al_load_bitmap("Dino-Clear-Background.png");
	al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
	Rainbow R1(0, 0, 0, .5);
	//start dark for a second
	for (float i = 0; i < 1; i += .0005) {
		R1.Change();
		al_clear_to_color(al_map_rgb(R1.getColor('R'), R1.getColor('G'), R1.getColor('B')));
	}
	//fade in
	for (float i = 0; i < 1; i += .0008) {
		R1.Change();
		al_clear_to_color(al_map_rgb(R1.getColor('R'), R1.getColor('G'), R1.getColor('B')));
		al_draw_tinted_bitmap(DinoPic1, al_map_rgba_f(1, 1, 1, i), 50, 50, 0);
		al_draw_tinted_bitmap(DinoPic2, al_map_rgba_f(1, 1, 1, i), 550, 50, 0);
		al_flip_display();
	}
	//stay solid for a second
	for (float i = 0; i < 1; i += .001) {
		R1.Change();
		al_clear_to_color(al_map_rgb(R1.getColor('R'), R1.getColor('G'), R1.getColor('B')));
		al_draw_tinted_bitmap(DinoPic1, al_map_rgba_f(1, 1, 1, 1), 50, 50, 0);
		al_draw_tinted_bitmap(DinoPic2, al_map_rgba_f(1, 1, 1, 1), 550, 50, 0);
		al_flip_display();
	}
	//fade out
	for (float i = 1; i > 0; i -= .0005) {
		R1.Change();
		al_clear_to_color(al_map_rgb(R1.getColor('R'), R1.getColor('G'), R1.getColor('B')));
		al_draw_tinted_bitmap(DinoPic1, al_map_rgba_f(i, 1, 1, i), 50, 50, 0);
		al_draw_tinted_bitmap(DinoPic2, al_map_rgba_f(i, 1, 1, i), 550, 50, 0);
		al_flip_display();
	}
	al_rest(1);
	al_destroy_bitmap(DinoPic1);
	al_destroy_bitmap(DinoPic2);
	al_destroy_display(screen);
}