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

	if (getcwd(strPwd, BUFSIZ) != NULL) { //getwd�� ��� ���� ���� ������ ���(re-entrance)���� ���â ���ð��� 
		printf("getcwd: %s\n", strPwd);
	}
	if (getwd(strPwd) != NULL) { // ���� �۾����� ����� ��ġ�� ����
		printf("getcwd: %s\n", strPwd);
	}
	for (int i = 0; i < 10; i++)
	{
		pPwd = get_current_dir_name();//ȭ�� ��� get_current_dir_name() �Լ� ���鼭 �޸𸮸� �Ҵ��� 
		printf("%02d : %p : Get_XXX : %s\n", i, pPwd, pPwd); // ���� �ּҰ� ����϶� 
		//free(pPwd);//check point       �ּ� ó���ϸ� �� �޶��� 
     }
	return 0;
}


