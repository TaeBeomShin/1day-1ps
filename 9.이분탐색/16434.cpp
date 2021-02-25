#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

/*
	BOj 16434 - �巡�� ����
	
	1. l=1, r=1e18(�ִ밪 ����) ���� ����
	2. ���� ��ȸ�ϸ� ��� ���� ������ �ִ��� Ȯ��
	3. �ȵȴٸ� �ٽ� ���ư��� �ݺ�
	
	* r�� �����ϴ� ���� �̺�Ž������ ���� �߿��� ��.. ó���� ������ ���� ��Ƽ� ac ������. 
*/
typedef long long ll;
typedef struct{
	int type;
	int attack;
	int hp;
}room;

int n,h_atk;
vector<room> v;

int main(){
	fastio;
	cin>>n>>h_atk;
	v.resize(n);
	
	for(int i=0;i<n;i++)
		cin>>v[i].type>>v[i].attack>>v[i].hp;
	
	long long l=1,r=1e18;
	
	while(l<=r){
		ll mid=(l+r)/2;
		ll maxhp=mid,chp=maxhp,catk=h_atk;
		bool check=true;
		
		for(int i=0;i<n;i++){
			if(v[i].type==1){
				ll mhp=v[i].hp,mattack=v[i].attack;
				chp-=(mhp/catk+(mhp%catk!=0)-1)*mattack;
				if(chp<=0) check=false;
			}else{//���ǹ� 
				chp=min(maxhp,chp+v[i].hp);
				catk+=v[i].attack;
			}
			if(!check) break;
		}
		
		if(check) r=mid-1;
		else l=mid+1;
	}
	cout<<l;
}
