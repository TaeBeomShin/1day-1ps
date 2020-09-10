#include<bits/stdc++.h>
using namespace std;

int n,w,L;
int result;
int cur_weight;
queue <int> q;
int truck[1010];

int main(){
	
	cin>>n>>w>>L;
	
	for(int i=0;i<n;i++) cin>>truck[i];
	
	for(int i=0;i<n;i++)
	{
		while(true){
			if(q.size()==w)
			{
				cur_weight-=q.front();
				q.pop();
			}
			if(truck[i]+cur_weight<=L) break;
			q.push(0);
			result++;
		}
		q.push(truck[i]);
		cur_weight+=truck[i];
		result++;
	}
	
	cout<<result+w;
	
	return 0;
}
