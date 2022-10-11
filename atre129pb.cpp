#include<iostream>
#include<vector> 
#include<algorithm> 
#include<cmath> 
#define ll long long 
#define mod 1000000009
#define maxn 10000000000
using namespace std ;

int main(){
	int n, l, r, maxx, minn, smin, smax; 
	cin>>n>>l>>r; 
	n--; 
	cout<<0<<endl; 
	vector<int>R; 
	vector<int> L;
	//R.push_back(r), L.push_back(l); 
	maxx= r, minn= l, smin= r, smax= l; 
	while(n--){
		cin>>l>>r; 
		if(l>smax){
			smax= l; 
		}
		if(r<smin){
			smin= r; 
		}
		if(smax-smin<= 0) cout<<0<<endl;
		else {
			if((smax-smin)%2) cout<<(smax-smin)/2+1<<endl;
			else cout<<(smax-smin)/2<<endl;
		}
	}
}