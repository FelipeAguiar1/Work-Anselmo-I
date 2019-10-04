#ifndef _proj_h_
#define _proj_h_

typedef struct _cofo_ {
  void **elm;
  int max;
  int num;
  int cur;
}cofo;

typedef struct _carro_{
  char *marca;
  int pot;
  int numPort;
  float preco;
  char *placa;
}carro;

cofo *cofCreate(int num);
int cofInsert(cofo *c, void *elm);
void* cofRemove(cofo *c, void* key, int (*cmpPlaca)(void*, void*));
int cofDestroy(cofo *c);
void* cofQuewyM(cofo *c, void* key, int(*cmpMarca)(void*, void*));
void* cofQuewyP(cofo *c, void* key, int(*cmpPlaca)(void*, void*));
int cmpMarca(void* elm1, void* elm2);
int cmpPlaca(void* elm1, void* elm2);
void flush_in();
int ApresentarMenu();
int inserirDados(cofo *c);
void opcaoDeProc(cofo *c);
void removerCarro(cofo *c);
void listarDados(cofo *c);
void imprimirCarro(carro *cr);
void* maisDeUmasPlaca(cofo *c);

#endif