#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class job
{
public:
	double p; // Time on the supercomputer
	double f; // Time on a PC
	job(double pi, double fi) : p(pi), f(fi) {}
};

void create_jobs(vector<job> &jobs);
void inform_completion_time(vector<job> &jobs, string name);
void create_optimal_schedule(vector<job> &jobs);

int main()
{
	vector<job> jobs;
	create_jobs(jobs);
	inform_completion_time(jobs, "Current");

	create_optimal_schedule(jobs);
	inform_completion_time(jobs, "Optimal");

	return 0;
}

void create_jobs(vector<job> &jobs)
{
	cout << "Inform each job time on the supercomputer (p) ";
	cout << "and time on a PC (f)" << endl;
	double pi, fi;
	while(cin >> pi >> fi)
	{
		jobs.push_back(job(pi, fi));
	}
}

void inform_completion_time(vector<job> &jobs, string name)
{
	double time_on_supercomputer = 0.0;
	double completion_time = 0.0;
	cout << endl << name << " schedule:" << endl;
	for(job j : jobs)
	{
		cout << "> p: " << j.p << "; f:" << j.f << endl;
		time_on_supercomputer += j.p;
		double local_completion_time = time_on_supercomputer + j.f;
		if(completion_time < local_completion_time)
		{
			completion_time = local_completion_time;
		}
	}
	cout << name << " completion time is: " << completion_time << endl;
}

void create_optimal_schedule(vector<job> &jobs)
{
	for(unsigned int i = 0; i < jobs.size()-1; ++i)
	{
		unsigned int greater_f_index = 0;
		double greater_f = 0;
		for(unsigned int j = i; j < jobs.size(); ++j)
		{
			if(greater_f < jobs.at(j).f)
			{
				greater_f = jobs.at(j).f;
				greater_f_index = j;
			}
		}
		swap(jobs[i], jobs[greater_f_index]);
	}
}
