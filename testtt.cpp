#include <iostream>
#include<queue>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<math.h>
#include<unordered_map>
#define ll long long
using namespace std;
int n, maxx= 0;
unordered_map<int, int> bit;
ll sum(ll i){
    ll s= 0;
    while(i>0){
        s +=bit[i];
        i-= i& -i; // lowbit
    }
    return s;
}
void modify(ll i){
    if(i==maxx) {
        bit[i]+= 1;
        return;
    }
    while(i< maxx){
        bit[i]+= 1;
        i+= i& -i;
    }
}
int main(){
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    int c= 1;
    while(scanf("%d", &n)&& n){
        ll ss= 0;
        for(int i=0; i<n; i++){
            int a;
            scanf("%d", &a);
            if(a> maxx) maxx= a;
            else ss+= sum(maxx)-sum(a);
            modify(a);
        }
        printf("Case #%d: %d\n", c, ss);
        //cout<<"Case #"<<c<<c<<ss<<endl;
        c++;
        maxx= 0;
        bit.clear();
    }
    return 0;
}
