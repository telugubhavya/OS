#include <stdio.h>
int main()
{
int i,j,n,bu[10],wa[10],tat[10],t,ct[10],max;
float awt = 0,att = 0, temp = 0;
printf("Enter the no of process");
scanf("%d", &n);
for( i = 0; i <n ;i++){
printf("\n Enter the burst time for process %d", i+1);
scanf("%d", &bu[i]);
ct[i] = bu[i];
}
printf("\n enter the size of time slice..");
scanf("%d", &t);
max = bu[0];
for(i =1; i <n; i++)
if(max <bu[i])
max = bu[i];
for(j =0; j <(max/t) + 1; j++)
for(i = 0; i <n; i++)
if(bu[i]!=0)
if(bu[i]<=t)
{
tat[i] = temp + bu[i];
temp = temp + bu[i];
bu[i] = 0;
}
else
{
bu[i] = bu[i] -t;
temp = temp + t;
}
for( i =0; i <n; i++)
{
wa[i] = tat[i] - ct[i];
att+= tat[i];
awt+= wa[i];
}
printf("\n the avg tat is---%f",att/n);
printf("\n the avg wt--%f",awt/n);
printf("\n\tprocess\tburst time\t waiting time\t turn around time\n");
for( i =0; i <n; i++)
printf("\t%d\t%d\t\t%d\t\t %d\n", i+1,ct[i],wa[i],tat[i]);
}



