#include<iostream>
#include<vector>
#include<cmath> 
#include<string> 
#include<sstream>
#define ll long long 
#define INF 100000000000
using namespace std; 

int main(){
	ll n; 
	int t; 
	cin>>t; 
	while(t--){
		cin>>n; 
		ll temp= n, c, minn= -1, maxx= -1; 
		if(n%2==1) cout<<-1<<endl;
		else if(n==2) cout<<-1<<endl;
		else{
			n/= 2; 
			if(n%3!= 0) minn= n/3+1;
			else minn= n/3;  
			cout<<minn<<" "<<n/2<<endl;
		}
	}
}