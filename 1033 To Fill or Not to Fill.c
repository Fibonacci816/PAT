#include <stdio.h>
#include <stdlib.h>
typedef struct NodeS{
    int distance; //����վ�ľ�������·��
    double price; //����վ�ĵ�λ�ͼ�
} Station;
Station stations[501];
int capacity, totalDistance, distancePerUnit, stationNum; //��������������·�̡�ÿ��λ�����н���·�̡�����վ����
int cmp(const void * a, const void * b)
{
    return (*(Station *)a).distance - (*(Station *)b).distance;
}
//�ҵ����Ե������һ���ͼ۸����˵ļ���վ���Ƿ��ѡ���ͼ���ȵļ���վ�����ս��û��Ӱ�죩����������ڷ���-1
int FindNextCheaperStation(int curStation)
{
    double cheapestPrice = stations[curStation].price;
    int cheapestStation = curStation;
    for(int i = curStation + 1; stations[i].distance - stations[curStation].distance <= capacity * distancePerUnit; i++){
        if(stations[i].price < cheapestPrice){ //�����< Ҳ�ɸ�Ϊ<=
            cheapestPrice = stations[i].price;
            cheapestStation = i;
            break;
        }
    }
    return cheapestStation != curStation ? cheapestStation : -1;
}
//�ҵ����Ե���ļ���վ(��������ǰ����վ)���ͼ�����˵��Ǹ�����վ
int FindNextCheapestStation(int curStation)
{
    double cheapestPrice = stations[curStation+1].price;
    int cheapestStation = curStation+1;
    for(int i = curStation + 2; stations[i].distance - stations[curStation].distance <= capacity * distancePerUnit; i++){
        if(stations[i].price < cheapestPrice){
            cheapestPrice = stations[i].price;
            cheapestStation = i;
        }
    }
    return cheapestStation;
}
int main()
{
    scanf("%d %d %d %d", &capacity, &totalDistance, &distancePerUnit, &stationNum);
    for(int i = 0; i < stationNum; i++){
        scanf("%lf %d", &stations[i].price, &stations[i].distance);
    }
    //Ϊ�򻯴����������һ������վ���յ㣬�䵥λ�ͼ�Ϊ0����ʹ�㷨���ܵ����յ�������������ѡ���յ��������վ
    stations[stationNum].price = 0;
    stations[stationNum].distance = totalDistance;
    //���ݾ���Լ���վ����
    qsort(stations, stationNum+1, sizeof(Station), cmp);
    //��Ϊһ��ʼû�ͣ���������������ļ���վ��������㣬���޷��н�
    if(stations[0].distance > 0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    //��ʼ����ǰ�н��ľ��롢��ǰ���ڵļ���վ����ǰ���������Ѳ������ͷ�
    int curDistance = 0, curStation = 0, nextCheaperStation, nextcheapestStation;
    double curUnits = 0, cheapestPrice = 0;
    while(curDistance < totalDistance){
        //��������һ������վ��·�̴���capacity * distancePerUnit�����ܵ�����һ������վ��Ҳ�Ͳ��ܵ����յ�
        if(stations[curStation+1].distance - stations[curStation].distance > capacity * distancePerUnit){
            printf("The maximum travel distance = %d.00", stations[curStation].distance + capacity * distancePerUnit);
            break;
        }
        //�ҵ���һ���ܵ���ĸ����˵ļ���վ
        nextCheaperStation = FindNextCheaperStation(curStation);
        if(nextCheaperStation != -1){
            //�ɵ���ĸ����˵ļ���վ�����ڣ����ڵ�ǰ����վ�������պÿ��Ե���
            //��Ϊ��ǰ�����Ƿ񹻵��Ǹ������˼���վ������������������������
            if((double)(stations[nextCheaperStation].distance - stations[curStation].distance) / distancePerUnit > curUnits){
                cheapestPrice += ((double)(stations[nextCheaperStation].distance - stations[curStation].distance) / distancePerUnit - curUnits) * stations[curStation].price;
                curUnits = 0;
            } else {
                curUnits -= (double)(stations[nextCheaperStation].distance - stations[curStation].distance) / distancePerUnit;
            }
            curStation = nextCheaperStation;
            curDistance = stations[nextCheaperStation].distance;
        } else {
            //���ɵ���ļ���վ���ͼ۶������ڵ�ǰ����վ���ͼۣ����ڵ�ǰ����վ�����ͣ�ȥ�ɵ���ļ���վ���ͼ�����˵��Ǹ�
            nextcheapestStation = FindNextCheapestStation(curStation);
            cheapestPrice += (capacity - curUnits) * stations[curStation].price;
            curUnits = capacity - (double)(stations[nextcheapestStation].distance - stations[curStation].distance) / distancePerUnit;
            curStation = nextcheapestStation;
            curDistance = stations[nextcheapestStation].distance;
        }
    }
    //���������յ�������������ͷ�
    if(curDistance == totalDistance){
        printf("%.2f", cheapestPrice);
    }
    return 0;
}
