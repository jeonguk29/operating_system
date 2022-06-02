#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int ResultPrint(char* pBuffer);

int main()
{
	int nPid;
	char buffer[BUFSIZ];
	memset(buffer, 0, BUFSIZ);

	nPid = fork();
	if (nPid > 0)
	{
		sprintf(buffer, "A (PID: %d)", getpid());
		ResultPrint(buffer);
	}
	else
	{
		sprintf(buffer, "\t\t\tB (PID: %d)", getpid());
		ResultPrint(buffer);
	}

	return 0;
}

int ResultPrint(char* pBuffer)
{
	int nCount = 0;
	for (int i = 0;; i++)
	{
		for (int j = 0;; j++)
		{
			time(NULL);
			if (j >= 0x0FFFFFFF)
				break;
		}
		nCount++;
		printf("%s (%d)\n", pBuffer, nCount);
	}

	return 0;
}