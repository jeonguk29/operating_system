#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
	int nCount = atoi(argv[1]);                // �޸� �ڿ� �Ҵ� 100000 ���� �Ҵ��� ���ִ°��� ps au �ؼ� Ȯ�� �ϸ� ���� 
	char* p = 0;

	printf("Allocating memories.....\n");
	for (int i = 0; i < nCount; i++)
	{
		p = (char*)malloc(4096);   // ���� 4096 �������ٰ� ���� p�� ��� ����� �� 
	}

	printf("Done....\n");
	getchar();          // Ű���忡 ���� ���ö� ���� ��� ���� 

	return 0;
}