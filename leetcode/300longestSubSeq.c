#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define max(a,b) ((a>b)?(a):(b))
int lengthOfLIS(int *nums,int numsSize)
{
	int *dp;
	int i,j;
	int m =0;

	dp = (int*)malloc(sizeof(int)*numsSize);

	for(i=0;i<numsSize;i++)
	{
		dp[i] = 1;
	}

	for(i=1;i<numsSize;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(nums[i]>nums[j]) {
				dp[i] = max(dp[j]+1,dp[i]);
				
			}

		}
	}
	for(i=0;i<numsSize;i++)
	{
		m = max(m,dp[i]);
	}
	return m;
}
