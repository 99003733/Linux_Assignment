#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include <pthread.h> 

#define MAX 20

 
#define MAX_THREAD 10 



int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220, 110, 200, 254, 289 }; 
int sum[10] = { 0 }; 
int part = 0; 

void* sum_array(void* arg) 
{ 

	// Each thread computes sum of 1/10th of array 
	int thread_part = part++; 

	for (int i = thread_part * (MAX / 10); i < (thread_part + 1) * (MAX / 10); i++) 
		sum[thread_part] += a[i]; 
} 

// Driver Code 
int main() 
{ 

	pthread_t threads[MAX_THREAD]; 

	// Creating 10 threads 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_create(&threads[i], NULL, sum_array, (void*)NULL); 

	// joining 10 threads i.e. waiting for all 10 threads to complete 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(threads[i], NULL); 

	// adding sum of all 4 parts 
	int total_sum = 0; 
	for (int i = 0; i < MAX_THREAD; i++) 
		total_sum += sum[i]; 

    printf("The sum is %d",total_sum);

	return 0; 
} 
