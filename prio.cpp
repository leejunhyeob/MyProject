#include<stdio.h>
int main(void)
{
	int p[3];
	int pr[3];
	int i,j,k=0;
	int temp;
	int wait=0;
	int retu=0;
	for(i=0;i<=3;i++)
	{
		printf("%d��° ���μ��� ����Ʈ �ð��� �켱������ �Է��ϼ��� ",i+1);
		scanf("%d %d",&p[i],&pr[i]); 
	}
    for(j=0;j<=3;j++)
    {
        for(k=0;k<=3;k++)
        {
            if(pr[k] > pr[k+1]) 
            {
                temp = pr[k];   
                pr[k]=pr[k+1];
                pr[k+1] = temp;
            }
        }
     }
     
     for(i=0;i<=3;i++)
     {
     	printf("%d",pr[i]);
     	printf("  ,%d\n",p[i]);
	 }
 }
