#include<bits/stdc++.h>
using namespace std;
/*
	�ٸ��� �ö� �� ���� Ʈ���� ������ �ʸ� ���� �����ְ�
	������ Ʈ���� �ö���� �ٸ��� ���̸�ŭ �ʸ� ���ؼ� ������ ��ȯ�Ѵ�. 
*/
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer=0,sum=0,idx=0;
    queue<int> Q;
    
    while(true){
        if(idx==truck_weights.size()){
            answer+=bridge_length;
            break;
        }
        answer++;
        
        int temp=truck_weights[idx];
        
        if(Q.size()==bridge_length){
            sum-=Q.front();
            Q.pop();
        }
        if(sum+temp<=weight){
            Q.push(temp);
            sum+=temp;
            idx++;
        }else{
            Q.push(0);
        }
    }
    return answer;
} 
