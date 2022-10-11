#include<iostream>
#include<vector>
#define ll long long 

using namespace std; 

int main(){
  int n, k, ans= 0; 
  cin>>n>>k; 
  vector<string> v(n); 
  for(int i=0; i<n; i++) 
    cin>>v[i]; 

  for(int i=0; i<(1<<n); i++){
    vector<int> sum(26);
    for(int j=0; j<n; j++){
      if((i>>j)&1) {
        for(int z=0; z<v[j].size(); z++)
          sum[v[j][z]-'a']++; 
      
      }
    }
    int now= 0; 
    for(int j=0; j<26; j++)
      if(sum[j]== k) now++; 
    ans= max(now, ans); 
  }

  cout<<ans<<endl;
}