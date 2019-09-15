/* task01 for digital system (mainly use strings)
 * 		1. translate decimal number to binary and hex 
 *		2. accomplish complement
 *      3. simulate 32bits
 * author: fulfade 
 * last modified date: 10/09/2019
 * release 01
 */
#include<stdio.h>
#include<malloc.h>
#include<math.h>
char* convert_2(int num);
char* convert_16(int num);

/*
 *main function
 */
int main(int argc, char** argv)
{
	int num = 0;

	printf("Enter the integer:\t");

	while(scanf("%d", &num))
	{
		char* result_2;
		char* result_16;
	    result_2 = convert_2(num);
		result_16 = convert_16(num);
		printf("binary:%s\n", result_2);
		printf("hex:0X%s\n", result_16);
		free(result_2);
		free(result_16);
		printf("\nEnter the integer:\t");
	}

	return 0;
}

/*
 *convert integer to binary,accomplish complement
 */
char* convert_2(int num)
{
	char* a = (char*)malloc(33);
	char* result = (char*)malloc(33);
	int source = num;
	int temp = abs(num);
	int i = 0;

	while(temp)
	{
		num = temp % 2;
		a[i++] = 48 + num;					   //ascii code for '0' is 48
		temp /= 2;
	}

	int y = 0, x = 31;
    for(; y < i; x--, y++)
	{
		result[x] = a[y];
	}

	result[32] = '\0';
	for(int j = 0; j <= x; j++)
		result[j] = '0';

	if(source < 0)								//if the integer is negative, compute the complement
	{
		bool flag[32] = {0};					//use flag[32] to store carry-bits
		flag[31] = 1;
		for(int j = 0; j < 32; j++)				//reverse the binary string
		{
			if(result[j] == '1')
				result[j] = '0';
			else
				result[j] = '1';
		}
		for(int j = 31; j >= 0; j--)			//for each bits, judge whether necessary to carry the bit
		{
			if(result[j] == '1' && flag[j])
			{
				flag[j - 1] = 1;
				result[j] = '0';
			}
			else if(result[j] == '0' && flag[j])
			{
				result[j] = '1';
			}
		}
	}

	free(a);
	return result;
}

/*
 *use returned string of convert_2() to compute the hex
 */
char* convert_16(int num)
{
	char* result = (char*)malloc(8);
	char* string_b = convert_2(num);
	int i = 0;
	int temp = 0;

	while(i < 8)
	{
		temp = 0;
		for(int j = 0; j < 4; j++)				//use each four bits of binary to compute one hex
		{
			if(string_b[j + 4 * i] - '0')
				temp += pow(2, 3 - j);
		}
		if(temp < 10)
			result[i] = temp + 48;
		else
			//ascii code for 'A' is 65, result[i] for case "temp >= 10" is "temp + 65 - 10"
			result[i] = temp + 55;
		i++;
	}

	return result;
}
