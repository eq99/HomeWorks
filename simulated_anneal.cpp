#include <iostream>
#include <vector>
#include <algorithm> // ramdom_shuffle
#include <cmath> // exp()
#include <random> 
#include "simulatedAnneal.h"
#include <ctime> //time()
#include <fstream>

void initAnswer(Answer &answer){
  for(int i=0; i<CITY_NUM; ++i){
    answer.push_back(i);
  }
  std::random_shuffle(answer.begin(),answer.end());
}

int calculateCost(const int (&TSP)[CITY_NUM][CITY_NUM], Answer answer){
   int cost = TSP[ answer[CITY_NUM-1] ][ answer[0] ];
   for(int i=0; i<CITY_NUM-1; ++i){
     cost+=TSP[ answer[i] ][ answer[i+1] ];
   }

   return cost;
}

void changeAnswer(Answer &answer){
  std::random_shuffle(answer.begin(),answer.end());
  
}

bool isAcceptable(int costDiff, double temperature){
  std::default_random_engine e;
  std::uniform_real_distribution<double> u(0,1);
  return  ( exp(-costDiff/temperature) > u(e) );
}

void printAnswer(Answer answer){
  std::ofstream record("record.txt", std::ios::app);
  for(auto p=answer.begin(); p!=answer.end(); ++p){
    std::cout<<(*p)<<' ';
    record<<(*p)<<' ';
  }
  std::cout<<std::endl;
  record<<std::endl;
  record.close();
}


void simulatedAnneal(const int (&TSP)[CITY_NUM][CITY_NUM], Answer &answer){
  std::ofstream record("record.txt", std::ios::app);

  double maxTemperature = 1e2;
  double minTemperature = 1e-2;
  double annealRate = 0.98;
  int maxIterNum = 10;

  initAnswer(answer);
  int cost = calculateCost(TSP, answer);

  Answer newAnswer = answer;
  int newCost = cost; 

  Answer bestAnser = answer;

  for( double temperature = maxTemperature; temperature > minTemperature; temperature *= annealRate ){

    for(int iterNumder = maxIterNum ; iterNumder != 0; --iterNumder ){
      changeAnswer(newAnswer);
      newCost = calculateCost(TSP, newAnswer);
      
      std::cout<<"newcost: "<<newCost<< "  oldcost: "<<cost<< std::endl;
      record<<"newcost: "<<newCost<< "  oldcost: "<<cost<< std::endl;

      int costDiff = newCost-cost;

      if( costDiff < 0 ){
        answer = newAnswer;
        cost = newCost;
        std::cout<<"accepted < 0"<<newCost<<std::endl;
        record<<"accepted < 0"<<newCost<<std::endl;

        if( cost < calculateCost(TSP, bestAnser) )
          bestAnser = answer;
      }else{
        if( isAcceptable(costDiff, temperature) ){
          answer = newAnswer;
          cost = newCost;
          std::cout<<"accepted > 0"<<newCost<<std::endl;
          record<<"accepted > 0"<<newCost<<std::endl;
        }
      }
    }

  }

  record.close();
  answer = bestAnser;

}

void initTSP(int (&TSP)[CITY_NUM][CITY_NUM]){
  std::default_random_engine e;
  std::uniform_int_distribution<unsigned> u(10,99);
  for(int i=0; i<CITY_NUM; ++i){
    for(int j=0; j<CITY_NUM; ++j){
      TSP[i][j] = u(e);
    }
  }
  
}

void printTSP(const int (&TSP)[CITY_NUM][CITY_NUM]){
  std::ofstream record("record.txt", std::ios::app);
  for(int i=0; i<CITY_NUM; ++i){
    for(int j=0; j<CITY_NUM; ++j){
      std::cout<<TSP[i][j]<<' ';
      record<<TSP[i][j]<<' ';
    }
    std::cout<<std::endl;
    record<<std::endl;
  }
  record.close();
}

int main(){
  int TSP[CITY_NUM][CITY_NUM];
  initTSP( TSP );
  printTSP( TSP );

  Answer answer;
  simulatedAnneal( TSP, answer );

  printAnswer( answer );
}
