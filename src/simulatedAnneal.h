#include <vector>

#define CITY_NUM 10

typedef std::vector<int> Answer;


void initAnwser(Answer &answer);

int calculateCost(const int (&TSP)[CITY_NUM][CITY_NUM], Answer answer);

void changeAnswer(Answer &answer);

bool isAcceptable(double costDiff, double temperature);

void printAnswer(Answer answer);

void simulatedAnneal(const int (&TSP)[CITY_NUM][CITY_NUM], Answer &answer);

void initTSP(int (&TSP)[CITY_NUM][CITY_NUM]);

void printTSP(const int (&TSP)[CITY_NUM][CITY_NUM]);

