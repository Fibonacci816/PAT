#include <iostream>
#include <set>
using namespace std;

struct Item {
	int index, frequency;
	bool operator < (const Item &item) const {
		return frequency != item.frequency ? frequency > item.frequency : index < item.index;
	}
};

int main()
{
	int N, K, itemIndex;
	scanf("%d %d", &N, &K);
	set<Item> items;
	int itemsFrequency[50001] = {0};
	for(int i = 0; i < N; i++) {
		scanf("%d", &itemIndex);
		if(i != 0) {
			printf("%d:", itemIndex);
			int recNum = 0;
			for(auto it = items.begin(); recNum < K && it != items.end(); recNum++, it++)
				printf(" %d", it->index);
			printf("\n");
		}
		auto it = items.find(Item{itemIndex, itemsFrequency[itemIndex]});
		if(it != items.end()) items.erase(it);
		items.insert(Item{itemIndex, ++itemsFrequency[itemIndex]});
	}
	return 0;
 } 
