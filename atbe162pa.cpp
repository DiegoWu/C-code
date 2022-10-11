#include<bits/stdc++.h>

#define ll long long 
#define maxn 10004
#define mod 1000000007
#define mp make_pair

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n; 
	if(n%4==2) cout<<n<<endl;
	else if(n%4==1) cout<<n+1<<endl;
	else if(n%4==3) cout<<n+3<<endl;
	else if(n%4==0) cout<<n+2<<endl;
}
