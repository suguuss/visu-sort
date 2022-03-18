/*
	Author		: suguuss
	Date		: 18/03/2022
	Filename	: main.cpp
	Descritpion : 
*/

using namespace std;

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <ctime>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../includes/gfx.h"
#include "../includes/array.h"


#define WIDTH 	500
#define HEIGHT 	500

#define SIZE 	WIDTH

// Function prototypes
void bubble_sort(const type_t* const unsorted_array, type_t* sorted_array, uint32_t size);
uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max);

void renderer(SDL_Renderer *ren, type_t *array);

int main()
{
	srand(time(NULL));

	type_t *unsorted = create_shuffled_array(SIZE);
	type_t *sorted = new type_t[SIZE];
	// type_t *sorted = bubble_sort(unsorted, SIZE);

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stdout, "Couldn't initialise SDL\n");
		fprintf(stdout, "SDL error : %s\n", SDL_GetError());
	}
	SDL_Window *win = SDL_CreateWindow("Visualiser", 
										SDL_WINDOWPOS_CENTERED, 
										SDL_WINDOWPOS_CENTERED, 
										WIDTH, HEIGHT, 0);

	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, 0);

	thread sort(bubble_sort, unsorted, sorted, SIZE);
	renderer(rend, sorted);

	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);

	delete[] unsorted;
	delete[] sorted;

	return 0;
}


/**
 * @brief Renderer function
 * 
 * @param rend SDL_Renderer
 * @param array Array to be displayed
 */
void renderer(SDL_Renderer *rend, type_t *array)
{
	bool running = true;
	SDL_Event event;

	while (running)
	{
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.scancode)
					{
						case SDL_SCANCODE_ESCAPE:
							running = false;
							break;
						default:
							break;
					}
				default:
					break;
			}
		}

		SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
		SDL_RenderClear(rend);

		SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
		display_array(rend, array, SIZE, WIDTH, HEIGHT);

		SDL_RenderPresent(rend);
	}
}

/**
 * @brief Scale a value from input range to ouput range
 * 
 * @param x Value to be scaled
 * @param in_min 
 * @param in_max 
 * @param out_min 
 * @param out_max 
 * @return uint32_t Scaled value
 */
uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/**
 * @brief Sorts an array using the BubbleSort algorithm
 * 
 * @param unsorted_array Array to sort (won't be touched)
 * @param size size of the array
 * @return type_t* Pointer to the sorted array
 */
void bubble_sort(const type_t* const unsorted_array, type_t* sorted_array, uint32_t size)
{
	// Create a copy of the array
	memcpy(sorted_array, unsorted_array, (sizeof *sorted_array) * size);

	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (uint32_t i = 0; i < size - 1; i++)
		{
			if (sorted_array[i] > sorted_array[i + 1])
			{
				sorted = false;
				type_t tmp = sorted_array[i + 1];
				sorted_array[i + 1] = sorted_array[i];
				sorted_array[i] = tmp;
			}
			usleep(50);
		}
	}
}