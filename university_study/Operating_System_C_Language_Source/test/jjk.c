#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
	int nCount = atoi(argv[1]);                // 메모리 자원 할당 100000 정도 할당을 해주는거임 ps au 해서 확인 하면 보임 
	char* p = 0;

	printf("Allocating memories.....\n");
	for (int i = 0; i < nCount; i++)
	{
		p = (char*)malloc(4096);   // 값은 4096 빙빙돌다가 값은 p에 계속 덮어쓰기 됨 
	}

	printf("Done....\n");
	getchar();          // 키보드에 값이 들어올때 까지 계속 상주 

	return 0;
}