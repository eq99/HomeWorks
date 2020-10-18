
#include "maze.h"

int
main(){

  Map_T map={
    {1,1,1,1,1,1},
    {1,0,0,0,1,1},
    {1,0,1,0,0,1},
    {1,0,0,0,1,1},
    {1,1,0,0,0,1},
    {1,1,1,1,1,1}};

  Node_T *exitNode;

  createMap(&map);
  displayMap(map);
  exitNode=findExit(m);
  displayPath(map,exitNode);
}
