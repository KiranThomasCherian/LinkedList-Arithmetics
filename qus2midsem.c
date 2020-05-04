#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *ptr;
};
struct node *hptr[2];
void insert(int x,int z)
{
struct node* temp=(struct node *)malloc(sizeof(struct node));
temp->data=x;
temp->ptr=NULL;
if(hptr[z]==NULL)
hptr[z]=temp;
else
{
temp->ptr=hptr[z];
hptr[z]=temp;
}
}
void print(int z)
{
struct node *temp=hptr[z];
while(temp!=NULL)
{
printf(" %d ",temp->data);
temp=temp->ptr;
}
}
void main()
{
int z;
hptr[0]=NULL;
hptr[1]=NULL;
hptr[2]=NULL;
int a,b,dat,i,j,s,k;
printf("\n\n\n\tOPERATIONS ON SET : \n 1)Union \n 2)Intersection \n 3)Complement \n 4)Search  \n\n Enter Option : ");
scanf("%d",&z);
switch(z)
{
case 1:	printf("Enter no of elements of a: ");
	scanf("%d",&a);
	printf("Enter Elements : \n");
	for(i=0;i<a;i++)
	{
	scanf("%d",&dat);
	insert(dat,0);
	}
	printf("Enter no of elements of b: ");
	scanf("%d",&a);
	printf("Enter Elements : \n");
	for(i=0;i<a;i++)
	{
	scanf("%d",&dat);
	insert(dat,1);
	}
	struct node *temp6=hptr[0];
	
	while(temp6!=NULL)
	{
	insert(temp6->data,2);
	temp6=temp6->ptr;
	}
	
	struct node *temp7=hptr[1];
	while(temp7!=NULL)
	{
	insert(temp7->data,2);
	temp7=temp7->ptr;
	}
	struct node *temp22=hptr[2];
	while(temp22!=NULL)
	{
	struct node*temp33=NULL;
	struct node *temp44=hptr[2];
	while(temp44!=NULL)
	{
	if(temp22->data==temp44->data&&temp22!=temp44)
	{
	if(temp33==NULL)
	hptr[2]=hptr[2]->ptr;
	else
	temp33->ptr=temp33->ptr->ptr;
	}
	temp33=temp44;	
	temp44=temp44->ptr;
	}
	temp22=temp22->ptr;
	}
	
	printf(" Answer :  ");
	if(hptr[2]==NULL)
	printf("No Union ... ");
	else	
	print(2);
	break;
case 2: printf("Enter no of elements of a: ");
	scanf("%d",&a);
	printf("Enter elements : \n");
	for(i=0;i<a;i++)
	{
	scanf("%d",&dat);
	insert(dat,0);
	}
	printf("Enter no of elements of b: ");
	scanf("%d",&a);
	printf("Enter elements : \n");
	for(i=0;i<a;i++)
	{
	scanf("%d",&dat);
	insert(dat,1);
	}
	struct node *temp0=hptr[0];
	k=0;
	while(temp0!=NULL)
	{
	struct node *temp11=hptr[1];
	while(temp11!=NULL)
	{
	if(temp0->data==temp11->data)
	{
	insert(temp0->data,2);
	break;
	}
	temp11=temp11->ptr;
	}
	temp0=temp0->ptr;
	}
	struct node *temp2=hptr[2];
	while(temp2!=NULL)
	{
	struct node*temp3=NULL;
	struct node *temp4=hptr[2];
	while(temp4!=NULL)
	{
	if(temp2->data==temp4->data&&temp2!=temp4)
	{
	if(temp3==NULL)
	hptr[2]=hptr[2]->ptr;
	else
	temp3->ptr=temp3->ptr->ptr;
	}
	temp3=temp4;	
	temp4=temp4->ptr;
	}
	temp2=temp2->ptr;
	}
	
	printf("Answer : ");
	if(hptr[2]==NULL)
	printf("No intersection ... ");
	else	
	print(2);
	break;
	
case 3: printf("Enter no of elements of a: (in range 10) ");
	scanf("%d",&a);
	printf("Enter Elements : \n");
	for(i=0;i<a;i++)
	{
	scanf("%d",&dat);
	insert(dat,0);
	}
	
	struct node *temp222=hptr[0];
	while(temp222!=NULL)
	{
	struct node*temp333=NULL;
	struct node *temp444=hptr[0];
	while(temp444!=NULL)
	{
	if(temp222->data==temp444->data&&temp222!=temp444)
	{
	if(temp333==NULL)
	hptr[0]=hptr[0]->ptr;
	else
	temp333->ptr=temp333->ptr->ptr;
	}
	temp333=temp444;	
	temp444=temp444->ptr;
	}
	temp222=temp222->ptr;
	}	

	
	int x[10];
	for(i=0;i<10;i++)
	x[i]=i;
	s=9;
	struct node *temp=hptr[0];
	while(temp!=NULL)
	{
	for(j=0;j<10;j++)
	{
	if(x[j]==temp->data)
	{
	if(j==9)
	s--;
	else
	{	
	k=j;
	while(k<9)
	{x[k]=x[k+1];
	k++;
	}
	s--;
	}
	}
	}
	temp=temp->ptr;
	}
	if(s==-1)
	printf("\n No Complements present.. ");
	else
	{
	printf(" \n Answer : ");	
	for(i=0;i<=s;i++)
	printf(" %d ",x[i]);
	}	
	break;
case 4: printf("Enter no of elements of a: ");
	scanf("%d",&a);
	printf("Enter elements : \n");
	for(i=0;i<a;i++)
	{
	scanf("%d",&dat);
	insert(dat,0);
	}
	printf("Enter element to search : ");
	scanf("%d",&dat);
	j=0;
	struct node *temp1=hptr[0];
	while(temp1!=NULL)
	{
	if(temp1->data==dat)
	{	
	j=1;
	printf("\n Element present . ");
	break;
	}
	temp1=temp1->ptr;
	}
	if(j==0)
	printf("\n Element missing..");
	break;
default:printf("\nInvalid Entry... ");
	break;
}
}
