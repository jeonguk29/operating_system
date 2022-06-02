#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int
main(int argc, char* argv[]) //int ,char* ����Ʈ�� �迭 ���� ������ ���(���־��� ���)
{
	int nFd1 = -1;//������
	int nFd2 = -1;//������
	char pBuf[BUFSIZ] = { 0, };
	int nLen = 0;

	if (argc != 3)
	{
		perror("we need an argument.\n");
		return -1;
	}

	nFd1 = open(argv[1], O_RDONLY);//������ɾ�
	nFd2 = open(argv[2], O_WRONLY | O_CREAT, 0644);//���� �����

	while ((nLen = read(nFd1, pBuf, BUFSIZ)) > 0)//�Ҿ�� ������ ã�� �ҽ�
	{
		if (write(nFd2, pBuf, nLen) < 0)//if ������ ������ �о��
		{
			printf("Writting Failed.\n");//���� ��µ� ����
			break;
		}
	}
	close(nFd2);
	close(nFd1);

	return 0;//����
}
