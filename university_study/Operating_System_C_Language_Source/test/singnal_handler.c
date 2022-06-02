#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void callback_sig_handler(int nSigNumber);

int  
main()// 인터럽트 동작 예
{

	printf("PID: %d\n", getpid());

	signal(SIGUSR1, callback_sig_handler);
	signal(SIGUSR2, callback_sig_handler);

	for (int i = 0; ; i++)
	{
		if (i % 4 = 0)
			printf("\r-");
		else if (i % 4 = 1)
			printf("\r\\");
		else if (i % 4 = 2)
			printf("\r|");
		else
			printf("\r/");

		fflush(stdout);
		usleep(50000);
		
	}
return 0;
}

void callback_sig_handler(int nSigNumber)
{
	printf("we just got a signal(%d).\n", nSigNumber);
}
