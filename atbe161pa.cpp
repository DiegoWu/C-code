#include<bits/stdc++.h>

#define ll long long 
#define maxn 3003
#define mod 1000000007
#define mp make_pair

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, a1, b, b1; 
	cin>>a>>a1>>b>>b1; 
	if(b>=a1|| a>=b1) cout<<0<<endl;
	else{
		cout<<min(a1, b1)-max(a, b)<<endl;
	}
}
