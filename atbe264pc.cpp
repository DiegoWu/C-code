#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 9223372036854775807
#define mod 998244353
#define mp make_pair

using namespace std;
using P= pair<ll, int>; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	int h, w, h1, w1; 
	cin>>h>>w; 
	int arr[h][w];
	for(int i=0; i<h; i++)
		for(int j=0;j<w; j++) cin>>arr[i][j]; 
	cin>>h1>>w1; 
	int arr1[h1][w1]; 
	for(int i=0; i<h1; i++)
		for(int j=0;j<w1; j++) cin>>arr1[i][j]; 
	string ans= "No"; 
	if(h1> h|| w1> w) cout<<"No"<<endl;
	else{

		vector<int> rec; 
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(arr[i][j]== arr1[0][0]){
					int cnt= 0; 

					for(int y= j; y<w; y++){
						if(arr[i][y]== arr1[0][cnt]) {
							rec.push_back(y); 
							cnt++; 
						}
						if(cnt>=w1) break; 
					}
					//for(auto gg: rec) cout<<gg<<endl;
					if(cnt!= w1) {
						rec.clear(); 
						continue; 
					}
					else{
						//cout<<"Hi"<<endl;
						cnt= 0; 
						int cnt1= 0; 
						for(int g= i; g< h; g++){
							cnt= 0; 
							for(auto x:rec){
								if(arr[g][x]!= arr1[cnt1][cnt]) break; 
								else cnt++; 
							}
							if(cnt==w1) cnt1++; 
						}
						if(cnt1== h1) ans= "Yes"; 
					}
				}
			}
		}
		cout<<ans<<endl;
	}
 }
