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
	char pBuf[BUFSIZ] = { 0, };
	int nLen = 0;

	if (argc != 2)
	{
		perror("we need an argument.\n");
		return -1;
	}
	
	nFd = open(argv[1], O_RDONLY);//생성명령어
	

	while ((nLen = read(nFd, pBuf, BUFSIZ)) > 0)//잃어올 파일을 찾는 소스
	{
		printf("%s", pBuf);
	}
	close(nFd);


	return 0;//종료
}
