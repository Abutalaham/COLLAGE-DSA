#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=10;
int x=0;
void producer(){
	--mutex;
	++full;
	--empty;
	++x;
	printf("\nproducer producers item %d",x);
	++mutex;
}
void consumer(){
	--mutex;
	--full;
	++empty;
	printf("\nconsumer consumes items %d",x);
	--x;
	++mutex;
}
int main(){
	int n;
	printf("\n1.press 1 for producer");
	printf("\n2.press 2 for consumer");
	printf("\n3.press 3 to exit\n");
	while(1){
		printf("\nenter your choice: ");
		scanf("%d",&n);
		switch(n){
			case 1:
				if((mutex==1)&&(empty!=0)){
					producer();
				}else{
					printf("\nbuffer is full");
				}
				break;
			case 2:
				if((mutex==1)&&(full!=0)){
					consumer();
				}else{
					printf("\nBuffer is empty");
				}
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("\nInvalid choice");
		}
	}
	return 0;
}
