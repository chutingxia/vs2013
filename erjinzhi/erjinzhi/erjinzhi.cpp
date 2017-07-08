// erjinzhi.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h> 
#include "string.h"

typedef long int INT_32;
void GetPerBinary(INT_32 data,int *);

int GetbinaryNumber(INT_32 leftdata, INT_32 rightdata){
	int *p = NULL;
	p = (int *)malloc(sizeof(int) * 32);
	memset(p, 0, 32 * sizeof(int));
	GetPerBinary(leftdata,p);
	int *q = NULL;
	q = (int *)malloc(sizeof(int) * 32);
	memset(q, 0, 32 * sizeof(int));
	GetPerBinary(rightdata,q);
	int Num[32 * 32] = { 0 };
	//memset(Num, 0, 32 * 32 * sizeof(int));
	//int m = 0;
	int dataNum=0;
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++){
				int m= i + j;
				Num[m] += p[i] * q[j];
		}
	}
	for (int i = 0; i < 32 * 32;i++){
		while (Num[i]>1)
		{
			Num[i] -= 2;
			Num[i + 1]+= 1;
		}
	}
	for (int i = 0; i < 32 * 32; i++){
		if (Num[i])
			dataNum++;
	}
	free(p);
	free(q);
	return dataNum;
} 

void GetPerBinary(INT_32 data,int *a){
	int i = 0;
	while (data){
		if (data % 2){
			a[i] = 1;
		}else{
			a[i] = 0;
		}
		i++;
		data = data / 2;
	}
}

int main()
{
	INT_32 leftitem=4;
	INT_32 rightitem=32;
	int num;
	num=GetbinaryNumber(leftitem, rightitem);
	printf("Num=%d", num);
	getchar();
	return 0;
}

