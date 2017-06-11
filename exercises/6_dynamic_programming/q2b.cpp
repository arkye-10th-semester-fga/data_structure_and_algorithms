#include <iostream>
#include <vector>
#include <utility>

#define ui unsigned int
#define NOTHING 0
#define LOW_STRESS_JOB 1
#define HIGH_STRESS_JOB 2

using namespace std;

void get_jobs(vector<pair<ui,ui>> &jobs);
void build_plan(vector<pair<ui,ui>> &jobs, vector<pair<ui,ui>> &plan);
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
	cout << "The total revenue is: " << plan.back().second << "." << endl;
}
