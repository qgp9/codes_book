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
    int findDuplicate(vector<int>& nums) {
        int slow_ptr = 0;
        int fast_ptr = 0;

        do{
            slow_ptr = nums[slow_ptr];
            fast_ptr = nums[nums[fast_ptr]];
        }while ( slow_ptr != fast_ptr);

        fast_ptr = 0;
        while ( slow_ptr != fast_ptr){
            slow_ptr = nums[slow_ptr];
            fast_ptr = nums[fast_ptr];
        }
        return slow_ptr;
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
    printf("---- i=%5d : n=%4d\tx/found=%4d/%4d\tnx=%4d\tcount=%4d\n",ievent,n,x,res,nx,0);
  }
  return 0;
}
