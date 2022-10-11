#include<iostream> 
#include<vector>
#include<algorithm> 
#include<string> 
#include<cmath> 
#define ll long long 
using namespace std; 
int gcd(int a, int b){
	if(!a) return b; 
	return gcd(b%a, a); 
}
void extgcd(int a, int b, int &x, int &y){
	if(!b) {
		x= 1, y= 0; 
	}
	else{
		int x_, y_; 
		 extgcd(b, a%b, x_, y_);
		// 小問題解求大問題解
		x= y_; 
		y= x_-(a/b)*y_;  
	}
}
int main(){
	int a, n; 
	while(cin>>a>>n){
		int x, y; 
		if(gcd(min(a, n), max(a, n))!= 1|| n==1) cout<<"No Inverse"<<endl;
		else {
			extgcd(a, n, x, y); 
			if(x< 0){
				int t= abs(x)/n; 
				t++; 
				x+= n*t; 
			}
			cout<<x<<endl;
		}
	}
}
