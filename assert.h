/* assert-h standard header */
#undef assert /* remove existing definition */
#ifdef NDEBUG
#define assert (test) ( (void) 0)
#else /* NDEBUG not defined */
static unsigned int __failed__;
static unsigned int __passed__;

extern void _Assert (char *) ;
extern void _Log (char *) ;
extern void __LogPrintf (char *format, ...) ;
extern void __Print_Log (void) ;
extern void __Report (unsigned int, unsigned int) ;
extern void* _memcmp (void *, void *, int) ;
  /* macros */
#define NULL ((void *)0)
#define _STR(x) _VAL(x)
#define _VAL(x) #x  /*To convert __LINE__ into string :after: substution*/
#define _Report(...) __Report(__failed__, __passed__)

#define assert(test) ( (test) ? (void) 0 \
  : _Assert(__FILE__ ":" _STR(__LINE__) "\t" #test) )

#define _log(msg) _Log(__FILE__ ":" _STR(__LINE__) "\t" msg)
#define _test(test, job) ( (test) ? (++__passed__) : ({++__failed__; job;}) )
#define _assertCount(test, msg)  _test(test, _log(msg))

#define assertTrue(test)    _assertCount(test, _STR(test))
#define assertFalse(test)   _assertCount( !(test), _STR(!(test)) )
#define assertEquals(x, y)  _assertCount( (x) == (y), _STR((x) == (y)) )

#define assertNull(x)       _assertCount( ((void *)(x) == NULL), "(" #x ") == NULL" )
#define assertNotNull(x)    _assertCount( ((void *)(x) != NULL), "(" #x ") != NULL" )

#define assertSame(x, y)    _assertCount( ((void *)(x) == (void *)(y)), "(" #x ") == (" #y ")" )
#define assertNotSame(x, y) _assertCount( ((void *)(x) != (void *)(y)), "(" #x ") != (" #y ")" )

#define assertArrayEquals(x, y, s) \
({                                                                               \
   char* _r = _memcmp(x, y, s*sizeof(*x));                                       \
   _test(!_r, int _i = (_r-(char *)x)/sizeof(*x);                                \
   __LogPrintf("%s\t%s[%d] != %s[%d]",                                           \
   __FILE__ ":" _STR(__LINE__), #x, _i, #y, _i) );                               \
  })

/* ({ \
   char* _r = _memcmp(x, y, s); \
   (!_r) ? (++__passed__) : \
   ({++__failed__; int _ind = _r-x; \
     __LogPrintf("%s\t%s[%d] != %s[%d]", __FILE__ ":" _STR(__LINE__), #x, _ind, #y, _ind); \
    }); \
 }) */

#endif


// #define assertArrayEquals(x, y, s) _assertArrayEquals(__FILE__, __LINE__, x, y, s, &__failed__, &__passed__)

/* static inline 
void _assertArrayEquals(char* file, int line, 
                        void* x, void* y, int s, 
                        unsigned *fail, unsigned *pass) {
    int indis;
    char* result = _memcmp(x, y, s);
    if (!result) *pass++;
    else {
        *fail++;
        indis = result - (char *)x;
        __LogPrintf("%s:%d\t%s[%d] != %s[%d]", file, line, _STR(x), indis, _STR(y), indis);
    }
} */