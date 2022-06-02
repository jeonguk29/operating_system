#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int
main(int argc, char* argv[])
{
	char strPwd[BUFSIZ] = {0, };//변수값

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <path>\n", argv[0]);
		return -1;//이동하고자하는 함수
	}
	
	if (getcwd(strPwd, BUFSIZ) != NULL) {
		printf("getcwd: %s\n", strPwd);
	}

	printf("Changing Path...\n");

	chdir(argv[1]);

	if (getcwd(strPwd, BUFSIZ) != NULL) {
		printf("getcwd: %s\n", strPwd);//작업 종료후 복귀  실제 위치가 바뀌는게 아님 
	}									// 칼리 환경에서pwd 하면 똑같음 
	return 0;//종료
}
