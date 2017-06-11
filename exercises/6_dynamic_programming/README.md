**Aluno**: Jonathan Moraes (12/0122553)

**Aluno**: Laura Martins (10/0033440)

**Disciplina**: Estrutura de Dados e Algoritmos 2

**Professor**: Maurício Serrano

**Data**: 12/06/2017

# Lista 6

**1.** Let `G = (V, E)` be an undirected graph with `n` nodes. Recall that a subset of the nodes is called an **independent set** if no two of them are joined by an edge. Finding large independent sets is difficult in general; but here we'll see that it can be done efficiently if the graph is _simple_ enough.

Call a graph `G = (V, E)` a **path** if its nodes can be written as `v1, v2, ..., vn`, with an edge between `vi` and `vj` if and only if the numbers `i` and `j` differ by exactly `1`. With each node `vi`, we associate a positive integer **weight** `wi`.

Consider, for example: `1 - 8 - 6 - 3 - 6`. The goal in this question is to solve the following problem: **Find an independent set in a path `G` whose total weight is as large as possible**.

**a)** Give an example to show that the following algorithm does not always find an independent set of maximum total weight.

```
The "heaviest-first" greedy algorithm
	Start with S equal to the empty set
	While some node remains in G
		Pick a node vi of maximum weight
		Add vi to S
		Delete vi and its neighbors from G
	Endwhile
	Return S
```

* **R**: `G = { 4 - 5 - 4 }`. Algorithm will return `S = { 5 }`, but it should be `S = { 4, 4 }`.

**b)** Give an example to show that the following algorithm also does not always find an independent set of maximum total weight.

```
Let S1 be the set of all vi where i is an odd number
Let S2 be the set of all vi where i is an even number
(Note that S1 and S2 are both independent sets)
Determine which of S1 or S2 has greater total weight, and return this one
```

* **R**: `G = { 6 - 4 - 3 - 7 }`. Algorithm will return `S = { 4, 7 }`, but it should be `S = { 6, 7 }`

**c)** Give an algorithm that takes an `n`-node path `G` with weights and returns an independent set of maximum total weight. The running time should be polynomial in `n`, independent of the values of the weights.

* **R**:
	* **Source**: `q1c.cpp`
	* **Compile**: `make q1c`
	* **Run Question (a) Example**: `./q1c < examples/q1/a.input`
	* **Run Question (b) Example**: `./q1c < examples/q1/b.input`

```C
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
```

-------------

**2.** Suppose you’re managing a consulting team of expert computer hackers, and each week you have to choose a job for them to undertake. Now, as you can well imagine, the set of possible jobs is divided into those that are **low-stress** (e.g., setting up a Web site for a class at the local elementary school) and those that are **high-stress** (e.g., protecting the nation’s most valuable secrets, or helping a desperate group of Cornell students finish a project that has something to do with compilers). The basic question, each week, is whether to take on a low-stress job or a high-stress job.

If you select a low-stress job for your team in week `i`, then you get a revenue of `li > 0` dollars; if you select a high-stress job, you get a revenue of `hi > 0` dollars. The catch, however, is that in order for the team to take on a high-stress job in week `i`, it’s required that they do no job (of either type) in week `i − 1`; they need a full week of prep time to get ready for the crushing stress level. On the other hand, it’s okay for them to take a low-stress job in week `i` even if they have done a job (of either type) in week `i − 1`.

So, given a sequence of `n` weeks, a **plan** is specified by a choice of `low-stress`, `high-stress`, or `none` for each of the `n` weeks, with the property that if `high-stress` is chosen for week `i > 1`, then `none` has to be chosen for week `i − 1`. (It’s okay to choose a high-stress job in week `1`.) The **value** of the plan is determined in the natural way: for each `i`, you add `li` to the value if you choose `low-stress` in week `i`, and you add `hi` to
the value if you choose `high-stress` in week `i`. (You add `0` if you choose `none` in week `i`.)

