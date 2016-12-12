/*
 https://leetcode.com/problems/find-the-duplicate-number/
 287. Find the Duplicate Number
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
  int count;
  int findDuplicate(vector<int>& nums) {
    count=0;
    int N = nums.size()-1;
    int bottom = 1;
    int top    = N;
    int left = 0;
    int right = N;
    int nbuffer = 10;
    while( 1 ){
      count++;
      int mid = (top+bottom)/2;
      int n_low = 0;
      // For Speed
      while( left < right ){
        if( nums[left] < bottom ) left++;
        else break;
      }
      while( left < right ){
        if( nums[right] > top ) right--;
        else break;
      }
      if( (top-bottom+1) < nbuffer){
          int nbuffer = top-bottom+1;
          vector<int>buffer(nbuffer,0);
          for( int i=left;i<=right;i++){
            if( nums[i] < bottom || nums[i]>top) continue;
            if( ++buffer[nums[i]-bottom] > 1 ) return nums[i];
          }
      }
      // Actual Logic
      for( int i=left; i<=right; i++ ){
        if( nums[i] >= bottom && nums[i] <= mid )
        n_low++;
      }
      if( n_low > mid-bottom+1 ){
        if( mid == bottom ) return bottom;
        top = mid;
      }
      else{
        if( top == mid+1 ) return top;
        bottom = mid + 1;
      }
    }
    return N+1;
  }
};


int main(){
  std::srand(std::time(0));
  Solution sol;
  for( int ievent=0;ievent<1000;ievent++){
    int n = rand()%10000;
    int x = rand()%n+1;
    int nx = rand()%2? 1 : rand()%n;
    vector<int> nums(n+1);
    for( int k=0;k<n;k++ )
    nums[k] = k+1;
    nums[n] = x;
    for( int k=0;k<nx;k++ )
    nums[rand()%n] = x;

    for( int k=0;k<n;k++ ) swap( nums[rand()%(n+1)],nums[rand()%(n+1)]);
    //for( int k=0;k<n+1;k++ )printf("%s%3d",( (k%20) ? " " : "\n"), nums[k]);cout<<endl;
    //cout<<"\n---- BEGIN"<<endl;
    int res = sol.findDuplicate(nums);
    if( res != x ) exit(1);
    printf("---- i=%5d : n=%4d\tx/found=%4d/%4d\tnx=%4d\tcount=%4d\n",ievent,n,x,res,nx,sol.count);
  }
  return 0;
}
