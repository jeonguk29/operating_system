#include <unistd.h>
#include <stdio.h>

int main(void)
{

	for (int i = 0;; i++)
	{
		if (access("test.txt", F_OK) == 0)  //test.txt 파일 있는지 확인
		{
			printf("There is a file(%05d).\n", i);  // 있으면 출력
		}
		usleep(5000);    // rm으로 택스트 파일 지우고 실행하면 출력 안됨
	}
	return 0;
}