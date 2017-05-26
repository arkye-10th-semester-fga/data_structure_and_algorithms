**Aluno**: Jonathan Moraes (12/0122553)

**Aluno**: <Laura>

**Disciplina**: Estrutura de Dados e Algoritmos 2

**Professor**: Maurício Serrano

**Data**: 22/05/2017

# Lista 4

1. Some of your friends have gotten into the burgeoning field of time-series data mining, in which one looks for patterns in sequences of events that occur over time. Purchases at stock exchanges — what’s being bought — are one source of data with a natural ordering in time. Given a long sequence **S** of such events, your friends want an efficient way to detect certain “patterns” in them — for example, they may want to know if the four events `buy Yahoo, buy eBay, buy Yahoo, buy Oracle` occur in this sequence **S**, in order but not necessarily consecutively. They begin with a collection of possible events (e.g., the possible transactions) and a sequence **S** of **n** of these events. A given event may occur multiple times in **S** (e.g., Yahoo stock may be bought many times in a single sequence **S**). We will say that a sequence **S'** is a subsequence of **S** if there is a way to delete certain of the events from **S** so that the remaining events, in order, are equal to the sequence **S'**. So, for example, the sequence of four events above is a subsequence of the sequence `buy Amazon, buy Yahoo, buy eBay, buy Yahoo, buy Yahoo, buy Oracle`. Their goal is to be able to dream up short sequences and quickly detect whether they are subsequences of **S**. So this is the problem they pose to you: Give an algorithm that takes two sequences of events — **S'** of length **m** and **S** of length **n**, each possibly containing an event more than once — and decides in time `O(m + n)` whether **S'** is a subsequence of **S**.
	* **R**:
		* **Source**: `q4.cpp`
		* **Compile**: `make q4`
		* **Run Book Example**: `./q4 < examples/q4/book.input`

	```C
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
	```
1. Let’s consider a long, quiet country road with houses scattered very sparsely along it. (We can picture the road as a long line segment, with an eastern endpoint and a western endpoint.) Further, let’s suppose that despite the bucolic setting, the residents of all these houses are avid cell phone users. You want to place cell phone base stations at certain points along the road, so that every house is within four miles of one of the base stations. Give an efficient algorithm that achieves this goal, using as few base stations as possible.
	* **R**:
		* **Source**: `q5.c`
		* **Compile**: `make q5`
	```C
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <time.h>

	#define TOWER_RADIUS 4
	#define TOWER_DIAMETER 8

	int main() {
	    int *torres_local,
	        *estrada,
	        tamanho,
	        torres=0,
	        i=0;

	    srand ( time(NULL) );

	    printf("Insira o tamanho da estrada:\n");
	    if(scanf("%d", &tamanho) == 1)
	    {
	      torres_local =
	        malloc(tamanho/TOWER_DIAMETER * (sizeof(int)));
	      estrada =
	        malloc(tamanho * (sizeof(int)));

	      for (i = 0; i < tamanho; i++)
	        estrada[i] = rand() % 2;

	      printf("\nEstrada preenchida randomicamente: ");
	      printf("0 = km vazio, 1 = casa\n\n");

	      for (i = 0; i < tamanho; i++)
	        printf("[%d]", estrada[i]);

	      printf("\n");

	      i=0;

	      while(i < tamanho) {
	        if(estrada[i] == 1) {
	          if(i + TOWER_RADIUS < tamanho)
	            torres_local[torres] = i+TOWER_RADIUS;
	          else
	            torres_local[torres] = tamanho;
	          torres++;
	          i = i + TOWER_DIAMETER;
	        }
	        else
	          i++;
	      }

	      if(torres == 1) {
	        printf("\n1 torre alocada no quilometro %d\n",
	          torres_local[0]);
	      }
	      else {
	        printf("\n%d torres alocadas nos quilometros \n",
	          torres);
	        printf("%d", torres_local[0]);
	        for(i = 1; i < torres; i++)
	          printf(", %d", torres_local[i]);
	        printf("\n");
	      }
	    }
	}
	```
