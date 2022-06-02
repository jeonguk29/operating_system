#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[]) //int ,char* 포인트와 배열 더블 포인터 방식(자주쓰는 방식)
{
	FILE* fp = NULL;
	long nOffset = 0;
	char strBuffer[BUFSIZ] = { 0, };

	if (argc != 3)//값의 조건
	{
		printf("Usage:%s <pathname> <offset>\n", argv[0]);
		return -1;
	}//명령어 입력

	nOffset = atoi(argv[2]);//값 배정

	fp = fopen(argv[1], "r");
	if (fseek(fp, nOffset, SEEK_SET) < 0) {
		printf("Setting Position has been failed.\n");
		return -1;//파일 읽는 함수 지정해준 만큼  받아서 그부분부터 끝까지 읽어 출력함
	}

	memset(strBuffer, 0, BUFSIZ);//값을 비교하는 함수

	if(fgets(strBuffer, BUFSIZ,fp) != NULL) {
	printf("Data : %s", strBuffer);   // 값을 출력해줌
    }
	fclose(fp);//fp  종료

	return 0;
}
