#include <iostream>
#include <vector>

using namespace std;

void get_weights(vector<int> &weights);
void get_maximum_set(vector<int> &weights,
	vector<int> &maximum_set);

int main()
{
	vector<int> weights;
	get_weights(weights);

	vector<int> maximum_set;
	get_maximum_set(weights, maximum_set);

	int total_weight = 0;
	cout << "-> Selected set: " << endl;
	for(int node : maximum_set)
	{
		total_weight += node;
		cout << "(" << node << ")";
	}
	cout << endl << "-> Total weight: " << total_weight << endl;

	return 0;
}

void get_weights(vector<int> &weights)
{
	cout << "Write each node weight." << endl;
	cout << "End the input with 0." << endl;
	int weight;
	while(cin >> weight && weight)
	{
		weights.push_back(weight);
	}
}

void get_maximum_set(vector<int> &weights,
	vector<int> &maximum_set)
{
	vector<int> visited_nodes;
	vector<vector<int>> selected_sets;

	visited_nodes.push_back(0);
	visited_nodes.push_back(weights[0]);

	vector<int> initial_set;
	selected_sets.push_back(initial_set);

	initial_set.push_back(weights[0]);
	selected_sets.push_back(initial_set);

	int visited_index = 2;
	for(unsigned int i = 1; i < weights.size(); ++i)
	{
		int previous_node = visited_nodes[visited_index-1];
		int node = weights[i] + visited_nodes[visited_index-2];

		if(previous_node >= node)
		{
			visited_nodes.push_back(previous_node);
			vector<int> selected_set = selected_sets.back();
			selected_sets.push_back(selected_set);
		}
		else
		{
			visited_nodes.push_back(node);
			vector<int> selected_set = selected_sets[visited_index-2];
			selected_set.push_back(weights[i]);
			selected_sets.push_back(selected_set);
		}

		++visited_index;
	}

	maximum_set.assign(selected_sets.back().begin(),
		selected_sets.back().end());
}
