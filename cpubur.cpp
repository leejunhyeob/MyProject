#include<stdio.h>

int main(void)
{
	int p[2];
	int i=0;
	int wait=0;
	int retu=0;
	printf("���μ����� 0��->1��->2��->3��.... ������� ����\n"); 
	for(i=0;i<=2;i++)
	{
		printf("%d��° ���μ��� ����Ʈ �ð�:",i+1);
		scanf("%d",&p[i]); 
	}
	wait=0+(p[0]-1)+(p[0]+p[1]-2);
	printf("��� ���ð�: %d \n",wait/3 );
	retu=p[0]+(p[0]-1+p[1])+(p[0]-1+p[1]-1+p[2]);
	printf("��� ��ȯ�ð�: %d ",retu/3);
}
