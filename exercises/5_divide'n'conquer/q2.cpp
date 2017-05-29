#include <iostream>
#include <vector>

using namespace std;

#define ui unsigned int

void create_sequence(vector<ui> &sequence);
ui sort_and_count(vector<ui> &sequence, vector<ui>::iterator start,
	vector<ui>::iterator finish);
ui merge_and_count(vector<ui>::iterator start, vector<ui>::iterator mid,
	vector<ui>::iterator finish);

int main()
{
	vector<ui> sequence;
	create_sequence(sequence);

	ui count = sort_and_count(sequence, begin(sequence), end(sequence));

	cout << "Quantity of significant inversions: " << count << "." << endl;
	cout << "Sorted List Based on Inversion Criteria:" << endl << "\t";
	for(ui element : sequence)
	{
		cout << "[" << element << "]";
	}
	cout << endl;

	return 0;
}

void create_sequence(vector<ui> &sequence)
{
	const ui END_OF_INPUT = 0;
	cout << "Insert a list of unique numbers." << endl;
	cout << "End the insertion with " << END_OF_INPUT  << "." << endl;
	bool creation_is_done = false;
	while(!creation_is_done)
	{
		ui number = 0;
		cin >> number;
		if(number != END_OF_INPUT)
		{
			sequence.push_back(number);
		}
		else
		{
			creation_is_done = true;
		}
	}
}

ui sort_and_count(vector<ui> &sequence, vector<ui>::iterator start,
	vector<ui>::iterator finish)
{
	ui count = 0;
	size_t length = distance(start, finish);
	if(length > 1)
	{
		size_t middle = length/2;
		vector<ui>::iterator mid = next(start, middle);
		count += sort_and_count(sequence, start, mid);
		count += sort_and_count(sequence, mid, finish);
		count += merge_and_count(start, mid, finish);
	}
	return count;
}

ui merge_and_count(vector<ui>::iterator start, vector<ui>::iterator mid,
	vector<ui>::iterator finish)
{
	ui count = 0;
	vector<ui> work_vector(start,finish);

	vector<ui>::iterator work_start = begin(work_vector);
	vector<ui>::iterator work_finish = end(work_vector);
	vector<ui>::iterator work_mid = next(work_start, distance(start, mid));

	vector<ui>::iterator left = work_start;
	vector<ui>::iterator right = work_mid;
	vector<ui>::iterator index = start;

	while(left < work_mid && right < work_finish)
	{
		if(*left <= *right * 2)
		{
			*index = move(*left++);
		}
		else
		{
			*index = move(*right++);
			count += distance(left, work_mid);
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

	return count;
}
