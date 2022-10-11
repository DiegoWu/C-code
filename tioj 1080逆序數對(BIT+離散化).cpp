#include<iostream>
#include<queue>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<cmath>
#include<unordered_map>
#include<map>
#define ll long long
using namespace std;
int n; 
int bit[100001]; 
vector<int>v(100001);   
vector<int> use; 
int pos(int node){
    return lower_bound(use.begin(), use.end(), node)-use.begin()+1; 
}
int sum(int w){
    ll s= 0;
    while(w>0){
        s +=bit[w];
        w-= w& -w; // lowbit
    }
    return s;
}
void modify(int z){
    
    while(z<= n){
        bit[z]++;
        z+= z& -z;
    }
    return ; 
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int c= 1;
    while(cin>>n&& n){
        ll ss= 0;
        for(int i=0; i<n; i++){
            cin>>v[i]; 
            bit[i]= 0; 
            use.push_back(v[i]); 
        }
        bit[n]= 0; 
        sort(use.begin(), use.end()); 
        use.erase(unique(use.begin(), use.end()), use.end()); 

        for(int i=0; i<n; i++){
           
            ss+= i-sum(pos(v[i]));
            modify(pos(v[i]));
        }
        cout<<"Case #"<<c<<": "<<ss<<endl;
        use.clear(); 
        c++;
        v.clear(); 
    }
    return 0;
}
