#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <openssl/rc4.h>
#include <openssl/aes.h>
#include <getopt.h>

int
main(int argc, char* argv[]) //int ,char* ����Ʈ�� �迭 ���� ������ ���(���־��� ���)
{
	int nFd_In = -1;
	int nFd_Out = -1;
	int nRead, nWritten;
	
	unsigned char p_cInputData[AES_BLOCK_SIZE];
	unsigned char p_cOutputData [AES_BLOCK_SIZE];
	
	int bEncryption = false;
	 
	int nopt = -1;
	
	unsigned char p_ckey[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	unsigned char p_cIvec[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };  // Ű, ���� �����ϰ� ���� 

	AES_KEY stKey;

	if (argc != 4) {
		printf("Usage: %s <-e/-d> <in-file> <out-file>\n", argv[0]);
		return -1;
	}
	while ((nopt - getopt(argc, argv, "ed")) > 0) {
		switch (nopt) {
		case 'e':
			bEncryption = true;      // e��� Ʈ��� ����
			break;
		case 'd':
			bEncryption = false;       // d�� �޽��� ����
			break;
		default:
			printf("Usage: %s <-e/-d> <in-file> <out-file>\n", argv[0]);
			return -1;
		}
	}

	printf("CKEY=");
	for (int i = 0; i < 16; i++) {
		printf("%02x", p_ckey[i]);
	}
	
	printf("\n");
	printf("IVEC=");
	
	for (int i = 0; i < 16; i++) {
		printf("%02x", p_cIvec[i]);
	}
	printf("\n");
	printf("Input File: %s\n", argv[optind]);
	printf("Output File: %s\n", argv[optind + 1]);
	
	nFd_In = open(argv[optind], O_RDONLY);                                // �б������ ������������ ���� 
	nFd_Out = open(argv[optind + 1], O_WRONLY | O_CREAT, 0644);
	/* set the encryption stkey */
	AES_set_encrypt_key(p_ckey, 128, &stKey);   // AES �� ���Ѽ��� 128��Ʈ�� ���ڴ�.
    
	int nBlockIndex = 0;
	while (1) {
		nRead = read(nFd_In, p_cInputData, AES_BLOCK_SIZE);      // rc4�� �ٸ��� ��������  �� �� ������ ��ŭ �о� ����
		if (nRead <= 0)
			break;
		if (bEncryption) {  // e ��� ���� ���� ��ȣȭ ��� �����϶�, �ƴϸ� ��ȣȭ ����� �����϶�
			AES_cfb128_encrypt(p_cInputData, p_cOutputData, nRead,
				&stKey, p_cIvec, &nBlockIndex,
				AES_ENCRYPT);
		}
		else {
			AES_cfb128_encrypt(p_cInputData, p_cOutputData, nRead,
				&stKey, p_cIvec, &nBlockIndex,
				AES_DECRYPT);

		}
		nWritten = write(nFd_Out, p_cOutputData, nRead);
	}
		close(nFd_In);
		close(nFd_Out);

	return 0;//����
}
