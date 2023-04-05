#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2
#define COUNT_LIMIT 16

int count = 0;  // number of chars in the queue
pthread_mutex_t count_mutex;
pthread_cond_t consumer_cv;
pthread_cond_t producer_cv;
char queue[COUNT_LIMIT];
FILE *fp;

void *producer(void *t) 
{
	int i;
	long my_id = (long)t;
	char c;
	
	// printf("Starting producer(): thread %ld\n", my_id);
	
	// try opening the file
	if((fp=fopen("message.txt", "r"))==NULL){
		printf("ERROR: can't open string.txt!\n");
		return 0;
	}
	
	// lock mutex to do producer work
	pthread_mutex_lock(&count_mutex);
	
	// read message.txt and add character to queue
	while ((c = getc(fp)) != EOF){
		// check if producer reached queue limit
		if (count == COUNT_LIMIT) {
			// printf("producer(): thread %ld, count = %d  Threshold reached. Going into wait...\n", my_id, count);
			pthread_cond_wait(&producer_cv, &count_mutex);
		}
		
		// add character to queue and increase count
		queue[count] = c;
		count ++;

		// check if there is a character in the queue for consumer to print
		if (count == 1){
			// wake up consumer
			pthread_cond_signal(&consumer_cv);
			// printf("Just sent signal to consumer.\n");
		}
	}
	
	// add EOF char to queue as a stop for consumer
	c = getc(fp);
	queue[count] = c;
	count ++;
	
	// printf("producer(): thread %ld, count = %d, unlocking mutex\n", my_id, count);
	pthread_mutex_unlock(&count_mutex);

	pthread_exit(NULL);
}

void *consumer(void *t) 
{
	long my_id = (long)t;
	int i;

	// printf("Starting consumer(): thread %ld\n", my_id);

	// lock mutex to do consumer work
	pthread_mutex_lock(&count_mutex);
	
	// read and remove character in queue and print
	while(queue[0] != EOF){
		// check if queue is empty
		if (count == 0) {
			// printf("consumer(): thread %ld, count = %d  Empty queue. Going into wait...\n", my_id, count);
			pthread_cond_wait(&consumer_cv, &count_mutex);
		}
		
		// print char from queue, decrease count, shift left
		printf("%c\n", queue[0]);
		count --;
		for (i = 0; i < count; i++){
			queue[i] = queue[i + 1];
		}

		// check if there is an opening in the queue for producer to add
		if (count == COUNT_LIMIT - 1){
			// wake up producer
			pthread_cond_signal(&producer_cv);
			// printf("Just sent signal to producer.\n");
		}
	}
	
	// decrement count for EOF char
	count --;
	
	// printf("consumer(): thread %ld, count = %d, unlocking mutex\n", my_id, count);
	pthread_mutex_unlock(&count_mutex);
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int i, rc; 
	long t1=1, t2=2;
	pthread_t threads[2];
	pthread_attr_t attr;

	/* Initialize mutex and condition variable objects */
	pthread_mutex_init(&count_mutex, NULL);
	pthread_cond_init (&consumer_cv, NULL);
	pthread_cond_init (&producer_cv, NULL);

	/* For portability, explicitly create threads in a joinable state */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_create(&threads[0], &attr, consumer, (void *)t1);
	pthread_create(&threads[1], &attr, producer, (void *)t2);

	/* Wait for all threads to complete */
	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	// printf ("Main(): Waited and joined with %d threads. Final value of count = %d. Done.\n", NUM_THREADS, count);

	/* Clean up and exit */
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&consumer_cv);
	pthread_cond_destroy(&producer_cv);
	pthread_exit (NULL);
}