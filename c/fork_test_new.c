#include <unistd.h>
#include <stdio.h>

int main() {
	int i=0;
	printf("i son/pa ppid pid fpid\n");

	for (i=0; i<2; i++) {
		pid_t fpid = fork();
		if (fpid == 0) {
			printf("%d son parent_id:%4d pid:%4d fpid:%4d\n", i, getppid(), getpid(), fpid);
		}
		else {
			printf("%d parent parent_id:%4d pid:%4d fpid:%4d\n", i, getppid(), getpid(), fpid);
		}
	}

	return 0;
}

/**
 * i=0 fork后：
 * 1, parent 5169 5184 5185
 *
 * 循环 i = 1
 * 如果parent 5184先行：fork后,系统新增一个进程5186
 * 2, parent 5169 5184 5186
 *
 * i=0时的child执行
 * 3, child 5184 5185 0
 *
 * parent进程return 0进程结束
 *
 * i=1进的child执行
 * 4，child 1 5186 0
 */
