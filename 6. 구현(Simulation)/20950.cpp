#include<bits/stdc++.h>
using namespace std;

typedef struct color{
	int r;
	int g;
	int b;
}color;
vector<color> v;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	
	v.resize(n);
	
	for(int i=0;i<n;i++) cin>>v[i].r>>v[i].g>>v[i].b;
	
	struct color bear;
	cin>>bear.r>>bear.g>>bear.b;
	
	int ans=1e9;
	//섞을 물감의 개수 i 
	vector<int> temp;
	for(int i=2;i<=min(n,7);i++){
		temp.clear();
		for(int j=0;j<n;j++){
			if(j<i) temp.push_back(0);
			else temp.push_back(1);
		}
		
		do{
			int sumr=0,sumg=0,sumb=0;
			for(int k=0;k<temp.size();k++){
				if(temp[k]==0){
					sumr+=v[k].r;
					sumg+=v[k].g;
					sumb+=v[k].b;
				}
			}
			sumr/=i;sumg/=i;sumb/=i;
			
//			cout<<sumr<<" "<<sumg<<" "<<sumb<<"\n";
			ans=min(ans,abs(bear.r-sumr)+abs(bear.g-sumg)+abs(bear.b-sumb));
		}while(next_permutation(temp.begin(),temp.end()));
	}
	cout<<ans;
}
