#include<bits/stdc++.h>
#define x first
#define y second
#define ll long long
using namespace std;

vector< pair<ll,ll> >  v(10001);

long long ccw(pair<ll,ll> &p1,pair<ll,ll> &p2,pair<ll,ll> &p3){
	long long ans=p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.x*p3.y-p3.x*p2.y-p2.x*p1.y;
	return ans;
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i].x>>v[i].y;
	ll sum=0;
	for(int i=0;i<n-1;i++)
		sum+=ccw(v[0],v[i],v[i+1]);
		
	printf("%.1lf",abs(sum/2.0));
}
