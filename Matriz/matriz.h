#ifndef _proj_h_
#define _proj_h_

int ApresentarMenu();
int LerLinhaA();
int LerColunaA();
float *AlocaMatA(int n, int m);
int LerLinhaB();
int LerColunaB();
float *AlocaMatB(int n, int m);
float *MultMatAB(int n, int m, int p, int q, float *vma, float *vmb);
float *multABT(int n, int m, int p, int q, float *vma, float *vmb);
float *MatTransp(int n, int m, float *vma);
float *TriangSup(int n, int m, float *vma);
float *DiagonalA(int n, int m, float *vma);
float *LinhaK(int n, int m, float *vma, int k);
float *ColunaK(int n, int m, float *vma, int k);

#endif