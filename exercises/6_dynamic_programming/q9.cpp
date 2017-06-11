#include <iostream>
#include <vector>

#define ui unsigned int

using namespace std;

void get_available_data(vector<ui> &X);
void get_computer_performance(vector<ui> &S);
ui get_number_of_terabytes_processed(vector<ui> &X, vector<ui> &S);

int main()
{
	vector<ui> X;
	get_available_data(X);

	vector<ui> S;
	get_computer_performance(S);

	ui opt = get_number_of_terabytes_processed(X, S);

	cout << "Number of Terabytes Processed: " << opt << endl;

	return 0;
}

void get_available_data(vector<ui> &X)
{
	X.push_back(0);
	cout << "Write the size of each data to be processed." << endl;
	cout << "End the input with 0." << endl;
	ui x;
	while(cin >> x && x)
	{
		X.push_back(x);
	}
}

void get_computer_performance(vector<ui> &S)
{
	S.push_back(0);
	cout << "Write the computer performance." << endl;
	cout << "End the input with 0." << endl;
	ui s;
	while(cin >> s && s)
	{
		S.push_back(s);
	}
}

ui get_number_of_terabytes_processed(vector<ui> &X, vector<ui> &S)
{
	ui n = X.size()-1;
	ui opt[n+1][n+1];
	for(ui j = 1; j <= n; ++j)
	{
		opt[n][j] = min(X[n], S[j]);
	}

	for(ui i = (n-1); i >= 1; --i)
	{
		for(ui j = 1; j <= i; ++j)
		{
			opt[i][j] = max(opt[i+1][1], min(X[i], S[j]) + opt[i+1][j+1]);
		}
	}

	return opt[1][1];
}
