#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int coordinate[2]; /*(x,y)*/
  struct Node *parent; /*The parent node, used to genarate path*/
} Node_T;

#define MAP_SIZE 6
typedef int Map_T[MAP_SIZE][MAP_SIZE];

typedef struct Stark{
  Node_T *node;
  struct Stark *next;
} Stark_T;

void initStark(Stark_T **S){
  (*S)=(Stark_T *)malloc(sizeof(Stark_T));
  (*S)->node=NULL;
  (*S)->next=NULL;
}

void push(Stark_T **S,Node_T *node){
  /*create an new node in stark.*/
  Stark_T *s;
  s=(Stark_T *)malloc(sizeof(Stark_T));
  s->node=node;
  /*Note: S is the header pointer of stack.*/
  s->next=(*S)->next;

  (*S)->next=s;
}

void pop(Stark_T **S,Node_T **n){
  /*s is the node to be pop.*/
  Stark_T *s;
  s=(*S)->next;
  if(s!=NULL){
    (*n)=s->node;
    (*S)->next=s->next;
    free(s);
  }else{
    (*n)=NULL;
  }
}

int findStark(Stark_T *V, int x, int y ){
  Stark_T *p;
  for(p=V->next; p!=NULL; p=p->next){
    if( (p->node->coordinate[0]==x ) && (p->node->coordinate[1]==y ) ){
      return 0; /*find node*/
    }
  }
  return -1; /*didn't find node*/
}

void
disPlayStark(Stark_T *S){
  Stark_T *p;
  for(p=S->next; p!=NULL; p=p->next){
    printf("node:%p, ", p->node);
  }
  printf("\n");
}

void
disPlayMap(Map_T map){
  int i,j;

  printf("The map:\n");
  for(i=0; i<MAP_SIZE; i++){
    for(j=0; j<MAP_SIZE; j++){
      if(map[i][j]==1){/*brick*/
        printf("X");
      }else if(map[i][j]==0){/*road*/
        printf("O");
      }else if(map[i][j]==2){/*trace*/
        printf("*");
      }
    }

    printf("\n");
  }
}

int /*return 0 if a normal child; retrun 1 if exit*/
generateChild(int x, int y, Map_T map, Stark_T **S, Stark_T *V, Node_T **current){
  
  printf("hit(%d,%d)\n",x,y);

  if( ( map[x][y]==0 ) && ( findStark( V, x, y )!=0 ) ){

    printf("process(%d,%d)\n",x,y);

    Node_T *node;
    node = (Node_T *)malloc(sizeof(Node_T));
    node->coordinate[0]=x;
    node->coordinate[1]=y;
    node->parent= *current;

    /* is the exit node? */
    if( (x==4) && (y==4) ){
      printf("find exit!\n");
      (*current)=node;
      return 1;
    }else{
      push(S,node);
    }
  }
  
  return 0;
}

void findExitPath(Map_T *map){
  Node_T start, *current;
  Stark_T *S;/*to be visited*/
  Stark_T *V;/*aready visited*/

  /*init the stark*/
  initStark(&S);
  /*visited node here*/
  initStark(&V);

  start.coordinate[0]=1;
  start.coordinate[1]=1;
  start.parent=NULL;

  printf("start...\n");

  push(&S,&start);

  for(pop(&S,&current); current!=NULL; pop(&S,&current)){

    /*generae left child node*/
    if( generateChild(current->coordinate[0],current->coordinate[1]-1, *map, &S, V, &current ) ==1 ){
      break;
    }
    /*generae right child node*/
    if( generateChild(current->coordinate[0],current->coordinate[1]+1, *map, &S, V, &current ) ==1 ){
      break;
    }
    /*generae top child node*/
    if( generateChild(current->coordinate[0]-1,current->coordinate[1], *map, &S, V, &current ) ==1 ){
      break;
    }
    /*generae bottom child node*/
    if( generateChild(current->coordinate[0]+1,current->coordinate[1], *map, &S, V, &current ) ==1 ){
      break;
    }
    push(&V,current);
  }

  Node_T *p;
  for(p=current; p!=NULL; p=p->parent){
    (*map)[p->coordinate[0]][p->coordinate[1]]=2;
  }

}

int
main(){
  Map_T map={
    {1,1,1,1,1,1},
    {1,0,0,0,1,1},
    {1,0,1,0,0,1},
    {1,0,0,0,1,1},
    {1,1,0,0,0,1},
    {1,1,1,1,1,1}};

  disPlayMap(map);
  findExitPath(&map);
  printf("Path In ");
  disPlayMap(map);
}
