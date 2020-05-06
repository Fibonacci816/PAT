#include <stdio.h>
#include <string.h>
typedef struct PhoneTimeS{
    int time;
    char flag[9];
} PhoneTime;
typedef struct RecordS{
    char name[21];
    int month;
    PhoneTime phoneTimes[1000];
    int recordNum;
} Record;
Record records[1000];
int tolls[24];
int HaveName(int n, char name[]); //�ж��û��ǲ����Ѿ����ֹ������ֹ������±꣬���򷵻�-1
double PrintTimeAndTolls(int startTime, int endTime); //��������ӡΪ���ڸ�ʽ������ӡ�˵�����
double calculate(int minute);
int main()
{
    int N;
    for(int i = 0; i < 24; i++){
        scanf("%d", &tolls[i]);
    }
    scanf("%d", &N);
    char name[21];
    int nameNum = 0;
    int index;
    int dd;
    int hh;
    int mm;
    int cur_time;
    for(int i = 0; i < N; i++){
        if(i == 0){
            scanf("%s %d", records[0].name, &records[0].month);
            scanf(":%d:%d:%d %s", &dd, &hh, &mm, records[0].phoneTimes[0].flag);
            records[0].phoneTimes[0].time = dd * 24 * 60 + hh * 60 + mm; //����ת��Ϊ������
            records[0].recordNum = 1;
            //printf("%s %02d:%02d:%02d:%02d %s\n", records[0].name, records[0].month, dd, hh, mm, records[0].phoneTimes[0].flag);
            nameNum = 1;
        } else {
            scanf("%s", name);
            index = HaveName(nameNum, name);
            if(index != -1){
                scanf("%d", &records[index].month);
                scanf(":%d:%d:%d", &dd, &hh, &mm);
                cur_time = dd * 24 * 60 + hh * 60 + mm;
                int j;
                for(j = records[index].recordNum; j > 0; j--){
                    //Ѱ�Һ��ʵĲ���λ�ã���ͨ����¼��ʱ������
                    if(cur_time > records[index].phoneTimes[j-1].time){
                        break;
                    }
                    records[index].phoneTimes[j] = records[index].phoneTimes[j-1];
                }
                records[index].phoneTimes[j].time = cur_time;
                scanf("%s", records[index].phoneTimes[j].flag);
                //printf("%s %02d:%02d:%02d:%02d %s\n", name, records[index].month, dd, hh, mm, records[index].phoneTimes[j].flag);
                records[index].recordNum += 1;
            } else {
                int k;
                for(k = nameNum; k > 0; k--){
                    //Ѱ�Һ��ʵĲ���λ�ã��Ա�֤�û�������ĸ����
                    if(strcmp(name , records[k-1].name) > 0){
                        break;
                    }
                    records[k] = records[k-1];
                }
                strcpy(records[k].name, name);
                scanf("%d:%d:%d:%d %s", &records[k].month, &dd, &hh, &mm, records[k].phoneTimes[0].flag);
                records[k].phoneTimes[0].time = dd * 24 * 60 + hh * 60 + mm;
                records[k].recordNum = 1;
                //printf("%s %02d:%02d:%02d:%02d %s\n", name, records[k].month, dd, hh, mm, records[k].phoneTimes[0].flag);
                ++nameNum;
            }
        }
    }
    int flag;
    double totalAmount;
    for(int i = 0; i < nameNum; i++){
        flag= 0;
        totalAmount = 0;
        for(int j = 0; j < records[i].recordNum - 1; j++){
            if(!strcmp("on-line", records[i].phoneTimes[j].flag) && !strcmp("off-line", records[i].phoneTimes[j+1].flag)){
                if(flag == 0){
                    printf("%s %02d\n", records[i].name, records[i].month);
                    flag = 1;
                }
                totalAmount += PrintTimeAndTolls(records[i].phoneTimes[j].time, records[i].phoneTimes[j+1].time);
            }
        }
        if(flag){
            printf("Total amount: $%.2f\n", totalAmount);
        }
    }
    return 0;
}
int HaveName(int n, char name[])
{
    for(int i = 0; i < n; i++){
        if(strcmp(records[i].name, name) == 0){
            return i;
        }
    }
    return -1;
}
double PrintTimeAndTolls(int startTime, int endTime)
{
    double totalAmount;
    printf("%02d:%02d:%02d", startTime/(24*60), startTime/60%24, startTime%60);
    printf(" %02d:%02d:%02d", endTime/(24*60), endTime/60%24, endTime%60);
    printf(" %d", endTime-startTime);
    totalAmount = calculate(endTime) - calculate(startTime);
    printf(" $%.2f\n", totalAmount);
    return totalAmount;
}
double calculate(int minute)
{
    double totalAmount = 0;
    for(int i = 0; i < minute/60; i++){
        totalAmount += 60 * tolls[i % 24];
    }
    totalAmount += minute % 60 * tolls[minute/60%24];
    return totalAmount / 100;
}
