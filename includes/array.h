/*
	Author		: suguuss
	Date		: 18/03/2022
	Filename	: array.h
	Descritpion : Array functions
*/

#ifndef __ARRAY_H__
#define __ARRAY_H__

using namespace std;

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gfx.h"

typedef uint32_t type_t;

type_t *create_shuffled_array(uint32_t size);
void print_array(const type_t *const array, uint32_t size);

#endif