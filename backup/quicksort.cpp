#include <iostream>

void
displayArray(int a[], int begin, int end){
  for(int i=begin; i<end; ++i){
    std::cout<<*(a+i)<<' ';
  }
  std::cout<<std::endl;
  
}

int
split(int a[], int b, int e){
  auto i=b; //The begin iter
  auto x=a[b]; //take the beginning element as the base.
  for(auto j=b+1; j!=e; ++j){
    if(a[j]<=x){
      ++i;
      if(i!=j) std::swap(a[i],a[j]);
    }
  }

  std::swap(a[b],a[i]);
  displayArray(a,b,e);
  return i;
}


void
quicksort(int a[], int b, int e){

  if(b<e-1){
    auto w=split(a,b,e);
    quicksort(a,b,w-1);
    quicksort(a,w+1,e);
  }

}


int
main(){
  int a[10]={2,32,5,67,876,54,234,53,4562,345};

  displayArray(a,0,10);

  quicksort(a,0,10);

  displayArray(a,0,10);

}
