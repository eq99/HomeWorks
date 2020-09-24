#include<stdio.h>
#include<time.h>

typedef unsigned long int number_t;

#define MAXN 100000

number_t
getPrimerCountV1(number_t n){
  number_t primerCount, i, j;

  primerCount = 1;
  
  for(i=2; i<=n; i++){
    for(j=2; j<i; j++){
      if(i%j == 0) break;
      if(j == i-1){
        primerCount+=1;
        }
     }
  }
  
  return primerCount;
}

number_t
getPrimerCountV2(number_t n){

  number_t primers[MAXN];
  number_t primerCount, i, j;
  
  primers[0] = 2;
  primerCount = 1;
  
  for(i=2; i<=n; i++){
    for(j=0; j<=primerCount; j++){
      if(i%primers[j] == 0) break;
      if(j == (primerCount - 1)){
        primers[primerCount]=i;
        primerCount+=1;
        }
     }
  }
  
  return primerCount;
}

int
main(int argc, char *argv[]){
  number_t n = 10000, Result1, Result2;
  time_t start1, end1, start2, end2;
  
  start1=clock();
  Result1=getPrimerCountV1(n);
  end1=clock();

  start2=clock();
  Result2=getPrimerCountV2(n);
  end2=clock();

  printf("primerCountV1 1~%ld : %ld used %f ms\n", n, Result1, difftime(end1,start1));
  printf("primerCountV2 1~%ld : %ld used %f ms\n", n, Result2, difftime(end2,start2));

}
