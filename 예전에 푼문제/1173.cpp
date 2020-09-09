#include<iostream>

using namespace std;

int main(){
	int N,m,M,T,R;
//	1분마다 운동과 휴식 중에 결정.
//	맥박이 X였따면 1분동안 운동을하고 맥박이 X+T가됨, M을 넘으면안됨.
//	휴식을하면 맥박이 R만큼 감소한다.
//	처음 맥박은 m, 운동을 N분하는데 걸리는 시간의 최솟값.
	cin>>N>>m>>M>>T>>R; //N:운동시간, m:처음맥박&최소맥박,M:최대맥박,T:맥박증가 ,R:맥박감소. 
	
	int count=0;
	int exercise=0;
	int current=m;
//	운동을 끝낼수 없는경우
//	1.운동을 하면 바로 M을 넘는경우m+T>=M
//	2.운동하고 휴식을하면 바로 m보다 낮아지는 경우.
	if(m+T>M){
		cout<<-1;
	}
	else{
		while(exercise!=N){
			if(current+T<=M){
				current=current+T;
				exercise++;
			}
			else{//current+T>M;
				current=current-R;
				if(current<m) current=m;
			}
			count++;
//			cout<<current<<" "<<count<<" "<<exercise<<"\n";
		}
		cout<<count;
	}
}
