#include <iostream>
#include <vector>
template< class T >
class myVector : public std::vector<T> {
public:
  myVector():std::vector<T>(){;}
  myVector (unsigned int n, const T& val = T()):std::vector<T>(n, val){;}
  template <class X> myVector (X first, X last):std::vector<T>(first, last){}
  myVector (const std::vector<T>& x):std::vector<T>(x){}
  myVector (std::initializer_list<T> x):std::vector<T>(x){}

  T& operator[](int i){ 
    return this->std::vector<T>::operator[]( i<0 ? this->size()+i : i );
  }
  const T& operator[] (int i) const{
    return this->std::vector<T>::operator[]( i<0 ? this->size()+i : i );
  }
};

using namespace std;
int main(){
  myVector<int> vec = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  cout<<vec[-1]<<endl;
  cout<<vec[-2]<<endl;
  return 0;
}