**The problem**. Given sets of values `l1, l2, ..., ln` and `h1, h2, . .., hn`, find a plan of maximum value. (Such a plan will be called **optimal**.)

**Example**. Suppose `n = 4`, and the values of `li` and `hi` are given by the following table. Then the plan of maximum value would be to choose `none` in week `1`, a high-stress job in week `2`, and low-stress jobs in weeks `3` and `4`. The value of this plan would be `0 + 50 + 10 + 10 = 70`.

||Week 1|Week 2|Week 3|Week 4|
|:-:|:-:|:-:|:-:|:-:|
|l|10|1|10|10|
|h|5|50|5|1|

**a)** Show that the following algorithm does not correctly solve this problem, by giving an instance on which it does not return the correct answer.

```
For iterations i = 1 to n
	If h(i+1) > li + l(i+1) then
		Output "Choose no job in week i"
		Output "Choose a high-stress job in week i+1"
		Continue with iteration i+2
	Else
		Output "Choose a low-stress job in week i"
		Continue with iteration i+1
	Endif
End
```

To avoid problems with overflowing array bounds, we define `hi = li = 0` when `i > n`. In your example, say what the correct answer is and also what the above algorithm finds.

* **R**:

||Week 1|Week 2|Week 3|
|:-:|:-:|:-:|:-:|
|l|2|4|6|
|h|5|10|20|

* Algorithm steps:
```
	i = 1
		if h[2] > l[1] + l[2] : (10 > 2 + 4)
			Week 1 = None : 0
			Week 2 = h[2] : 10
			i += 2
	i = 3
		Week 3 = l[3] : 6
```

* Algorithm total: `Plan = { 0, 10, 6 } : 16`
* Optimal solution: `Plan = { 5, 0, 20 } : 25`

**b)** Give an efficient algorithm that takes values for `l1, l2, ..., ln` and `h1, h2, ..., hn` and returns the value of an optimal plan.

* **R**:
	* **Source**: `q2b.cpp`
	* **Compile**: `make q2b`
	* **Run Question (a) Example**: `./q2b < examples/q2/a.input`
	* **Run All Low Example**: `./q2b < examples/q2/all_low.input`
	* **Run High Example**: `./q2b < examples/q2/high.input`

