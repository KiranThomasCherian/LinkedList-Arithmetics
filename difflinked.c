//Difference of 2 long numbes in linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *next;
};
struct node *hptr[3];
int c;  //c<0 => a is greater than b
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
struct node *p1=hptr[1];
struct node *p0=hptr[0];
int flag=0;
int diff=0;
int car=0;
while(p0!=NULL)
{
diff=(p1->data - p0->data);
if(diff>=0)
{insert(diff,0,2);
}
else
{
flag=0;
struct node *temp=p1->next;
while(flag==0)
{

if(temp->data!=0)
{
(temp->data)--;
flag=1;
}
else
temp->data=9;
temp=temp->next;
}
diff=((p1->data)+10)-p0->data;
insert(diff,0,2);
}
p0=p0->next;
p1=p1->next;
}
while(p1!=NULL)
{
insert(p1->data,0,2);
p1=p1->next;
}
if(c<0)
{
struct node *tem=hptr[2];
tem->data=-(tem->data);
}
}
void print()
{
struct node *thptr=hptr[2];
while(thptr!=NULL)
{
printf("%d",thptr->data);
thptr=thptr->next;
}
}



void main()
{
for(int w=0;w<3;w++)
hptr[w]=NULL;
int i,al,bl;
char a[500],b[500];
int o=0;
printf("Enter the numbers :\n");
gets(a);
gets(b);
al=strlen(a);
bl=strlen(b);
if(al<bl)
c=-1;
else if(al>bl)
c=+1;
else
{
c=strcmp(a,b);
}



if(c>0)
{
for(i=strlen(a)-1;i>=0;i--)
{
int q=a[i];
int x=q-48;
insert(x,o,1);
o++;
}
o=0;
for(i=strlen(b)-1;i>=0;i--)
{
int q=b[i];
int x=q-48;
insert(x,o,0);
o++;
}
}
if(c<0)
{
for(i=strlen(b)-1;i>=0;i--)
{
int q=b[i];
int x=q-48;
insert(x,o,1);
o++;
}
o=0;
for(i=strlen(a)-1;i>=0;i--)
{
int q=a[i];
int x=q-48;
insert(x,o,0);
o++;
}
}
if(c==0)
printf("\nAnswer = 0 ");
else
{
calc();
printf("Difference = ");
print();
}
}

