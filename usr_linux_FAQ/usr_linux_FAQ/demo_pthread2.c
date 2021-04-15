#include <stdio.h>
#include <pthread.h>

void *mythread1(void)
{
	int i;
	for(i=0; i < 10; i++)
	{
		printf("This is the 1st pthread, created by xiaoqiang!\n");
		sleep(1);
	}
	pthread_exit("1st time over!\n");
}

void *mythread2(void)
{
	int i;
	for(i=0; i < 10; i++)
	{
		printf("This is the 2st pthread, created by xiaoqiang!\n");
		sleep(1);
	}
	pthread_exit("2st time over!\n");
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int ret = 0;
	void *temp1;
	void *temp2;
	pthread_t id1,id2;

	ret = pthread_create(&id1, NULL, (void *)mythread1, NULL);
	if(ret)
	{
		printf("create pthread error!\n");
		return 1;
	}

	ret = pthread_create(&id1, NULL, (void *)mythread2, NULL);
	if(ret)
	{
		printf("create pthread error!\n");
		return 1;
	}

	pthread_join(id1, &temp1);
	pthread_join(id2, &temp2);

	return 0;
}
