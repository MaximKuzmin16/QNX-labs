#include <stdio.h>
#include <time.h>
#include <sync.h>
#include <sys/neutrino.h>

barrier_t barrier;    

//int data_ready = 0;
//int inf = 0;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;

void *thread1 (void * not_used)
{
	time_t now;
	char buf[27];
	time(&now);
	printf("Potok 1, vremia starta %s \n", ctime_r(&now,buf));
	sleep(3);
	barrier_wait(&barrier);
	time(&now);
	printf("barier v potoke 1 , vremia srabativania %s \n", ctime_r(&now,buf));
}

void *thread2 (void * not_used)
{
	time_t now;
	char buf[27];
	time(&now);
	printf("Potok 2, vremia starta %s \n", ctime_r(&now,buf));
	sleep(6);
	barrier_wait(&barrier);
	time(&now);
	printf("barier v potoke 2 , vremia srabativania %s \n", ctime_r(&now,buf));
}

void *thread3 (void * not_used)
{
	time_t now;
	char buf[27];
	time(&now);
	printf("Potok 3, vremia starta %s \n", ctime_r(&now,buf));
	sleep(9);
	barrier_wait(&barrier);
	time(&now);
	printf("barier v potoke 3 , vremia srabativania %s \n", ctime_r(&now,buf));
}

void main()
{
	time_t now;
	char buf[27];
   barrier_init(&barrier, NULL, 3);
   printf("Start \n");
   pthread_create(NULL,NULL, thread1 ,NULL);
   pthread_create(NULL,NULL, thread2 ,NULL);
   pthread_create(NULL,NULL, thread3 ,NULL);
	time(&now);
	printf(" Main(): oshidanie y bariera, vremia %s \n", ctime_r(&now,buf));
	barrier_wait(&barrier);
	time(&now);
	printf("barier v main() , vremia srabativania %s \n", ctime_r(&now,buf));
sleep(5);
printf("Maxim Kuzmin I914B");
}
