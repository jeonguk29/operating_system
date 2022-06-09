#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <openssl/rc4.h>


int
main(int argc, char* argv[]) //int ,char* 포인트와 배열 더블 포인터 방식(자주쓰는 방식)
{
	int nFd_In = -1;
	int nFd_out = -1;
	
	unsigned char p_cKey[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }; // 암호화 복호 화를 위한 키 
	
	int nDataLen;
	unsigned char p_cInputData[BUFSIZ] = {0};
	unsigned char p_cOutputData[BUFSIZ] = {0};
	
	RC4_KEY stRc4Key;
	
	if (argc != 3) {
	printf("Usage: cmd <in-file> <out-file>\n");
	return -1;
	}
	printf("KEY=");
	for (int i = 0; i < 16; i++) {
	printf("%02x", p_cKey[i]);
	}
	printf("\n");
	
	nFd_In = open(argv[1], O_RDONLY);
	nFd_out = open(argv[2], O_WRONLY | O_CREAT, 0644);

	printf("set key.\n");
	RC4_set_key(&stRc4Key, 16, p_cKey);          // 키를 입력받고

	printf("start to encrypt.\n");
	while (1) {
		nDataLen = read(nFd_In, p_cInputData, BUFSIZ);  // 루프를 계속 돌아서 
		if (nDataLen <= 0)
			break;

		RC4(&stRc4Key, nDataLen, p_cInputData, p_cOutputData);  // 파일을 계속 출력 합니다 결론적으로 암호화 복호화 수행
		if (write(nFd_out, p_cOutputData, nDataLen) <= 0)   // 한번 수행하면 암호화 그다음 수행하면 복호화 가능 
			break;
	}
		close(nFd_In);  // 끝나면 마지막 반환후 
		close(nFd_out);
	
		
		printf("En/De-cryption is done.\n"); // 출력 

	return 0;//종료
}
