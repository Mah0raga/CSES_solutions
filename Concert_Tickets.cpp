#include <bits/stdc++.h>
//g++ -std=c++11 -O2 -Wall x.cpp -o x
//I am using c++ 11
typedef long long ll;
using namespace std;

int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    set<array<int ,2>> s;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        s.insert({a, i});
    }
    for(int i=0; i<m; i++){
        int t;
        cin>>t;
       /*
       There are 4 conditions:
       - the lower_bound function found a value  = t we will print it and remove it from the set
       - the lower bound function found a value > t because it did not find a value = t this means that the value before
       this value grater than t should be lesser than t we print the value before the one pointer by iterator *prev(t) and
       we also need to make sure that the value pointed by the iterator is noth s.begin() because there is no value before it
       - the lower bound function did not find any value >= t it == s.end() if it != s.begin() we print the value before
       the iterator it should be <t and because the set is ordered it is the greatest value in the set and closest value
       to t we also need to check that this value is less than t because may be all the values in the set are greater
       than t if there is one element in the set this part of the code should take care of that too
       - if non of the above is true we have two options either
            - All the values in the set are grater than t we need to print -1
            - Either the set is empty we also need to print -1
        Writing better code:
        If you observe the code you will see that we can make it shorter and optimize it
        - we can combine the first and the second conditions in one condition by giving s.lower_bound({t+1, 0}) the value t+1
        the value before t+1 will either be t if not a value lesser than t ubt first we need to check that the iterator is
        not pointing at the s.begin() because there is no value beforfe it
        - if all the values are lesser than t+1 and s.lower_bound returned s.end() we will return the value before s.end()
        it should be the closest to t but first we nee check that the iterator is not pointing at s.begin()
        - if all the values in the set are grater than t+1 s.lower_bound will return s.begin()
        - if the set is empty s.lower_bound will return s.begin()
        using all of this obeservations we can write the code like this
        --------------------------------------------------------------------------------------------------------
        int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    
    cin >> n >> m;
    set<array<int ,2>> s;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        s.insert({a, i});
    }
    for(int i=0; i<m; i++){
        int t;
        cin>>t;
        
        auto it = s.lower_bound({t+1, 0});
        if(it == s.begin())
            cout<<"-1\n";
        else {
            --it;
            cout<<(*it)[0]<<"\n";
            s.erase(it);
        }
    }
}
        --------------------------------------------------------------------------------------------------------
       - One last thing why set<arr<int, 2>>
       why we store the value and its order {t, i}
       - We want to use sets and sets store only unique elemtns to solve this problem
       we have added the index to now we can store duplicate elements
       */
        auto it = s.lower_bound({t, 0});
        if((*it)[0] == t){
            cout<<t<<"\n";
            s.erase(it);
        }else if((*it)[0] > t && it != s.begin()){

            cout<<(*prev(it))[0]<<"\n";
            s.erase(prev(it));

        }else if(it == s.end() && it != s.begin() && (*prev(it))[0] < t){
            cout<<(*prev(it))[0]<<"\n";
             s.erase(prev(it));
        }else
            cout<<"-1\n";
        
    }
}
