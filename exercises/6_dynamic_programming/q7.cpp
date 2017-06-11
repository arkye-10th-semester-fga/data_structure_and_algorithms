#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void get_prices(vector<int> &prices);
int find_days_and_maximum_profit(vector<int> &prices, pair<int,int> &days);

int main()
{
	vector<int> prices;
	get_prices(prices);

	pair<int,int> days;
	int profit = find_days_and_maximum_profit(prices, days);

	if(days.first and days.second)
	{
		cout << "The best day to buy the stock is: " << days.first << endl;
		cout << "The best day to sell the stock is: " << days.second << endl;
		cout << "Maximum profit: " << profit << endl;
	}
	else
	{
		cout << "It is impossible to profit with this stock." << endl;
	}

	return 0;
}

void get_prices(vector<int> &prices)
{
	const int INFINITY = 1000000;
	prices.push_back(INFINITY);
	cout << "Write the price of the stock for each day." << endl;
	cout << "End the input with 0." << endl;
	int price;
	while(cin >> price && price)
	{
		prices.push_back(price);
	}
}

int find_days_and_maximum_profit(vector<int> &prices, pair<int,int> &days)
{
	days.first = 0;
	days.second = 0;

	vector<int> profits;
	profits.push_back(0);

	int maximum_profit = 0;
	int minimum_price = prices[0];
	int quantity_of_prices = prices.size();
	for(int i = 1; i < quantity_of_prices; ++i)
	{
		int previous_price = prices[i-1];
		int price = prices[i];

		int previous_profit = profits[i-1];
		int profit = previous_profit + (price - previous_price);

		if(profit > 0)
		{
			profits.push_back(profit);
			if(profit > maximum_profit)
			{
				days.second = i;
				maximum_profit = profit;
			}
		}
		else
		{
			profits.push_back(0);
			if(price < minimum_price)
			{
				minimum_price = price;
				days.first = i;
			}
		}
	}

	return maximum_profit;
}
