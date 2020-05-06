#include <stdio.h>
#include <stdlib.h>
typedef struct NodeS{
    int distance; //加油站的距离起点的路程
    double price; //加油站的单位油价
} Station;
Station stations[501];
int capacity, totalDistance, distancePerUnit, stationNum; //定义容油量、总路程、每单位油能行进的路程、加油站数量
int cmp(const void * a, const void * b)
{
    return (*(Station *)a).distance - (*(Station *)b).distance;
}
//找到可以到达的下一个油价更便宜的加油站（是否可选择油价相等的加油站对最终结果没有影响），如果不存在返回-1
int FindNextCheaperStation(int curStation)
{
    double cheapestPrice = stations[curStation].price;
    int cheapestStation = curStation;
    for(int i = curStation + 1; stations[i].distance - stations[curStation].distance <= capacity * distancePerUnit; i++){
        if(stations[i].price < cheapestPrice){ //这里的< 也可改为<=
            cheapestPrice = stations[i].price;
            cheapestStation = i;
            break;
        }
    }
    return cheapestStation != curStation ? cheapestStation : -1;
}
//找到可以到达的加油站(不包括当前加油站)中油价最便宜的那个加油站
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
    //为简化处理，虚拟最后一个加油站在终点，其单位油价为0，以使算法在能到达终点的情况下以优先选择终点这个加油站
    stations[stationNum].price = 0;
    stations[stationNum].distance = totalDistance;
    //根据距离对加油站排序
    qsort(stations, stationNum+1, sizeof(Station), cmp);
    //因为一开始没油，所以若距离最近的加油站不是在起点，则无法行进
    if(stations[0].distance > 0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    //初始化当前行进的距离、当前所在的加油站、当前的油量和已产生的油费
    int curDistance = 0, curStation = 0, nextCheaperStation, nextcheapestStation;
    double curUnits = 0, cheapestPrice = 0;
    while(curDistance < totalDistance){
        //若距离下一个加油站的路程大于capacity * distancePerUnit，则不能到达下一个加油站，也就不能到达终点
        if(stations[curStation+1].distance - stations[curStation].distance > capacity * distancePerUnit){
            printf("The maximum travel distance = %d.00", stations[curStation].distance + capacity * distancePerUnit);
            break;
        }
        //找到下一个能到达的更便宜的加油站
        nextCheaperStation = FindNextCheaperStation(curStation);
        if(nextCheaperStation != -1){
            //可到达的更便宜的加油站若存在，则在当前加油站加油至刚好可以到达
            //分为当前油量是否够到那个更便宜加油站两种情况，若不够则加油至够
            if((double)(stations[nextCheaperStation].distance - stations[curStation].distance) / distancePerUnit > curUnits){
                cheapestPrice += ((double)(stations[nextCheaperStation].distance - stations[curStation].distance) / distancePerUnit - curUnits) * stations[curStation].price;
                curUnits = 0;
            } else {
                curUnits -= (double)(stations[nextCheaperStation].distance - stations[curStation].distance) / distancePerUnit;
            }
            curStation = nextCheaperStation;
            curDistance = stations[nextCheaperStation].distance;
        } else {
            //若可到达的加油站的油价都不低于当前加油站的油价，则在当前加油站加满油，去可到达的加油站中油价最便宜的那个
            nextcheapestStation = FindNextCheapestStation(curStation);
            cheapestPrice += (capacity - curUnits) * stations[curStation].price;
            curUnits = capacity - (double)(stations[nextcheapestStation].distance - stations[curStation].distance) / distancePerUnit;
            curStation = nextcheapestStation;
            curDistance = stations[nextcheapestStation].distance;
        }
    }
    //若到达了终点则输出产生的油费
    if(curDistance == totalDistance){
        printf("%.2f", cheapestPrice);
    }
    return 0;
}
