#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) //int ,char* 포인트와 배열 더블 포인터 방식(자주쓰는 방식)
{
	int nFd = -1;
	int nWhence, nCount, nOffset;
	char pBuf[BUFSIZ];
	int nLen = 0;

	if (argc != 2) 
	{
		printf("Usage:cmd [filename]\n");//파일이름
		return -1;
	}

	nFd = open(argv[1], O_RDONLY);

	printf("Select Whence: SEEK_SET(0), SEEK_CUR(1),SEEK_END(2)");//명령어 쳐서 작동
	scanf("%d", &nWhence);
	printf("Where will you start to read?\n");
	scanf("%d", &nOffset);
	printf("How many characters will you read?\n");
	scanf("%d", &nCount);

	switch (nWhence) //스위치문으로 명령어 조건으로 위에서 입력받은 값에 따라서 
	{
	case 0:
			lseek(nFd, nOffset, SEEK_SET);   // 여기 조건이 결정 됨
			break;
	case 1:
			lseek(nFd, nOffset, SEEK_CUR); 
			break;
	default:
		    lseek(nFd, nOffset, SEEK_END);
			break;
    }
    
	nLen = read(nFd, pBuf, nCount);   // 값을 저장하고
	printf("Data at (%d):\n", nOffset);    // 출력 함 
	printf("%s\n", pBuf);

	close(nFd);

	return 0;
}
