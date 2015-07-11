#include <stdio.h>
#include <stdlib.h>

int SeqSearch(int a[],int len,int key);
int BinSearch(int a[],int len,int key);
int IndexSearch();
int HashSearch();

int main(int argc,char **argv)
{
	int aseq[]={1,2,3,4,5,66,77,88,99,100,111};
	int ret;
	int key = atoi(argv[1]);
	ret = SeqSearch(aseq,sizeof(aseq)/sizeof(aseq[0]),key);
//	ret = BinSearch(aseq,sizeof(aseq)/sizeof(aseq[0]),key);
	printf("I Find %d @ %d\n",key,ret+1);
	return 0;
}


/*
*顺序查找
*SeqSearch
*/
int SeqSearch(int a[],int len,int key)
{
	int index;
	for(index=0;index<len;index++)
	{
		if(a[index]==key)
	    {return index;}
	}
	return -1;
}

/*
*二分查找
*BinSearch
*/
int BinSearch(int a[],int len,int key)
{
	int low,high,mid;
	low = 0;
	high = len;
	while(low <= high)		/**/
	{
		mid = low+(high-low)/2;		/*整数溢出，low+((high-low)/2)*/
		if(a[mid] < key)
			low = mid + 1;
		else if(a[mid] > key)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

/*
*索引查找
*IndexSearch
*/
int IndexSearch()
{
	return 0;
}
/*
*哈希查找
*HashSearch
*/
int HashSearch()
{
	return 0;
}