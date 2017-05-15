#ifndef INPUT_H
#define INPUT_H

using namespace std;

// Inputs
void inform_execution_pattern();
void inform_quantity_of_elements_pattern();
void inform_seed_pattern();
void inform_insertion_pattern();

// Output
void print_list(const char *list_name, vector<int> &elements);
void print_step(char description[100], const char *step_name, vector<int> &elements,
	vector<int>::iterator start, vector<int>::iterator finish);
void print_rule();

#endif // INPUT_H
