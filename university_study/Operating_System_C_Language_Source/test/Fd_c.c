#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int
main(int argc, char* argv[]) //int ,char* ����Ʈ�� �迭 ���� ������ ���(���־��� ���)
{
	int nFd = -1;//������

	if (argc != 2)
	{
		perror("we need an argument.\n");
		return -1;
	}
	
	nFd = open(argv[1], O_RDWR | O_CREAT, 0644);//������ɾ�

	printf("Fd is %d\n", nFd);//���� ��µ� ����

	close(nFd);

	return 0;//����
}
