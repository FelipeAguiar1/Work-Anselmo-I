#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

int LerLinhaA() {
  FILE *arq1;
  char ch;
  int aux;

  arq1 = fopen("matrizA.txt", "r");

  if (arq1==NULL) {
    printf("Erro, nao foi possivel abrir o arquivo\n");
  }
  else {
    do {
      fscanf(arq1, "%i", &aux);
      //printf("%i ", aux);
      break;
    }
    while ((ch=fgetc(arq1))!= EOF);
  }
  return aux;
  
  fclose(arq1);
}

int LerColunaA() {
  FILE *arq1;
  char ch;
  int aux, coluna;

  arq1 = fopen("matrizA.txt", "r");

  if (arq1==NULL) {
    printf("Erro, nao foi possivel abrir o arquivo\n");
  }
  else {
    do {
      if (ch=='\n') {
        coluna = aux;
        //printf("%d ", coluna);
        break;
      }
      fscanf(arq1, "%i", &aux);
      //printf("%i ", aux);
    } while ((ch=fgetc(arq1))!= EOF);
  }
  return coluna;
  
  fclose(arq1);
}

float *AlocaMatA(int n, int m) {
  FILE *arq;
  float *vma = (float*)malloc(n*m*sizeof(float));
  char aux;

  arq = fopen("matrizA.txt", "r");
  printf("\n");
  aux = fgetc(arq);
  aux = fgetc(arq);
  aux = fgetc(arq);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      fscanf(arq, "%f", &vma[(m*i)+j]);
      printf("%.0f ", vma[(m*i)+j]);
    }
    printf("\n");
    aux = fgetc(arq);
  }

  return vma;

  fclose(arq);

}

int LerLinhaB() {
  FILE *arq1;
  char ch;
  int aux;

  arq1 = fopen("matrizB.txt", "r");

  if (arq1==NULL) {
    printf("Erro, nao foi possivel abrir o arquivo\n");
  }
  else {
    do {
      fscanf(arq1, "%i", &aux);
     // printf("%i ", aux);
      break;
    }
    while ((ch=fgetc(arq1))!= EOF);
  }
  return aux;
  
  fclose(arq1);
}

int LerColunaB() {
  FILE *arq1;
  char ch;
  int aux, coluna;

  arq1 = fopen("matrizB.txt", "r");

  if (arq1==NULL) {
    printf("Erro, nao foi possivel abrir o arquivo\n");
  }
  else {
    do {
      if (ch=='\n') {
        coluna = aux;
       // printf("%d ", coluna);
        break;
      }
      fscanf(arq1, "%i", &aux);
      //printf("%i ", aux);
    } while ((ch=fgetc(arq1))!= EOF);
  }
  return coluna;
  
  fclose(arq1);
}

float *AlocaMatB(int n, int m) {
  FILE *arq;
  float *vmb = (float*)malloc(n*m*sizeof(float));
  char aux;

  arq = fopen("matrizB.txt", "r");
  printf("\n");
  aux = fgetc(arq);
  aux = fgetc(arq);
  aux = fgetc(arq);
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      fscanf(arq, "%f", &vmb[(m*i)+j]);
      printf("%.0f ", vmb[(m*i)+j]);
    }
    printf("\n");
    aux = fgetc(arq);
  }

  return vmb;

  fclose(arq);

}

float *MultMatAB(int n, int m, int p, int q, float *vma, float *vmb) {
  float *vmc;
  
  if (m==p) {
    vmc = (float*)malloc(n*q*sizeof(float));
    if (vmc!=NULL) {
      for (int i=0; i<n; i++) {
        for (int j=0; j<q; j++) {
          for (int k=0; k<m; k++) {
            vmc[(m*i)+j] += vma[(m*i)+k]*vmb[(m*k)+j];
          }
        }
      }
      for (int i=0; i<n; i++) {
        for (int j=0; j<q; j++) {
          printf("%.0f ", vmc[(m*i)+j]);
        }
        printf("\n");
      }
      return vmc;
    }
  }
  return NULL;
}

