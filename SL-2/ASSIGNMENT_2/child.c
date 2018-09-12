#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char* argv[])
{
	int n=argc;
	
	printf("In child : \n");
	printf("\nSorted array : \n");
	
	int a[100];
	for(int i=0;i<n;i++)
	{
		a[i]=atoi(argv[i]);
		printf("%d ",a[i] );
	}
	printf("\n\nEnter element to binary search : ");
	int ele;
	scanf("%d",&ele);

	int l=0,r=n-1,mid=0,flag=0;

	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]==ele)
		{
			printf("\nFound at %d\n",mid );
			flag=1;
			break;
		}
		if(a[mid]>ele)
		{
			r=mid-1;
		}
		else
			l=mid+1;
	}
	if(!flag)
	{
			printf("\nNot found");
	}
	return 0;
}
