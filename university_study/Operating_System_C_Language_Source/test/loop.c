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
main(void) //int ,char* ����Ʈ�� �迭 ���� ������ ���(���־��� ���)
{
	for (int i = 0;; i++)//������
	{
		printf("\r");
		switch (i % 4)//i�� ������ ������ ��°� ����
		{
		case 0:
				printf("-");
       			break;
		case 1:
				printf("\\");
			    break;
		case 2:
				printf("|");
				break;
		case 3:
				printf("/");
				break;
		}
		fflush(stdout);
		if (i == 0x7FFFFFFF)//���� �������� ��� ����
			i = 0;
	}
	return 0;//����
}
