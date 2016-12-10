#include <iostream>
#include <vector>
#include <algorithm>
class Ranger {
public:
  typedef int value_type;
  struct iterator {
    iterator(size_t counter) : counter(counter) {}
    iterator operator++(){ return iterator(++counter); }
    bool operator!=(iterator o) { return counter != o.counter; }
    value_type operator*(){ return value_type{counter}; }
  private:
    value_type counter;
  };
  Ranger(int begin, int end){ SetRange(begin,end); }
  void SetRange( int begin, int end ){
    if( begin>end ){
      std::cout<<"begin("<<begin<<") must be smaller than end("<<end<<")"<<std::endl;
      exit(1);
    }
    fBegin=begin;fEnd=end;
  }
  iterator begin(){ return iterator(fBegin); }
  iterator end()  { return iterator(fEnd+1); }
private:
  int fBegin;
  int fEnd;
};

template< class T >
Ranger range( std::vector<T> & t, int begin=0, int end=-1 ){ return Ranger( begin, end<0?t.size()-1:end  ); }
Ranger range( int end ){ return Ranger( 0, end-1 ); }
Ranger range( int begin, int end ){ return Ranger( begin, end ); }

using namespace std;
void testRange(){
  std::vector<int> vec = { 1, 2, 3, 4, 5 };

  for( auto i : range( 3 )      ) cout<< i <<", ";cout<<endl;
  for( auto i : range( 1,3 )    ) cout<< i <<", ";cout<<endl;
  for( auto i : range( vec )    ) cout<< i <<", ";cout<<endl;
  for( auto i : range( vec, 2 ) ) cout<< i <<", ";cout<<endl;
}

int main(){
  testRange();
  return 0;
}
