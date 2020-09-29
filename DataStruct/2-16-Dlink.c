#include<stdio.h>
#include<stdlib.h>

typedef int elem_T;

typedef struct DNode {
  elem_T data;
  int freq;
  struct DNode *prev;
  struct DNode *next;
} DNode_T;

static void
initDLink(DNode_T **L, elem_T data){
  (*L)=(DNode_T *)malloc(sizeof(DNode_T));
  (*L)->data=data;
  (*L)->freq=0;
  (*L)->prev=NULL;
  (*L)->next=NULL;
}

static void
createDNode(DNode_T **L, elem_T data){

  DNode_T *s;

  s=(DNode_T *)malloc(sizeof(DNode_T));

  s->data=data;
  s->freq=0;
  s->prev=NULL;
  s->next=(*L);
  (*L)->prev=s;
  (*L)=s;
}

static void
displayDLink(DNode_T *L){
  DNode_T *p;

  for(p=L; p!=NULL; p=p->next){
    printf("data:%d, freq:%d\n", p->data, p->freq);
  }
}

static void
locateNode(DNode_T **L, elem_T x){
  DNode_T *p;

  for(p=(*L); p!=NULL; p=p->next){
    if(p->data==x){
      p->freq++;
      
      /*bubble p*/
      for( ; (p->prev!=NULL) && (p->freq > p->prev->freq); p=p->prev){
        int freqtmp;
        elem_T datatmp;

        /*backup*/
        freqtmp=p->freq;
        datatmp=p->data;

        p->freq=p->prev->freq;
        p->data=p->prev->data;

        p->prev->freq=freqtmp;
        p->prev->data=datatmp;
      }

      break;
    }
  }
}

int
main(){
  int i;
  DNode_T *L;

  initDLink(&L, (elem_T)0);

  for(i=1; i<=10; i++){
    createDNode(&L,(elem_T)i);
  }

  displayDLink(L);

  elem_T x;
  for(;;){
    printf("Please Input element:");
    scanf("%d", &x);
    locateNode(&L, x);
    displayDLink(L);
  }
}
