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
	char pBuf[BUFSIZ] = { 0, };
	int nLen = 0;

	if (argc != 2)
	{
		perror("we need an argument.\n");
		return -1;
	}
	
	nFd = open(argv[1], O_RDONLY);//������ɾ�
	

	while ((nLen = read(nFd, pBuf, BUFSIZ)) > 0)//�Ҿ�� ������ ã�� �ҽ�
	{
		printf("%s", pBuf);
	}
	close(nFd);


	return 0;//����
}
