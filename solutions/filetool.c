#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/* long_options array synopsis:
   Each element has: .name ("quiet"), .has_arg (no_argument or required_argument),
   .flag (NULL if we want getopt_long to return val), and .val (the shortcut char).
   Think of this as an array of 4-column rows defining each option.
   You can use it without full struct knowledge. */

static struct option long_options[] = {
	{"quiet", no_argument, 0, 'q'}, // --quiet or -q
	{"output", required_argument, 0, 'o'}, // --output=<file> or - o <file>
	{"help", no_argument, 0, 'h'}, // --help or -h 
	{0, 0, 0, 0}		      // termination entry
};

int main(int argc, char *argv[]) {
	int quiet = 0;
	char *outfile = NULL;
	int opt, option_index;

	//Loop over options
	
	while ((opt = getopt_long(argc, argv, "qo:h", long_options, &option_index)) != -1) {
		switch (opt) {
			case 'q':
				quiet = 1;
				break;
			case 'o':
				outfile = optarg; //optarg points to the string following -o
				break;
			case 'h':
				printf("Usage: %s [-q|--quiet] [-o|--output <file>] [--help] <inputs>...\n", argv[0]);
				exit(EXIT_SUCCESS);
			default:
				fprintf(stderr, "Unknown option '%c'. Use --help.\n", optopt);
				exit(EXIT_FAILURE);
			}
	}

	// Report settings
	if (quiet) printf("Quiet mode ON\n");
	if (outfile) printf("Output file; %s\n", outfile);
	
	// Remaining argv entries are inputs
	for (int i = optind; i < argc; i++) {
		printf("Input: %s\n", argv[i]);
	}

	return 0;
}

