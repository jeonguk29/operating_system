#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char buffer[BUFSIZ];

	for (int i = 0; i < 1000000; i++)
	{
		char c = 'a' + i % 26;   
		buffer[i % BUFSIZ] = c;  // ó������ a �״��� ���� z �ٽ� a���� ��� ��� �ɰ��� 100����
		if (i != 0 && i % BUFSIZ == BUFSIZ - 1)  // ���۰� ��ã���� Ȯ��
		{
			printf(buffer);   // ���� ��� 
			fflush(stdout);
		}

	}
	printf(buffer);
	fflush(stdout);
	
	return 0;
}