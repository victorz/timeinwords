/* Written by Victor Zamanian <victor.zamanian@gmail.com> 2009 */

#ifndef TIMEINWORDS
#define TIMEINWORDS
#endif

#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct tm brokentime;

brokentime getbrokentime (void);

char *gettimestring (char *buffer);
