#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv) {

    const char *s = "hvl:";

    static struct option l[] = {
    	{"list",    required_argument, 0, 'l'},
    	{"version", no_argument,       0, 'v'},
        {"help ",    no_argument,       0, 'h'}, 
        {0, 0, 0},
    };

    const char *h = "Program options:\n"
    "-l[<val1>,...]                        - all arguments\n"
    "-v or --version                       - program version\n"
    "-h or --help                          - options\n";

    

    bool h_bool, v_bool, l_bool = false;
    
    int index, code;

    while ((code = getopt_long(argc, argv, s, l, &index)) != -1) {
        switch (code) {
            case 'h': {
                if (!h_bool) {
                    h_bool = true;
                    printf("%s\n", h);
                }
                break;
            }
            case 'l': {
                if (!l_bool) {
                    char *args;
                    printf("List:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL) {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    l_bool = true;
                }
                break;
            }
            case 'v': {
                if (!v_bool) {
                    v_bool = true;
                    printf("Current version\n");
                }
                break;
            }
            default: {
                printf("Error!\n");
                return 0;
            }
        }
    }
    return 0;
}
