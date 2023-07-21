#include <stdio.h>
int main() {
	int total = 0, num = 0, count = 0;
	while(1){
		printf("Enter Number %d : " , count+1);
		scanf("%d" , &num);
		if(num <= 0){
			printf("=======================\n");
			printf("Total = %d\n" , total);
			printf("Average = %f\n", (double)total/count);
			printf("=======================\n");
			return 0;
		}else{
			total +=  num;
			count++;
		}
	}
}
