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
