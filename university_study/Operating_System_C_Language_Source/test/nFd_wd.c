#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int
main(int argc, char* argv[]) //int ,char* 포인트와 배열 더블 포인터 방식(자주쓰는 방식)
{
	int nFd = -1;//변수값

	if (argc != 2)
	{
		perror("we need an argument.\n");
		return -1;
	}
	
	nFd = creat(argv[1], 0644);//생성명령어
	
	write(nFd, "Hello", 5);//쓰기

	close(nFd);

	printf("Press Enter key to continue.\n");//실행키

	getchar();

	printf("Deleting %s\n",argv[1]); //삭제

	unlink(argv[1]); // 이것을 통해 사라짐 

	printf("Done.\n");

	return 0;//종료
}
