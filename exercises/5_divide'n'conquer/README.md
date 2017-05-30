**Aluno**: Jonathan Moraes (12/0122553)

**Aluno**: Laura Martins (10/0033440)

**Disciplina**: Estrutura de Dados e Algoritmos 2

**Professor**: Maurício Serrano

**Data**: 29/05/2017

# Lista 5
**Escolher 4 exercícios**

1. You are interested in analyzing some hard-to-obtain data from two separate databases. Each database contains **n** numerical values — so there are **2n** values total — and you may assume that no two values are the same. You’d like to determine the **median** of this set of **2n** values, which we will define here to be the **nth** smallest value. However, the only way you can access these values is through queries to the databases. In a single query, you can specify a value **k** to one of the two databases, and the chosen database will return the **kth** smallest value that it contains. Since queries are expensive, you would like to compute the median using as **few** queries as possible. Give an algorithm that finds the **median** value using at most `O(log n)` queries.
	* **R**:
		* **Source**: `q1.c`
		* **Compile**: `make q1`

	```C
	Laura
	```
1. Recall the problem of finding the number of inversions. As in the text, we are given a sequence of **n** numbers `a1, . . . , an`, which we assume are all distinct, and we define an inversion to be a pair `i < j` such that `ai > aj`. We motivated the problem of counting inversions as a good measure of how different two orderings are. However, one might feel that this measure is too sensitive. Let’s call a pair a significant inversion if `i < j` and `ai > 2aj`. Give an `O(n log n)` algorithm to count the number of significant inversions between two orderings.
	* **R**:
		* **Source**: `q2.cpp`
		* **Compile**: `make q2`
		* **Run No Inversion Example**: `./q2 < examples/q2/no_inversion.input`
			* Since `5 < 3*2` and `5 < 4*2`, there are no inversions.
		* **Run One Inversion First Example**: `./q2 < examples/q2/one_inversion.input`
			* Since `7 > 3*2` and `7 < 4*2`, there is only one inversion.
		* **Run One Inversion Second Example**: `./q2 < examples/q2/one_inversion_2.input`
			* Since `8 > 3*2` and `8 == 4*2`, there is only one inversion.
		* **Run Two Inversions Example**: `./q2 < examples/q2/two_inversions.input`
			* Since `9 > 3*2` and `9 < 4*2`, there are two inversions.

	```C
	#include <iostream>
	#include <vector>

	using namespace std;

	#define ui unsigned int

	void create_sequence(vector<ui> &sequence);
	ui sort_and_count(vector<ui> &sequence, vector<ui>::iterator start,
		vector<ui>::iterator finish);
	ui merge_and_count(vector<ui>::iterator start, vector<ui>::iterator mid,
		vector<ui>::iterator finish);

	int main()
	{
		vector<ui> sequence;
		create_sequence(sequence);

		ui count = sort_and_count(sequence, begin(sequence), end(sequence));

		cout << "Quantity of significant inversions: " << count << "." << endl;
		cout << "Sorted List Based on Inversion Criteria:" << endl << "\t";
		for(ui element : sequence)
		{
			cout << "[" << element << "]";
		}
		cout << endl;

		return 0;
	}

	void create_sequence(vector<ui> &sequence)
	{
		const ui END_OF_INPUT = 0;
		cout << "Insert a list of unique numbers." << endl;
		cout << "End the insertion with " << END_OF_INPUT  << "." << endl;
		bool creation_is_done = false;
		while(!creation_is_done)
		{
			ui number = 0;
			cin >> number;
			if(number != END_OF_INPUT)
			{
				sequence.push_back(number);
			}
			else
			{
				creation_is_done = true;
			}
		}
	}

	ui sort_and_count(vector<ui> &sequence, vector<ui>::iterator start,
		vector<ui>::iterator finish)
	{
		ui count = 0;
		size_t length = distance(start, finish);
		if(length > 1)
		{
			size_t middle = length/2;
			vector<ui>::iterator mid = next(start, middle);
			count += sort_and_count(sequence, start, mid);
			count += sort_and_count(sequence, mid, finish);
			count += merge_and_count(start, mid, finish);
		}
		return count;
	}

	ui merge_and_count(vector<ui>::iterator start, vector<ui>::iterator mid,
		vector<ui>::iterator finish)
	{
		ui count = 0;
		vector<ui> work_vector(start,finish);

		vector<ui>::iterator work_start = begin(work_vector);
		vector<ui>::iterator work_finish = end(work_vector);
		vector<ui>::iterator work_mid = next(work_start, distance(start, mid));

		vector<ui>::iterator left = work_start;
		vector<ui>::iterator right = work_mid;
		vector<ui>::iterator index = start;

		while(left < work_mid && right < work_finish)
		{
			if(*left <= *right * 2)
			{
				*index = move(*left++);
			}
			else
			{
				*index = move(*right++);
				count += distance(left, work_mid);
			}
			++index;
		}

		while(left < work_mid)
		{
			*index = move(*left++);
			++index;
		}

		while(right < work_finish)
		{
			*index = move(*right++);
			++index;
		}

		return count;
	}
	```
