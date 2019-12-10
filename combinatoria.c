/*
 * Analise combinatoria
 * Copyright (c) 2019
 * Autor Jótelly Barros
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "split.h"
#include "table.h"
#include "trim.h"

int main(int argc, char *argv[]) {
  char line[255];
  char buffer[256];
  char **argsv;
  int argsc;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s csv_file\n", argv[0]);
    return (1);
  }

  /* Saida arquivo. */
  sprintf(buffer, "saida_%s", argv[1]);
  FILE *fp_saida = fopen(buffer, "w+");

  /* Obtem as configuracoes no arquivo. */
  FILE *fp = fopen(argv[1], "r");

  if (fp) {
    while (!feof(fp)) {
      if (fgets(line, sizeof(line), fp)) {
        Trim_Trim(line, line, ";; \t\r\n");

        if (strlen(line) > 0) {
          Split_Split(line, ";", &argsc, &argsv);
          if (argsc > 1) {
            for (int i = 0; i < argsc; i++) {
              for (int j = i + 1; j <= argsc - 1; j++) {
                sprintf(buffer, "%s%s%s\n", argsv[i], argv[2], argsv[j]);
                printf("%s", buffer);
                fputs(buffer, fp_saida);
              }
            }
          }
          Split_Free(&argsc, &argsv);
        }
      }
    }
  } else {
    printf("Arquivo não existe! \n", argsc);
    return 1;
  }
  fclose(fp_saida);
  fclose(fp);
  return 0;
}
