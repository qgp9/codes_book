#include <stdio.h>

int main(){
  const int NK = 3; 
  const int NN = 5;

  int sizes[NK] = { 5, 4, 4 };
  int arr[NK][NN] = {
    {4, 10, 15, 24, 26},
    {0, 9, 12, 20},
    {5, 18, 22, 30},
  };

  int indice[NK];
  for( int k=0;k<NK;k++ ){
    indice[k] = 0;
  }
  int min_k = 0;
  int max_k = 0;
  int range[2] = { -1e9, 1e9 };

  while( indice[min_k] < sizes[min_k] ){
    min_k = max_k = 0;
    for( int k=0;k<NK;k++ ){
      if( arr[min_k][indice[min_k]] > arr[k][indice[k]] ) min_k = k;
      if( arr[max_k][indice[max_k]] < arr[k][indice[k]] ) max_k = k;
    }
    if( arr[max_k][indice[max_k]]-arr[min_k][indice[min_k]] < range[1]-range[0] ){
      range[1] = arr[max_k][indice[max_k]];
      range[0] = arr[min_k][indice[min_k]];
    }
    indice[min_k]++;
  }

  printf("%d\t%d\n",range[1],range[0]);
  return 0;
}
