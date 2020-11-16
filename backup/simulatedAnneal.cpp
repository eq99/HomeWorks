


vector<int>
simulatedAnneal(int TSP[]){

  double maxTemperature = 1e6;
  double minTemperature = 1e-6;
  double annealRate = 0.98;
  int maxIterNum = 1000;

  vector<int> answer = getRandomAnser();
  double cost = calculateCost(answer);

  vector<int> newAnswer = answer;
  double newCost = cost; 

  vector<int> bestAnser = answer;

  for( double temperature = maxTemperature; temperature > minTemperature; temperature *= annealRate ){

    for(int iterNumder = maxIterNum ; iterNumder != 0; --iterNumder ){
      newAnswer = getNewAnser(answer);
      newCost = calculateCost(newAnswer);

      costDiff = newCost-cost;

      if( costDiff < 0 ){
        answer = newAnswer;
        cost = newCost;

        if( cost < calculateCost(bestAnser) )
          bestAnser = answer;
      }else{
        if( isAcceptable(costDiff, temperature) ){
          answer = newAnswer;
          cost = newCost;
        }
      }
    }

  }

  return bestAnser;

}


int
main(){
  using CITY_NUM 30;
  int TSP[CITY_NUM][CITY_NUM];
  initTSP( TSP, CITY_NUM );
  printTSP( TSP, CITY_NUM );

  vector<int> answer;
  simulatedAnneal( TSP, CITY_NUM, answer );

  printAnswer( answer );
}
