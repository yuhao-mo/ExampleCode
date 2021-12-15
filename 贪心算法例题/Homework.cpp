#include<bits/stdc++.h>
using namespace std;
char str[100005];
struct Node{
	char flag;
	vector<int> num;
	int size=0;
};
bool compare(Node a,Node b){
	if(a.size==b.size) return a.flag<b.flag;//在数量相同时，优先删除字典序小的
	return a.size<b.size;
}
Node node[26];
int main(){
	int k;
	gets(str);
	cin>>k;
	int len=strlen(str);
	if(k>=len)	cout<<0<<"\n";//允许删除的字符超过字符串长度时直接打印0即可
	else{
		for(int i=0;i<len;++i){
			node[str[i]-'a'].flag=str[i];//如果没要求优先删除字典序小的字符，可以不需要保存字符
			node[str[i]-'a'].num.push_back(i);
			node[str[i]-'a'].size++;
		}	
		sort(node,node+26,compare);//让字符按出现次数从小到大排序，优先删除数量更少的字符
		int total=0,rest=26;
		for(int i=0;i<26;++i){//一共只有26中字符，最多操作26次
			int j=0;
			if(k-total>=node[i].size)//当允许删除的字符不足以减少字符种数时就停止操作
				for(;j<node[i].size;++j){
					str[node[i].num[j]]=0;//将该位置的字符置0，代表已删除
					total++;//total代表已经删掉的字符数
				}
			if(j==node[i].size) rest--;//当一种字符删除完成时，剩余字符数-1
		}
		printf("%d\n",rest);//打印剩余的字符数
		for(int i=0;i<len;++i)
			if(str[i]) printf("%c",str[i]);//打印删除后的字符
	}
    return 0;
}
