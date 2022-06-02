#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>

int
main(int argc, char* argv[]) //int ,char* ����Ʈ�� �迭 ���� ������ ���(���־��� ���)
{
	struct passwd* stPasswd;
	
	if (argc != 2)
	{
		printf("Usage: %s <username>\n", argv[0]);
		return -1;
	}

	printf("LogIn Account: %s\n", getlogin());
	stPasswd = getpwuid(getuid());//����� ��������,����� ID����

	if (stPasswd == NULL)
	{
		printf("There is no %s ", argv[1]);
		return -1;
	}


	printf("Name: %s\n", stPasswd->pw_name);//��й�ȣ
	printf("UID: %d\n", stPasswd -> pw_uid);
	printf("GID: %d\n", stPasswd->pw_gid); // ����� �׷� ����
	printf("Additional: %s\n", stPasswd->pw_gecos);
	printf("HOME: %s\n", stPasswd->pw_dir);
	printf("Shell: %s\n", stPasswd->pw_shell);


	
	
	return 0;//����
}
