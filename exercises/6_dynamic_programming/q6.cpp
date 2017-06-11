#include <iostream>
#include <string>
#include <vector>

#define INFINITY 10000000000
#define ll long long

using namespace std;

ll get_line_length();
void get_text(vector<string> &words);
ll get_minimal_slack(vector<string> &words, ll line_length,
	vector<ll> &breaking_indexes);
void print_lines(vector<string> &words,
	vector<ll> &breaking_indexes);

int main()
{
	ll line_length = get_line_length();
	vector<string> words;
	get_text(words);

	vector<ll> breaking_indexes(words.size());
	ll slack = get_minimal_slack(words, line_length, breaking_indexes);

	cout << "=== Pretty Printing Results ===" << endl;
	cout << "-> Formatted Text:" << endl;
	print_lines(words, breaking_indexes);
	cout << "-> Slack Counter: " << slack << endl;

	return 0;
}

ll get_line_length()
{
	cout << "Inform the desired line length." << endl;
	ll line_length;
	cin >> line_length;
	return line_length;
}

void get_text(vector<string> &words)
{
	cout << "Write the text in a single line." << endl;
	cout << "End the writting with an END." << endl;
	bool received_end = false;
	while(!received_end)
	{
		string word;
		cin >> word;
		if(word == "END")
		{
			received_end = true;
		}
		else
		{
			words.push_back(word);
		}
	}
}

ll get_minimal_slack(vector<string> &words, ll line_length,
	vector<ll> &breaking_indexes)
{
	ll n = words.size();
	ll cost[n][n];
	for(ll i = 0; i < n; ++i)
	{
		cost[i][i] = line_length - words[i].length();
		for(ll j = i+1; j < n; ++j)
		{
			cost[i][j] = cost[i][j-1] - words[j].length() - 1;
		}
	}

	for(ll i = 0; i < n; ++i)
	{
		for(ll j = i; j < n; ++j)
		{
			if(cost[i][j] < 0)
			{
				cost[i][j] = INFINITY;
			}
			else
			{
				cost[i][j] *= cost[i][j];
			}
		}
	}

	ll min_cost[n];
	for(ll i = n-1; i >= 0; --i)
	{
		min_cost[i] = cost[i][n-1];
		breaking_indexes[i] = n;
		for(ll j = n-1; j > i; --j)
		{
			if(cost[i][j-1] != INFINITY and
				min_cost[i] > min_cost[j] + cost[i][j-1])
			{
				min_cost[i] = min_cost[j] + cost[i][j-1];
				breaking_indexes[i] = j;
			}
		}
	}

	return min_cost[0];
}

void print_lines(vector<string> &words,
	vector<ll> &breaking_indexes)
{
	ll i = 0;
	ll j;
	ll n = words.size();
	cout << endl;
	do
	{
		j = breaking_indexes[i];
		for(ll k = i; k < j; ++k)
		{
			cout << words[k] << " ";
		}
		cout << endl;
		i = j;
	} while(j < n);
	cout << endl;
}