```C
#include <iostream>
#include <vector>
#include <utility>

#define ui unsigned int
#define NOTHING 0
#define LOW_STRESS_JOB 1
#define HIGH_STRESS_JOB 2

using namespace std;

void get_jobs(vector<pair<ui,ui>> &jobs);
void build_plan(vector<pair<ui,ui>> &jobs,
	vector<pair<ui,ui>> &plan);
void show_plan(vector<pair<ui,ui>> &jobs, vector<pair<ui,ui>> &plan);

int main()
{
	vector<pair<ui,ui>> jobs;
	get_jobs(jobs);

	vector<pair<ui,ui>> plan;
	build_plan(jobs, plan);

	show_plan(jobs, plan);

	return 0;
}

void get_jobs(vector<pair<ui,ui>> &jobs)
{
	ui week = 1;
	do
	{
		pair<ui,ui> week_jobs;
		cout << "Write the low-stress job and the high-stress job ";
		cout << "for the week " << week << "." << endl;
		cout << "End the input with 0." << endl;
		cin >> week_jobs.first >> week_jobs.second;
		if(week_jobs.first and week_jobs.second)
		{
			jobs.push_back(week_jobs);
			++week;
		}
		else
		{
			week = 0;
		}
	} while(week);
}

void build_plan(vector<pair<ui,ui>> &jobs, vector<pair<ui,ui>> &plan)
{
	plan.push_back(make_pair(NOTHING, NOTHING));

	if(jobs.front().first >= jobs.front().second)
	{
		plan.push_back(make_pair(LOW_STRESS_JOB, jobs.front().first));
	}
	else
	{
		plan.push_back(make_pair(HIGH_STRESS_JOB, jobs.front().second));
	}

	for(ui i = 1; i < jobs.size(); ++i)
	{
		ui low_stress_job = jobs[i].first + plan[i].second;
		ui high_stress_job = jobs[i].second + plan[i-1].second;
		if(low_stress_job >= high_stress_job)
		{
			plan.push_back(make_pair(LOW_STRESS_JOB, low_stress_job));
		}
		else
		{
			plan.push_back(make_pair(HIGH_STRESS_JOB, high_stress_job));
		}
	}
}

void show_plan(vector<pair<ui,ui>> &jobs, vector<pair<ui,ui>> &plan)
{
	cout << "-> The Optimal Plan is:" << endl;
	ui week = 1;
	ui previous_revenue = 0;
	ui current_revenue = 0;
	for(ui i = 1; i < plan.size(); ++i)
	{
		pair<ui,ui> week_job = plan[i];
		current_revenue = week_job.second - previous_revenue;
		cout << "On week " << week << " do: ";
		if(i+1 < plan.size() and plan[i+1].first == HIGH_STRESS_JOB
		and ((week_job.first == LOW_STRESS_JOB
			and current_revenue != jobs[i-1].first)
		or (week_job.first == HIGH_STRESS_JOB
			and current_revenue != jobs[i-1].second)))
		{
			cout << "nothing." << endl;
		}
		else if(week_job.first == LOW_STRESS_JOB)
		{
			previous_revenue = week_job.second;
			cout << "The low-stress job with revenue of ";
			cout << current_revenue << " dollars." << endl;
		}
		else
		{
			previous_revenue = week_job.second;
			cout << "The high-stress job with revenue of ";
			cout << current_revenue << " dollars." << endl;
		}
		++week;
	}
	cout << "The total revenue is: " << plan.back().second;
	cout << "." << endl;
}
```

-------------

**6.** In a word processor, the goal of **pretty-printing** is to take text with a ragged right margin, like this:

```
Call me Ishmael.
Some years ago,
never mind how long precisely,
having little or no money in my purse,
and nothing particular to interest me on shore,
I thought I would sail about a little
and see the watery part of the world.
```

And turn it into text whose right margin is as **even** as possible, like this:

```
Call me Ishmael. Some years ago, never
mind how long precisely, having little
or no money in my purse, and nothing
particular to interest me on shore, I
thought I would sail about a little
and see the watery part of the world.
```

To make this precise enough for us to start thinking about how to write a pretty-printer for text, we need to figure out what it means for the right margins to be **even**. So suppose our text consists of a sequence of **words**, `W = {w1, w2, ..., wn}`, where `wi` consists of `ci` characters. We have a maximum line length of `L`. we will assume we have a fixed-width font and ignore issues of punctuation or hyphenation.

A **formatting** of `W` consists of a partition of the words in `W` into lines. In the words assigned to a single line, there should be a space after each word except the last; and so if `wj, w(j+1), ..., wk` are assigned to one line, the we should have:

```
[sum_(i=j)^(k-1) ci+1] + ck <= L
```

We will call an assignment of words to a line **valid** if it satisfies this inequality. The difference between the left-hand side and the right-hand side will be called the **slack** of the line - that is, the number of spaces left at the right margin.

Give an efficient algorithm to find a partition of a set of words `W` into valid lines, so that the sum of the **squares** of the slacks of all lines (including the last line) is minimized.

* **R**:
	* **Source**: `q6.cpp`
	* **Compile**: `make q6`
	* **Run Book Example**: `./q6 < examples/q6/book.input`
	* **Run Book Example With Line Length = 16**: `./q6 < examples/q6/book16.input`
	* **Run Book Example With Line Length = 64**: `./q6 < examples/q6/book64.input`
	* **Run Perfect Match Example**: `./q6 < examples/q6/result0.input`

```C
#include <iostream>
#include <string>
#include <vector>
#include <climits>

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
```

-------------

