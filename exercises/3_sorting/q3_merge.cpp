#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include "io.h"
#include "list_creator.h"
#include "gnuplot_i.h"

using namespace std;

void merge_sort(vector<int> &elements, vector<int>::iterator start,
	vector<int>::iterator finish);
void merge(vector<int> &elements, vector<int>::iterator start,
	vector<int>::iterator mid, vector<int>::iterator finish);

gnuplot_ctrl *plot;

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
	print_rule();

	plot = gnuplot_init();
	merge_sort(elements, begin(elements), end(elements));
	sleep(3);
	gnuplot_close(plot);
	print_list("Sorted List", elements);

	return 0;
}

void merge_sort(vector<int> &elements, vector<int>::iterator start,
	vector<int>::iterator finish)
{
	size_t length = distance(start, finish);
	if(length > 1)
	{
		size_t middle = length/2;
		vector<int>::iterator mid = next(start, middle);
		merge_sort(elements, start, mid);
		merge_sort(elements, mid, finish);
		merge(elements, start, mid, finish);
	}
}

void merge(vector<int> &elements, vector<int>::iterator start,
	vector<int>::iterator mid, vector<int>::iterator finish)
{
	gnuplot_resetplot(plot);
	gnuplot_setstyle(plot, "impulses");
	char command[100];
	sprintf(command, "set xrange [-1:%lu]", distance(start, finish));
	gnuplot_cmd(plot, command);
	double points[distance(start, finish)];
	copy(start, finish, points);
	char description[100];
	print_step(description, "STEP", elements, start, finish);
	gnuplot_plot_x(plot, points, distance(start, finish), description);
	sleep(2);

	vector<int> work_vector(start,finish);

	vector<int>::iterator work_start = begin(work_vector);
	vector<int>::iterator work_finish = end(work_vector);
	vector<int>::iterator work_mid = next(work_start, distance(start, mid));

	vector<int>::iterator left = work_start;
	vector<int>::iterator right = work_mid;
	vector<int>::iterator index = start;

	while(left < work_mid && right < work_finish)
	{
		if(*left < *right)
		{
			*index = move(*left++);
		}
		else
		{
			*index = move(*right++);
		}
		++index;
	}

	while(left < work_mid)
	{
		*index = move(*left++);
		++index;
	}

	while(right < work_finish)
	{
		*index = move(*right++);
		++index;
	}

	gnuplot_resetplot(plot);
	gnuplot_setstyle(plot, "impulses");
	sprintf(command, "set xrange [-1:%lu]", distance(start, finish));
	gnuplot_cmd(plot, command);
	copy(start, finish, points);
	print_step(description, "SORT", elements, start, finish);
	gnuplot_plot_x(plot, points, distance(start, finish), description);
	sleep(2);
	print_rule();
}
