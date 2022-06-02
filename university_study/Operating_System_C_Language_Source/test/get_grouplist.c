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
	gid_t nGIds[BUFSIZ];
	int nCount = BUFSIZ;
	int nRet = 0;

	struct passwd* stPasswd;
	struct group* stGroup;

	if (argc < 2) {
		stPasswd = getpwuid(getuid());   
 	}
	else
	{
		stPasswd = getpwnam(argv[1]);
	}
	if (stPasswd == NULL) {     // 사용자의 계정정보를 찾으면 여기 건너 뀜 
		printf("No Accounts!!\n");
		return-1;
	}
	nRet = getgrouplist(stPasswd->pw_name, stPasswd->pw_gid, nGIds, &nCount); // 사용자의 해당되는   정보들을 넘겨주면
	if(nRet <0) {
		printf("Getting group list was failed\n");
		return -1;
	}

	printf("Group of %s is\n", stPasswd->pw_name); // 사용자 이름 출력
	for (int i = 0; i < nCount; i++)
	{
		stGroup = getgrgid(nGIds[i]);       // id 널고
		printf("\t[%02d] : %s(%d)\n", i, stGroup->gr_name, nGIds[i]); // 그룹에 대한 정보 출력 

	}
	printf("Done.\n");  // 이렇게 되면 해당 사용자에 대한 그룹 리스트들을 출력하게 됨
	return 0;//종료
}
