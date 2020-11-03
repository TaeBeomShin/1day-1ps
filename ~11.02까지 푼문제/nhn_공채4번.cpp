#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;

void solution(int numOfOrder, string *orderArr) {
  // TODO: �̰��� �ڵ带 �ۼ��ϼ���. �߰��� �ʿ��� �Լ��� ���������� �����ؼ� ����ϼŵ� �˴ϴ�.
	// ���� ����?
	for(int i=0;i<numOfOrder;i++){	
		stack <char> S;
		string answer="";
		for(int j=0;j<orderArr[i].length();j++){
			char c=orderArr[i][j];//������ ����.
			char last;
			if(!S.empty()){//������ ������� ������.
				string temp="";
				string ts="";
				if(c=='R'||c=='G'||c=='B'){//�����϶�
					S.push(c);
				}
				else if(c>='1'&&c<='9'){//�����϶�
					S.push(c);
				}
				else if(c=='('){
					S.push(c);
				}
				else if(c==')'){
					while(S.top()!='('){//(��ȣ�� ����������.
						temp+=S.top();
						S.pop();
					}
					if(last>='1'&&last<='9'){//�����϶�  
						int num=last-'0';
						for(int k;k<temp.length();k++){
							for(int l=0;l<num;l++){
								 ts+=temp[k];
							}
						}
					}
					else{//���ڿ� 
						for(int k;k<temp.length();k++){
							ts+=last;
							ts+=temp[k];
						} 
					}
				}
				answer+=temp;
			}else{//������ ���������
				if(c=='('){//��ȣ ���ڰ�����.
					S.push(c);
				}else{
					answer+=c;
					last=c;//�������� �ε���
				}
			}
		}
		// 1. �����϶�
		// 	1-1.���� �ڰ� �����϶�
		// 	1-2.���� �ڰ� ��ȣ�϶�
		// 2. ��ȣ�� ������
		// 	2-1.��ȣ ���� �����϶�
		// 	2-2.��ȣ ���� �����϶�
		// 3. �����϶�
		cout<<answer<<"\n";
	}	
}

struct input_data {
  int numOfOrder;
  string *orderArr;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfOrder;

  inputData.orderArr = new string[inputData.numOfOrder];
  for (int i = 0; i < inputData.numOfOrder; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.orderArr[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfOrder, inputData.orderArr);
  return 0;
}
