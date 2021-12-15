#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double a[900]; 
int main(){
	int m,n,V,count=1;
	while((cin>>m>>n)&&m!=0&&n!=0){
		int k=m*n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=k;++i)
			cin>>a[i];
		sort(a+1,a+k+1);
		cin>>V;
		double h=(double)V/100,rate=0;
		int sum=0,j=1;
		for(j=1;j<k;++j){
			sum+=(a[j+1]-a[j])*j;
			if(sum>=h)
				break;
		} 
		if(j<k){
			h=(h-sum+(a[j+1]-a[j])*j)/j+a[j];
			rate=(double)j/k*100;
			printf("Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n",count,h,rate);
		} 
		else{
			h=(h-sum)/k+a[k];
			printf("Region %d\nWater level is %.2f meters.\n100.00 percent of the region is under water.\n",count,h);
		}
		++count;
		printf("\n");
	}
	return 0;
}
