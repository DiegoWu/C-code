#include<bits/stdc++.h>

#define ll long long 
#define maxn 3003
#define mod 1000000007
#define mp make_pair

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; 
	cin>>t; 
	while(t--){
		int n;
		cin>>n; 
		if(n==1) cout<<1<<endl;
		else{
			
			cout<<n<<" ";
			for(int i=1; i<n; i++) cout<<i<<" "; 
			cout<<endl;
		}
		
	}
	
}
