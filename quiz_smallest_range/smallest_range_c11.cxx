#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>

typedef std::vector<int> ints;
typedef std::vector<ints> intss;
typedef unsigned int uint;

intss gen_array1(){
  intss arr = {
    {4, 10, 15, 24, 26},
    {0, 9, 12, 20},
    {5, 18, 22, 30},
  };
  return arr;
}


int main(){
  auto arr = gen_array1();
  //== iterators of each array
  std::vector<std::pair<ints*,ints::iterator>> iters( arr.size() );
  ints range(2);
  range[0] = -1e9; // tmp min
  range[1] = 1e9;  // tmp max
  //== point of iterator
  auto min_iter= &iters[0];
  auto max_iter= &iters[0];

  //== Fill inter with first elements of arrays
  for( uint k = 0 ; k < arr.size(); k++ )
    iters[k] = { &arr[k], arr[k].begin() }; 

  //== Loop until end up to any array.
  while(min_iter->second != min_iter->first->end()){
    //== init min/max. can be improved but let's keep simple
    min_iter = max_iter = &iters[0];
    for( auto k = iters.begin() ; k != iters.end(); k++ ){
      //== Can be improved by checking of last max and new iters[min_k]
      if( *(k->second) < *(min_iter->second) ) min_iter = &*k;
      //== Can be improved by checking of last max and new iters[min_k]
      if( *(k->second) > *(max_iter->second) ) max_iter = &*k;
    }
    //printf("min,max => %10d (%2d), %10d (%2d)\n", min,min_k, max, max_k);
    if( *(max_iter->second) - *(min_iter->second) < range[1]-range[0] )
      range = { *(min_iter->second), *(max_iter->second) };
    min_iter->second++;
  }
  std::cout<<range[0]<<", "<<range[1]<<std::endl;
}
