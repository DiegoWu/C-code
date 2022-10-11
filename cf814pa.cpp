#include<bits/stdc++.h> 
#define ll long long 
#define maxn 200005
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	int t; 
	cin>>t; 
	while(t--){
		int n, m;
		cin>>n>>m;
		if(n%2==0&& m%2== 0) cout<<"Tonya"<<endl;
		else if(n%2==1&& m%2==1) cout<<"Tonya"<<endl;
		else cout<<"Burenka"<<endl;
	}
}
