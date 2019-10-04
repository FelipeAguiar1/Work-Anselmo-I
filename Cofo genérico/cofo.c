#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"

int cmpMarca(void* elm1, void* elm2) {
  char *k1 = (char*) elm1;
  carro *k2 = (carro*) elm2;
  if (*k1==*k2->marca) {
    return 1;
  }
  else {
    return 0;
  }
}

int cmpPlaca(void* elm1, void* elm2) {
  char *k1 = (char*) elm1;
  carro *k2 = (carro*) elm2;
  if (*k1==*k2->placa) {
    return 1;
  }
  else {
    return 0;
  }
}

cofo *cofCreate(int num) {
  cofo *c;
  if (num>0) {
    cofo *c = (cofo*)malloc(1*sizeof(cofo));
    if (c!=NULL) {
      c->elm = (void**)malloc(num*sizeof(void*));
      if (c->elm!=NULL) {
        c->max = num;
        c->num = 0;
        c->cur = -1;
        return c;
      }
    }
  }
  return NULL;
}

int cofInsert(cofo *c, void *elm) {
  if (c!=NULL) {
    if (c->num < c->max) {
      c->elm[c->num] = elm;
      c->num++;
      c->cur++;
      return 1;
    }
  }
  return 0;
}

void* cofRemove(cofo *c, void* key, int (*cmpPlaca)(void*, void*)) {
  void* aux;
  int stat;

  for (int i=0; i<c->num; i++) {
    stat = cmpPlaca(key, c->elm[i]);
    if (stat==1) {
      aux = c->elm[i];
      for (int j=i; j<c->num; j++) {
        c->elm[j] = c->elm[j+1];
      }
      c->num--;
      c->cur--;
      return aux;
    }
  }
  return NULL;
}

int cofDestroy(cofo *c) {
  int opc;

  if (c!=NULL) {
    if (c->num > 0) {
      printf("Ainda existe dados armazenados. Destruir mesmo assim? SIM [1] NÃO [qualquer tecla] \n");
      scanf("%d", &opc);
      if (opc==1) {
        c->num = 0;
        c->cur = -1;
        free(c->elm);
        free(c);
        return 1;
      }
      else {
        return 0;
      }
    } else if (c->num==0) {
      free(c->elm);
      free(c);
      return 1;
    }
  }
  return 0;
}

void* cofQuewyM(cofo *c, void* key, int(*cmpMarca)(void*, void*)) {
  void* aux;
  void* exe;
  int stat, cont = 0;

  if (c!=NULL) {
    if (c->num>0) {
      for (int i=0; i<c->num; i++) {
        stat = cmpMarca(key, c->elm[i]);
        if (stat==1) {
          cont++;
          aux = c->elm[i];
        }
      }
      if (cont>=2) {
        printf("\nMais de um carro encontrado, por favor pesquisar por placas! (Opção 2)\n");
        exe = maisDeUmasPlaca(c);
        if (exe!=NULL) {
          return exe;
        }
      } else if (cont==1) {
        return aux;
      }
    }
  }
  return NULL;
}

void* maisDeUmasPlaca(cofo *c) {
  void* exe;
  char *proc = (char*)malloc(sizeof(char)*20);
  
  if (c!=NULL) {
    printf("Digite a PLACA do carro: \n");
    scanf("%s", proc);
    flush_in();
    exe = cofQuewyP(c, proc, cmpPlaca);
    if (exe!=NULL) {
      return exe;
    }
  }

  return NULL;
}

void* cofQuewyP(cofo *c, void* key, int(*cmpPlaca)(void*, void*)) {
  void* aux;
  int stat;

  if (c!=NULL) {
    if (c->num>0) {
      for (int i=0; i<c->num; i++) {
        stat = cmpPlaca(key, c->elm[i]);
        if (stat==1) {
          aux = c->elm[i];
          return aux;
          break;
        } 
      }
    }
  }
  return NULL;
}

