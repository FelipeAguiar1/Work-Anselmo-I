#ifndef _proj_h_
#define _proj_h_

typedef struct _SLLNode_ {
  struct _SLLNode_ *next;
  void* data;
}SLLNode;

typedef struct _SLList_ {
  SLLNode *first;
  SLLNode *cur;
}SLList;

typedef struct _carro_{
  char *marca;
  int pot;
  int numPort;
  float preco;
  char *placa;
}carro;

int ApresentarMenu();
int inserirDados(SLList *l);
int cmpMarca(void* elm1, void* elm2);
int cmpPlaca(void* elm1, void* elm2);
SLList *sllCreate();
int sllInsertFirst(SLList *l, void* elm);
void* sllRemoveFirst(SLList *l);
int sllInsertLast(SLList *l, void* elm);
void* sllRemoveSpec(SLList *l, void* key, int (*cmpPlaca)(void*, void*));
void* sllQuery(SLList *l, void* key, int (*cmp)(void*, void*));
int sllDestroy(SLList *l);
void listarDados(SLList *l);
void imprimirCarro(carro *cr);
void flush_in();
void opcaoDeProc(SLList *l);
void removerCarro(SLList *l);

#endif