#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

char message[32] = "hello world\n";
void *thread_func();
int a = 1;

int main(void){
	pthread_t a_thread;
	void *result;
    /*pthread_create(&t1, NULL,(int *)read_data, NULL);*/
	if (pthread_create(&a_thread, NULL, (void *)thread_func, NULL) != 0){
		printf("fail to pthread_create\n"); exit(-1);
	}
	while(a == 1);
	pthread_join(&a_thread, &result);
	printf("result is %s\n",result);
	printf("message is %s\n",message);
	return 0;
}

void *thread_func(){
	a = 0;
	sleep(1);
	printf("this here\n");
	strcpy(message, "marked by thread\n");
	pthread_exit("thank you for waiting for me\n");
}
