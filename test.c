#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>

int main() {
	long pid;
	char *filename;
	long int ret;

	printf("Enter process pid: ");
	scanf("%ld", &pid);
	printf("Enter filename: ");
	scanf("%s", filename);
	printf("\n");

	ret = syscall(315, pid, filename);

	if (ret < 0) {
		if (errno == 2) {
			printf("error: file '%s' doesn't exist.\n", filename);
		}
		if (errno == 3) {
			printf("error: process with pid '%ld' doesn't exist.\n", pid);
		}
	}
	return 0;
}
