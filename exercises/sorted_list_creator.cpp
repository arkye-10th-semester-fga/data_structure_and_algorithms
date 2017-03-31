#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "sorted_list_creator.h"

using namespace std;

/*
 * Create Sorted List
 * If the creation was unsuccessful, return false, otherwise true
 */
bool create_sorted_list(vector<long long> &sorted_elements, int quantity_of_elements)
{
	bool is_creation_successful = true;
	if(quantity_of_elements == 0) // User chose to insert elements
	{
		if(!get_sorted_list_from_user(sorted_elements, quantity_of_elements))
		{
			is_creation_successful = false;
		}
	}
	else if(quantity_of_elements >= 10) // User chose to program create elements
	{
		create_automatic_sorted_list(sorted_elements, quantity_of_elements);
	}
	else // Unexpected choice
	{
		is_creation_successful = false;
	}
	return is_creation_successful;
}

/*
 * Get Sorted List from User
 * A new element must be greater than 0
 * A new element must be greater or equals than the previous element
 * return false if no element created, otherwise true
 */
bool get_sorted_list_from_user(vector<long long> &sorted_elements, int quantity_of_elements)
{
	bool has_elements = true;

	long long previous_element = 1;
	long long new_element;
	while(scanf("%lld", &new_element) == 1 && new_element > 0)
	{
		if(previous_element <= new_element && new_element < 1000000000)
		{
			sorted_elements.push_back(new_element);
			previous_element = new_element;
		}
	}
	if(sorted_elements.size() == 0)
	{
		has_elements = false;
	}
	else
	{
		for(auto element : sorted_elements)
		{
			printf("[%lld]", element);
		}
		printf("\n");
	}
	return has_elements;
}

/*
 * Create Sorted List
 * L = l + (l)+1 + ... + (l)+n
 * l = 1
 */
void create_automatic_sorted_list(vector<long long> &sorted_elements, int quantity_of_elements)
{
	long long new_element = 1;
	for(int i = 0; i < quantity_of_elements; ++i, ++new_element)
	{
		sorted_elements.push_back(new_element);
	}
}
