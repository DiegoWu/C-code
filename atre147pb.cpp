#include<bits/stdc++.h> 
#define ll long long 
#define maxn 200005
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	
	int n; 
	cin>>n; 
	
	vector<int> v(n+1);  

	for(int i=1; i<n+1; i++) {
		cin>>v[i]; 
			
	}
	vector<pair<char, int> > rec; 
	int cnt= 0; 

	for(int i=n; i>=1; i-=2){
		if(v[i]%2!= i%2) cnt++; 
		else if(cnt>0&& v[i]%2== i%2){
			cnt--; 
			for(int j=i+2; j<=n; j+=2){
				//if(v[j]%2== j%2) break; 
				rec.push_back(mp('B', j-2)); 
				//cout<<"HI"<<endl;
				swap(v[j-2], v[j]); 
			}
		}
	}
	
	for(int i=2; i<n+1; i+=2){
		
		if(v[i-1]%2!= (i-1)%2){
			rec.push_back(mp('A', i-1));
			swap(v[i-1], v[i]); 
		}

		else if(v[i+1]%2!= (i+1)%2){
			if(n%2==0&& i==n) continue;
			rec.push_back(mp('A', i));
			swap(v[i+1], v[i]); 
		}
	}
	for(int i=1; i<n+1; i++) cout<<v[i]<<" ";
	cout<<endl;
	for(int i=1; i<n+1; i++){
		for(int j=1; j<n-i; j+=2){
			if(v[j]!= j){
				rec.push_back(mp('B', j)); 
				swap(v[j+2], v[j]); 
			} 
		}
		for(int j=2; j<n-i; j+=2){
			if(v[j]!= j){
				rec.push_back(mp('B', j)); 
				swap(v[j+2], v[j]); 
			} 
		}
	}
	cout<<rec.size()<<endl;

	for(int i=1; i<n+1; i++) cout<<v[i]<<" ";
	cout<<endl;
	for(int i=0; i<rec.size(); i++) cout<<rec[i].first<<" "<<rec[i].second<<endl; 
	
}
