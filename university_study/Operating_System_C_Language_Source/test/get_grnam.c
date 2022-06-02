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
	struct group* stGroup;

	if (argc != 2) {
		printf("Usage: %s [group name]\n", argv[0]);//�׷��̸� �˻�         // ���ϴ� �׷� ���� �Է��ϸ� �Ʒ��� ���� ���� �����
		return -1;
 	}
	
	stGroup = getgrnam(argv[1]);
	if (stGroup == NULL) { //�׷��� �������� �ʴ�
		printf("No Group!!\n");
		return -1;
	}

	printf("Group Name : %s\n", stGroup->gr_name);//�׷��̸�
	printf("Memders are : \n");//�׷쳻 �����   ������ ��� ��� 
	for (int i = 0; ; i++)
	{
		if (stGroup->gr_mem[i] == NULL)
			break;

		printf("\t[%02d] : %s\n", i, stGroup->gr_mem[i]); //�׷쳻 ���̵� ���

	}
	printf("Done.\n");
	return 0;//����
}