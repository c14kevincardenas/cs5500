#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 1024
#define NUM_THREADS 2

int total = 0;
int n1,n2;
char *s1,*s2;
FILE *fp;
pthread_mutex_t mutex;

int readf(FILE *fp)
{
	if((fp=fopen("strings.txt", "r"))==NULL){
		printf("ERROR: can't open string.txt!\n");
		return 0;
	}
	s1=(char *)malloc(sizeof(char)*MAX);
	if(s1==NULL){
		printf("ERROR: Out of memory!\n");
		return -1;
	}
	s2=(char *)malloc(sizeof(char)*MAX);
	if(s2==NULL){
		printf("ERROR: Out of memory\n");
		return -1;
	}
	/*read s1 s2 from the file*/
	s1=fgets(s1, MAX, fp);
	s2=fgets(s2, MAX, fp);
	n1=strlen(s1)-1;  /*length of s1*/
	n2=strlen(s2)-1; /*length of s2*/
	
	if(s1==NULL || s2==NULL || n1<n2)  /*when error exit*/
		return -1;
}

void *worker(void *threadid)
{
	// cast thread ID back to long
	long tid;
	tid = (long) threadid;
	
	// declare vars for finding substring
	int i,j,k;
	int count;
	
	// find substring locally
	for (i = tid; i <= (n1-n2); i = i + NUM_THREADS){
		count=0;
		for(j = i,k = 0; k < n2; j++,k++){  /*search for the next string of size of n2*/  
			if (*(s1+j)!=*(s2+k)){
				break;
			}
			else {
				count++;
			}
			if(count==n2){    
				pthread_mutex_lock (&mutex);
				total++;		/*found a substring in this step*/                          
				pthread_mutex_unlock (&mutex);                       
			}
		}
	}

	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	// declare variables
	pthread_t threads[NUM_THREADS];
	int ret;
	long t;
 
	// initialize mutex
	pthread_mutex_init(&mutex, NULL);
 
	// read file
	readf(fp);

	// create two threads to do work
	for(t = 0; t < NUM_THREADS; t++){
		printf("In main: creating thread %ld\n", t);
		ret = pthread_create(&threads[t], NULL, worker, (void *)t);
		if (ret != 0){
			printf("ERROR; return code from pthread_create() is %d\n", ret);
			exit(-1);
		}
	}
	
	sleep(1);
	
	printf("The number of substrings is: %d\n", total);
	
	/* Last thing that main() should do */
	pthread_exit(0);
}
