/*
	Author		: suguuss
	Date		: 18/03/2022
	Filename	: gfx.h
	Descritpion : Drawing functions
*/

#ifndef __GFX_H__
#define __GFX_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdint>

typedef uint32_t type_t;

void gfx_draw_rectangle(SDL_Renderer *ren, int x1, int y1, int x2, int y2, int height);
void display_array(SDL_Renderer *ren, const type_t *const array, uint32_t size, uint32_t width, uint32_t height);

extern uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max);
#endif