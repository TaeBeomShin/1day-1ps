#include<bits/stdc++.h>
using namespace std;

int n,m,K;
//파이어볼의 이동 방향 
int dy[8]={0,1,1,1,0,-1,-1,-1},dx[8]={-1,-1,0,1,1,1,0,-1};
struct fireball{
	int r,c,m,s,d;
};

int main(){
	cin>>n>>m>>K;
	vector<fireball> v;

	v.resize(m);
	for(int i=0;i<m;i++) cin>>v[i].r>>v[i].c>>v[i].m>>v[i].s>>v[i].d;
	
	while(K--){
		int board[n+1][n+1]={0,};
		bool visited[int(v.size())]={false,};
		
		//1.모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다
		for(int i=0;i<m;i++){
			auto curfire=v[i];
			int cr=curfire.r,cc=curfire.c,cm=curfire.m,cd=curfire.d,cs=curfire.s;
			
			int move=cs%n;
			 
			int nr=cr+dx[cd]*move,nc=cc+dy[cd]*move;
			if(nr<1) nr+=n;
			if(nr>n) nr-=n;
			if(nc<1) nc+=n;
			if(nc>n) nc-=n;
			v[i].r=nr;v[i].c=nc;
			cout<<cr<<" "<<cc<<" "<<nr<<" "<<nc<<"\n";
			board[nr][nc]++;
		}
		
		//2.이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다
		
		vector<fireball> new_v; 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				//2-1.같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
				if(board[i][j]>=2){
					cout<<"합쳐짐 "<<i<<" "<<j<<"\n";
					int newr=i,newc=j,newm=0,news=0,newd=0;
					bool dir=true;
					for(int k=0;k<v.size();k++){
						if(v[i].r==i&&v[i].c==j){
							new_v.push_back(v[i]);
							//제거할 파이어볼 표시. 
							newm+=v[i].m;news+=v[i].s;
							if(newd!=0){
								if(v[i].d%2&&newd==1){
									newd=1;
								}else if(v[i].d%2==0&&newd==2){
									newd=2;
								}else{
									dir=false;	
								}
							}else{
								newd=(v[i].d%2)?1:2;
							}
							visited[k]=true;
						}
					}
					
					newm/=5;news=news/board[i][j];
					newd=(dir)?1:2;
					
					if(newm==0) continue;
					if(newd==1){
						for(int rd=0;rd<=6;rd+=2) new_v.push_back({newr,newc,newm,news,rd});
						
					}else{
						for(int rd=1;rd<=7;rd+=2) new_v.push_back({newr,newc,newm,news,rd});
					}
				}
			}			
		}
		for(int i=0;i<v.size();i++){
			if(!visited[i]) new_v.push_back(v[i]);
		}
		while(!v.empty()) v.pop_back();
		
		for(int i=0;i<new_v.size();i++){
			v.push_back(new_v[i]);
//			cout<<v[i].r<<" "<<v[i].c<<" "<<v[i].m<<" "<<v[i].s<<" "<<v[i].d<<"\n";
		}
	}
	
	int ans=0;
	
	for(int i=0;i<v.size();i++) ans+=v[i].m;
	
	cout<<ans;
}
