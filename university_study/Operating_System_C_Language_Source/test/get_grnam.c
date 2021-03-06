#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int
main(int argc, char* argv[]) //int ,char* 포인트와 배열 더블 포인터 방식(자주쓰는 방식)
{
	struct group* stGroup;

	if (argc != 2) {
		printf("Usage: %s [group name]\n", argv[0]);//그룹이름 검색         // 원하는 그룹 정보 입력하면 아래와 같은 내용 출력함
		return -1;
 	}
	
	stGroup = getgrnam(argv[1]);
	if (stGroup == NULL) { //그룹이 존재하지 않다
		printf("No Group!!\n");
		return -1;
	}

	printf("Group Name : %s\n", stGroup->gr_name);//그룹이름
	printf("Memders are : \n");//그룹내 사용자   있으면 계속 출력 
	for (int i = 0; ; i++)
	{
		if (stGroup->gr_mem[i] == NULL)
			break;

		printf("\t[%02d] : %s\n", i, stGroup->gr_mem[i]); //그룹내 아이디 출력

	}
	printf("Done.\n");
	return 0;//종료
}
