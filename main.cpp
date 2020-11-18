#include "./src/simulatedAnneal.h"


int
main(){
  int TSP[CITY_NUM][CITY_NUM];
  initTSP( TSP );
  printTSP( TSP );

  Answer answer;
  simulatedAnneal( TSP, answer );

  printAnswer( answer );
}
