#ifndef LIST_CREATOR_H
#define LIST_CREATOR_H

using namespace std;

bool create_sorted_list(vector<long long> &sorted_elements, int quantity_of_elements);
bool get_sorted_list_from_user(vector<long long> &sorted_elements, int quantity_of_elements);
void create_automatic_sorted_list(vector<long long> &sorted_elements, int quantity_of_elements);

bool create_circular_list(vector<long long> &circular_list, int quantity_of_elements);
bool get_circular_list_from_user(vector<long long> &circular_list, int quantity_of_elements);
void create_automatic_circular_list(vector<long long> &circular_list, int quantity_of_elements);

#endif // LIST_CREATOR_H
