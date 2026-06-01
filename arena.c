#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    /*int *c = malloc(sizeof(int));

    printf("Test!\n");
    *c = 5; 
    printf("C address = %p, val = %d, c points to %p\n", (void *) &c, *c, c);
    free(c);
    printf("C address after free = %p, C val = %d, c points to %p\n", (void *) &c, *c, c);

    printf("Int size = %lu", sizeof(int));
    */
    // So
    // Malloc grabs a pointer, and makes it point to a piece of memory.
    // You can then assign a value to said memory. 
    // Once you free memory, the pointer continues to point to that spot in memory, but the value there is gone. 
    // Pointer to memory is not lost. 


    // Lets do our arena!
    // Should be able to fit 256 integer pointers in a big chunk here. 
    // Alternativley, can only fit 128 integers. Lets try with that instead.
    printf("Int size = %lu, int pointer size = %lu\n", sizeof(int), sizeof(int*));
    int *arena = malloc(1024);
    printf("\nAllocated 'arena'. Memory address = %p\n\n", arena);
    int *test = arena; 
    printf("Now testing moving 4 bits to the right of the allocated memory chunk. Test = arena, test = %p\n", test);
    test++;
    test++;
    printf("Test++ = %p\n", test);
    // So we are starting here, at wherever test++ x2 is pointing. Can place first one there.
    *test = 5;
    printf("Test value = %d\n", *test);
    int *test2 = test;
    test2++;
    test2++;
    *test2 = 10;
    printf("Test 2, which is test incremented twice, = %d, test = %d\n", *test2, *test);
    printf("All addresses:\n Arena = %p\n Test = %p\n Test2 = %p\n", arena, test, test2);
    printf("Value at arena = %d\n", *arena);
    int *arena2 = arena;
    arena2++;
    printf("Address of arena++ = %p, Value at arena ++ = %d\n", (void *) arena2, *arena2);
    arena2++;
    printf("Address of arena++ again = %p, Value at arena++ again = %d\n", (void *) arena2, *arena2);
    bool check = (arena2 == test);
    printf("%d\n", check);



    return 0;
}