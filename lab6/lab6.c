#include <stdio.h>
#include <pthread.h>
int data_ready = 0;
int inf = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;

void *consumer (void * notused)
{
	printf("Eto potrebitel \n");
	while(1)
	{
	pthread_mutex_lock (&mutex);
	 printf("W1 - consumer \n");
	 while (!data_ready)
	     {
                printf("W2 - consumer\n");
	           pthread_cond_wait (&condvar, & mutex);  
               printf("W3 - consumer \n");
         }
	printf("dannie ot proizv = %d \n",inf);
    data_ready=0;
    pthread_cond_signal(&condvar);	
	pthread_mutex_unlock(&mutex);
	}
}
void *producer (void * notused)
{
	   printf("Eto proizvoditel \n");
	while(1)
	{
	sleep(2);
    printf("proizvoditel polychil dannie ot h/w = %d \n",inf);
	pthread_mutex_lock (&mutex);
printf("Wp1 - producer \n");
	 while (data_ready)
	     {
           printf("Wp2 - producer\n");
          pthread_cond_wait (&condvar, & mutex);  
         }
	data_ready=1;
    inf++;
    printf("Wp3 - producer\n");
    pthread_cond_signal(&condvar);	
	pthread_mutex_unlock(&mutex);
	}
}
void main()
{
 printf("Start \n");
 pthread_create(NULL,NULL, consumer,NULL);
 pthread_create(NULL,NULL, producer,NULL);
sleep(10);
printf("Kuzmin Maxim I914B\n");
}
