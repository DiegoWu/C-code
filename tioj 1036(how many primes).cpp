#include<iostream> 
#include<vector> 
#include<cmath> 

#define maxn 10000000

using namespace std; 

vector<int> notprime(maxn+1); 
void e_sieve(){
	notprime[1]= 1;
	for(int i=2; i<=sqrt(maxn); i++){
		if(!notprime[i]) {
			for(int j=i*2; j<=maxn; j+=i)
				notprime[j]= 1;  
		}
	}
	for(int i=2; i<=maxn-1; i++)
		notprime[i+1]+= notprime[i]; 
	
}

int main(){

	int m; 
	cin>>m; 
	e_sieve(); 
	while(m--){
		int n; 
		cin>>n; 
		if(n==1) cout<<0<<endl; 
		else cout<<n-notprime[n]-1<<endl; 
	}
}