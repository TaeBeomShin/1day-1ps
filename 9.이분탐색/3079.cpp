#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

typedef long long ll;
int arr[100001];

int main(){
	fastio;
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++) cin>>arr[i];
	ll l=0,r=1e18;
	while(l+1<r){
		ll mid = l+r>>1,sum=0;//mid�� �ȿ� ��ü�ɽð� �������� üũ.
		for(int i=0;i<n;i++){
			sum+=mid/arr[i];
			if(sum>m) break;
		}
		(sum>=m)?r=mid:l=mid;
	}
	cout<<r;
}
