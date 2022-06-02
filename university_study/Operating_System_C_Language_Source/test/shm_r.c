#include <sys/ipc.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <stdio.h>

int  
main()//���μ��� ���� �ڵ�
{
int nShmId = 0;
char* pSharad = 0;

nShmId = shmget(0x1234, 4096, IPC_CREAT | 0666);
//0666 : �а� ���� ���� IPC_CREAT :�޸� ����     
printf("Shared Memory ID is %d\n", nShmId);
//���� �޸� �̸� ����
pSharad = (char*)shmat(nShmId, NULL, 0);
//shmat :�޸� ������ �޸� �ʿ� �߰�

memset (pSharad, 0, 4096);

for (int i = 0; i < 20; i++)
{
    sprintf(pSharad, "Data : %s\n", pSharad);
    sleep(1);//���� �޸� �����ؼ� 1�ʿ� �ѹ� ���ڿ� ��� 
}

shmdt(pSharad);

return 0;
}
