#include<stdio.h>
#include<stdlib.h>

#define N 5 /*dimention of polynomial*/

typedef struct SLink{
  int data;
  struct SLink *next;
}SLink_t;

void
initSLink(SLink_t **L){
  (*L)=(SLink_t *)malloc(sizeof(SLink_t));

  (*L)->data=0;
  (*L)->next=NULL;
}

void
addSLinkNode(SLink_t **L, int data){
  SLink_t *s;

  s=(SLink_t *)malloc(sizeof(SLink_t));
  s->data=data;
  s->next=NULL;
  
  SLink_t *p;
  for(p=(*L); p!=NULL; p=p->next){
    if(p->next == NULL){
      p->next = s;
      break;
    }
  }
}

int
getCoefByIndex(SLink_t *L, int i){
  SLink_t *p;
  int j;

  for(j=0, p=L->next; p!=NULL; p=p->next, j++ ){
    if(j == i){
      return p->data;
    }
  }
}

void
displayDLink(SLink_t *L){
  SLink_t *p;
  int i;

  printf("%d", L->next->data);
  for(i=1, p=L->next->next; p!=NULL; i++, p=p->next){
    if(p->data == 0)continue;

    if(p->data == 1){
      printf(" + x^%d", i);

    }else{
      printf(" + %dx^%d", p->data, i);
    }
  }

  printf("\n");

}

int
main(){
  SLink_t *L1, *L2, *L3;/*polynomial L1, L2, and L3*/

  initSLink(&L1);
  initSLink(&L2);
  initSLink(&L3);

  int i, j;

  int c1[N]={0,0,0,0,1};
  int c2[N]={1,2,3,4,5};

  for(i=0; i<N; i++){
    addSLinkNode(&L1, c1[i]);
    addSLinkNode(&L2, c2[i]);
  }

  printf("L1 and L2:\n");
  displayDLink(L1);
  displayDLink(L2);
  int ci; 
  for(i=0; i<N*N; i++){
    
    ci=0;
    for(j=0; j<=i; j++){
      ci+=getCoefByIndex(L1, j)*getCoefByIndex(L2, i-j);
    }
    addSLinkNode(&L3, ci);
  }

  printf("The result of L1*L2:\n");
  displayDLink(L3);
}