1. The wildly popular Spanish-language search engine El Goog needs to do a serious amount of computation every time it recompiles its index. Fortunately, the company has at its disposal a single large supercomputer, together with an essentially unlimited supply of high-end PCs. They’ve broken the overall computation into **n** distinct jobs, labeled `J1, J2,..., Jn`, which can be performed completely independently of one another. Each job consists of two stages: first it needs to be preprocessed on the supercomputer, and then it needs to be finished on one of the PCs. Let’s say that job **Ji** needs **pi** seconds of time on the supercomputer, followed by **fi** seconds of time on a PC. Since there are at least **n** PCs available on the premises, the finishing of the jobs can be performed fully in parallel—all the jobs can be processed at the same time. However, the supercomputer can only work on a single job at a time, so the system managers need to work out an order in which to feed the jobs to the supercomputer. As soon as the first job in order is done on the supercomputer, it can be handed off to a PC for finishing; at that point in time a second job can be fed to the supercomputer; when the second job is done on the supercomputer, it can proceed to a PC regardless of whether or not the first job is done (since the PCs work in parallel); and so on. Let’s say that a schedule is an ordering of the jobs for the supercomputer, and the completion time of the schedule is the earliest time at which all jobs will have finished processing on the PCs. This is an important quantity to minimize, since it determines how rapidly El Goog can generate a new index. Give a polynomial-time algorithm that finds a schedule with as small a completion time as possible.
	* **R**:
		* **Source**: `q7.cpp`
		* **Compile**: `make q7`
		* **Run First Example**: `./q7 < examples/q7/1.input`
		* **Run Second Example**: `./q7 < examples/q7/2.input`

	```C
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
	```
1. A small business—say, a photocopying service with a single large machine—faces the following scheduling problem. Each morning they get a set of jobs from customers. They want to do the jobs on their single machine in an order that keeps their customers happiest. Customer **i’s** job will take **ti** time to complete. Given a schedule (i.e., an ordering of the jobs), let **Ci** denote the finishing time of job **i**. For example, if job **j** is the first to be done, we would have `Cj = tj`; and if job **j** is done right after job **i**, we would have `Cj = Ci + tj`. Each customer **i** also has a given weight **wi** that represents his or her importance to the business. The happiness of customer **i** is expected to be dependent on the finishing time of **i’s** job. So the company decides that they want to order the jobs to minimize the _weighted sum_ of the completion times. Design an efficient algorithm to solve this problem. That is, you are given a set of **n** jobs with a processing time **ti** and a weight **wi** for each job. You want to order the jobs so as to minimize the _weighted sum_ of the completion times. **Example**: Suppose there are two jobs - the first takes time `t1 = 1` and has weight `w1 = 10`, while the second job takes time `t2 = 3` and has weight `w2 = 2`. Then doing job **1** first would yield a weighted completion time of `10 · 1 + 2 · 4 = 18`, while doing the second job first would yield the larger weighted completion time of `10 · 4 + 2 · 3 = 46`
* **R**:
	* **Source**: `q5.c`
	* **Compile**: `make q5`
	```C
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include <time.h>

	#define MAX 100
	#define N 10


	typedef struct _jobs{
		int ttf; //time to finish
		int priority;
		int id;
	}Jobs;


	Jobs *init_jobs(){
		Jobs *jobs;
		jobs = (Jobs *) malloc(N * sizeof(Jobs));
		return jobs;
	}

	void pop_jobs(Jobs * j){
		int i;
		srand(time(0));
		for(i=0; i<N; i++){
			j[i].ttf = rand() % MAX+1;
			j[i].priority = rand() % MAX+1;
			j[i].id = i+1;
	    }
	}

	void print_jobs(Jobs * j){
	    int i;
	    for(i=0; i<N; i++)
	        printf("Job: %d\n ttf: %d\n priority: %d\n---------------\n", j[i].id, j[i].ttf, j[i].priority);
	}

	void print_job(Jobs * j, int i){
	    printf("Job: %d\n ttf: %d\n priority: %d\n---------------\n", j[i].id, j[i].ttf, j[i].priority);
	}

	void greedy_jobs(Jobs * j){
	    int i;
	    int size = N;
	    int index = 0;
	    double biggest = -1;

	    while(size > 0){
	        for(i=0; i<size; i++){
	            if ((double)j[i].priority/j[i].ttf > biggest){
	                index = i;
	                biggest = (double)j[i].priority/j[i].ttf;
	            }
	        }
	        print_job(j, index);
	        remove_from_jobs_list(j, index, size);
	        biggest = -1;
	        size --;
	    }
	}

	void remove_from_jobs_list(Jobs * j, int i, int n){
	    j[i]=j[n-1];
	}

	int main(){
	    Jobs *jobs = init_jobs();
	    pop_jobs(jobs);
	    printf("Original jobs list:\n\n");
	    print_jobs(jobs);
	    printf("\nOptimal Solution:\n\n");
	    greedy_jobs(jobs);



	    return 0;
	}
	```
