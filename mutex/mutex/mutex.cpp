#include<stdafx.h>
#include <stdio.h>                                                                                                                                                                                                                           
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

volatile int flag = 0;
void *func1(void *argv)
{
	while (1)
	{
		if (flag == 0)
		{
			usleep(100000);
			printf("%s: %d ", __func__, flag);
			__sync_fetch_and_add(&flag, 1);
		}
	}

	return 0;
}

void *func2(void *argv)
{
	while (1)
	{
		if (flag == 1)
		{

			printf("%s: %d ", __func__, flag);
			__sync_fetch_and_add(&flag, 1);
		}
	}

	return 0;
}

void *func3(void *argv)
{
	while (1)
	{
		if (flag == 2)
		{
			usleep(100000);
			printf("%s: %d\n", __func__, flag);
			__sync_lock_release(&flag);
		}
	}

	return 0;
}
int main()
{
	pthread_t td1;
	pthread_t td2;
	pthread_t td3;

	pthread_create(&td1, NULL, func1, NULL);
	pthread_create(&td2, NULL, func2, NULL);
	pthread_create(&td3, NULL, func3, NULL);

	pthread_join(td1, NULL);
	pthread_join(td2, NULL);
	pthread_join(td3, NULL);

}