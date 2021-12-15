#include<cstdio>
#include<iostream>
#include<cstring> 
#include<algorithm>
using namespace std;
const int N=100010;
struct Money{
	int x, y;
	bool operator < (const Money e) const{
		return x<e.x;
	}
} money[N];
int main() {
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)
		cin>>money[i].x>>money[i].y;
	sort(money,money+n);
	int ans=0;
	while(1){
		int need,rest=m;
		for(int i=n-1;i>=0;--i){
			if(money[i].y==0) continue;
			need=rest/money[i].x;
			if(need>money[i].y) need=money[i].y;
			money[i].y-=need;
			rest-=need*money[i].x;
			if(rest==0) break;
		}
		if(rest!=0){
			for(int i=0;i<n;++i){
				if(money[i].y==0) continue;
				need=rest/money[i].x+1; //注意+1
				if(need>money[i].y) need=money[i].y;
				money[i].y-=need;
				rest-=need*money[i].x;
				if(rest<=0) break;
			}
		}
		if(rest>0) break;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
