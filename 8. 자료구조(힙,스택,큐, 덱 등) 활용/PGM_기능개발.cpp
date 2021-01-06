#include <bits/stdc++.h>
using namespace std;
/*
 	ť�� ������ ����.
	 
	�ڷᱸ�� ���빮���� ���� ���� �������µ�, ť�� ������ �������� ���Ӵ�.
	
	������ �����ϴ�. 
	1. queue�� �켱���� ������� �������ڸ� ����־��ش�. 
	2. Q.front()�� ���캸�� �ֻ��� �켱�������� �������ڰ� ���̰ų� ���� ������ �����Ѵ�.
	3. �� �� �������ڰ� ������ pop�ϰ� ���� Q.front()�� �Ѿ��.
	4. ������ ��� ������ �����Ѵ�. (�ݺ�) 
*/
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Q;
    int size=speeds.size();
    
    for(int i=0;i<size;i++){
        int day=int(ceil((double)(100-progresses[i])/speeds[i]));
        Q.push(day);
    }
    while(!Q.empty()){
        int num=Q.front();
        int count=1;
        Q.pop();
        while(!Q.empty()){
            if(Q.front()<=num){
                count++;
                Q.pop();
            }else{
                break;
            }
        }
        answer.push_back(count);
    }
    return answer;
}
