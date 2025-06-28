#include <stdio.h>

int main(int argc, char *argv[]) {
	// Loop from argv[1] to argv[argc-1]
	for (int i = 1; i < argc; i++) {
		printf("Input file: %s\n", argv[i]);
	}
	return 0;
}