1. Suppose you’re consulting for a bank that’s concerned about fraud detection, and they come to you with the following problem. They have a collection of **n** bank cards that they’ve confiscated, suspecting them of being used in fraud. Each bank card is a small plastic object, containing a magnetic stripe with some encrypted data, and it corresponds to a unique account in the bank. Each account can have many bank cards corresponding to it, and we’ll say that two bank cards are equivalent if they correspond to the same account. It’s very difficult to read the account number off a bank card directly, but the bank has a high-tech “equivalence tester” that takes two bank cards and, after performing some computations, determines whether they are equivalent. Their question is the following: among the collection of **n** cards, is there a set of more than `n/2` of them that are all equivalent to one another? Assume that the only feasible operations you can do with the cards are to pick two of them and plug them in to the equivalence tester. Show how to decide the answer to their question with only `O(n log n)` invocations of the equivalence tester.
	* **R**:
		* **Source**: `q3.c`
		* **Compile**: `make q3`

	```C
	Laura
	```

1. You’ve been working with some physicists who need to study, as part of their experimental design, the interactions among large numbers of very small charged particles. Basically, their setup works as follows. They have an inert lattice structure, and they use this for placing charged particles at regular spacing along a straight line. Thus we can model their structure as consisting of the points `{1, 2, 3, . . . , n}` on the real line; and at each of these points **j**, they have a particle with charge **qj**. (Each charge can be either positive or negative.) They want to study the **total force** on each particle, by measuring it and then comparing it to a computational prediction. This computational part is where they need your help. The total net force on particle **j**, by **Coulomb’s Law**, is equal to `Fj = SUM[i<j](Cqiqj)/(j-i)^2  - SUM[i>j](Cqiqj)/(j-i)^2`.
	* They’ve written the following simple program to compute **Fj** for all **j**:

	```
	For j = 1, 2, . . . , n
		Initialize Fj to 0
		For i = 1, 2, . . . , n
			If i < j then
				Add (C qi qj)/(j − i)^2 to Fj
			Else if i > j then
				Add − (C qi qj)/(j − i)^2 to Fj
			Endif
		Endfor
		Output Fj
	Endfor
	```
	* It’s not hard to analyze the running time of this program: each invocation of the inner loop, over **i**, takes `O(n)` time, and this inner loop is invoked `O(n)` times total, so the overall running time is `O(n²)`. The trouble is, for the large values of **n** they’re working with, the program takes several minutes to run. On the other hand, their experimental setup is optimized so that they can throw down **n** particles, perform the measurements, and be ready to handle **n** more particles within a few seconds. So they’d really like it if there were a way to compute all the forces **Fj** much more quickly, so as to keep up with the rate of the experiment. Help them out by designing an algorithm that computes all the forces **Fj** in `O(n log n)` time.
	* **R**:
		* **Source**: `q4.cpp`
		* **Compile**: `make q4`

	```C
	#include <iostream>
	#include <vector>

	using namespace std;

	#define C 299792458

	void create_particles(vector<double> &particles);
	void create_elements(vector<double> &particles, vector<double> &elements);
	double calculate_net_force(vector<double> &particles,
		vector<double> &elements);

	int main()
	{
		vector<double> particles;
		create_particles(particles);

		vector<double> elements;
		create_elements(particles, elements);

		double net_force = calculate_net_force(particles, elements);
		cout << "The Net Force is: " << net_force << endl;

		return 0;
	}

	void create_particles(vector<double> &particles)
	{
		const double END_OF_INPUT = 0.0;
		cout << "Insert a list of particle charges." << endl;
		cout << "End the insertion with " << END_OF_INPUT  << "." << endl;
		bool creation_is_done = false;
		while(!creation_is_done)
		{
			double charge = 0;
			cin >> charge;
			if(charge != END_OF_INPUT)
			{
				particles.push_back(charge);
			}
			else
			{
				creation_is_done = true;
			}
		}
	}

	void create_elements(vector<double> &particles, vector<double> &elements)
	{
		for(unsigned int i = particles.size(); i > 0; --i)
		{
			double element = 1.0/(i*i);
			elements.push_back(element);
		}

		for(unsigned int i = 1; i < particles.size(); ++i)
		{
			double element = -1.0/(i*i);
			elements.push_back(element);
		}
	}

	double calculate_net_force(vector<double> &particles,
		vector<double> &elements)
	{
		double net_force = 0;
		unsigned int i = 0;
		unsigned int j = particles.size()-1;
		bool inversed = false;
		for(double element : elements)
		{
			net_force = particles[i]*element*C*particles[j];
			if(!inversed)
			{
				--j;
				++i;
				if(i == particles.size()-1)
				{
					inversed = true;
				}
			}
			else
			{
				++j;
				--i;
			}
		}
		return net_force;
	}
	```

1. Hidden surface removal is a problem in computer graphics that scarcely needs an introduction: when Woody is standing in front of Buzz, you should be able to see Woody but not Buzz; when Buzz is standing in front of Woody, . . . well, you get the idea. The magic of hidden surface removal is that you can often compute things faster than your intuition suggests. Here’s a clean geometric example to illustrate a basic speed-up that can be achieved. You are given **n** nonvertical lines in the plane, labeled `L1, . . . , Ln`, with the **ith** line specified by the equation `y = aix + bi`. We will make the assumption that no three of the lines all meet at a single point. We say line **Li** is uppermost at a given x-coordinate **x0** if its y-coordinate at **x0** is greater than the y-coordinates of all the other lines at **x0**: `aix0 + bi > ajx0 + bj` for all `j = i`. We say line **Li** is visible if there is some x-coordinate at which it is uppermost—intuitively, some portion of it can be seen if you look down from “`y=∞`”. Give an algorithm that takes **n** lines as input and in `O(n log n)` time returns all of the ones that are visible.
		* **R**:
			* **Source**: `q5.c`
			* **Compile**: `make q5`

		```C
		Laura
		```
