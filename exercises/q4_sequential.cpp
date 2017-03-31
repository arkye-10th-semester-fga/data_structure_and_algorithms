#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "input.h"
#include "ordered_list_creator.h"

#define PRIMARY_INDEX_RATIO 10

using namespace std;

bool create_primary_index_table(vector<long long> &primary_index, vector<long long> &sorted_elements);
int sequential_search(vector<long long> &primary_index, vector<long long> &sorted_elements, long long search_value);

int main(int argc, char* argv[])
{
	vector<long long> sorted_elements;

	if(!has_four_arguments(argc))
	{
		exit(1);
	}

	int quantity_of_elements = atoi(argv[1]);

	if(!create_sorted_list(sorted_elements, quantity_of_elements))
	{
		exit(1);
	}

	long long search_value = atoll(argv[2]);

	if(search_value < 1 || search_value > quantity_of_elements)
	{
		inform_search_value_pattern();
		exit(1);
	}

	vector<long long> primary_index;

	if(create_primary_index_table(primary_index, sorted_elements))
	{
		int search_index = sequential_search(primary_index, sorted_elements, search_value);
		if(search_index != -1)
		{
			printf("ELEMENT FOUND - Position: %d; Value: %lld\n", search_index, search_value);
		}
		else
		{
			printf("ELEMENT NOT FOUND\n");
		}
	}

	return 0;
}

/*
 *
 */
bool create_primary_index_table(vector<long long> &primary_index, vector<long long> &sorted_elements)
{
	bool need_primary_index_table = false;

	int primary_index_size = sorted_elements.size()/PRIMARY_INDEX_RATIO;

	if(primary_index_size != 0)
	{
		need_primary_index_table = true;

		if(sorted_elements.size()%PRIMARY_INDEX_RATIO != 0)
		{
			++primary_index_size;
		}

		for(int i = 0; i < primary_index_size-1; ++i)
		{
			primary_index.push_back(sorted_elements[(i*PRIMARY_INDEX_RATIO)-1]);
		}
		primary_index.push_back(sorted_elements[sorted_elements.size()-1]);
	}

	return need_primary_index_table;
}

/*
 *
 */
int sequential_search(vector<long long> &primary_index, vector<long long> &sorted_elements, long long search_value)
{
	int size_primary = primary_index.size();
	int aux,auxSorted;
	for(aux=0; aux< size_primary; aux++){
		if(!(primary_index[aux] < search_value)){
			break;
		}
	}
	aux = aux*PRIMARY_INDEX_RATIO;
	for(auxSorted =0; auxSorted < 10; aux++){
		if(sorted_elements[aux] == search_value)
		{
			return aux;
		}
		if(sorted_elements[aux] > search_value)
			return -1;
	}
	return -1;
}
