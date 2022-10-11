#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; 
    cin>>n>>k; 
    set<int> rec; 
    vector<int> ans(maxn);
    vector<int> v(n);
    map<int, int> m, m1; 
    for(int i=0; i<n; i++) cin>>v[i]; 
    int cnt= 1, cc; 
    for(int i=0; i<n; i++){
        auto it = rec.upper_bound(v[i]); 
        //cout<<i<<endl;
        if(it== rec.end()) {
            rec.insert(v[i]); 
            m[v[i]]= cnt; 
            m1[cnt]++; 
            cc= m1[cnt]; 
            cnt++; 

        }
        else{
            int temp= *it;
            rec.erase(*it); 
            rec.insert(v[i]); 
            m[v[i]]= m[temp]; 
            m1[m[temp]]++; 
            cc= m1[m[temp]]; 
        }

        if(cc== k){
            ans[m[v[i]]]= i+1; 
            rec.erase(v[i]); 
        }
    }

    sort(v.begin(), v.end()); 

    for(int i=0; i<n; i++){
            int cntv= m[v[i]];
            if(ans[cntv]==0) ans[cntv]= -1; 
            cout<<ans[cntv]<<endl;
    }
     cout<<endl;
}
