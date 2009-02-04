/*
  This file is part of timeinwords (tiw).

  tiw is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  tiw is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with tiw.  If not, see <http://www.gnu.org/licenses/>.
 */

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
