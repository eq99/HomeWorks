#include<stdio.h>

typedef unsigned long int number_t;

#define MAXN 100000

number_t
getPrimerCount(number_t n){
  number_t primers[MAXN];
  number_t primerCount, i, j;

  primers[0] = 2;
  primerCount = 1;
  
  for(i=2; i<=n; i++){
    for(j=2; j<i; j++){
      if(i%j == 0) break;
      if(j == i-1){
        primers[primerCount]=i;
        primerCount+=1;
        }
     }
  }
  
  return primerCount;
}

int
main(int argc, char *argv[]){
  number_t n = 100;
  
  printf("primer count: %ld\n", getPrimerCount(n));

}
