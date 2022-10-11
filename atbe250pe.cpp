#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include <stdexcept>
#define ll long long
#define INF 1000000001
#define mod 998244353
using namespace std;

struct tuple{
    int a, b, c; 
}; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; 

    cin>>n>>q; 
    vector<tuple> v; 
    for(int i=0; i<q; i++){
        int a, b; 
        cin>>a>>b; 
        v.push_back((tuple){a, b, i}); 
    }

}
