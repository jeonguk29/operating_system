#include <unistd.h>
#include <stdio.h>

int main(void)
{

	for (int i = 0;; i++)
	{
		if (access("test.txt", F_OK) == 0)  //test.txt ���� �ִ��� Ȯ��
		{
			printf("There is a file(%05d).\n", i);  // ������ ���
		}
		usleep(5000);    // rm���� �ý�Ʈ ���� ����� �����ϸ� ��� �ȵ�
	}
	return 0;
}