#include <iostream>
#include <vector>
using namespace std;


int main(){
  int n;
  cin>>n;
  vector<bool> sq(n+1,false);
  for(int i=1;i*i<=n;i++) sq[i*i]=true;
  vector<vector<int> > d(n+1);
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j+=i) d[j].push_back(i);
  }
  vector<int> cnt(n+1);
  for(int i=1;i<=n;i++){
    int f=0;
    for(int j=0;j<d[i].size();j++) if(sq[d[i][j]]) f=d[i][j];
    cnt[i/f]++;
  }
  int ans=0;
  for(int i=1;i<=n;i++) ans+=cnt[i]*cnt[i];
  cout<<ans<<endl;
}

