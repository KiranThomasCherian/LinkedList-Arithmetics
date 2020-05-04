//pgm to find complent and compare 2 numbers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
int data;
struct node *next;
};
struct node *hptr[2];
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

void print()
{
struct node *thptr=hptr[1];
while(thptr!=NULL)
{
printf("%d",thptr->data);
thptr=thptr->next;
}
}
void main()
{
for(int i=0;i<2;i++)
hptr[i]=NULL;
printf("\n\n 1)compare 2 numbers \n 2)negate \n Enter your choice : \n");
int z;
scanf("%d",&z);
char a[500],b[500];
int o=0,x;
//char c;
int fl=0;
switch(z)
{
case 1: printf("Enter 1st number : ");
	getchar();	
	gets(a);
 	printf("Enter 2nd number : ");
	//getchar();
	fl=0;	
	gets(b);
	for(int i=0;i<strlen(a);i++)
	{	
	if(a[i]=='-')
	{
	fl=1;
	continue;
	}
	
	int q=a[i];
	if(fl==1)
	{
	x=-(q-48);
	fl=0;
	}
	else
	x=q-48;
	insert(x,o,0);
	o++;
	}
	o=0;
	fl=0;
	for(int i=0;i<strlen(b);i++)
	{
	if(b[i]=='-')
	{
	fl=1;
	continue;
	}	
	int q=b[i];
	if(fl==1)
	{
	x=-(q-48);
	fl=0;
	}
	else
	x=q-48;
	insert(x,o,1);
	o++;
	}
	//puts(a);

	//print();
while(hptr[0]->data==0&&hptr[0]->next!=NULL)
hptr[0]=hptr[0]->next;

while(hptr[1]->data==0&&hptr[1]->next!=NULL)
hptr[1]=hptr[1]->next;
	struct node *p0=hptr[0];
	struct node *p1=hptr[1];
	int flag=0;
	while(p0!=NULL||p1!=NULL)
	{
	if(p0->data!=p1->data)
	{
	flag=1;
	break;
	}
	p0=p0->next;
	p1=p1->next;
	}
	if((p0==NULL&&p1!=NULL)||(p1==NULL&&p0!=NULL))
	flag=1;
	if(flag==0)
	printf("\n Given numbers are same . ");
	else
	printf("\n Given numbers are not equal . ");
	
	break;
case 2:  printf("\nEnter the number :");
	getchar();	 
	gets(b);
	fl=0;
        //scanf("%s",&b);
	for(int i=0;i<strlen(b);i++)
	{
	if(b[i]=='-')
	{
	fl=1;
	continue;
	}		
	int q=b[i];
	if(fl==1)
	{
	x=-(q-48);
	fl=0;
	}
	else
	x=q-48;
	insert(x,o,0);
	o++;
	}

while(hptr[0]->data==0&&hptr[0]->next!=NULL)
hptr[0]=hptr[0]->next;
	hptr[0]->data=-(hptr[0]->data);
	printf(" Negated value : ");
	print();
	break;
default :printf("\nInvalid Entry..Exiting.. ");
	 break;
}
}