void flush_in(){ 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int ApresentarMenu() {
  int op;

  printf("BEM VINDO!!! \n");
  printf("SELECIONE A OPÇÃO DESEJADA: \n");
  printf("Inserir dados do carro [1] \n");
  printf("Consultar dados do carro [2] \n");
  printf("Remover dados do carro [3] \n");
  printf("Destruir dados dos carros [4] \n");
  printf("Listar dados dos carros [5] \n");
  scanf("%d", &op);

  return op;
}

int inserirDados(cofo *c) {
  carro *p = (carro*)malloc(sizeof(carro)*1);
  int op;
  
  if (c!=NULL) {
    if (p!=NULL) {
      if (c->num < c->max) {
        printf("INFORMAÇÕES PARA ADICIONAR SOBRE O CARRO: \n");
        printf("Marca: \n");
        p->marca = (char*)malloc(sizeof(char)*20);
        if (p->marca!=NULL) {
          scanf("%s", p->marca);
          flush_in();
        }
        printf("Potencia: \n");
        scanf("%d", &p->pot);
        printf("Número de portas: \n");
        scanf("%d", &p->numPort);
        printf("Preço: \n");
        scanf("%f", &p->preco);
        printf("Placa: \n");
        p->placa = (char*)malloc(sizeof(char)*20);
        if (p->placa!=NULL) {
          scanf("%s", p->placa);
          flush_in();
        }

        op = cofInsert(c, p);
        if (op==1) {
          return 1;
        }
      }
    }
  }
  return 0;
}

void opcaoDeProc(cofo *c) {
  int op;
  char *proc = (char*)malloc(sizeof(char)*20);
  void* exe;

  if (c!=NULL) {
    if (c->num > 0) {
      printf("Opção de procura: \n");
      printf("Marca do carro [1] \n");
      printf("Placa do carro [2] \n");
      scanf("%d", &op);
      if (op==1) {
        if (proc!=NULL) {
          printf("Digite a MARCA do carro: \n");
          scanf("%s", proc);
          flush_in();
          exe = cofQuewyM(c, proc, cmpMarca);
          if (exe!=NULL) {
            carro *c1 = (carro*) exe;
            printf("Potencia: %d \n", c1->pot);
            printf("Numero de portas: %d \n", c1->numPort);
            printf("Preço: R$ %f \n", c1->preco);
            printf("Placa: %s \n", c1->placa);
          }
          else {
            printf("Nenhum dado encontrado! \n");
          }
        }
      } else if (op==2) {
        if (proc!=NULL) {
          printf("Digite a PLACA do carro: \n");
          scanf("%s", proc);
          flush_in();
          exe = cofQuewyP(c, proc, cmpPlaca);
          if (exe!=NULL) {
            carro *c2 = (carro*) exe;
            printf("Potencia: %d \n", c2->pot);
            printf("Numero de portas: %d \n", c2->numPort);
            printf("Preço: R$ %.2f \n", c2->preco);
            printf("Marca: %s \n", c2->marca);
          }
          else {
            printf("Nenhum dado encontrado! \n");
          }
        }
      }
    }
    else {
      printf("Sem dados armazenados! \n");
    }
  }
}

void removerCarro(cofo *c) {
  char *proc = (char*)malloc(sizeof(char)*20);
  void* exe;

  if (c!=NULL) {
    if (c->num > 0) {
      printf("Digite a PLACA do carro: \n");
      scanf("%s", proc);
      flush_in();
      exe = cofRemove(c, proc, cmpPlaca);
      if (exe!=NULL) {
        carro *c3 = (carro*) exe;
        printf("Dados apagados: \n");
        printf("Potencia: %d \n", c3->pot);
        printf("Numero de portas: %d \n", c3->numPort);
        printf("Preço: R$ %.2f \n", c3->preco);
        printf("Marca: %s \n", c3->marca);
      }
      else {
        printf("Nenhum dado encontrado! \n");
      }
    }
  }
}

void listarDados(cofo *c) {
  if (c!=NULL) {
    if (c->num > 0) {
      carro *cr1;
      for (int i=0; i<c->num; i++) {
        cr1 = (carro*)c->elm[i];
        printf("\nCarro %d \n", i+1);
        imprimirCarro(cr1);
      }
    }
  }
}

void imprimirCarro(carro *cr) {
  if (cr!=NULL) {
    printf("Marca: %s \n", cr->marca);
    printf("Potencia: %d \n", cr->pot);
    printf("Numero de portas: %d \n", cr->numPort);
    printf("Preço: R$ %.2f \n", cr->preco);
    printf("Marca: %s \n", cr->placa);
  }
  else {
    printf("Nada a exibir! \n");
  }
}
