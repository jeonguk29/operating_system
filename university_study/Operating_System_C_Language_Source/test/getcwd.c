#define _GNU_SOURCE 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(void)
{
	char strPwd[BUFSIZ] = { 0, };
	char* pPwd = NULL;

	if (getcwd(strPwd, BUFSIZ) != NULL) { //getwd의 경우 내부 정적 공간을 사용(re-entrance)주의 경고창 나올거임 
		printf("getcwd: %s\n", strPwd);
	}
	if (getwd(strPwd) != NULL) { // 현재 작업중인 경로의 위치를 추출
		printf("getcwd: %s\n", strPwd);
	}
	for (int i = 0; i < 10; i++)
	{
		pPwd = get_current_dir_name();//화면 출력 get_current_dir_name() 함수 돌면서 메모리를 할당함 
		printf("%02d : %p : Get_XXX : %s\n", i, pPwd, pPwd); // 논리적 주소값 출력하라 
		//free(pPwd);//check point       주석 처리하면 값 달라짐 
     }
	return 0;
}


