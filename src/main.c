#include <stdio.h>
#include "../include/ping.h"

int main(int argc, char* argv[]) {
    puts(argv[1]);
    ping(argv[1]);

    return 0;
}
