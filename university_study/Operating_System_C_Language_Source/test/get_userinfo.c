#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>

int
main(int argc, char* argv[]) //int ,char* 포인트와 배열 더블 포인터 방식(자주쓰는 방식)
{
	struct passwd* stPasswd;
	
	if (argc != 2)
	{
		printf("Usage: %s <username>\n", argv[0]);
		return -1;
	}

	printf("LogIn Account: %s\n", getlogin());
	stPasswd = getpwuid(getuid());//사용자 정보추출,사용자 ID추출

	if (stPasswd == NULL)
	{
		printf("There is no %s ", argv[1]);
		return -1;
	}


	printf("Name: %s\n", stPasswd->pw_name);//비밀번호
	printf("UID: %d\n", stPasswd -> pw_uid);
	printf("GID: %d\n", stPasswd->pw_gid); // 사용자 그룹 추출
	printf("Additional: %s\n", stPasswd->pw_gecos);
	printf("HOME: %s\n", stPasswd->pw_dir);
	printf("Shell: %s\n", stPasswd->pw_shell);


	
	
	return 0;//종료
}
