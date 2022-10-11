#include<iostream>
#include<vector>
#include<algorithm>
#include<set> 
#define ll long long 
#define maxn 4005
#define mp make_pair
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ios::sy
	int n, x; 
	cin>>n>>x; 
	cout<<x<<" "; 
	for(int i=1; i<n+1; i++){
		if(i== x) continue; 
		cout<<i<<" ";
	}
	cout<<endl;
}