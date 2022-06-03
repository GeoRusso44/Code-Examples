#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include<limits.h>
 void swap(int* Wa,int* Wb,int  n); void swap2(int * a, int * b); int max( int a, int b); int main(int argc, char* argv[]) { FILE * pFIn= fopen(argv[3], "r"); FILE * pFIn2 =fopen(argv[2], "r"); FILE * writer=fopen("graph.dot", "w"); int length,numVer; int iResult,iResult2; int q=atoi(argv[1]);
if(pFIn ==  NULL || pFIn2 ==  NULL) {        printf("Error opening file\n");        exit(1);
}
else{
iResult=fscanf(pFIn,"%d\n",&length);
char name[length*50]; char* p[length];
for (int i=0;i<length;i++) { p[i]=&name[i*50]; for (int j=0;j<50;j++){ p[i][j]=0; } } for (int i= 0; i<length;i++){ fscanf(pFIn,"%[a-z0-9A-Z ]\n",p[i]);
 
 }  fclose(pFIn);
iResult2=fscanf(pFIn2,"%d\n",&numVer);
int array[numVer*numVer];
for (int i=0; i<numVer;i++) for (int j=0;j<numVer;j++) fscanf(pFIn2,"%d", &array[i*numVer+j]);
fclose(pFIn2);
int Wa[numVer*numVer]; int Wb[numVer*numVer]; int Dq[numVer*numVer]; int P[numVer*numVer];
int minWeight,dist; for (int i=0; i<numVer;i++) for (int j=0;j<numVer;j++){ Wa[numVer*i+j]=array[numVer*i+j]; Wb[numVer*i+j]=array[numVer*i+j]; Dq[numVer*i+j]=array[numVer*i+j]; P[numVer*i+j]=0; } for(int m=1; m<q; m++) { for (int j=0; j<numVer; j++) for (int k=0; k<numVer; k++) { minWeight=__INT_MAX__; for(int g=0; g<numVer; g++) if(g!=j && g!=k) { dist=max(array[numVer*j+g],Wa[numVer*g+k]); if(dist<minWeight) minWeight=dist; } if(minWeight<Dq[numVer*j+k]) Dq[numVer*j+k]=minWeight; Wb[numVer*j+k]=minWeight; }        swap(Wa,Wb,numVer);
    }    for (int j=0; j<numVer; j++)    for (int k=0; k<numVer; k++)    if(k!=j)    if(Dq[numVer*j+k]==array[numVer*j+k])    P[numVer*j+k]=array[numVer*j+k];                               
 
 fputs("graph{\n\t overlap=scale\n", writer);
for (int i=0; i<numVer;i++) for (int j=0;j<numVer;j++) if(P[i*numVer+j]>0) { fputs ("\t", writer); fputs("\"",writer); fputs (p[i], writer); fputs("\"",writer); fputs (" -- ", writer); fputs("\"",writer); fputs (p[j], writer); fputs("\"",writer); fputs ("\n", writer); P[j*numVer+i]=0;
 } fputs ("}", writer); fclose(writer);
}
}
int max( int a, int b){ int maxNum=-1; if(a>b) maxNum=a; else if (b>a) maxNum=b; else maxNum=a; return maxNum; }
 void swap(int* Wa,int* Wb,int  n){
int* p=Wa; int* q=Wb;
for( int i =0; i<n; i++) { p=Wa+i; q=Wb+i; swap2(p,q); }
}
void swap2(int *a, int *b){ *a=(*a)^(*b); *b=(*a)^(*b); *a=(*a)^(*b);
}