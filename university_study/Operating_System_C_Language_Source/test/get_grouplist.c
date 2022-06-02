#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int
main(int argc, char* argv[]) //int ,char* ����Ʈ�� �迭 ���� ������ ���(���־��� ���)
{
	gid_t nGIds[BUFSIZ];
	int nCount = BUFSIZ;
	int nRet = 0;

	struct passwd* stPasswd;
	struct group* stGroup;

	if (argc < 2) {
		stPasswd = getpwuid(getuid());   
 	}
	else
	{
		stPasswd = getpwnam(argv[1]);
	}
	if (stPasswd == NULL) {     // ������� ���������� ã���� ���� �ǳ� �� 
		printf("No Accounts!!\n");
		return-1;
	}
	nRet = getgrouplist(stPasswd->pw_name, stPasswd->pw_gid, nGIds, &nCount); // ������� �ش�Ǵ�   �������� �Ѱ��ָ�
	if(nRet <0) {
		printf("Getting group list was failed\n");
		return -1;
	}

	printf("Group of %s is\n", stPasswd->pw_name); // ����� �̸� ���
	for (int i = 0; i < nCount; i++)
	{
		stGroup = getgrgid(nGIds[i]);       // id �ΰ�
		printf("\t[%02d] : %s(%d)\n", i, stGroup->gr_name, nGIds[i]); // �׷쿡 ���� ���� ��� 

	}
	printf("Done.\n");  // �̷��� �Ǹ� �ش� ����ڿ� ���� �׷� ����Ʈ���� ����ϰ� ��
	return 0;//����
}
