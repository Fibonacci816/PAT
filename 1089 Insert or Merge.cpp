#include <iostream>
#include <algorithm>
using namespace std;

int N, ori[100], partlySorted[100];

int IsEqual(int a[], int b[])
{
	for(int i = 0; i < N; i++){
		if(a[i] != b[i])
			return 0;
	}
	return 1;
}
void MergeSort()
{
	int flag = 0, m = 1;
	while(!flag){
		flag = IsEqual(partlySorted, ori);
		m *= 2;
		for(int i = 0; i < N; i+=m){
			if(i+m > N){
				sort(ori+i, ori+N);
			} else {
				sort(ori+i, ori+i+m);
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &ori[i]);
	}
	for(int i = 0; i < N; i++){
		scanf("%d", &partlySorted[i]);
	}
	int i, j;
	for(i=0;i<N-1&&partlySorted[i]<=partlySorted[i+1];i++);
    for(j=i+1;j<N&&ori[j]==partlySorted[j];j++);
    if(j==N)
    {
        printf("Insertion Sort\n");
        sort(ori,ori+i+2);
    } else {
		printf("Merge Sort\n");
		MergeSort();
	}
	for(int i = 0; i < N; i++){
		printf("%d", ori[i]);
		if(i != N-1)
			printf(" ");
	}
	return 0;
}
