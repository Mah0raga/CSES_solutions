#include <bits/stdc++.h>
//g++ -std=c++11 -O2 -Wall x.cpp -o x
//I am using c++ 11
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, x=0, idx = 1;
    vector<ll> v;
   
    cin>>n;
    for(ll i=0; i<n; i++){
      cin>>x;
             v.push_back(x);
    }
    sort(v.begin(), v.end());
    if(*v.begin() == *v.end()){
      cout<<idx<<"\n";
      return 0;
    }
    for(ll i=0; i<n-1; i++){
      // cout<<"i-idx: "<<i-idx<<" "<<v[i-idx]<<"\n";
      // cout<<"i-idx+1: "<<i-idx+1<<" "<<v[i-idx+1]<<"\n";
      if(v[i] != v[i+1]){
 
        idx++;
       
      }
    }
    cout<<idx<<"\n";
    

   
   
    return 0;
}
