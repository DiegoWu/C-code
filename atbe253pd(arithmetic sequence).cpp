#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<set> 
#define ll long long
#define INF 1000000001
#define mod 998244353
#define mp make_pair
using namespace std;

ll gcd(ll a, ll b){
	if(a== 0)
	 	return b; 
	else if (a== 1)
		return 1;
	b= b%a;
	return gcd(b, a); 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, a, b, ta, tb, tcom; 
    cin>>n>>a>>b; 

    ll zz= n/a;
    ta= (zz*(a+a*zz))/2;  
    if(a==1|| b==1) cout<<0<<endl;
    else if(a==b){ 
    	if(a>n){
    		cout<<((1+n)*n)/2<<endl;
    	}
    	else{
	    	cout<<((1+n)*n)/2-ta<<endl;
    	}
    }
    else if(max(b,a)%min(b,a)==0){

    	ll mn= min(b,a);
    	if(mn>n){
    		cout<<((1+n)*n)/2<<endl;
    	}
    	else{
	    	zz= n/mn; 
	    	n= ((1+n)*n)/2;
	    	ta= (zz*(mn+mn*zz))/2; 
	    	cout<<n-ta<<endl;
    	}
    }
    else{
    	
	    ll zzz= n/b;
    	if(a>n&&b>n){
    		cout<<((1+n)*n)/2<<endl;
    	}
    	else if(a>n){
	     cout<<((1+n)*n)/2-(zzz*(b+b*zzz))/2;
    	}
    	else if(b>n){
    		cout<<((1+n)*n)/2-ta<<endl;
    	}
    	else {
    		ll tt= gcd(a, b); 
    		tt= (a*b)/tt; 
    		ll z= n/tt; 
	    	n= ((1+n)*n)/2;
		    tb= (zzz*(b+b*zzz))/2;   
		    tcom= (z*(tt+z*tt))/2; 
		    
	   		cout<<n-ta-tb+tcom<<endl;
	   		
	   }
	}
}
