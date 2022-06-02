#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int
main(int argc, char* argv[]) //int ,char* 포인트와 배열 더블 포인터 방식(자주쓰는 방식)
{
	int nFd = -1;//변수값

	int i = 0;
	FILE* fp1 = NULL; //file pointr1
	FILE* fp2 = NULL; //file pointr2

	char buffer[BUFSIZ];
	int buffer_len = 0;

	if (argc != 3) {
		printf("Usage: %s file1 file2\n", argv[0]);
		return -1;
	}

	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "w");

	while (fgets(buffer, BUFSIZ, fp1) != NULL)
	{
		printf("$02d: S%", i++, buffer);
		fputs(buffer, fp2);
	}

	fclose(fp2);
	fclose(fp1);

	return 0;//종료
}
