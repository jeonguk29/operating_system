#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int
main(int argc, char* argv[]) //int ,char* 포인트와 배열 더블 포인터 방식(자주쓰는 방식)
{
	int nFd1 = -1;//변수값
	int nFd2 = -1;//변수값
	char pBuf[BUFSIZ] = { 0, };
	int nLen = 0;

	if (argc != 3)
	{
		perror("we need an argument.\n");
		return -1;
	}

	nFd1 = open(argv[1], O_RDONLY);//생성명령어
	nFd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);//쓰고 만들기

	while ((nLen = read(nFd1, pBuf, BUFSIZ)) > 0)//잃어올 파일을 찾는 소스
	{
		if (write(nFd2, pBuf, nLen) < 0)//if 문으로 파일을 읽어옴
		{
			printf("Writting Failed.\n");//값이 출력되 생성
			break;
		}
	}
	close(nFd2);
	close(nFd1);

	return 0;//종료
}
