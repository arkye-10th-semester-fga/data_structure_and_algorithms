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
		* **Run Book Example**: `./q4 < book_examples/q4.input`

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
	```C
	printf("-");
	```
1. The wildly popular Spanish-language search engine El Goog needs to do a serious amount of computation every time it recompiles its index. Fortunately, the company has at its disposal a single large supercomputer, together with an essentially unlimited supply of high-end PCs. They’ve broken the overall computation into **n** distinct jobs, labeled `J1, J2,..., Jn`, which can be performed completely independently of one another. Each job consists of two stages: first it needs to be preprocessed on the supercomputer, and then it needs to be finished on one of the PCs. Let’s say that job **Ji** needs **pi** seconds of time on the supercomputer, followed by **fi** seconds of time on a PC. Since there are at least **n** PCs available on the premises, the finishing of the jobs can be performed fully in parallel—all the jobs can be processed at the same time. However, the supercomputer can only work on a single job at a time, so the system managers need to work out an order in which to feed the jobs to the supercomputer. As soon as the first job in order is done on the supercomputer, it can be handed off to a PC for finishing; at that point in time a second job can be fed to the supercomputer; when the second job is done on the supercomputer, it can proceed to a PC regardless of whether or not the first job is done (since the PCs work in parallel); and so on. Let’s say that a schedule is an ordering of the jobs for the supercomputer, and the completion time of the schedule is the earliest time at which all jobs will have finished processing on the PCs. This is an important quantity to minimize, since it determines how rapidly El Goog can generate a new index. Give a polynomial-time algorithm that finds a schedule with as small a completion time as possible.
	* **R**:
	```C
	printf("-");
	```
1. Suppose you have **n** video streams that need to be sent, one after another, over a communication link. Stream **i** consists of a total of **bi** bits that need to be sent, at a constant rate, over a period of **ti** seconds. You cannot send two streams at the same time, so you need to determine a schedule for the streams: an order in which to send them. Whichever order you choose, there cannot be any delays between the end of one stream and the start of the next. Suppose your schedule starts at time 0. We assume that all the values **bi** and **ti** are positive integers. Now, because you’re just one user, the link does not want you taking up too much bandwidth, so it imposes the following constraint, using a fixed parameter **r**: `(∗) For each natural number t > 0, the total number of bits you send over the time interval from 0 to t cannot exceed rt`. Note that this constraint is only imposed for time intervals that start at 0, not for time intervals that start at any other value. We say that a schedule is valid if it satisfies the constraint **(∗)** imposed by the link. **The Problem**: Given a set of **n** streams, each specified by its number of bits **bi** and its time duration **ti**, as well as the link parameter **r**, determine whether there exists a valid schedule. **Example**: Suppose we have `n = 3` streams, with `(b1, t1) = (2000, 1), (b2, t2) = (6000, 2), (b3, t3) = (2000, 1)`, and suppose the link’s parameter is `r = 5000`. Then the schedule that runs the streams in the order `1, 2, 3`, is valid, since the constraint **(∗)** is satisfied - `t = 1`: the whole first stream has been sent, and `2000 < 5000 · 1`; `t = 2`: half of the second stream has also been sent, and `2000 + 3000 < 5000 · 2`; Similar calculations hold for `t = 3` and `t = 4`.
	1. Consider the following claim - **Claim**: There exists a valid schedule if and only if each stream **i** satisfies `bi ≤ rti`. Decide whether you think the claim is true or false, and give a proof of either the claim or its negation.
		* **R**:
	1. Give an algorithm that takes a set of **n** streams, each specified by its number of bits **bi** and its time duration **ti**, as well as the link parameter **r**, and determines whether there exists a valid schedule. The running time of your algorithm should be polynomial in `n`.
		* **R**:
		```C
		printf("-");
		```
1. A small business—say, a photocopying service with a single large machine—faces the following scheduling problem. Each morning they get a set of jobs from customers. They want to do the jobs on their single machine in an order that keeps their customers happiest. Customer **i’s** job will take **ti** time to complete. Given a schedule (i.e., an ordering of the jobs), let **Ci** denote the finishing time of job **i**. For example, if job **j** is the first to be done, we would have `Cj = tj`; and if job **j** is done right after job **i**, we would have `Cj = Ci + tj`. Each customer **i** also has a given weight **wi** that represents his or her importance to the business. The happiness of customer **i** is expected to be dependent on the finishing time of **i’s** job. So the company decides that they want to order the jobs to minimize the _weighted sum_ of the completion times. Design an efficient algorithm to solve this problem. That is, you are given a set of **n** jobs with a processing time **ti** and a weight **wi** for each job. You want to order the jobs so as to minimize the _weighted sum_ of the completion times. **Example**: Suppose there are two jobs - the first takes time `t1 = 1` and has weight `w1 = 10`, while the second job takes time `t2 = 3` and has weight `w2 = 2`. Then doing job **1** first would yield a weighted completion time of `10 · 1 + 2 · 4 = 18`, while doing the second job first would yield the larger weighted completion time of `10 · 4 + 2 · 3 = 46`
	* **R**:
	```C
	printf("-");
	```
1. The manager of a large student union on campus comes to you with the following problem. She’s in charge of a group of **n** students, each of whom is scheduled to work one shift during the week. There are different jobs associated with these shifts (tending the main desk, helping with package delivery, rebooting cranky information kiosks, etc.), but we can view each shift as a single contiguous interval of time. There can be multiple shifts going on at once. She’s trying to choose a subset of these **n** students to form a supervising committee that she can meet with once a week. She considers such a committee to be complete if, for every student not on the committee, that student’s shift overlaps (at least partially) the shift of some student who is on the committee. In this way, each student’s performance can be observed by at least one person who’s serving on the committee. Give an efficient algorithm that takes the schedule of **n** shifts and produces a complete supervising committee containing as few students as possible. **Example**: Suppose `n = 3`, and the shifts are `Monday 4 P.M.–Monday 8 P.M., Monday 6 P.M.–Monday 10 P.M., Monday 9 P.M.–Monday 11 P.M.`. Then the smallest complete supervising committee would consist of just the second student, since the second shift overlaps both the first and the third.
	* **R**:
	```C
	printf("-");
	```
