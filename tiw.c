/* Written by Victor Zamanian <victor.zamanian@gmail.com> 2009 */

#ifndef TIMEINWORDS
#include "tiw.h"
#endif

char *singles[] = {
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine"
};

char *doubles[] = {
  "ten",
  "eleven",
  "twelve",
  "thirteen",
  "fourteen",
  "fifteen",
  "sixteen",
  "seventeen",
  "eighteen",
  "nineteen"
};

char *tens[] = {
  "twenty",
  "thirty",
  "forty",
  "fifty",
};

brokentime
getbrokentime (void)
{
  time_t curtime = time (NULL);
  return *localtime (&curtime);
}

char *
gettimestring (char *buffer)
{
  brokentime bt = getbrokentime ();
  char hour[20], min[20];
  if (bt.tm_hour == 0) {
    strcat (hour, doubles[2]);
  } else if (bt.tm_hour < 10) {
    strcat (hour, singles[bt.tm_hour-1]);
  } else if (bt.tm_hour < 20) {
    strcat (hour, doubles[bt.tm_hour - 10]);
  } else {
    strcat (hour, tens[bt.tm_hour / 10 - 2]);

    if (bt.tm_hour % 10 > 0) {
      strcat (hour, "-");
      strcat (hour, singles[bt.tm_hour % 10 - 1]);
    }
  }

  if (bt.tm_min == 0) {
    strcat (min, "sharp");
  } else if (bt.tm_min < 10) {
    strcat ("oh-", singles[bt.tm_min - 1]);
  } else if (bt.tm_min < 20) {
    strcat (min, doubles[bt.tm_min - 10]);
  } else {
    strcat (min, tens[bt.tm_min / 10 - 2]);

    if (bt.tm_min % 10 > 0) {
      strcat (min, "-");
      strcat (min, singles[bt.tm_min % 10 - 1]);
    }
  }

  strcat (buffer, hour);
  strcat (buffer, " ");
  strcat (buffer, min);

  return buffer;
}

int
main (void)
{
  char string[50];
  gettimestring (string);
  printf("%s\n", string);
  return 0;
}
