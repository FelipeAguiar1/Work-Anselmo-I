#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

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

int inserirDados(SLList *l) {
  carro *p = (carro*)malloc(sizeof(carro)*1);
  int op;
  
  if (l!=NULL) {
    if (p!=NULL) {
      printf("INFORMAÇÕES PARA ADICIONAR SOBRE O CARRO: \n");
      printf("Marca: \n");
      p->marca = (char*)malloc(sizeof(char)*20);
      if (p->marca!=NULL) {
        scanf("%s", p->marca);
        //flush_in();
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
        //flush_in();
      }
      op = sllInsertFirst(l, p);
      if (op==1) {
        return 1;
      }
    }
  }
  return 0;
}

void listarDados(SLList *l) {
  SLLNode *aux;
  int i = 0;
  
  if (l!=NULL) {
    if (l->first!=NULL) {
      aux = l->first;
      carro *cr1;
      while (aux!=NULL) {
        cr1 = (carro*)aux->data;
        i = i + 1;
        printf("\nCarro %d \n", i);
        imprimirCarro(cr1);
        aux = aux->next;
      }
    }
    else {
      printf("Sem dados a serem listados!\n");
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

void opcaoDeProc(SLList *l) {
  int op;
  char *proc = (char*)malloc(sizeof(char)*20);
  void* exe;

  if (l!=NULL) {
    if (l->first!=NULL) {
      printf("Digite a PLACA do carro: \n");
      scanf("%s", proc);
      flush_in();
      exe = sllQuery(l, proc, cmpPlaca);
      if (exe!=NULL) {
        carro *c2 = (carro*)exe;
        printf("Potencia: %d \n", c2->pot);
        printf("Numero de portas: %d \n", c2->numPort);
        printf("Preço: R$ %.2f \n", c2->preco);
        printf("Marca: %s \n", c2->marca);
      } 
      else {
        printf("Nenhum dado encontrado! \n");
      }
    } else {
      printf("Sem dados armazenados! \n");
    }
  }
}

void removerCarro(SLList *l) {
  char *proc = (char*)malloc(sizeof(char)*20);
  void* exe;

  if (l!=NULL) {
    if (l->first!=NULL) {
      printf("Digite a PLACA do carro: \n");
      scanf("%s", proc);
      flush_in();
      exe = sllRemoveSpec(l, proc, cmpPlaca);
      if (exe!=NULL) {
        carro *c3 = (carro*)exe;
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

void flush_in(){ 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}
/*
int cmpMarca(void* elm1, void* elm2) {
  char *k1 = (char*) elm1;
  carro *k2 = (carro*) elm2;
  int pass;

  pass = strcmp(*k1, *k2->marca);
  if (pass==0) {
    return 1;
  } else {
    return 0;
  }
  if (*k1==*k2->marca) {
    return 1;
  }
  else {
    return 0;
  }
}
*/
int cmpPlaca(void* elm1, void* elm2) {
  char *k1 = (char*) elm1;
  carro *k2 = (carro*) elm2;
  int pass;

  pass = strcmp(k1, k2->placa);
  if (pass==0) {
    return 1;
  } else {
    return 0;
  }
  /*
  if (*k1==*k2->marca) {
    return 1;
  }
  else {
    return 0;
  }
  */
}

SLList *sllCreate() {
  SLList *l = (SLList*)malloc(sizeof(SLList));
  if (l!=NULL) {
    l->first = NULL;
    l->cur = NULL;
    return l;
  }
  return NULL;
}

int sllInsertFirst(SLList *l, void* elm) {
  SLLNode *newNode;
  if (l!=NULL) {
    newNode = (SLLNode*)malloc(sizeof(SLLNode));
    if (newNode!=NULL) {
      newNode->data = elm;
      newNode->next = l->first;
      l->first = newNode;
      return 1;
    }
  }
  return 0;
}

void* sllRemoveFirst(SLList *l) {
  SLLNode *aux;
  void* data;
  if (l!=NULL) {
    if (l->first!=NULL) {
      aux = l->first;
      data = aux->data;
      l->first = aux->next;
      free(aux);
      return data;
    }
  }
  return NULL;
}

int sllInsertLast(SLList *l, void* elm) {
  SLLNode *newNode;
  SLLNode *aux, *prev;
  if (l!=NULL) {
    newNode = (SLLNode*)malloc(sizeof(SLLNode));
    if (newNode!=NULL) {
      newNode->data = elm;
      newNode->next = NULL;
      prev = NULL;
      aux = l->first;
      while (aux!=NULL) {
        prev = aux;
        aux = aux->next;
      }
      if (prev!=NULL) {
        prev->next = newNode;
        return 1;
      }
      l->first = newNode;
      return 1;
    }
  }
  return 0;
}

void* sllRemoveSpec(SLList *l, void* key, int (*cmpPlaca)(void*, void*)) {
  SLLNode *aux, *prev;
  int stat;
  void* data;
  
  if (l!=NULL) {
    if (l->first!=NULL) {
      prev = NULL;
      aux = l->first;
      stat = cmpPlaca(key, aux->data);
      while (aux!=NULL && stat!=1) {
        prev = aux;
        aux = aux->next;
        stat = cmpPlaca(key, aux->data);
      }
      if (stat==1) {
        if (prev!=NULL) {
          prev->next = aux->next;
        } else {
          l->first = aux->next;
        }
        data = aux->data;
        free(aux);
        return data;
      }
    }
  }
  return NULL; 
}

void* sllQuery(SLList *l, void* key, int (*cmpPlaca)(void*, void*)) {
  SLLNode *aux;
  int stat;

  if (l!=NULL) {
    if (l->first!=NULL) {
      aux = l->first;
      while (aux!=NULL) {
        stat = cmpPlaca(key, aux->data);
        if (stat==1) {
          return aux->data;
        }
        aux = aux->next;
      }
    }
  }
  return NULL;
}

int sllDestroy(SLList *l) {
  int op;
  SLLNode *aux, *prev;
  void* data;
  char *proc = (char*)malloc(sizeof(char)*20);

  if (l!=NULL) {
    if (l->first==NULL) {
      free(l);
      return 1;
    }
    else {
      printf("Há dados armazenados. Apagar mesmo assim? SIM [1] / NÃO [Qualquer tecla]\n");
      scanf("%d", &op);
      if (op==1) {
        aux = l->first;
        while (aux!=NULL) {
          prev = aux;
          aux = aux->next;
          proc = (char*)prev->data->placa;
          data = sllRemoveSpec(l,(void*) &data, cmpPlaca);
        }
        free(l);
        return 1;
      }
    }
  }
  return 0;
}