
#include<stdio.h>

typedef unsigned long long int number_t;

static number_t
getFactorSum(number_t  n){
  number_t previousResult, sum;

  previousResult=1;
  sum=0;
  for(int i=1; i<=n; i++){
    previousResult=previousResult*i;
    sum+=previousResult;
  }
  return sum;
}

int
main(){

  number_t n = 4;
  printf("1!+...+%ld! = %ld\n", n, getFactorSum(n));
}
