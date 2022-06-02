#include <sys/ipc.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/shm.h>


int  
main()//프로세스 생선 코드
{
int nShmId = 0;
char* pSharad = 0;

nShmId = shmget(0x1234, 4096, IPC_EXCL | 0666);
//0666 : 읽고 쓰기 가능 IPC_CREAT :메모리 생성     
printf("Shared Memory ID is %d\n", nShmId);
//생성 메모리 이름 질문
pSharad = (char*)shmat(nShmId, NULL, 0);
//shmat :메모리 생성후 메모리 쪽에 추가

memset (pSharad, 0, 4096);

for (int i = 0; i < 20; i++)
{
    sprintf(pSharad, "Shared : %d", i);
    sleep(1);   
}

shmdt(pSharad);

return 0;
}
