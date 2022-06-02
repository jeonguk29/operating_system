#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

int
main(int argc, char* argv[]) //int ,char* ����Ʈ�� �迭 ���� ������ ���(���־��� ���)
{
	DIR* pDir;//���� ���丮
	char pPwd[BUFSIZ] = {0};//������
	struct dirent* pEntry;
	
	pDir = opendir(".");

	getcwd(pPwd, BUFSIZ);
	printf("PWD: %s\n", pPwd);
	
	printf("[i-Node]\t[type]\tName\n");//���� ��,Ÿ��,�̸� ����    ���� �ִ� ���丮�� ������ �� ��µ� 
	while (pEntry = readdir(pDir)) {   // ls �� ���������� �̷������� ������ 
		printf("[%d]\t[%02d]\t%s\n",
			pEntry->d_ino, pEntry->d_type, pEntry->d_name);
	}//���� ���丮 ����
	

	closedir(pDir);
	
	
	return 0;//����
}
