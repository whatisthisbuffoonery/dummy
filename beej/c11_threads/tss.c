#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

tss_t str;

void some_function(void)
{
    // Retrieve the per-thread value of this string
    char *tss_string = tss_get(str);

    // And print it
    printf("TSS string: %s\n", tss_string);
}

int run(void *arg)
{
    int serial = *(int*)arg;  // Grab i
    free(arg);//immediate free

    char *s = malloc(64);//ooooo malloc
    sprintf(s, "thread %d! :)", serial);  //smiley face string

    tss_set(str, s);//set to global(tss thread safe) var

    some_function();//func call here

    return 0;   // Equivalent to thrd_exit(0)
				// automatic destructor call (free)
}

#define THREAD_COUNT 15

int main(void)
{
    thrd_t t[THREAD_COUNT];

    // Make a new TSS variable, the free() function is the destructor
    tss_create(&str, free);

    for (int i = 0; i < THREAD_COUNT; i++) {
        int *n = malloc(sizeof *n);  // malloc 1 num at a time
        *n = i;
        thrd_create(t + i, run, n);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        thrd_join(t[i], NULL);
    }

    tss_delete(str);//deinit tss
}
