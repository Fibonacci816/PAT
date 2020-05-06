#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	int N, M, K;
	scanf("%d %d", &N, &M);
	unordered_map<int, unordered_map<int, int>> incompatible;
	int good1, good2;
	for(int i = 0; i < N; i++){
		scanf("%d %d", &good1, &good2);
		incompatible[good1][good2] = incompatible[good2][good1] = 1;
	}
	for(int i = 0; i < M; i++){
		scanf("%d", &K);
		int goods[K], flag = 1;
		vector<int> danger;  //danger��Ŵ����Ի����б����п��ܲ�����ը�Ļ��� 
		for(int j = 0; j < K; j++){
			scanf("%d", &goods[j]);
			if(flag){
				if(incompatible.count(goods[j])){
                    for(int k = 0; k < danger.size(); k++){
                        if(incompatible[goods[j]].count(danger[k])){  //֮ǰ���ܲ�����ը�Ļ������Ƿ��ĳ����͵�ǰ���ﲻ���� 
                            flag = 0;
						    break;
                        }
                    }
                    danger.push_back(goods[j]);
                }
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
 } 
