#include <stdatomic.h>
#include <stdio.h>

int main() {
    volatile int a;
    printf("var is %slock-free\n",
           atomic_is_lock_free(&a) ? "" : "not ");
}
