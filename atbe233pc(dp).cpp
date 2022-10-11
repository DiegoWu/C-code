#include<iostream>
#include<vector>
#include<map>
#define ll long long
#define INF 1000000001
#define mod 998244353
#define mp make_pair
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; 
    ll x; 
    cin>>n>>x; 
    vector<ll> v[n]; 
    for(int i=0; i<n; i++){
    	int a;
    	cin>>a; 
    	for(int j=0; j<a; j++){
    		ll b; 
    		cin>>b; 
    		v[i].push_back(b); 
    	}
    } 
    map<ll, ll> mp; 
    vector<ll> vis; 
    for(int i=0; i<v[0].size(); i++) {
 		mp[v[0][i]]++; 
    	if(mp[v[0][i]]> 1) continue; 
    	vis.push_back(v[0][i]); 
    }
    vector<ll> temp; 
    map<ll, ll> cnt; 
    map<ll, ll> prv;
    for(int i=1; i<n; i++){
    	prv.clear(); 
    	temp.clear(); 
    	for(int j=0; j<vis.size(); j++) prv[vis[j]]= mp[vis[j]]; 
    	mp.clear(); 
    	cnt.clear(); 
    	for(int j=0; j<v[i].size(); j++){
    		for(int k=0; k<vis.size(); k++){
    			if(v[i][j]*vis[k]> x) continue; 
    			mp[v[i][j]*vis[k]]+= prv[vis[k]];  
    			cnt[v[i][j]*vis[k]]++; 
    			if(cnt[v[i][j]*vis[k]]>1) continue; 
    			temp.push_back(v[i][j]*vis[k]);
    		}
    	}
    	if(i== n-1) {
    		cout<<mp[x]<<endl;
    		return 0; 
    	}
    	vis.clear();
    	for(int j=0; j<temp.size(); j++) vis.push_back(temp[j]);
    	
    }

}
