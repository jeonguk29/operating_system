#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

int
main(int argc, char* argv[]) //int ,char* 포인트와 배열 더블 포인터 방식(자주쓰는 방식)
{
	DIR* pDir;//읽을 디랙토리
	char pPwd[BUFSIZ] = {0};//변수값
	struct dirent* pEntry;
	
	pDir = opendir(".");

	getcwd(pPwd, BUFSIZ);
	printf("PWD: %s\n", pPwd);
	
	printf("[i-Node]\t[type]\tName\n");//파일 값,타입,이름 종류    현재 있는 디렉토리에 정보가 다 출력됨 
	while (pEntry = readdir(pDir)) {   // ls 가 내부적으로 이런식으로 동작함 
		printf("[%d]\t[%02d]\t%s\n",
			pEntry->d_ino, pEntry->d_type, pEntry->d_name);
	}//파일 디렉토리 접근
	

	closedir(pDir);
	
	
	return 0;//종료
}
