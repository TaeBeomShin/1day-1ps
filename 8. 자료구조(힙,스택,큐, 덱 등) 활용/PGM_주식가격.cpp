#include <bits/stdc++.h>
using namespace std;
/*
	��Ÿ�ϳ��� ��ã�Ƽ� 1�ð� ��� ����..�Ф�
	
	�˰����� �����ϴ�. 
	������ ������� �ʰ�, ������ ���� �� ���� ������ ���� ������ ���ݺ��� ū���
	������ ������ ���̱� ������, �� ���� ������� �ش� ������ �������� ���� �Ⱓ�� �ε�����
	���� ���ͷ� ��ȯ�Ѵ�.
	
	����� Ǯ�̺��� �ε��� ���� ������ Ȱ���ؼ� �� �����ϰ� �� ��  �ִ� ��. 
*/
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int,int>> ans;
    stack<pair<int,int>> S;
    for(int i=0;i<prices.size();i++){
        if(!S.empty()&&S.top().second>prices[i]){
            while(!S.empty()&&S.top().second>prices[i]){
                auto cur=S.top();
                ans.push({cur.first,i-cur.first});
                S.pop();
            }
        }
        S.push({i,prices[i]});
    }
    while(!S.empty()){
        auto cur=S.top();
        ans.push({cur.first,int(prices.size())-1-cur.first});
        S.pop();
    }
    while(!ans.empty()){
        answer[ans.top().first]=ans.top().second;
        ans.pop();
    }
    return answer;
}
