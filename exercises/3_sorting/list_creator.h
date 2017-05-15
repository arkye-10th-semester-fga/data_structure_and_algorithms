#ifndef LIST_CREATOR_H
#define LIST_CREATOR_H

using namespace std;

bool create_list(vector<int> &elements,
	int quantity_of_elements, int seed);

void get_list_from_user(vector<int> &elements,
	int quantity_of_elements);

void create_unsorted_list(vector<int> &elements,
	int quantity_of_elements, int seed);

#endif // LIST_CREATOR_H