float *multABT(int n, int m, int p, int q, float *vma, float *vmb) {
  float *vmc, *vmd, *vme;

  vmd = (float*)malloc(p*q*sizeof(float));
  vme = (float*)malloc(n*q*sizeof(float));

  if (vmd!=NULL) {
    for (int i=0; i<q; i++) {
      for (int j=0; j<p; j++) {
        vmd[(q*i)+j] = vmb[(q*j)+i];
      }
    }
  }
  
  if (vme!=NULL) {
    if (m==q) {
      vmc = (float*)malloc(n*p*sizeof(float));
      if (vmc!=NULL) {
        for (int i=0; i<n; i++) {
          for (int j=0; j<p; j++) {
            vmc[(p*i)+j] = 0;
            for (int k=0; k<m; k++) {
              vmc[(p*i)+j] += vma[(m*i)+k]*vmd[(q*k)+j];
              vme[(q*i)+j] = vmc[(p*i)+j];
            }
          }
        } 
        for (int i=0; i<n; i++) {
          for (int j=0; j<q; j++) {
            printf("%.0f ", vme[(m*i)+j]);
          }
          printf("\n");
        }
        return vme;
      }
    }
  }

  return NULL;
}

float *MatTransp(int n, int m, float *vma) {
  float *vmb;

  vmb = (float*)malloc(n*m*sizeof(float));
  
  if (vmb!=NULL) {
    for (int i=0; i<m; i++) {
      for (int j=0; j<n; j++) {
        vmb[(m*i)+j] = vma[(m*j)+i];
      }
    }
    for (int i=0; i<m; i++) {
      for (int j=0; j<n; j++) {
        printf("%.0f ", vmb[(m*i)+j]);
      }
      printf("\n");
    }
    return vmb;
  }

  return NULL;
}

float *TriangSup(int n, int m, float *vma) {
  float *vet;
  int cont = 0;

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (j>i) {
        cont++;
      }
    }
  }

  vet = (float*)malloc(cont*sizeof(float));

  cont = 0;
  if (vet!=NULL) {
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (j>i) {
          vet[cont] = vma[(m*i)+j];
          printf("%.0f ", vet[cont]);
          cont++;
          printf("\n");
        }
      }
    }
    return vet;
  }

  return NULL;
}

float *DiagonalA(int n, int m, float *vma) {
  int cont = 0;

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (i==j) {
        cont++;
      }
    }
  }

  float *diag = (float*)malloc(cont*sizeof(float));

  cont = 0;
  if (diag!=NULL) {
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (i==j) {
          diag[cont] = vma[(m*i)+j];
          cont++;
        }
      }
    }

    for (int i=0; i<cont; i++) {
      printf("%.0f ", diag[i]);
    }
  }
  return diag;
}

float *LinhaK(int n, int m, float *vma, int k) {
  float *linha;

  linha = (float*)malloc(m*sizeof(float));
  printf("\n");
  if (linha!=NULL) {
    for (int i=0; i<n; i++) {
      if (i==(k-1)) {
        for (int j=0; j<m; j++) {
          linha[j] = vma[(m*i)+j];
          printf("%.0f ", linha[j]);
        }
      }
    }
  }

  return linha;

}
/////////////////// COLUNA K DA MATRIZ ////////////////////
float *ColunaK(int n, int m, float *vma, int k) {
  float *coluna;
  
  coluna = (float*)malloc(n*sizeof(float));
  printf("\n");
  if (coluna!=NULL) {
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (j==(k-1)) {
          coluna[i] = vma[(m*i)+j];
          printf("%.0f ", coluna[i]);
        }
      }
    }
  }

  return coluna;

}

int ApresentarMenu() {
  int op;

  printf("ESCOLHA A OPÇÃO DESEJADA: \n");
  printf("Multiplicar matriz A e B [1]\n");
  printf("Multiplicar matriz A por transposta de B [2]\n");
  printf("Transposta de A [3]\n");
  printf("Triangular superior de A [4]\n");
  printf("Diagonal de A [5]\n");
  printf("Linha 'K' de A [6]\n");
  printf("Coluna 'K' de A [7]\n");

  scanf("%d", &op);

  return op;
}