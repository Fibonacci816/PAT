#include <stdio.h>
#include <string.h>

char days[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	char str1[61], str2[61], str3[61], str4[61];
	scanf("%s\n%s\n%s\n%s", str1, str2, str3, str4);
	int flag = 1;
	for(int i = 0; str1[i]!='\0' && str2[i]!='\0'; i++){
		if(str1[i] == str2[i] && flag ==1){
			if(str1[i]>='A' && str1[i]<='G'){
				printf("%s ", days[str1[i]-'A']);
				flag = 0;
				continue;
			} 	
		}
		if(str1[i] == str2[i] && flag == 0){
			if(str1[i]>='0'&&str1[i]<='9'){
                printf("%02d:",str1[i]-'0');
                break;
            } else if(str1[i]>='A' && str1[i]<='N'){
				printf("%d:", str1[i]-'A'+10);
				break;
			}
		}
	}
	for(int i = 0; str3[i]!='\0' && str4[i]!='\0'; i++){
		if(str3[i] == str4[i]){
			if(str3[i]>='a' && str3[i]<='z' || str3[i]>='A' && str3[i]<='Z'){
				printf("%02d", i);
				break;
			}
		}
	}
	return 0;
 } 
