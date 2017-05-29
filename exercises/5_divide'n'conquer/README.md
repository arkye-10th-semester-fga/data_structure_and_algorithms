**Aluno**: Jonathan Moraes (12/0122553)

**Aluno**: Laura Martins (10/0033440)

**Disciplina**: Estrutura de Dados e Algoritmos 2

**Professor**: Maurício Serrano

**Data**: 29/05/2017

# Lista 5
**Escolher 4 exercícios**

1. You are interested in analyzing some hard-to-obtain data from two separate
databases. Each database contains n numerical values—so there are
2n values total—and you may assume that no two values are the same.
You’d like to determine the median of this set of 2n values, which we will
define here to be the nth smallest value.
However, the only way you can access these values is through queries
to the databases. In a single query, you can specify a value k to one of the
two databases, and the chosen database will return the kth smallest value
that it contains. Since queries are expensive, you would like to compute
the median using as few queries as possible.
Give an algorithm that finds the median value using at most O(log n)
queries.
	* **R**:
		* **Source**: ``
		* **Compile**: ``

	```C

	```

1. Recall the problem of finding the number of inversions. As in the text,
we are given a sequence of n numbers a1, . . . , an, which we assume are all
distinct, and we define an inversion to be a pair i < j such that ai > aj.
We motivated the problem of counting inversions as a good measure
of how different two orderings are. However, one might feel that this
measure is too sensitive. Let’s call a pair a significant inversion if i < j and
ai > 2aj. Give an O(n log n) algorithm to count the number of significant
inversions between two orderings.
	* **R**:
		* **Source**: ``
		* **Compile**: ``

	```C

	```

1. Suppose you’re consulting for a bank that’s concerned about fraud detection,
and they come to you with the following problem. They have a
collection of n bank cards that they’ve confiscated, suspecting them of
being used in fraud. Each bank card is a small plastic object, containing
a magnetic stripe with some encrypted data, and it corresponds to
a unique account in the bank. Each account can have many bank cards
corresponding to it, and we’ll say that two bank cards are equivalent if
they correspond to the same account.
It’s very difficult to read the account number off a bank card directly,
but the bank has a high-tech “equivalence tester” that takes two bank
cards and, after performing some computations, determines whether
they are equivalent.
Their question is the following: among the collection of n cards, is
there a set of more than n/2 of them that are all equivalent to one another?
Assume that the only feasible operations you can do with the cards are
to pick two of them and plug them in to the equivalence tester. Show how
to decide the answer to their question with only O(n log n) invocations of
the equivalence tester.
	* **R**:
		* **Source**: ``
		* **Compile**: ``

	```C

	```

1. You’ve been working with some physicists who need to study, as part of
their experimental design, the interactions among large numbers of very
small charged particles. Basically, their setup works as follows. They have
an inert lattice structure, and they use this for placing charged particles
at regular spacing along a straight line. Thus we can model their structure
as consisting of the points {1, 2, 3, . . . , n} on the real line; and at each of
these points j, they have a particle with charge qj. (Each charge can be
either positive or negative.)
They want to study the total force on each particle, by measuring it
and then comparing it to a computational prediction. This computational
part is where they need your help. The total net force on particle j, by
Coulomb’s Law, is equal to
					Fj = SUM[i<j](Cqiqj)/(j-i)^2  - SUM[i>j](Cqiqj)/(j-i)^2
They’ve written the following simple program to compute Fj for all j:

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

It’s not hard to analyze the running time of this program: each
invocation of the inner loop, over i, takes O(n) time, and this inner loop
is invoked O(n) times total, so the overall running time is O(n2).
The trouble is, for the large values of n they’re working with, the program
takes several minutes to run. On the other hand, their experimental
setup is optimized so that they can throw down n particles, perform the
measurements, and be ready to handle n more particles within a few seconds.
So they’d really like it if there were a way to compute all the forces
Fj much more quickly, so as to keep up with the rate of the experiment.
Help them out by designing an algorithm that computes all the forces
Fj in O(n log n) time.
	* **R**:
		* **Source**: ``
		* **Compile**: ``

	```C

	```

1. Hidden surface removal is a problem in computer graphics that scarcely
needs an introduction: when Woody is standing in front of Buzz, you
should be able to see Woody but not Buzz; when Buzz is standing in
front of Woody, . . . well, you get the idea.
The magic of hidden surface removal is that you can often compute
things faster than your intuition suggests. Here’s a clean geometric example
to illustrate a basic speed-up that can be achieved. You are given n
nonvertical lines in the plane, labeled L1, . . . , Ln, with the ith line specified
by the equation y = aix + bi. We will make the assumption that no three of
the lines all meet at a single point. We say line Li is uppermost at a given
x-coordinate x0 if its y-coordinate at x0 is greater than the y-coordinates
of all the other lines at x0: aix0 + bi > ajx0 + bj for all j = i. We say line Li is
visible if there is some x-coordinate at which it is uppermost—intuitively,
some portion of it can be seen if you look down from “y=∞.”
Give an algorithm that takes n lines as input and in O(n log n) time
returns all of the ones that are visible. Figure 5.10 gives an example.
		* **R**:
			* **Source**: ``
			* **Compile**: ``

		```C

		```
