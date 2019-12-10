/*
 * split.c
 *
 *     This file implements an expression splitter library.
 *
 *     Copyright (C) 2013 Roberto Luiz Souza Monteiro.
 *
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program; if not, write to the Free Software
 *     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * RCS: @(#) $Id: split.c,v 1.0 2013/05/25 13:54:00 monteiro Exp $
 *
 */

#include "split.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * int Split_Split(char *expression, char *separator, int *argc, char ***argv)
 *
 *     Splits an expression in its parts.
 *
 * Arguments:
 *     expression    the expression to split.
 *     separator     a list of characters to match when breaking the string.
 *     argc          the number of parts returned.
 *     argv          an array of strings containing each expression part.
 *
 * Retults:
 *     The function splits an expression in its parts.
 */
int Split_Split(char *expression, char *separator, int *argc, char ***argv) {
  char *p;
  char *start;
  char *end;
  int length;
  char **args;
  int argsc;
  char *arg;
  int i;
  int j;

  /* Get the expression start. */
  p = expression;

  /* Count the number of parts in expression. */
  argsc = 1;

  while (*p) {
    if (strchr(separator, *p) != NULL) {
      argsc++;
    }
    p++;
  }

  /* Allocate space for each expression part. */
  args = (char **)malloc(argsc * sizeof(char **));

  /* Get each expression part. */
  p = expression;

  start = p;
  end = p;

  i = 0;

  while (*p) {
    if (strchr(separator, *p) != NULL) {
      end = p - 1;

      length = end - start + 1;

      /* Allocate space for this expression part. */
      args[i] = (char *)malloc(length * sizeof(char) + 1);

      /* Copy this expression part to the allocated array. */
      arg = args[i];

      for (j = 0; j < length; j++) {
        arg[j] = *start;
        start++;
      }

      arg[j] = '\0';

      /* Restart search. */
      p++;
      i++;

      start = p;
      end = p;
    }

    p++;
  }

  /* Get the last expression part. */
  end = p - 1;

  length = end - start + 1;

  /* Allocate space for this expression part. */
  args[i] = (char *)malloc(length * sizeof(char) + 1);

  /* Copy this expression part to the allocated array. */
  arg = args[i];

  for (j = 0; j < length; j++) {
    arg[j] = *start;
    start++;
  }

  arg[j] = '\0';

  /* Returns the expression parts array. */
  *argv = args;
  *argc = argsc;

  return (*argc);
}

/*
 * void Split_Free(int *argc, char ***argv)
 *
 *     Free an array of strings.
 *
 * Arguments:
 *     argc          the number of strings to free.
 *     argv          an array of strings containing each string to free.
 *
 * Retults:
 *     The function frees an array of strings.
 */
void Split_Free(int *argc, char ***argv) {
  char **p;
  int i;

  p = *argv;

  for (i = 0; i < *argc; i++) {
    free(p[i]);
  }

  free(*argv);

  *argc = 0;
}
