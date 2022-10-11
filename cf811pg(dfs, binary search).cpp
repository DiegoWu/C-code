#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 200005
#define mod 998244353
#define mp make_pair
 
using namespace std;
struct P{
	int an;
	int a, b; 
};

vector<vector<P> > g(maxn); 
vector<ll> rec(maxn); 
vector<int> num(maxn);
vector<ll> temp; 

void dfs(int node, int p, ll cnt, ll cnt1){
	//cout<<node<<endl;
	for(auto [next, a, b]: g[node]){
		num[node]--;
		cnt+= b; 
		cnt1+= a; 
		rec[next]+= cnt1; 

		temp.push_back(cnt); 
		 
		int pos= upper_bound(temp.begin(), temp.end(), rec[next])-temp.begin();
		rec[next]= pos;  
 
		dfs(next, node, cnt, cnt1);
		cnt-= b; 
		cnt1-= a; 
		temp.pop_back(); 
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(NULL); 
	int t; 
	cin>>t; 
	while(t--){
		int n, p; 
		int a, b;
		cin>>n;
		num[1]= 0; 
		for(int i=2; i<n+1; i++){
			cin>>p>>a>>b; 
			num[p]++; 
			g[p].push_back((P){i, a, b}); 
		}	
		dfs(1, 1, 0, 0); 
		for(int i=2; i<n+1; i++) cout<<rec[i]<<" "; 
		cout<<endl;
		for(int i=0; i<n+1; i++) g[i].clear(), rec[i]= 0, num[i]= 0; 
		temp.clear(); 
	}
	return 0; 
}
