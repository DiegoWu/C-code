#include<bits/stdc++.h>

#define ll long long 
#define maxn 10004
#define mod 1000000007
#define mp make_pair

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	string ans= "Yes"; 
	int n, flip= 0; 
	cin>>n; 
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i]; 
	int i= 0; 

	for(int j=n-1; j>= 0; j--){
		if(i>j) break; 
		if(arr[j]==0&&!flip) continue;
		else if(arr[j]==1&&flip) continue;  
		else{
			if(!flip){
				if(arr[i]==1) ans= "No"; 
				else flip++; 
			}
			else{
				if(arr[i]==0) ans="No"; 
				else flip++; 
			}
			i++; 
		}
		flip%= 2; 
	} 
	cout<<ans<<endl;
}
