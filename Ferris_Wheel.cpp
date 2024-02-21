#include <bits/stdc++.h>
//g++ -std=c++11 -O2 -Wall x.cpp -o x
//I am using c++ 11
typedef long long ll;
using namespace std;

const int mxN=2e5;
int n, x, a[mxN];
int ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
   // freopen("output.txt", "w", stdout);
    // freopen("test_input.txt", "r", stdin);
  /*
  - first we order the array in order to pair big weights with smaller ones
  - i points at the beginning of the array i=0, j at the end j= n-1
  - if two elemnts can be paired a[i]+a[j] <= x we increment ans++, i++, j--
  - if two elemnts can't be paired we decrement j and , ans++
  why we don't increment i because a[i] is the smaller one we can't get any smaller by incrementing i, but we can with j
  to find a[i]+a[j] <= x
  */
   cin>>n>>x;
   for(int i=0;i<n; i++)
    cin>> a[i];
   sort(a, a+n);
   
   int i=0,j=n-1;
   while(i<=j){
    if(a[i]+a[j]<=x){
        ans++;
        i++;
        j--;
    }else{
        ans++;
        j++;
    }
   }
   cout<<ans<<"\n";
    return 0;
}
