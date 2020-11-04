#include <string>
#include <vector>
#include <iostream>
#include <cctype>

int
main(){
  std::string s{"hello world!"};

  for( auto it=s.begin(); it != s.end(); ++it ){
    *it = std::toupper(*it);
  }

  std::cout<<s<<std::endl;

  int a[]={1,2,3,4,5};
  int *pbegin=std::begin(a);
  int *pend=std::end(a);

  for( auto p=pbegin; p!=pend; ++p )
    std::cout<<*p<<' ';
  std::cout<<std::endl;
}
