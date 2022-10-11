#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; 
	cin>>n; 

	cout<<n*2<<endl;
	if(n<=4) cout<<n<<endl;
	else{
		int z= n/4; 
		int x= z*4; 
		int g= n-x; 
		if(g!= 0) cout<<g; 
		for(int i=0; i<z; i++) cout<<4; 
		cout<<endl; 
	}

}
