/* #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> */
//#include <assert.h>
#include "assert.h"

extern void mult(int *list, int *res, int size);
#define printfb(pattern, size) _printfb(size, pattern)
extern void _printfb(int size, unsigned long long pattern);
#define LEN 10

struct float_fields32 {
    unsigned int mants: 23;
    unsigned int expt: 8;
    unsigned int sign: 1;
}__attribute__((packed));


int main(int argc, char ** argv)
{
/*     static int l1[LEN];
    static int l2[LEN];
    
    mult(NULL, NULL, LEN);
    mult(l1, NULL, LEN);
    mult(l1, l2, 0);

    l1[0] = 1;
    mult(l1, l2, 1);
    assertion(l2[0], 0);

    l1[0]=1, l1[1]=2;
    mult(l1, l2, 2);
    assertion(l2[0], l1[1]);
    assertion(l2[1], l1[0]);

    l1[0]=1, l1[1]=2, l1[2]=3;
    mult(l1, l2, 3);
    assertion(l2[0], 6);
    assertion(l2[1], 3);
    assertion(l2[2], 2);
    
    printf("\x1B[32m %s\n", "This is text");

    float f = 0.875;
    struct float_fields32 *fp = &f;
    printfb(*(unsigned*)&f, 32);
    printfb(fp->sign, 1);
    printfb(fp->expt, 8);
    printfb(fp->mants, 23); */
    
    assertFalse(1 == 1);
    assertEquals(0, NULL);
    assertNull(1);
    assertNotNull(NULL);
    assertSame(NULL, 2);
    assertNotSame(2,2);

    char s1[] = "hello world!";
    char s2[] = "hello wordd!";
    assertArrayEquals(s1, s2, 13);

    int i1[] = {0,1,2,3,4};
    int i2[] = {0,1,2,4,4};
    assertArrayEquals(i1, i2, 5);

    _Report();
    return 0;
}