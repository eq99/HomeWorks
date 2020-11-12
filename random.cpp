#include <random>
#include <iostream>
int // random number [a,b)
randomRange(int a, int b){
  if(b < a)std::swap(a,b); // make sure a<b

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(a,b);
  return dist(rng);
}

int
main(){
  for(int i=0; i<20; ++i)
    std::cout<<randomRange(0,20)<<' ';
}
