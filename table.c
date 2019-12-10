/*
 *
 * table.h
 *
 * A simple table parser.
 *
 * Copyright(C) 2009 Roberto Luiz Souza Monteiro.
 * Todos os direitos reservados.
 *
 * http://www.souzamonteiro.com
 * info@souzamonteiro.com
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

char* table_next_row(char *table, char *row, int *status)
{
    char *p;
    char *q;

    p = table;
    q = row;

    while (1) {
        if ((*p == '\r') || (*p == '\n') || (*p == '\0')) {
            break;
        }

        *q = *p;
        p++;
        q++;
    }
    *q = '\0';

    if ( *p != '\0' ) {
      if (strlen(row) > 0) {
          *status = TABLE_ROW_OK;
      } else {
          *status = TABLE_ROW_NOT_FOUND;
      }

      if ((*p == '\r') || (*p == '\n')) {
          p++;
      }
    } else {
      *status = TABLE_EOF;
    }

    return p;
}

char* table_next_column(char *row, char *column, int *status)
{
    char *p;
    char *q;

    p = row;
    q = column;

    while (1) {
        if ((*p == ';') || (*p == '\0')) {
            break;
        }
        *q = *p;
        p++;
        q++;
    }
    *q = '\0';

    if (strlen(column) > 0) {
        *status = TABLE_COLUMN_OK;
    } else {
        *status = TABLE_COLUMN_NOT_FOUND;
    }

    if (*p == ';') {
        p++;
    }

    return p;
}

