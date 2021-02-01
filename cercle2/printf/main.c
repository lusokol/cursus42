#include <stdio.h>
int main(int ac, char **av)
{
    printf("%%d     :=%d=\n", 123);
    printf("%%5d    :=%5d=\n", 123);
    printf("%%.2d   :=%.2d=\n", 123);
    printf("%%5.10d :=%5.10d=\n", 123);
    printf("%%10.5d :=%10.5d=\n\n", 123);
    printf("%%s     :=%s=\n", "test");
    printf("%%5s    :=%5s=\n", "test");
    printf("%%.5s   :=%5.3s=\n", "test");
    printf("%%5.10s :=%5.10s=\n", "test");
    printf("%%10.5s :=%10.5s=\n", "test");
}