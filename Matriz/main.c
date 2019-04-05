#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void) {
  int op, verifica = 1;
  int linhaA, linhaB;
  int colunaA, colunaB;
  float *vma, *vmb;
  float *vet1, *vet2, *mat1, *mat2, *mat3, *mat4, *mat5;

  printf("MATRIZ A:");
  linhaA = LerLinhaA();
  colunaA = LerColunaA();
  vma = AlocaMatA(linhaA, colunaA);
  printf("\n");

  printf("MATRIZ B:");
  linhaB = LerLinhaB();
  colunaB = LerColunaB();
  vmb = AlocaMatB(linhaB, colunaB);
  printf("\n");

  while (verifica==1) {
    op = ApresentarMenu();
    switch (op) {
      case 1:
        vet1 = MultMatAB(linhaA, colunaA, linhaB, colunaB, vma, vmb);
      break;

      case 2:
        vet2 = multABT(linhaA, colunaA, linhaB, colunaB, vma, vmb);
      break;

      case 3:
        mat1 = MatTransp(linhaA, colunaA, vma);
      break;

      case 4:
        mat2 = TriangSup(linhaA, colunaA, vma);
      break;

      case 5:
        mat3 = DiagonalA(linhaA, colunaA, vma);
      break;

      case 6:
        printf("DIGITE UM VALOR PARA K: ");
        int num;
        scanf("%d", &num);
        mat4 = LinhaK(linhaA, colunaA, vma, num);
      break;

      case 7:
        printf("DIGITE UM VALOR PARA K: ");
        int num_1;
        scanf("%d", &num_1);
        mat5 = ColunaK(linhaA, colunaA, vma, num_1);
      break;
    }
    printf("DESEJA CONTINUAR: SIM [1] / NÃO [2] \n");
    scanf("%d", &verifica);
    if (verifica==2) {
      break;
    }
  }
}