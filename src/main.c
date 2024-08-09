#include <stdio.h>
#include "../include/ping.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "%s", "Input must contain one IP address or URL!\n");
        return 0;
    }

    puts(argv[1]);
    ping(argv[1]);
}
