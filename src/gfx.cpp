/*
	Author		: suguuss
	Date		: 18/03/2022
	Filename	: gfx.cpp
	Descritpion : Drawing functions
*/

#include "../includes/gfx.h"

void gfx_draw_rectangle(SDL_Renderer *ren, int x1, int y1, int x2, int y2, int height)
{
	SDL_Rect r = {.x = x1, .y = height-y2, .w = x2 - x1, .h = y2};
	SDL_RenderFillRect(ren, &r);
}

/**
 * @brief Displays an array as a bar graph
 * 
 * @param ren Renderer
 * @param array Array to be displayed
 * @param size size of the array
 * @param width width of the window
 * @param height height of the window
 */
void display_array(SDL_Renderer *ren, const type_t *const array, uint32_t size, uint32_t width, uint32_t height)
{
	uint32_t step = width / size;

	for (uint32_t i = 0; i < size; i++)
	{
		uint32_t x1 = step * i;
		uint32_t x2 = step * (i + 1);
		uint32_t y2 = map(array[i], 0, size, 0, height);

		// printf("i : %d | x1 : %d | y1 : %d | x2 : %d | y2: %d\n\n\n", array[i], x1, 0, x2, y1);

		gfx_draw_rectangle(ren, x1, 0, x2, y2, height);
	}
}