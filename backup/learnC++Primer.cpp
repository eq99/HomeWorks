#include <string>
#include <vector>
#include <iostream>
#include <cctype>

// ref args
/*
void reseti(int &i){
  i=0;
}
*/

//retrun array pointer
int *createArr(){
  static int arr[10];
  int j=0;
  for( auto i=std::begin(arr); i!=std::end(arr); ++i, ++j )
    (*i)=j*j;

  return arr;
}

int
main(){

  auto p=createArr();
  for( auto i=p; i!=p+10; ++i )
    std::cout<<*i<<' ';


  //string iteror
  /*
  std::string s{"hello world!"};
  for( auto it=s.begin(); it != s.end(); ++it ){
    *it = std::toupper(*it);
  }
  std::cout<<s<<std::endl;
  */

  // array iteror
  /*
  int a[]={1,2,3,4,5};
  int *pbegin=std::begin(a);
  int *pend=std::end(a);
  for( auto p=pbegin; p!=pend; ++p )
    std::cout<<*p<<' ';
  std::cout<<std::endl;
  */


  //muti dim array
  /*
  int a2[2][3]={1,2,3,4,5,6};
  for(auto row=a2; row!=a2+2; ++row )
    for( auto col=(*row); col<(*row)+3; ++col )
      std::cout<<(*col)<<' ';

  for( auto row=std::begin(a2); row!=std::end(a2); ++row )
    for( auto col=std::begin(*row); col!=std::end(*row); ++col )
      std::cout<<(*col)<<' ';
  */

  //ref args
  /*
  int c=42;
  std::cout<<"before:"<<c<<std::endl;
  reseti(c);
  std::cout<<"after:"<<c<<std::endl;
  */

  //array pointer
  /*
  int a[]={10,3,45,67,87,8};
  decltype(a) a1={0,2,35,3};

  for ( auto p=std::begin(a1); p!=std::end(a1); ++p ){
    std::cout<< (*p)<< ' ';
  }
  */


}
