#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <semaphore.h>

void* mythread_r(void* ptr);
void* mythread_w(void* ptr);

sem_t g_mutex;

int main(int argc, char* argv[])
{
	pthread_t thread1, thread2;
	int nValue = 0;

	sem_init(&g_mutex, 0, 1); 

	pthread_create(&thread1, NULL, *mythread_r, (void*)&nValue);
	pthread_create(&thread2, NULL, *mythread_w, (void*)&nValue);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	sem_destroy(&g_mutex);

	return 0;
}

void* mythread_r(void* p_value)  // 1초뒤에 실행 
{
	int* p_nValue = (int*)p_value;

	do
	{
		sem_wait(&g_mutex);
		if (*p_nValue % 2 == 0)
		{
			usleep(500000);
			printf("%d is even number!!\n", *p_nValue);

		}
		else
		{
			usleep(500000);
			printf("%d is add number!!\n", *p_nValue);
		}
		sem_post(&g_mutex);

		usleep(500000);
	} while (1);
	
	return p_nValue;
}


void* mythread_w(void* p_value)     // 0.5 뒤에 실행
{
	int* p_nValue = (int*)p_value;

	do
	{
		sem_wait(&g_mutex);
		(*p_nValue)++;
		sem_post(&g_mutex);

		usleep(500000);
	} while(1);

	return p_nValue;
}
