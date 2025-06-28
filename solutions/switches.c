#include <stdio.h>
#include <unistd.h> //for getopt

int main(int argc, char *argv[]) {
	int opt;
	int quiet = 0;

	//Loop through options until getopt returns -1
	while ((opt = getopt(argc, argv, "q")) != -1) {
		switch (opt) {
			case 'q': quiet = 1;
				  break;
			default:
			//getopt prints an error message
			break;
		}
}

// At this point, optind points to the first non-option argument
printf("quiet=%d (optind=%d) \n", quiet, optind);
return 0;
}
