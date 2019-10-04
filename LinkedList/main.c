#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int main(void) {
  int op, dados, pass = 1, des;
  SLList *l;
  void* proc;
  l = sllCreate();

  while(pass==1) {
    op = ApresentarMenu();
    switch(op) {
      case 1:
        if (l!=NULL) {
          dados = inserirDados(l);
          if (dados==1) {
            printf("Dados inseridos com sucesso! \n");
          }
        }
      break;

      case 2:
        opcaoDeProc(l);
      break;

      case 3:
        removerCarro(l);
      break;

      case 4:
        des = sllDestroy(l);
        if (des==1) {
          printf("Dados destruídos! \n");
        }
        else {
          printf("Espaço mantido! \n");
        }
      break;

      case 5:
        listarDados(l);
      break;
    }
    printf("Continuar operação: SIM [1] / NÃO [qualquer tecla] \n");
    scanf("%d", &pass);
  }
}