#include <random>
#include <iostream>

#include <cstdlib>
#include <ctime>
#include <random>

int
random2(int a, int b){
  if(b==a)return -1; // discard a-b==0
  if (b<a) std::swap(a,b);

  return (rand()%(b-a) + a); //[a,b)
}

int // random number [a,b)
random1(int a, int b){
  if(b < a)std::swap(a,b); // make sure a<b

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(a,b);
  return dist(rng);
}

void random3(){
  std::default_random_engine e;
  std::uniform_real_distribution<double> u(0,1);
  for (int i=0; i<20; ++i){
    std::cout<<u(e)<<' ';
  }
  std::cout<<std::endl;

}

int
main(){

  /*
  srand(time(0));
  for(int i=0; i<20; ++i)
    std::cout<<random2(0,10)<<' ';
    */
  random3();
}
