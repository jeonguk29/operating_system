#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <pwd.h>
#include <sys/syslog.h>

int
main(int argc, char* argv[]) //int ,char* 포인트와 배열 더블 포인터 방식(자주쓰는 방식)
{
	for (int i = 0; i < 10; i++)
	{
	   syslog(LOG_DEBUG, "[%d] We have a message.", i);
	}

	return 0;//종료
}
