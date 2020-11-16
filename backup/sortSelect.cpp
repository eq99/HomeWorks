#include <iostream>

void selectSort(int a[], int num){
  int i, j, tmp;
  
  for(i=0; i<num; i++)
    for(j=i+1; j<num; j++){
      if( a[i]<a[j] ){
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
      }
    }
}

void printArray(int a[], int num){
  for(int i=0; i<num; i++ )
    std::cout<< *(a+i) << ' ';

  std::cout<<std::endl;
}

int main(){
  int a[8]={32,34,24,53,52,65,3,87};
  int num=8;

  printArray(a,num);
  selectSort(a,num);
  printArray(a,num);

}

