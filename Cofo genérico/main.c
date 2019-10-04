#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"

int main(void) {
  int op, dados, pass = 1, des;
  cofo *c;
  void* proc;

  while(pass==1) {
    op = ApresentarMenu();
    switch(op) {
      case 1:
        printf("Total de carros a serem criadas: \n");
        int num;
        scanf("%d", &num);
        c = cofCreate(num);
        printf("Espaço criado para armazenamento! \n");
      break;

      case 2:
        dados = inserirDados(c);
        if (dados==1) {
          printf("Dados inseridos com sucesso! \n");
        }
      break;

      case 3:
        opcaoDeProc(c);
      break;

      case 4:
        removerCarro(c);
      break;

      case 5:
        des = cofDestroy(c);
        if (des==1) {
          printf("Dados destruídos! \n");
        }
        else {
          printf("Espaço mantido! \n");
        }
      break;

      case 6:
        listarDados(c);
      break;
    }
    printf("Continuar operação: SIM [1] / NÃO [qualquer tecla] \n");
    scanf("%d", &pass);
  }
}