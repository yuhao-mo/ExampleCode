#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=105;
int Get[N],loss[N],dis[N];
priority_queue< pair<int,int> > q;
int main(){
    int n,H;
    cin>>n>>H;
    H*=12;
    for(int i=0;i<n;++i)
        cin>>Get[i];
    for(int i=0;i<n;++i)
        cin>>loss[i];
    memset(dis, 0, sizeof(dis));
    int d;
    for(int i=1;i<n;++i){
        cin>>d;
        dis[i]=d+dis[i-1];
    }
    int max=0;
    for(int i=0;i<n;++i){
        int time=H-dis[i];
        if(time<=0) break;
        int ans=0;
        for(int j=0;j<=i;++j)
            q.push(make_pair(Get[j], j));
        while(time>0 && q.top().first>0){
            ans+=q.top().first;
            int b=q.top().second, a=q.top().first-loss[b];
            q.pop();
            q.push(make_pair(a,b));
            time--;
        }
        if(ans>max) max=ans;
    }
    cout<<max<<endl;
    return 0;
}
