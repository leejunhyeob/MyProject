#include<stdio.h>

int main(void)
{
	int p[2];
	int i=0;
	int wait=0;
	int retu=0;
	printf("프로세스는 0초->1초->2초->3초.... 순서대로 들어옴\n"); 
	for(i=0;i<=2;i++)
	{
		printf("%d번째 프로세스 버스트 시간:",i+1);
		scanf("%d",&p[i]); 
	}
	wait=0+(p[0]-1)+(p[0]+p[1]-2);
	printf("평균 대기시간: %d \n",wait/3 );
	retu=p[0]+(p[0]-1+p[1])+(p[0]-1+p[1]-1+p[2]);
	printf("평균 반환시간: %d ",retu/3);
}
