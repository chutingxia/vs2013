// two Summer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
int* twoSum(int* nums, int numsSize, int target){
	int findindex[2];
	int value;
	int findflag = 0;
	for (int i = 0; i < numsSize;i++)
	{

		value = target - nums[i];
		for (int j = 1; j < numsSize;j++)
		{
			if (value==nums[j])
			{
				findindex[0] = i;
				findindex[1] = j;
				return findindex;
			}
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	
	int nums[5] = { 2, 4, 5, 3, 11 };
	int *findindex;
	findindex=twoSum(nums, sizeof(nums) / sizeof(nums[0]), 9);
	printf("%d,%d", findindex[0], findindex[1]);
	getchar();
	return 0;

}

