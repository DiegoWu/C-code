#include<bits/stdc++.h>

#define ll long long 
#define maxn 105
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
		vector<string> arr(n); 
		for(int i=0; i<n; i++)
			cin>>arr[i]; 
		int ans= 0; 

		if(n%2==1){
			int x= 0, y= 0, nn= n; 
			for(int i=0; i<n/2; i++){
				int cnt= 0; 
				for(int j=0;j<nn/2; j++){
					cnt= 0;
					if(x+j== x){
						if(arr[x][y]== '1') cnt++; 
						if(arr[n-1-x][n-1-y]== '1') cnt++; 
						if(arr[n-1-x][y]== '1') cnt++; 
						if(arr[x][n-1-y]== '1') cnt++; 
						ans+= min(cnt, 4-cnt); 
					//	cout<<"cK"<<ans<<endl;
					}
					else{
						if(arr[x+j][y]== '1') cnt++; 
						if(arr[n-1-x-j][n-1-y]== '1') cnt++; 
						if(arr[n-1-x][y+j]== '1') cnt++; 
						if(arr[x][n-1-y-j]== '1') cnt++;
						ans+= min(cnt, 4-cnt); 
						//cout<<min(cnt, 4-cnt)<<endl; 
						cnt= 0; 
						if(arr[x][y+j]== '1') cnt++; 
						if(arr[n-1-x][n-1-y-j]== '1') cnt++; 
						if(arr[n-1-x-j][y]== '1') cnt++; 
						if(arr[x+j][n-1-y]== '1') cnt++; 
						ans+= min(cnt, 4-cnt); 
						//cout<<"aiming"<<endl;
						//cout<<min(cnt, 4-cnt)<<endl; 
						//cout<<j<<endl; 
					}
				}
				cnt= 0; 
				if(arr[i][y+nn/2]== '1') cnt++; 
				if(arr[y+nn/2][i]== '1') cnt++; 
				if(arr[n-1-i][y+nn/2]== '1') cnt++; 
				if(arr[y+nn/2][n-1-i]== '1') cnt++; 
				//cout<<"ck: "<ans<<endl;
				ans+= min(cnt, 4-cnt); 
				nn-= 2, x++, y++; 
				//cout<<ans<<endl;
			}
		}
		else{

			int x= 0, y= 0, nn= n; 
			for(int i=0; i<n/2; i++){
				int cnt= 0; 
				for(int j=0;j<nn/2; j++){
					cnt= 0;
					if(x+j== x){
						if(arr[x][y]== '1') cnt++; 
						if(arr[n-1-x][n-1-y]== '1') cnt++; 
						if(arr[n-1-x][y]== '1') cnt++; 
						if(arr[x][n-1-y]== '1') cnt++; 
						ans+= min(cnt, 4-cnt); 
					//	cout<<"cK"<<ans<<endl;
					}
					else{
						if(arr[x+j][y]== '1') cnt++; 
						if(arr[n-1-x-j][n-1-y]== '1') cnt++; 
						if(arr[n-1-x][y+j]== '1') cnt++; 
						if(arr[x][n-1-y-j]== '1') cnt++;
						ans+= min(cnt, 4-cnt); 
						//cout<<min(cnt, 4-cnt)<<endl; 
						cnt= 0; 
						if(arr[x][y+j]== '1') cnt++; 
						if(arr[n-1-x][n-1-y-j]== '1') cnt++; 
						if(arr[n-1-x-j][y]== '1') cnt++; 
						if(arr[x+j][n-1-y]== '1') cnt++; 
						ans+= min(cnt, 4-cnt); 
						//cout<<"aiming"<<endl;
						//cout<<min(cnt, 4-cnt)<<endl; 
						//cout<<j<<endl; 
					}
				}
				cnt= 0; 
				
				nn-= 2, x++, y++; 
				//cout<<ans<<endl;
			}
		
		}
		cout<<ans<<endl;
	}
}
