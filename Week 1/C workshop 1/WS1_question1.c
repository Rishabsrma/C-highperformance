#include <stdio.h>
#include <unistd.h>

void main (int argc, char *argv[]) {
    printf("Hello %s, you are %s years old", argv[1], argv[2]);
}