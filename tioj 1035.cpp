#include<iostream>
#include<vector> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#define maxn 11
#define n 50000
using namespace std; 

int main(){
	string l, l1; 
	cin>>l>>l1;
	vector<int> a[maxn]; 
	vector<int> a1[maxn]; 
	vector<pair<int, int> >lis; 
	int x= max(l1.size(), l.size()); 
	for(int i=0; i<l.size(); i++) a[l[i]-97].push_back(i);  
	for(int i=0; i<l1.size(); i++) a1[l1[i]-97].push_back(i); 
	for(int z= 0; z<maxn; z++)
		for(int i=0; i<a[z].size(); i++)
			for(int j=0; j<a1[z].size(); j++)
				lis.push_back(make_pair(a1[z][j], a[z][i])); 
			
	vector<vector<int> > ck(2, vector<int>(x+1)); 
	sort(lis.begin(), lis.end()); 
	int ans= 0; 
	for(int i=0; i<lis.size(); i++){
		if(lis[i].second== 0) ck[(lis[i].first)%2][lis[i].second]= 1; 
		else ck[(lis[i].first)%2][lis[i].second]= ck[(lis[i].first+1)%2][lis[i].second-1]+1; 
		ans= max(ans, ck[(lis[i].first)%2][lis[i].second]); 
	}
	cout<<ans<<endl;
	return 0; 
}