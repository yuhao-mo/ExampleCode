#include<iostream>
#include<algorithm>
using namespace std;
int high[10000],low[10000];
int main(){
	ios::sync_with_stdio(false);
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;++i)
		cin>>high[i];
	for(int i=0;i<M;++i)
		cin>>low[i];
	sort(high,high+N);
	sort(low,low+M);
	int k=0,ans=0; 
	for(int i=0;i<N;++i){
		if(high[i]>low[k]){
			++ans;
			++k;
		}
		if(k==M) break;
	}
	cout<<ans+N<<"\n";
	return 0;
}
