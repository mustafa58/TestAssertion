/* Assert function */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define STRBFSZ 10000
static char Logs[STRBFSZ];
static char* offset = Logs;

void* _memcmp(void *ptr1, void *ptr2, int size)
{ /* Compare two memory locations pointed by args */
    char *p1, *p2;
    for (p1 = ptr1, p2 = ptr2; 
        (p1 - (char *)ptr1)<size && (*p1 == *p2); 
        p1++,p2++);
    if ( (p1 - (char *)ptr1) == size )
        return NULL;
    else return p1;
}

void __LogPrintf(char* format, ...)
{ /* Formatted log using sprintf (variadic of course) */
    va_list args;
    va_start(args, format);
    vsprintf(offset, format, args);
    size_t msglen = strlen(offset);
    strncpy(offset + msglen, "\t-- Assertion Failed\n", 22);
    offset += (msglen + 22 - 1);
    va_end(args);
}

void _Assert (char *mesg)
{ /* print assertion message and abort */
    fputs(mesg, stderr);
    fputs("\t-- Assertion Failed\n", stderr);
    //abort();
}

void _Log (char *mesg)
{ /* Hold assertion messages in a buffer */
    size_t msglen = strlen(mesg);
    strcpy(offset, mesg);
    strncpy(offset + msglen, "\t-- Assertion Failed\n", 22);
    offset += (msglen + 22 - 1);
}

void __Print_Log ()
{ /* Print logs of assertions to stdout */
    fputs(Logs, stdout);
}

void __Report (unsigned int fail, unsigned int pass)
{ /* Report all results in number then show logs */
    printf("%d test(s) failed, %d test(s) passed. \n", fail, pass);
    __Print_Log();
}