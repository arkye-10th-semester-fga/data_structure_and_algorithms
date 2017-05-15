#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "io.h"
#include "list_creator.h"

using namespace std;

void radix_sort(vector<int> &elements);
void counting_sort(vector<vector<int>> &buckets, int digit);

int main(int argc, char* argv[])
{
	// Check Arguments Quantity
	if(argc != 3)
	{
		inform_execution_pattern();
		inform_quantity_of_elements_pattern();
		inform_seed_pattern();
		exit(EXIT_FAILURE);
	}

	// Create List
	int quantity_of_elements = atoi(argv[1]);
	int seed = atoi(argv[2]);
	vector<int> elements;
	if(!create_list(elements, quantity_of_elements, seed))
	{
		exit(EXIT_FAILURE);
	}

	print_list("Initial List", elements);

	radix_sort(elements);

	print_list("Sorted List", elements);

	return 0;
}

void radix_sort(vector<int> &elements)
{
	vector<vector<int>> buckets(100);

	for(int element : elements)
	{
		buckets[element/10].push_back(element);
	}

	for(int digit = 3; digit > 0; --digit)
	{
		counting_sort(buckets, digit);
	}

	int index = 0;
	for(vector<int> bucket : buckets)
	{
		for(int element : bucket)
		{
			elements[index] = element;
			index++;
		}
	}
}

void counting_sort(vector<vector<int>> &buckets, int digit)
{
	unsigned int fraction = 1;
	unsigned int module = 10;
	for(int i = 0; i < digit-1; i++)
	{
		fraction *= 10;
		module *= 10;
	}

	for(vector<int> bucket : buckets)
	{
		if(bucket.size() > 0)
		{
			vector<int> histogram(10,0);
			vector<int> sorted_bucket(bucket.size());
			for(unsigned int j = 0; j < bucket.size(); ++j)
			{
				unsigned int index = (bucket[j]%module)/fraction;
				++histogram[index];
			}
			for(unsigned int i = 1; i < 10; ++i)
			{
				histogram[i] = histogram[i] + histogram[i-1];
			}
			for(int j = bucket.size(); j > 0; --j)
			{
				int histogram_index = (bucket[j-1]%module)/fraction;
				int index = histogram[histogram_index]-1;
				sorted_bucket[index] = bucket[j-1];
				--histogram[histogram_index];
			}
			bucket = sorted_bucket;
		}
	}
}
