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

	struct passwd* stPasswd;
	struct group* stGroup;

	if (argc != 4) {
		printf("Usage: %s <owner> <group> <fileneme>\n", argv[0]);
		return -1;
	}
	stPasswd = getpwnam(argv[1]);
	stGroup = getgrnam(argv[2]);

	if (stPasswd == NULL || stGroup == NULL)
	{
		printf("Neither User nor Group exists in this system!!\n");
		return -1;
	}

	printf("UID: %d, GID: %d\n", stPasswd->pw_uid, stGroup->gr_gid);

	lchown(argv[3], stPasswd->pw_uid, stGroup->gr_gid);
	
	return 0;//종료
}