1. The manager of a large student union on campus comes to you with the following problem. She’s in charge of a group of **n** students, each of whom is scheduled to work one shift during the week. There are different jobs associated with these shifts (tending the main desk, helping with package delivery, rebooting cranky information kiosks, etc.), but we can view each shift as a single contiguous interval of time. There can be multiple shifts going on at once. She’s trying to choose a subset of these **n** students to form a supervising committee that she can meet with once a week. She considers such a committee to be complete if, for every student not on the committee, that student’s shift overlaps (at least partially) the shift of some student who is on the committee. In this way, each student’s performance can be observed by at least one person who’s serving on the committee. Give an efficient algorithm that takes the schedule of **n** shifts and produces a complete supervising committee containing as few students as possible. **Example**: Suppose `n = 3`, and the shifts are `Monday 4 P.M.–Monday 8 P.M., Monday 6 P.M.–Monday 10 P.M., Monday 9 P.M.–Monday 11 P.M.`. Then the smallest complete supervising committee would consist of just the second student, since the second shift overlaps both the first and the third.
	* **R**:
		* **Source**: `q15.cpp`
		* **Compile**: `make q15`
		* **Run Book Example**: `./q15 < examples/q15/book.input`
		* **Run First Example**: `./q15 < examples/q15/1.input`
		* **Run Second Example**: `./q15 < examples/q15/2.input`
	```C
	#include <iostream>
	#include <vector>

	using namespace std;

	class student
	{
	public:
		unsigned int id;

		unsigned int begin_hours;
		unsigned int end_hours;

		bool is_marked;

		student(unsigned int sid, string bwd, unsigned int bwh,
			bool bhia, string ewd, unsigned int ewh, bool ehia) :
			id(sid),
			begin_week_day(bwd),
			begin_week_hours(bwh),
			begin_hours_is_am(bhia),
			end_week_day(ewd),
			end_week_hours(ewh),
			end_hours_is_am(ehia)
		{
			begin_hours = get_week_as_hours(false)
				+ get_hours_format_24(false);
			end_hours = get_week_as_hours(true)
				+ get_hours_format_24(true);
			is_marked = false;
		}

		student() {}

		void print_shift()
		{
			cout << "Student #" << id << ": ";
			cout << begin_week_day << " ";
			cout << begin_week_hours << " ";
			cout << get_string_am_or_pm(begin_hours_is_am) << " ";
			cout << end_week_day << " ";
			cout << end_week_hours << " ";
			cout << get_string_am_or_pm(end_hours_is_am) << endl;
		}

	private:
		string begin_week_day;
		unsigned int begin_week_hours;
		bool begin_hours_is_am;

		string end_week_day;
		unsigned int end_week_hours;
		bool end_hours_is_am;

		unsigned int get_week_as_hours(bool from_end)
		{
			string week_days[7] = { "Sunday", "Monday", "Tuesday",
				"Wednesday", "Thursday", "Friday", "Saturday" };
			string week_day;
			if(from_end)
			{
				week_day = end_week_day;
			}
			else
			{
				week_day = begin_week_day;
			}
			unsigned int week_as_hours = 24;
			bool is_week_found = false;
			for(unsigned int i = 0; !is_week_found && i < 7; ++i)
			{
				if(week_day == week_days[i])
				{
					week_as_hours *= i;
					is_week_found = true;
				}
			}
			return week_as_hours;
		}

		unsigned int get_hours_format_24(bool from_end)
		{
			unsigned int hours;
			bool is_am;
			if(!from_end)
			{
				hours = begin_week_hours;
				is_am = begin_hours_is_am;
			}
			else
			{
				hours = end_week_hours;
				is_am = end_hours_is_am;
			}
			return is_am ? hours : hours + 12;
		}

		string get_string_am_or_pm(bool is_am)
		{
			return is_am ? "AM" : "PM";
		}
	};

	void create_shifts(vector<student> &shifts);
	void create_supervising_committee(vector<student> &shifts,
		vector<student> &committee);
	void show_committee(vector<student> &committee);
	bool intersects(student s1, student s2);
	student get_earliest_end_time_student(vector<student> &shifts);
	student get_latest_end_time_student(vector<student> &shifts,
		student earliest_end_time_student);
	unsigned int mark_all_intersected_students(vector<student> &shifts,
		student latest_end_time_student);

	int main()
	{
		vector<student> shifts;
		create_shifts(shifts);

		vector<student> committee;
		create_supervising_committee(shifts, committee);

		show_committee(committee);

		return 0;
	}

	void create_shifts(vector<student> &shifts)
	{
		const string END_OF_INPUT = "0";
		const string AM = "AM";

		cout << "Inform each student shift. End the input with a 0." << endl;

		unsigned int id = 0;
		bool has_finished = false;

		while(!has_finished)
		{
			string begin_week_day;
			unsigned int begin_week_hours;
			string begin_am_or_pm;

			string end_week_day;
			unsigned int end_week_hours;
			string end_am_or_pm;

			cin >> begin_week_day;
			if(begin_week_day != END_OF_INPUT)
			{
				cin >> begin_week_hours
				>> begin_am_or_pm
				>> end_week_day
				>> end_week_hours
				>> end_am_or_pm;

				++id;

				bool begin_hours_is_am = false;
				if(begin_am_or_pm == AM)
				{
					begin_hours_is_am = true;
				}

				bool end_hours_is_am = false;
				if(end_am_or_pm == AM)
				{
					end_hours_is_am = true;
				}

				shifts.push_back(student(id, begin_week_day,
					begin_week_hours, begin_hours_is_am, end_week_day,
					end_week_hours, end_hours_is_am));
			}
			else
			{
				has_finished = true;
			}
		}
	}

	void create_supervising_committee(vector<student> &shifts,
		vector<student> &committee)
	{
		unsigned int marks = 0;
		while(marks < shifts.size())
		{
			student earliest_end_time_student =
				get_earliest_end_time_student(shifts);

			student latest_end_time_student =
				get_latest_end_time_student(shifts, earliest_end_time_student);

			marks += mark_all_intersected_students(shifts, latest_end_time_student);

			committee.push_back(latest_end_time_student);
		}
	}

	void show_committee(vector<student> &committee)
	{
		for(student s : committee)
		{
			s.print_shift();
		}
	}

	bool intersects(student s1, student s2)
	{
		return (s1.begin_hours >= s2.begin_hours &&
			s1.begin_hours <= s2.end_hours) ||
			(s1.end_hours <= s2.end_hours &&
			s1.end_hours >= s2.begin_hours);
	}

	student get_earliest_end_time_student(vector<student> &shifts)
	{
		unsigned int earliest_end_time_student_index = 0;
		unsigned int earliest_end_time = 169;
		for(student s : shifts)
		{
			if(!s.is_marked)
			{
				if(earliest_end_time > s.end_hours)
				{
					earliest_end_time_student_index = s.id-1;
					earliest_end_time = s.end_hours;
				}
			}
		}
		return shifts.at(earliest_end_time_student_index);
	}

	student get_latest_end_time_student(vector<student> &shifts,
		student earliest_end_time_student)
	{
		unsigned int latest_end_time_student_index = 0;
		unsigned int latest_end_time = 0;
		for(student s : shifts)
		{
			if(intersects(s, earliest_end_time_student))
			{
				if(latest_end_time < s.end_hours)
				{
					latest_end_time_student_index = s.id-1;
					latest_end_time = s.end_hours;
				}
			}
		}
		return shifts.at(latest_end_time_student_index);
	}

	unsigned int mark_all_intersected_students(vector<student> &shifts,
		student latest_end_time_student)
	{
		unsigned int marks = 0;
		for(student s : shifts)
		{
			if(intersects(s, latest_end_time_student))
			{
				if(!s.is_marked)
				{
					++marks;
					shifts[s.id-1].is_marked = true;
				}
			}
		}
		return marks;
	}
	```
