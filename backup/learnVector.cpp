#include <iostream>
#include <vector>

void
displayVector(const std::vector<int> &v){
  for( auto p=v.begin(); p!=v.end(); ++p )
    std::cout<<(*p)<<' ';
  std::cout<<std::endl;
}

int
main(){
  std::vector<int> v1={2,32,43,43,12};
  std::vector<int> v2;

  v1.push_back(1);
  displayVector(v1);
  v2=v1;
  displayVector(v2);
}


