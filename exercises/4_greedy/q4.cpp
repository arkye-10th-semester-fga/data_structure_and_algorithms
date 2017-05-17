#include <iostream>
#include <vector>

using namespace std;

void create_sequence(vector<string> &sequence, string name);
bool is_subsequence(vector<string> &sequence, vector<string> &candidate);

int main()
{
	const string SEQUENCE_NAME = "S";
	const string CANDIDATE_NAME = "S\'";
	vector<string> sequence;
	vector<string> candidate;
	create_sequence(sequence, SEQUENCE_NAME);
	create_sequence(candidate, CANDIDATE_NAME);

	cout << CANDIDATE_NAME << " is ";
	if(!is_subsequence(sequence, candidate))
	{
		cout << "NOT ";
	}
	cout << "a subsequence of " << SEQUENCE_NAME << endl;

	return 0;
}

void create_sequence(vector<string> &sequence, string name)
{
	const string END_OF_INPUT = "0";
	cout << "Insert all events of " << name << "." << endl;
	cout << "End the insertion with " << END_OF_INPUT  << "." << endl;
	bool creation_is_done = false;
	while(!creation_is_done)
	{
		string event;
		if(getline(cin, event) && event != END_OF_INPUT)
		{
			sequence.push_back(event);
		}
		else
		{
			creation_is_done = true;
		}
	}
}

bool is_subsequence(vector<string> &sequence, vector<string> &candidate)
{
	unsigned int i = 0;
	unsigned int j = 0;
	while(i < sequence.size() && j < candidate.size())
	{
		if(sequence.at(i) == candidate.at(j))
		{
			++j;
		}
		++i;
	}
	return j == candidate.size();
}
