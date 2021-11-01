#include <stdio.h>

void main() {
    char name [20];
    int age;
    scanf("%s", name);
    scanf("%d", &age);
    printf("Hello %s, you are %d years old.", name, age);
}