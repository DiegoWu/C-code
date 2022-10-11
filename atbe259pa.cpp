#include<bits/stdc++.h>

#define ll long long 
#define maxn 92233720368547
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x, t, d; 
	cin>>n>>m>>x>>t>>d; 
	if(m>= x) cout<<t<<endl;
	else{
		int z= t-d*x; 
		z+= d*m; 
		cout<<z<<endl;
	}
	
}

