//sum of 2 long numbes in linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *next;
};
struct node *hptr[3];
int flag=0;
void insert(int x,int pos,int z)
{
struct node *temp=(struct node *)malloc(sizeof(struct node));
temp->data=x;
struct node *thptr=hptr[z];
int i=0;
if(pos==0)
{
temp->next=hptr[z];
hptr[z]=temp;
}
else
{
while(i<pos-1)
{
thptr=thptr->next;
++i;
}
temp->next=thptr->next;
thptr->next=temp;
}
}
void calc()
{
struct node *p1=hptr[0];
struct node *p2=hptr[1];
int lb,mb;
int sum=0;
int rem=0;
while((p1!=NULL) &&(p2!=NULL))
{
sum=(p1->data +p2->data) + rem;
lb=sum%10;
rem=sum/10;
insert(lb,0,2);
p1=p1->next;
p2=p2->next;
}
if((p1==NULL) && (p2!=NULL))
{
while(p2!=NULL)
{
sum=p2->data + rem;
lb=sum%10;
rem=sum/10;
insert(lb,0,2);
p2=p2->next;
}
}
if((p1!=NULL) && (p2==NULL))
{
while(p1!=NULL)
{
sum=p1->data + rem;
lb=sum%10;
rem=sum/10;
insert(lb,0,2);
p1=p1->next;
}
}
if(rem!=0)
{
insert(rem,0,2);
}
}
void print()
{
//for(int i=0;i<2;i++)
//{
struct node *thptr=hptr[2];
if(flag==1)

thptr->data=-(thptr->data);

while(thptr!=NULL)
{
printf("%d",thptr->data);
thptr=thptr->next;
}
//}

}



void main()
{
for(int w=0;w<3;w++)
hptr[w]=NULL;
int i,k=0;
char a[500],b[500];
int o=0;
printf("Enter the digits  : ");
gets(a);

printf("Enter the digits  : ");
gets(b);
if(a[0]=='-'&&b[0]=='-')
{
k=1;
flag=1;
}
else if((a[0]=='-'&&b[0]!='-')||(a[0]!='-'&&b[0]=='-'))
{
printf("This is equlivalent to subtraction.Do it in subtraction program .Exiting... ");
exit(0);
}
for(i=strlen(a)-1;i>=k;i--)
{
int q=a[i];
int x=q-48;
insert(x,o,0);
o++;
}
o=0;
for(i=strlen(b)-1;i>=k;i--)
{
int q=b[i];
int x=q-48;
insert(x,o,1);
o++;
}
printf("\n Sum= "); 
calc();
print();
}


