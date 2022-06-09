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
main(int argc, char* argv[]) //int ,char* ����Ʈ�� �迭 ���� ������ ���(���־��� ���)
{
	int nFd_In = -1;
	int nFd_out = -1;
	
	unsigned char p_cKey[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }; // ��ȣȭ ��ȣ ȭ�� ���� Ű 
	
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
	RC4_set_key(&stRc4Key, 16, p_cKey);          // Ű�� �Է¹ް�

	printf("start to encrypt.\n");
	while (1) {
		nDataLen = read(nFd_In, p_cInputData, BUFSIZ);  // ������ ��� ���Ƽ� 
		if (nDataLen <= 0)
			break;

		RC4(&stRc4Key, nDataLen, p_cInputData, p_cOutputData);  // ������ ��� ��� �մϴ� ��������� ��ȣȭ ��ȣȭ ����
		if (write(nFd_out, p_cOutputData, nDataLen) <= 0)   // �ѹ� �����ϸ� ��ȣȭ �״��� �����ϸ� ��ȣȭ ���� 
			break;
	}
		close(nFd_In);  // ������ ������ ��ȯ�� 
		close(nFd_out);
	
		
		printf("En/De-cryption is done.\n"); // ��� 

	return 0;//����
}
