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

#define TABLE_ROW_OK            0
#define TABLE_ROW_NOT_FOUND     1
#define TABLE_COLUMN_OK         0
#define TABLE_COLUMN_NOT_FOUND  1
#define TABLE_EOF               2

char* table_next_row(char *table, char *row, int *status);
char* table_next_column(char *row, char *column, int *status);


