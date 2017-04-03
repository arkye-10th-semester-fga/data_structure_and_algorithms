#ifndef INPUT_H
#define INPUT_H

// Inputs
void inform_number_of_elements_pattern();
void inform_sorted_insertion_pattern();
void inform_circular_insertion_pattern();
void inform_search_value_pattern();
void inform_stress_loop_pattern();
bool has_four_arguments(int argc);

// Outputs
void print_result(int search_index, long long search_value);
void print_time(clock_t start_time, clock_t end_time);

#endif // INPUT_H
