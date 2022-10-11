#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define maxn 10000
#define ll long long 
using namespace std;
void solve(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n== 0){
            cout<<0<<"\n";
            continue;
        }
        vector<ll> v;
        vector<ll> vis(maxn); 
        deque<ll> rec;
        for(int i=0; i<n; i++){
            int a; 
            cin>>a;
            v.push_back(a);
        }
        rec.push_back(v[n-1]);
        vis[v[0]]= 1; 
        for(int i=n-2; i>=0; i--){
           if(rec.size()>= 1&& v[i]> rec[rec.size()-1]){
            vis[v[i]]= 1; 
            rec.push_back(v[i]);
           }  
           else{
                //cout<<"i: "<<i<<" "<<"size: "<<rec.size()<<" "; 
                int x= lower_bound(rec.begin(), rec.end(), v[i])- rec.begin();
                vis[rec[x]]= 0; 
                vis[v[i]]= 1; 
                rec[x]= v[i];
            }    
        } 
        for(int i=0; i<n; i++){
            if(vis[v[i]]) continue; 
            int x= lower_bound(rec.begin(), rec.end(), v[i])-rec.begin(); 
        
            if(rec[x]> v[i]&&x<= i) rec[x]= v[i]; 
            else if(rec.size()>= 1&& rec[rec.size()-1]< v[i]&& x<= i) {
                rec.push_back(v[i]); 
            }
            //else if(rec[0]> v[i]) rec.push_front(v[i]); 
        }
        cout<<rec.size()<<"\n";
    }
}
int main() {
    solve();
    return 0;
}