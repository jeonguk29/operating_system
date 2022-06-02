#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int
main(void) //int ,char* 포인트와 배열 더블 포인터 방식(자주쓰는 방식)
{
	for (int i = 0;; i++)//루프값
	{
		printf("\r");
		switch (i % 4)//i의 변수에 나오는 출력값 결정
		{
		case 0:
				printf("-");
       			break;
		case 1:
				printf("\\");
			    break;
		case 2:
				printf("|");
				break;
		case 3:
				printf("/");
				break;
		}
		fflush(stdout);
		if (i == 0x7FFFFFFF)//값의 변경으로 출력 랜덤
			i = 0;
	}
	return 0;//종료
}
