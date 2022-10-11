#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 10004
#define mod 998244353
#define mp make_pair

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n, h, m, x; 
		cin>>n>>h>>m;
		x= h*60+m; 
		vector<int> v(n); 
		for(int i=0; i<n; i++){
			int a, b; 
			cin>>a>>b; 
			v[i]= a*60+b; 
			
		}
		sort(v.begin(), v.end()); 
		int pvt= 100000000; 
		for(int i=0; i<n; i++){
			if(v[i]< x){
				pvt= min(pvt, 24*60-x+v[i]); 
			}
			else{
				pvt= min(v[i]-x, pvt); 
			}
		}
		cout<<pvt/60<<" "<<pvt%60<<endl;
	}
}
