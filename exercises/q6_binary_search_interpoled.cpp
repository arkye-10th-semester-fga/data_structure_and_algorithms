#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "input.h"
#include "sorted_list_creator.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Variables
	vector<long long> sorted_elements;

	//Functions
	bool create_primary_index_table(vector<long long> &primary_index, vector<long long> &sorted_elements);
	int binary_search_interpoled(vector<long long> &sorted_elements,int value);

	int quantity_of_elements = atoi(argv[1]);

	if(!create_sorted_list(sorted_elements, quantity_of_elements))
	{
		exit(1);
	}

	long long search_value = atoll(argv[2]);

	printf("Binary search interpoled: %d\n",binary_search_interpoled(sorted_elements,search_value)+1);

	return 0;
}


//Binary Serarch
/*
int binary_search_interpoled(vector<long long> &sorted_elements,int value){
	int min = 0, max = sorted_elements.size() -1, avg;

	while (min <= max){
		avg = (min + max) / 2;
		if(sorted_elements.at(avg) == value){
			return avg;
		}
		if(sorted_elements.at(avg) > value){
			max = (max + avg)/2;
		}else{
			min = (min + avg)/2;
		}
	}
	return -1;
}*/

int binary_search_interpoled(vector<long long> &sorted_elements,int value)
{
    int low = 0;
    int high = sorted_elements.size() -1;
    int mid;

    while (sorted_elements.at(high) != sorted_elements.at(low) && value >= sorted_elements.at(low) && value <= sorted_elements.at(high)) {
        mid = low + ((value - sorted_elements.at(low)) * (high - low) / (sorted_elements.at(high) - sorted_elements.at(low)));

        if (sorted_elements.at(mid) < value)
            low = mid + 1;
        else if (value < sorted_elements.at(mid))
            high = mid - 1;
        else
            return mid;
    }

    if (value == sorted_elements.at(low))
        return low ;
    else
        return -1;
}