**7.** As a solved exercise in Chapter 5, we gave an algorithm with `O(n log n)` running time for the following problem. We're looking at the price of a given stock over `n` consecutive days, numbered `i = 1, 2, ..., n`. For each day `i`, we have a price `p(i)` per share for the stock on that day. (We'll assume for simplicity that the price was fixed during each day.) We'd like to know: How should we choose a day `i` on which to buy the stock and a later day `j > i` on which to sell it, if we want to maximize the profit per share, `p(j) - p(i)`? (If there is no way to make money during the `n` days, we should conclude this instead.)

In the solved exercise, we showed how to find the optimal pair of days `i` and `j` in time `O(n log n)`. But, in fact, it's possible to do better than this. Show how to find the optimal numbers `i` and `j` in time `O(n)`.

* **R**:
	* **Source**: `q7.cpp`
	* **Compile**: `make q7`

```C
```


**9.** You’re helping to run a high-performance computing system capable of processing several terabytes of data per day. For each of `n` days, you’re presented with a quantity of data; on day `i`, you’re presented with `xi` terabytes. For each terabyte you process, you receive a fixed revenue, but any unprocessed data becomes unavailable at the end of the day (i.e., you can’t work on it in any future day).

You can’t always process everything each day because you’re constrained by the capabilities of your computing system, which can only process a fixed number of terabytes in a given day. In fact, it’s running some one-of-a-kind software that, while very sophisticated, is not totally reliable, and so the amount of data you can process goes down with each day that passes since the most recent reboot of the system. On the first day after a reboot, you can process `s1` terabytes, on the second day after a reboot, you can process `s2` terabytes, and so on, up to `sn`; we assume `s1 > s2 > s3 > ... > sn > 0`. (Of course, on day `i` you can only process up to `xi` terabytes, regardless of how fast your system is.) To get the system back to peak performance, you can choose to reboot it; but on any day you choose to reboot the system, you can’t process any data at all.

**The problem**. Given the amounts of available data `x1, x2, ..., xn` for the next `n` days, and given the profile of your system as expressed by `s1, s2, ..., sn` (and starting from a freshly rebooted system on day `1`), choose the days on which you’re going to reboot so as to maximize the total amount of data you process.

**Example**. Suppose `n = 4`, and th evalues of `xi` and `si` are given by the following table.

||Day 1|Day 2|Day 3|Day 4|
|:-:|:-:|:-:|:-:|:-:|
|x|10|1|7|7|
|s|8|4|2|1|

The best solution would be to reboot on day `2` only; this way, you process `8` terabytes on day `1`, then `0` on day `2`, then `7` on day `3`, then `4` on day `4`, for a total of `19`. (Note that if you didn’t reboot at all, you’d process `8 + 1 + 2 + 1 = 12`; and other rebooting strategies give you less than `19` as well.)

**a)** Give an example of an instance with the following properties.

* There is a **surplus** of data in the sense that `xi > s1` for every `i`.

* The optimal solution reboots the system at least twice.

In addition to the example, you should say what the optimal solution
is. You do not need to provide a proof that it is optimal.

* **R**:

||Day 1|Day 2|Day 3|Day 4|Day 5|Day 6|Day 7|Day 8|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|x|20|10|5|10|20|20|20|20|
|s|15|10|6|5|4|3|2|1|
|r|15|10|5|0|15|0|15|10|

**Total**: 70

**a)** Give an efficient algorithm that takes values for `x1, x2, ..., xn` and `s1, s2, ..., sn` and returns the total number of terabytes processed by an optimal solution.

* **R**:
	* **Source**: `q9.cpp`
	* **Compile**: `make q9`
	* **Run Book Example**: `./q9 < examples/q9/book.input`
	* **Run Question (a) Example**: `./q9 < examples/q9/a.input`
	* **Run Equals Example**: `./q9 < examples/q9/equals.input`
	* **Run Mirror Example**: `./q9 < examples/q9/mirror.input`

```C
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
```

-------------
