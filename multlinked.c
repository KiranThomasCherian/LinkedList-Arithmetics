//multiply of 2 long numbes in linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *next;
};
struct node *hptr[5];
int al,bl;
char a[500],b[500];
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
//struct node *p0=hptr[0];
struct node *p1=hptr[1];
//struct node *p=hptr[1];
int lb,mb,z,v1;
int pro=0;
int rem=0;
int q=0;
while(p1!=NULL)
{
struct node *p0=hptr[0];
while((p0!=NULL))
{
z=p1->data;
v1=p0->data;
pro=(z*v1) + rem;
//printf("\n%d\n",pro);
lb=pro%10;
rem=pro/10;
insert(lb,0,2);
p0=p0->next;
}
if(rem!=0)
{
insert(rem,0,2);
}


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
for(m=0;m<n;m++)
insert(v[m],0,2);
for(int j=0;j<q;j++)
insert(0,0,2);

q++;

struct node *p2=hptr[2];//product pointer
struct node *p3=hptr[3];//sum pointer
//int lb,mb;
int sum=0;
rem=0;
while((p2!=NULL) &&(p3!=NULL))
{
sum=(p2->data +p3->data) + rem;
lb=sum%10;
rem=sum/10;
insert(lb,0,4);
p2=p2->next;
p3=p3->next;
}
if((p2==NULL) && (p3!=NULL))
{
while(p3!=NULL)
{
sum=p3->data + rem;
lb=sum%10;
rem=sum/10;
insert(lb,0,4);
p3=p3->next;
}
}
if((p2!=NULL) && (p3==NULL))
{
while(p2!=NULL)
{
sum=p2->data + rem;
lb=sum%10;
rem=sum/10;
insert(lb,0,4);
p2=p2->next;
}
}
if(rem!=0)
{
insert(rem,0,4);
}


struct node *temp4=hptr[4];
//int v[500];
//int n=0,m;
n=0;
while(temp4!=NULL)
{
v[n]=temp4->data;
n++;
temp4=temp4->next;

}
while(hptr[3]!=NULL)
hptr[3]=hptr[3]->next;
for(m=0;m<n;m++)
insert(v[m],0,3);
//print();
hptr[4]=NULL;
hptr[2]=NULL;

p1=p1->next;
//printf("\nhere\n");

}
}
void print()
{
//for(int i=0;i<2;i++)
//{

struct node *temp4=hptr[3];
int v[500];
int n=0,m;
n=0;
while(temp4!=NULL)
{
v[n]=temp4->data;
n++;
temp4=temp4->next;

}
while(hptr[3]!=NULL)
hptr[3]=hptr[3]->next;
for(m=0;m<n;m++)
insert(v[m],0,3);    
struct node *thptr=hptr[3];         

/*if(flag==1)

thptr->data=-(thptr->data);
*/
while(thptr!=NULL)
{
printf("%d",thptr->data);
thptr=thptr->next;
}
//}

}



void main()
{
for(int w=0;w<5;w++)
hptr[w]=NULL;
int i,k=0;

int o=0;
printf("Enter the digits  : ");
gets(a);

printf("Enter the digits  : ");
gets(b);
al=strlen(a);
bl=strlen(b);
/*if(a[0]=='-'&&b[0]=='-')
{
k=1;
flag=1;
}
else if((a[0]=='-'&&b[0]!='-')||(a[0]!='-'&&b[0]=='-'))
{
printf("This is equlivalent to subtraction.Do it in subtraction program .Exiting... ");
exit(0);
}*/
//printf("%d %d ",strlen(a),strlen(b)
for(i=strlen(a)-1;i>=k;i--)
{
int q=a[i];
int x=q-48;
insert(x,o,0);
//printf("\n%d\n",x);
o++;
}
o=0;
for(i=strlen(b)-1;i>=k;i--)
{
int q=b[i];
int x=q-48;
insert(x,o,1);
//printf("\n%d\n",x);
o++;
}
o=0;
for(i=strlen(a)-1;i>=k;i--)
{
insert(0,o,3);
o++;
}

printf("\nProduct= "); 
calc();
print();
}


