// Longest Substring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "malloc.h"
#include "stdio.h"

//char **CatchSubString(char *sinput,int length){
//	int i,j,k;
//	char *p;
//	p = (char*)malloc(char *q[1024]);
//	char *q[1024];
//	int FindSameFlag = 0;
//	for (i = 0; sinput[i] != '\0';i++)
//	{
//		FindSameFlag = 0;
//		for (j = i + 1; sinput[j] != '\0'; j++)
//		{
//			memcpy(p, &sinput[i], j - i);
//			p[j - i] = '\0';
//			for (k = 0; k < j - i;k++)
//			{
//				if (sinput[j] == p[k]){
//					FindSameFlag = 1;
//					break;
//				}
//			}
//			if (FindSameFlag)
//			{
//				break;
//			}
//		}
//		if (!FindSameFlag){
//			memcpy(p, &sinput[i], j - i);
//			p[j - i] = '\0';
//		}
//		q[i] = (char*)malloc(strlen(sinput));
//		memcpy(q[i], p, strlen(p));
//		q[i][j - i] = '\0';
//	}
//	return q;
//
//}
//char *CatchLongestSubString(char **q,int num){
//	int MaxNum = strlen(q[0]);
//	char *s=q[0];
//	for (int i = 0; i < num; i++){
//		if (strlen(q[i])>MaxNum) {
//			MaxNum = strlen(q[i]);
//			s = q[i];
//		}
//	}
//	return s;
//}
//int _tmain(int argc, _TCHAR* argv[])
//{
//	char buf[1024];
//	char **q;
//	char *s;
//	int i = 0;
//	while (((buf[i]=getchar())!=EOF)&&buf[i]!='\n'){
//		i++;
//	}
//	buf[i] = '\0';
//	q=CatchSubString(buf,strlen(buf));
//	s = CatchLongestSubString(q, strlen(buf));
//	printf("The SubString is %s", s);
//	getchar();
//	return 0;
//}
//
int lengthOfLongestSubstring(char* s)
{
	int len = 0;
	char *end = s, *temp;
	char* addressTable[128] = { NULL };
	while (*end){
		temp = addressTable[*end];
		addressTable[*end] = end;
		if (temp >= s){
			len = end - s > len ? end - s : len;
			s = temp + 1;
		}end++;
	}
	len = end - s > len ? end - s : len;
	return len;
}