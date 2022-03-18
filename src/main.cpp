/*
	Author		: suguuss
	Date		: 18/03/2022
	Filename	: main.cpp
	Descritpion : 
*/

#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 5

typedef uint32_t type_t;
type_t* bubble_sort(const type_t* const unsorted_array, uint32_t size);

int main()
{
	type_t test[SIZE] = {2, 5, 61, 2, 4};

	type_t *sorted = bubble_sort(test, SIZE);

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << sorted[i] << " ";
	}
	cout << endl;

	delete[] sorted;
	return 0;
}

type_t* bubble_sort(const type_t* const unsorted_array, uint32_t size)
{
	// Create a copy of the array
	type_t *sorted_array = new type_t[size];
	memcpy(sorted_array, unsorted_array, (sizeof *sorted_array) * size);
	
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << sorted_array[i] << " ";
	}
	cout << endl;

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
		}
	}

	return sorted_array;
}