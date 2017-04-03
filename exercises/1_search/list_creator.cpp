#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "list_creator.h"

#define MILLION 1000000
#define BILLION 1000000000
#define USER_CHOICE 0

using namespace std;

/*
 * Create Sorted List
 * If the creation was unsuccessful, return false, otherwise true
 */
bool create_sorted_list(vector<long long> &sorted_elements, int quantity_of_elements)
{
	bool is_creation_successful = true;
	if(quantity_of_elements == USER_CHOICE) // User chose to insert elements
	{
		if(!get_sorted_list_from_user(sorted_elements, quantity_of_elements))
		{
			is_creation_successful = false;
		}
	}
	else if(quantity_of_elements >= 10 && quantity_of_elements <= MILLION) // User chose to program create elements
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
		if(previous_element <= new_element && new_element < BILLION)
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

/*
 * Create Circular Sorted List
 * If the creation was unsuccessful, return false, otherwise true
 */
bool create_circular_list(vector<long long> &circular_list, int quantity_of_elements)
{
	bool is_creation_successful = true;
	if(quantity_of_elements == USER_CHOICE) // User chose to insert elements
	{
		if(!get_circular_list_from_user(circular_list, quantity_of_elements))
		{
			is_creation_successful = false;
		}
	}
	else if(quantity_of_elements >= 10) // User chose to program create elements
	{
		create_automatic_circular_list(circular_list, quantity_of_elements);
	}
	else // Unexpected choice
	{
		is_creation_successful = false;
	}

	return is_creation_successful;
}

/*
 * Get Circular Sorted List from User
 * A new element must be greater than 0
 * Once a new element is lesser than the previous element,
 * all the next new elements must be greater than the previous
 * and lesser than the highest element inserted.
 * return false if no element created, otherwise true
 */
bool get_circular_list_from_user(vector<long long> &circular_list, int quantity_of_elements)
{
	bool has_elements = true;

	long long previous_element = 1;
	long long new_element;
	long long highest_element = 0;
	while(scanf("%lld", &new_element) == 1 && new_element > 0)
	{
		if(highest_element == 0)
		{
			if(new_element < BILLION)
			{
				circular_list.push_back(new_element);
				if(previous_element > new_element)
				{
					highest_element = previous_element;
				}
				previous_element = new_element;
			}
		}
		else
		{
			if(previous_element <= new_element && new_element < highest_element)
			{
				circular_list.push_back(new_element);
				previous_element = new_element;
			}
			else
			{
				printf("Minimum value allowed is %lld\n", previous_element);
				printf("Maximum value allowed is %lld\n", highest_element-1);
				printf("To finish the insertion, insert the value 0\n");
			}
		}
	}

	if(circular_list.size() == 0)
	{
		has_elements = false;
	}
	else
	{
		for(auto element : circular_list)
		{
			printf("[%lld]", element);
		}
		printf("\n");
	}

	return has_elements;
}

/*
 * Create Circular Sorted List, Original list is:
 * L = l + (l)+1 + ... + (l)+n
 * l = 1
 * The circular list is the original list rotated
 * until l becomes the half element
 */
void create_automatic_circular_list(vector<long long> &circular_list, int quantity_of_elements)
{
	const int HALF_VALUE = (quantity_of_elements/2)+1;
	long long new_element = HALF_VALUE;
	for(int i = 0; i < quantity_of_elements; ++i, ++new_element)
	{
		circular_list.push_back(new_element);
		if(new_element == quantity_of_elements)
		{
			new_element = 0;
		}
	}
}
