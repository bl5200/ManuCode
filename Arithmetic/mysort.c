#include <stdio.h>
#include <stdlib.h>

void PrintArray(const int a[],int size);
void BubbleSort(int a[],int size);
void QuickSort(int a[],int left,int right);
void InsertSort(int a[],int size);
void ShellSort(int a[],int size);
void SelectSort(int a[],int size);

int main(int argc,char **argv)
{
    int a1[]={0,1,2,3,4,5,6,7,8,9};
    int a2[]={1,2,3,4,9,6,7,8,5};
    int a3[]={99,88,77,66,5,4,3,2,1,0};
	PrintArray(a3,sizeof(a3)/sizeof(a3[0]));	
//	BubbleSort(a3,sizeof(a3)/sizeof(a3[0]));
//	QuickSort(a3,0,sizeof(a3)/sizeof(a3[0])-1);
//	InsertSort(a3,sizeof(a3)/sizeof(a3[0]));
//	ShellSort(a3,sizeof(a3)/sizeof(a3[0]));
//	SelectSort(a3,sizeof(a3)/sizeof(a3[0]));
	PrintArray(a3,sizeof(a3)/sizeof(a3[0]));	

	return 0;
}

/*
*
*
*/
void PrintArray(const int a[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

/*
*
*
*/
void BubbleSort(int a[],int size)
{
	int i,j,tmp,flag;
	for(j=0;j<size-1;j++)
	{
		flag = 0;
		for(i=0;i<size-j-1;i++)
		{
			if(a[i] > a[i+1])
			{
				tmp=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp;
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}
}

/*
*
*
*/
void QuickSort(int a[],int left,int right)
{
	if(left >= right)
		return ;
	int l,r,key;
	l = left;
	r = right;
	key = a[left];
	while(l < r)
	{
		while(l<r && key<=a[r]) r--;
		a[l] = a[r];
		while(l<r && key>=a[l]) l++;
		a[r] = a[l];
	}
	a[l] = key;
	QuickSort(a,left,l-1);
	QuickSort(a,l+1,right);
}

/*
*
*
*/
void InsertSort(int a[],int size)
{
	int i,j,tmp;
	for(i=1;i<size;i++)
	{
		if(a[i]<a[i-1])
		{
			tmp=a[i];
			for(j=i;j>=0 && tmp<a[j-1];j--)
			{
				a[j]=a[j-1];
			}
			a[j] = tmp;
		}
	}
}


/*
*
*
*/
void ShellSort(int a[],int size)
{
	int gap,i,j,k,tmp;
	for(gap=size/2;gap>0;gap/=2)
	{
		for(i=0;i<gap;i++)
		{
			for(j=i+gap;j<size;j+=gap)
			{
				if(a[j]<a[j-gap])
				{
					tmp=a[j];
					for(k=j-gap;k>=0 && tmp<a[k];k-=gap)
					{
						a[k+gap]=a[k];
					}
					a[k+gap]=tmp;
				}
			}
		}
	}
}

/*
*
*
*/
void SelectSort(int a[],int size)
{
	int i,j,min,tmp;
	for(i=0;i<size-1;i++)	/*从0开始,需要n-1轮选取*/
	{
		min=i;
		for(j=i+1;j<size;j++)	/*在n-i个无序的数据中找出最小的数据*/
		{
			if(a[min] > a[j])
				min=j;
		}
		if(min != i)	/*第i轮,找出的第i小的数据,和位置i的数据交换位置*/
		{
			tmp=a[i];
			a[i]=a[min];
			a[min]=tmp;
		}
	}
}
