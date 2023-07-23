#include<stdio.h>
#include<string.h>
void main() //this is main
{
    char job[50][10],ctemp[10];
    int n,dead[50],profit[50],i,j,temp,seq[50]={0},max=0,tp=0;
    printf("Enter nubmer of jobs: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter job%d's deadline and profit:(j - d - p) ",i+1);
        scanf("%s%d%d",&job[i],&dead[i],&profit[i]);
    }
    for(i=0;i<n;i++)
        printf("%-5s",job[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%-5d",dead[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%-5d",profit[i]);

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(profit[i]<profit[j])
            {
                temp = dead[i];
                dead[i] = dead[j];
                dead[j] = temp;

                strcpy(ctemp,job[i]);
                strcpy(job[i],job[j]);
                strcpy(job[j],ctemp);

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=dead[i]-1;j>=0;j--)
        {
            if(seq[j]==0)
            {
                seq[j]=i+1;
                tp+=profit[i];
                break;
            }
        }
    }
    printf("\nThe sequence ");
    for(i=0;i<max;i++)
    {
    if(seq[i]!=0){
        j=seq[i]-1;
        printf("%s ",job[j]);
    }
    }
    printf(" with maximum profit : %d",tp);
}
