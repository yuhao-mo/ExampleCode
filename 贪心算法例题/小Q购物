#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int money[105];
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=0;i<n;++i)
		cin>>money[i];
	sort(money,money+n);//从小到大排序
	if(money[0]!=1)	cout<<"-1\n";//硬币中如果没有1，不可能组成1~m的币值
	else{
		int ans=0,temp=0,sum=0;
		for(int i=1;i<n;++i){
			if(money[i]<=sum) continue;
      //已经覆盖了（1~sum）的区间，现在要覆盖的区间为（1~money[i]-1）
			ans+=ceil((double)(money[i]-sum-1)/money[i-1]);
			sum+=(ans-temp)*money[i-1];
			if(sum>=m) break;
			temp=ans;
		}
		if(sum<m)//还没有覆盖到m并且已经取到最后一种硬币时，全部取该硬币直到覆盖m
			ans+=ceil((double)(m-sum-1)/money[n-1]);
		cout<<ans<<"\n";
	}
	return 0;
}
