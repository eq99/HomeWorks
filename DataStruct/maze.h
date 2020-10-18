#ifndef _MAZE_H_
#define _MAZE_H_

typedef struct Node {
  int coordinate[2];/*(x,y)*/
  struct Node *parent;
} Node_T;
/**/

#define MAP_SIZE 6

typedef int Map_T[MAP_SIZE][MAP_SIZE];

void
displayMap(Map_T map);

#endif
