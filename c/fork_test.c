#include <unistd.h>
#include <stdio.h>

int main() 
{
	pid_t fpid;
	int count = 0;
	fpid = fork();

	if (fpid < 0) {
		printf("error in fork!");
	}
	else if (fpid == 0) {
		printf("i am the child process, my process id is %d parent pid is %d\n", getpid(), getppid());
		count++;
	}
	else {
		printf("i am the parent process, my process id is %d fpid is %d parent pid is %d\n", getpid(), fpid, getppid());	
		count ++;
	}

	printf("统计结果是: %d\n", count);
	return 0;
}
