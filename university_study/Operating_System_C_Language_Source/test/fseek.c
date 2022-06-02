#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[]) //int ,char* ����Ʈ�� �迭 ���� ������ ���(���־��� ���)
{
	FILE* fp = NULL;
	long nOffset = 0;
	char strBuffer[BUFSIZ] = { 0, };

	if (argc != 3)//���� ����
	{
		printf("Usage:%s <pathname> <offset>\n", argv[0]);
		return -1;
	}//��ɾ� �Է�

	nOffset = atoi(argv[2]);//�� ����

	fp = fopen(argv[1], "r");
	if (fseek(fp, nOffset, SEEK_SET) < 0) {
		printf("Setting Position has been failed.\n");
		return -1;//���� �д� �Լ� �������� ��ŭ  �޾Ƽ� �׺κк��� ������ �о� �����
	}

	memset(strBuffer, 0, BUFSIZ);//���� ���ϴ� �Լ�

	if(fgets(strBuffer, BUFSIZ,fp) != NULL) {
	printf("Data : %s", strBuffer);   // ���� �������
    }
	fclose(fp);//fp  ����

	return 0;
}
