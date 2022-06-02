#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char buffer[BUFSIZ];

	for (int i = 0; i < 1000000; i++)
	{
		char c = 'a' + i % 26;   
		buffer[i % BUFSIZ] = c;  // 처음에는 a 그다음 이후 z 다시 a까지 계속 출력 될거임 100만번
		if (i != 0 && i % BUFSIZ == BUFSIZ - 1)  // 버퍼가 꽉찾는지 확인
		{
			printf(buffer);   // 이후 출력 
			fflush(stdout);
		}

	}
	printf(buffer);
	fflush(stdout);
	
	return 0;
}