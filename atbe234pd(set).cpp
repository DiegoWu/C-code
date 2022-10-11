#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<tuple> 
#include <stdexcept>
#define ll long long
#define INF 1000000001
#define mod 998244353
#define mp make_pair
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; 
    cin>>n>>k; 
    vector<int> v(n); 
   // vector<int> p(k); 
    set<int> st; 
    for(int i=0; i<n; i++)
        cin>>v[i]; 
    for(int i=0; i<k; i++) {
        st.insert(v[i]); 
    }
    //sort(p.begin(), p.end()); 
    auto it= st.begin();
    cout<<*it<<endl; 
    for(int i=k; i<n; i++){
        if(v[i]> *it){
            st.insert(v[i]); 
            st.erase(*it); 
            it= st.begin(); 
            cout<<*it<<endl;
        }
        else{
            cout<<*it<<endl;
        }
    } 
}
