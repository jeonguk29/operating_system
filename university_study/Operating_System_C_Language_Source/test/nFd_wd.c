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
	
	nFd = creat(argv[1], 0644);//������ɾ�
	
	write(nFd, "Hello", 5);//����

	close(nFd);

	printf("Press Enter key to continue.\n");//����Ű

	getchar();

	printf("Deleting %s\n",argv[1]); //����

	unlink(argv[1]); // �̰��� ���� ����� 

	printf("Done.\n");

	return 0;//����
}
