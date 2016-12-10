#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main( int argc, char* argv[] )
{

  unsigned long value = 5712925402340856ul;
  if( argc > 1  )
    value = atol( argv[1] );
  unsigned long denom = 2;
  vector<unsigned long> primeFactors;

  cout << "Target number = " << value << endl;

  while( denom <= value )
  {
    if( value % denom == 0 )
    {
      primeFactors.push_back( denom );
      value /= denom;
    }else{
      denom += denom>2 ? 2 : 1;
      if( denom*denom > value )
        denom = value;
    }
  }

  for( auto factor : primeFactors )
    cout<<factor<<" * ";
  cout<<endl;
  return 0;
}