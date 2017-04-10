07/04/2017 - Sexta-Feira

# Interval Scheduling

* Job j starts at sj and finishes at fj
* Two jobs compatible if they don't overlap
* **Goal**: Find maximum subset of mutually compatible jobs

## Greedy Template

* Consider jobs in some order. Take each job provided it's compatible with the ones already taken.
	* **Earliest Start Time**
	* **Earliest Finish Time**
	* **Shortest Interval**
	* **Fewest Conflicts**
	
## Best Solution

* **Greedy Template: Earliest Finish Time Without Overlaps**
	* With Radix and Counting Sort: `O(n)`

## Optimal Solutions

* There may be more than one optimal solutions for the same instance
* Prefix of a solution: Define the prefix of length I of a solution S as the first I jobs of S
	* The prefix of length 2 of AGD is AG
* Similarity of two solutions S and S': The largest j such that S and S' shares a prefix of length J

# Interval Partitioning

* Lecture j starts at sj and finishes at fj
* **Goal**: Find mininum number of classrooms to schedule all lectures so that no two occur at the same time in the same room

## Greedy Template

* Consider jobs in some order. Take each job provided it's compatible with the ones already taken.
	* **Earliest Start Time**
	* **Earliest Finish Time**
	* **Shortest Interval**
	* **Fewest Conflicts**

## Best Solution

* **Greedy Template: Earliest Starting Time. If overlaps, new classroom need to be created**
	* With Radix and Heap Sort: `O(nlog(n))`

# Scheduling to Minimize Lateness

* Single resource processes one job at a time
* Job j requires tj units of processing time and is due at time dj
* If j starts at time sj, it finishes of time fj = sj + tj
* Lateness lj = max (0, fj-dj)
* **Goal** Schedule all jobs to minimize _maximum_ lateness L = max lj.

## Greedy Template

* Consider jobs in some order
	* **Shortest Processing Time First**
	* **Earliest Deadline First**
	* **Smallest Slack**

## Best Solution

* **Greedy Template: Earliest Deadline First**
