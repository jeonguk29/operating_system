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
	char strPwd[BUFSIZ] = {0, };//������

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <path>\n", argv[0]);
		return -1;//�̵��ϰ����ϴ� �Լ�
	}
	
	if (getcwd(strPwd, BUFSIZ) != NULL) {
		printf("getcwd: %s\n", strPwd);
	}

	printf("Changing Path...\n");

	chdir(argv[1]);

	if (getcwd(strPwd, BUFSIZ) != NULL) {
		printf("getcwd: %s\n", strPwd);//�۾� ������ ����  ���� ��ġ�� �ٲ�°� �ƴ� 
	}									// Į�� ȯ�濡��pwd �ϸ� �Ȱ��� 
	return 0;//����
}
