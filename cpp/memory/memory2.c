#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define A_MEGABYTE (1024 * 1024)

int main()
{
	/*
	char *some_memory;

	int megs_obtained = 0;

	while (megs_obtained < 2048) {
		some_memory = (char *)malloc(A_MEGABYTE);
		if (some_memory != NULL) {
			megs_obtained ++;
			sprintf(some_memory, "Hello World");
			printf("%s - now allocated %d Megabytes\n", some_memory, megs_obtained);
		}
		else {
			exit(1);
		}
	}
	return 0;
	*/


	char *some_memory;
	int size_to_allocate = 1024;
	int megs_obtained = 0;
	int ks_obtained = 0;

	while (1) {
		for (ks_obtained = 0; ks_obtained < 1024; ks_obtained++) {
			some_memory = (char *)malloc(size_to_allocate);
			if (some_memory == NULL) {
				exit(1);	
			}
			sprintf(some_memory, "Hello World");
		}
		megs_obtained ++;
		printf("%s - now allocated %d Megabytes\n", some_memory, megs_obtained);
	}
	return 0;
}
