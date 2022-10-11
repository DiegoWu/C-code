#include<bits/stdc++.h>

#define ll long long 
#define maxn 100005
#define mod 1000000007
#define mp make_pair


using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll cnt= 0, ans= 0; 
	cin>>n; 
	vector<int> v(n+1);
	for(int i=1; i<n+1; i++) {
		cin>>v[i]; 
		if(v[i]==i) cnt++; 
	}
	for(int i=1; i<n+1; i++){
		if(v[i]==i) continue; 
		if(v[v[i]]== i) ans++; 
	}
	cnt= cnt*(cnt-1)/2; 
	ans/= 2; 
	cout<<ans+cnt<<endl;
}
