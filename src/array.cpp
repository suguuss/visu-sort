/*
	Author		: suguuss
	Date		: 18/03/2022
	Filename	: gfx.cpp
	Descritpion : Array functions
*/


#include "../includes/array.h"

/**
 * @brief Create a shuffled array
 * 
 * @param size size of the array
 * @return type_t* Pointer to the array
 */
type_t* create_shuffled_array(uint32_t size)
{
	type_t *array = new type_t[size];

	// Put all the values inside the array
	for (uint32_t i = 0; i < size; i++)
	{
		array[i] = i + 1;
	}

	// Shuffle all the values
	for (uint32_t i = 0; i < size; i++)
	{
		uint32_t index = rand() % size;
		uint32_t tmp = array[index];
		array[index] = array[i];
		array[i] = tmp;
	}

	return array;
}

/**
 * @brief Prints the content of an array on a single line
 * 
 * @param array Array to print
 * @param size size of the array
 */
void print_array(const type_t *const array, uint32_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}