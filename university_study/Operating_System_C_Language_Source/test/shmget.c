#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
	int nShmId = 0;

	nShmId = shmget(0x1234, 4096, IPC_CREAT|IPC_EXCL|0666);
	//0666 : �а� ���� ���� IPC_CREAT :�޸� ����     
	printf("Shared Memory ID is %d\n", nShmId);

	return 0;
}
