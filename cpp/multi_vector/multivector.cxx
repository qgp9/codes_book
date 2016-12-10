// Gist : https://gist.github.com/qgp9/93f119fd3ee8934fb6721d8df96915f6

#include <iostream>
#include <vector>


//=====================================================
// V1 : Wraper class of vector ( has vector ) 
//=====================================================
template < class T , int dim > 
class MultiVector {
public:
  typedef  typename MultiVector<T,dim-1>::ctype type; 
  typedef  MultiVector<T,dim> ctype; 
  type & operator[]( int i ){ return fArray[i]; }
  const type & operator[] ( int i ) const { return fArray[i]; }
  std::vector< type > * operator->(){ return &fArray; }
  MultiVector<T,dim> & operator<<( type v ){ fArray.push_back( v );return *this; }
private:
  std::vector< type > fArray;
};
template < class T >
class MultiVector<T,0>{
public:
  typedef T ctype;
};



//=====================================================
// V2 : Wraper class of pure multi dimensional vector 
//=====================================================
template < class T , int dim > 
class MultiVector2 {
public:
  typedef  typename MultiVector2<T,dim-1>::ctype type; 
  typedef  std::vector<type> ctype; 
  type & operator[]( int i ){ return fArray[i]; }
  const type & operator[] ( int i ) const { return fArray[i]; }
  ctype * operator->(){ return &fArray; }
  MultiVector2<T,dim> & operator<<( type v ){ fArray.push_back( v );return *this; }
private:
  ctype  fArray;
};
template < class T >
class MultiVector2<T,0>{
public:
  typedef T ctype;
};

//=====================================================
// V3 : Inherit from pure multi dimensional vector
//=====================================================
template < class T , int dim > 
class MultiVector31  {
public:
  typedef  std::vector< typename MultiVector31<T,dim-1>::type > type; 
};
template < class T >
class MultiVector31<T,0>{
public:
  typedef T type;
};

template < class T , int dim > 
class MultiVector3 : public std::vector< typename MultiVector31<T,dim-1>::type > {
};
template <class T> std::vector< T > & operator<<( std::vector<T> &l, T v ){ l.push_back(v);return l;}

//=====================================================
// V4 : Inherit from vector
//=====================================================

template < class T , int dim >  class MultiVector4 : public std::vector< typename MultiVector4<T,dim-1>::ctype > {
public:
  typedef  MultiVector4<T,dim-1>       itype; 
  typedef  MultiVector4<T,dim>         ctype; 
  MultiVector4<T,dim> & operator<<( itype v ){ push_back( v );return *this; }
};
template < class T >  class MultiVector4<T,0> : public std::vector< T > {
public:
  typedef T ctype;
};



//=====================================================
// TEST
//=====================================================


using namespace std;

int main(){

  MultiVector<int, 2> l21;
  l21->resize( 2 );
  l21[0] << 1 <<  2 <<  3 ; 
  l21[1] << 10 <<  20 <<  30 ; 
  for( unsigned int i=0; i<l21->size(); i++ ){
    for( unsigned int j=0; j<l21[i]->size(); j++ )
      cout<< l21[i][j] <<", ";
    cout<<endl;
  }
  MultiVector2<int, 2> l22;
  l22->resize( 2 );
  l22[0] << 1 <<  2 <<  3 ; 
  l22[1] << 10 <<  20 <<  30 ; 
  l22[0].push_back(4);
  for( unsigned int i=0; i<l22->size(); i++ ){
    for( unsigned int j=0; j<l22[i].size(); j++ )
      cout<< l22[i][j] <<", ";
    cout<<endl;
  }

  MultiVector3<int, 2> l23;
  l23.resize( 2 );
  l23[0] << 1 <<  2 <<  3 ; 
  l23[1] << 10 <<  20 <<  30 ; 
  l23[0].push_back(4);
  for( unsigned int i=0; i<l23.size(); i++ ){
    for( unsigned int j=0; j<l23[i].size(); j++ )
      cout<< l23[i][j] <<", ";
    cout<<endl;
  }

  MultiVector4<int, 2> l24;
  l24.resize( 2 );
  l24[0] << 1 <<  2 <<  3 ; 
  l24[1] << 10 <<  20 <<  30 ; 
  l24[0].push_back(4);
  for( unsigned int i=0; i<l24.size(); i++ ){
    for( unsigned int j=0; j<l24[i].size(); j++ )
      cout<< l24[i][j] <<", ";
    cout<<endl;
  }

  return 0;
}
