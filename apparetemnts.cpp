#include <bits/stdc++.h>
//g++ -std=c++11 -O2 -Wall x.cpp -o x
//I am using c++ 11
typedef long long ll;
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll m=0,n=0,k=0, x=0, idx=0;
    cin>>n>>m>>k;
    vector<ll> vm;
    vector<ll> vn;
    for (int i=0; i<n; i++){
      cin>>x;
      vn.push_back(x);
    }
    for (int i=0; i<m; i++){
      cin>>x;
      vm.push_back(x);
    }
    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());
    size_t j=0;
    for(size_t i=0; i<vn.size(); i++){
     
       
        while(vn[i]+k>=vm[j] && j < vm.size()){
           
          if (vm[j] >= vn[i]-k){
            idx++;
            j++;
           break;
          }
          j++;
            
        }
       }
            
           
            
        
    
    cout<<idx<<"\n";
            
      

   
   
    return 0;
}

