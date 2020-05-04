//we are performing integer division...//Difference of 2 long numbes in linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *next;
};
struct node *hptr[3];
char b[500];
int c,d,lsb;  //d=lenght of divisor
int count=0;
void insert(int x,int pos,int z)
{
struct node *temp=(struct node *)malloc(sizeof(struct node));
temp->data=x;
temp->next=NULL;
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
int r,g=1;
while(g!=0)
{
while(p0!=NULL)
{
int flag=0,diff=0;
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

while(hptr[2]->data==0&&hptr[2]->next!=NULL)
hptr[2]=hptr[2]->next;
count++;
r=0;
struct node*temp2=hptr[2];
while(temp2!=NULL)
{
r++;
temp2=temp2->next;
}
if(r==0)
break;
struct node *temp3=hptr[2];
int v[500];
int n=0,m;
while(temp3!=NULL)
{
v[n]=temp3->data;
n++;
temp3=temp3->next;

}
while(hptr[2]!=NULL)
hptr[2]=hptr[2]->next;
//free(hptr[2]);
for(m=0;m<n;m++)
insert(v[m],0,2);
p1=hptr[2];
p0=hptr[0];

while(hptr[2]!=NULL)
hptr[2]=hptr[2]->next;
if(n>d)
g=1;
else if(n==d)
{
for(int y=0;y<n;y++)
{
int l=b[y]-48;
//printf("\n %d %d \n ",l,v[y]);
if(l!=v[y])
{
if(l>v[y])
g=0;
else
g=1;
break;
}
}
/*
puts(f);
if(strcmp(f,b)<0)
g=1;
else
g=0;*/
}
else if(n<d)
g=0;
//printf("\n %d   \n",g);
}
//printf("\n %d %d",r,d);
//for(int y=0;y<n;y++)
//printf(" %d ",v[y]);
}
void print()
{
printf("\n");
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
char a[500];
int o=0;
printf("Enter the numbers :\n");
gets(a);
gets(b);
al=strlen(a);
bl=strlen(b);
d=bl;
lsb=b[0]-'0';
//printf("\n %d %d \n",lsb,d);
if(al<bl)
c=-1;
else if(al>bl)
c=+1;
else
c=strcmp(a,b);
if(c<0)
{
printf("We are doing integer division so answer = 0 . ");
exit(0);
}

if(c==0)
printf("\nAnswer = 1 ");
else
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

calc();
printf("Integer division answer = %d",count);
print();
}
}

