#include  <stdio.h>

int main(int argc, char *argv[]) {
    int a[5] = {2, 1, 27, 30, 5};

    int i = --a[1];
    int j = a[1]++;
    int k = a[i++];
    printf("%d %d %d\n", i, j, k);

    return 0;
}
