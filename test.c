#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void print(int a, int c)
{
    printf("%d ", a);
    printf("\n");
    printf("%d ", c);
}

int main(int argc, char **argv)
{
    int a = atoi(argv[1]);
    int c = atoi(argv[2]);
    print(a, c);
}