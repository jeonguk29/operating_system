#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) //int ,char* ����Ʈ�� �迭 ���� ������ ���(���־��� ���)
{
	int nFd = -1;
	int nWhence, nCount, nOffset;
	char pBuf[BUFSIZ];
	int nLen = 0;

	if (argc != 2) 
	{
		printf("Usage:cmd [filename]\n");//�����̸�
		return -1;
	}

	nFd = open(argv[1], O_RDONLY);

	printf("Select Whence: SEEK_SET(0), SEEK_CUR(1),SEEK_END(2)");//��ɾ� �ļ� �۵�
	scanf("%d", &nWhence);
	printf("Where will you start to read?\n");
	scanf("%d", &nOffset);
	printf("How many characters will you read?\n");
	scanf("%d", &nCount);

	switch (nWhence) //����ġ������ ��ɾ� �������� ������ �Է¹��� ���� ���� 
	{
	case 0:
			lseek(nFd, nOffset, SEEK_SET);   // ���� ������ ���� ��
			break;
	case 1:
			lseek(nFd, nOffset, SEEK_CUR); 
			break;
	default:
		    lseek(nFd, nOffset, SEEK_END);
			break;
    }
    
	nLen = read(nFd, pBuf, nCount);   // ���� �����ϰ�
	printf("Data at (%d):\n", nOffset);    // ��� �� 
	printf("%s\n", pBuf);

	close(nFd);

	return 0;
}
