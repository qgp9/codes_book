#include <iostream>
#include <cstdlib>

using namespace std;

void print(int* v, int n);
int * genArray( int n );
void swap( int &a, int &b ){int tmp=a;a=b;b=tmp;}

void solver( int * arr , int n ){
  if( n == 2 )
    return;

  bool reverse = false;
  if( n%4 == 2 ){
    arr++;
    n -= 2;
    reverse = true;
  }
  for( int i=0;i<n/4;i++ ) 
    swap( arr[i+n/4],arr[i+n/2] );
  solver( arr, n/2 );
  solver( arr+n/2,n/2);
  if( reverse )
    for( int i=0; i<n; i+=2 ) 
      swap( arr[i],arr[i+1] );
}

int main(int argc, char* argv[]){
  int n = 5;
  if( argc > 1 ) n = atoi(argv[1]);
  int * arr = genArray(n);
  print(arr, 2*n);
  solver( arr, 2*n );
  print(arr, 2*n);

  return 0;
}

void print(int* v, int n){
  for(int i=0;i<n;i++ ) cout<<v[i]<<" ";cout<<endl;
}

int * genArray( int n ){
  int * arr = new int[n*2];
  for( int i=0;i<n;i++){
    arr[i] = i+1;
    arr[i+n] = -(i+1);
  }
  return arr;
}
