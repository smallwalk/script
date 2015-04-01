#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/types.h>


void func_execlp();
void func_fork();
void func_redirect(char *);

int main(int argc, char *argv[])
{

	//func_execlp();
	//func_fork();
	char *filename;
	filename = argv[1];
	func_redirect(filename);

	printf("Done\n");
	return 0;
}

void func_redirect(char *filename)
{
	if (!freopen(filename, "r", stdin)) {
		fprintf(stderr, "could not redirect stdin from file %s\n", filename);
		exit(2);
	}
	int ch;
	while ((ch = getchar()) != EOF) {
		putchar(toupper(ch));
	}
}

//程序运行结束后，Done并没有出现。替换现有的exec这个程序
void func_execlp() 
{
	printf("Running ps with execlp\n");
	execlp("ps", "ps", "aux", 0);
}


/**
 *
 开始派生子进程
 This is the parent
 This is the child
 This is the child
 This is the parent
 This is the child
 This is the parent
 This is the child
 Done
 GuoChaodeMacBook-Pro:c guochao$ This is the child
 Done
 父进程在输出3次后就退出了，所以在输出内容中混杂了一个shell提示符
 */
void func_fork()
{
	pid_t pid;
	char *msg;
	int n;
	int exit_code;

	printf("开始派生子进程\n");
	pid = fork();

	switch (pid)
	{
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			msg = "This is the child";
			n = 5;
			exit_code = 37;
			break;
		default:
			msg = "This is the parent";
			n = 3;
			exit_code = 0;
			break;
	}

	for (; n > 0; n--) {
		puts(msg);
		sleep(1);
	}

	/*
	if (pid != 0) {
		int stat_val;
		pid_t child_pid;

		child_pid = wait(&stat_val);

		printf("Child has finished: PID=%d\n", child_pid);
		if (WIFEXITED(stat_val)) {
			//printf("Child exited with code %d\n", WEXISTSTATUS(stat_val));
			printf("Child exited with code\n");
		}
		else {

			printf("Child terminated abnormally\n");
			//printf("Child terminated abnormally\n");
		}
	}
	exit(exit_code);
	*/

}
