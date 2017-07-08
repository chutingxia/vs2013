// paixu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
using namespace std;
#include <vector>

typedef vector<int>  DateVec;
void showsymbol();
void showsymbol(int num,int digit){
	for (int m = 0; m < num; m++){
		if (m == 0){
			printf("%s", '+');
		}
		for (int j = 0; j < digit; j++){
			printf("%s", ' + ');
		}
		printf("%s", '+');
	}
	printf("%s", '\n');
};

void showdata(int num, int digit,int cols){
	for (int m = 0; m <num; m++){
		if (m == 0){
			printf("%s", '|');
		}

		char tempdata[32];
		char Formatedta[32];
		_itoa_s(date.at(i*k + m), tempdata, 10);
		int s = strlen(tempdata);
		int w;
		memset(Formatedta, 0, sizeof(Formatedta));
		if (s < minusNum)
		{
			for (w = 0; w < minusNum - s; w++)
			{
				Formatedta[w] = ' ';
			}
			Formatedta[w] = '\0';
		}
		strcat_s(Formatedta, tempdata);
		for (int j = 0; j < minusNum; j++){
			p[num] = Formatedta[j];
			num++;
		}
		p[num] = '|';
		num++;
	}
	p[num] = '\n';
	num++;
}

int main()
{
	int k = 5;
	DateVec date;
	int Array[8] = { 588888886, 128, 18, 92, 1 ,22,23,58};
	int MaxIndex=0;
	int minusNum;
	int cols,lastlist;
	//char p[num]=NULL;
	for (int i = 0; i < 8; i++)
	{
		date.push_back(Array[i]);
	}


	for (int i = 1; i < date.size(); i++){
		if (date.at(i) > date.at(MaxIndex))
			MaxIndex = i;
	}
	minusNum = date.at(MaxIndex);
	int i = 0;
	int num=0;
	while (minusNum){
		minusNum /= 10;
		i++;
	}
	minusNum = i;

		cols = date.size() / k;
		lastlist = date.size() % k;
		//p= (char*)malloc(date.size()*(minusNum + 2) * 2);
		char p[1024];
		if (cols){
			for (i = 0; i < cols; i++){
				for (int j = 0; j < k; j++)
				{
					showsymbol(minusNum);

					showdata(k, minusNum, date, i);
				}
	
			
			}		
	}
		int dataxing;
		if (cols)
			dataxing = k;
		else
			dataxing = lastlist;

		for (int m = 0; m < dataxing; m++){
			if (m == 0){
				p[num] = '+';
				num++;
			}
		
			for (int j = 0; j < minusNum; j++){
				p[num] = '-';
				num++;
			}
			p[num] = '+';
			num++;
		}
		if (lastlist){
			p[num] = '\n';
			num++;
		}
	
		for (int m = 0; m < lastlist; m++){
			if (m == 0){
				p[num] = '|';
				num++;
			}
		
			char tempdata[32];
			char Formatedta[32];
			memset(Formatedta, 0, sizeof(Formatedta));
			_itoa_s(date.at(cols*k + m), tempdata, 10);
			int s = strlen(tempdata);
			int w;
			if (s < minusNum)
			{
				for (w = 0; w < minusNum - s; w++)
				{
					Formatedta[w] = ' ';
				}
			}
			strcat_s(Formatedta, tempdata);
			for (int j = 0; j < minusNum; j++){
				p[num] = Formatedta[j];
				num++;
			}
			p[num] = '|';
			num++;
		}
		if (lastlist){
			p[num] = '\n';
			num++;
		}
	
		for (int m = 0; m < lastlist; m++){
			if (m == 0){
				p[num] = '+';
				num++;
			}
			
			for (int j = 0; j < minusNum; j++){
				p[num] = '-';
				num++;
			}
			p[num] = '+';
			num++;
		}
		p[num] = '\0';

		printf("%s", p);
	return 0;
}



