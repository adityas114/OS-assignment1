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
			printf("error: File '%s' doesn't exist.\n", filename);
		}
		if (errno == 3) {
			printf("error: Process with pid '%ld' doesn't exist.\n", pid);
		}
		if (errno == 25) {
			printf("error: Couldn't get the current tty.\n");
		}
	}
	return 0;
}
