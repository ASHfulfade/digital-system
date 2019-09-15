#include<stdio.h>//十进制转二进制 以二进制为基础转成十六进制
#include<math.h>
int main()
{
	int m, a[20], i, n, s, j, b[20], q, t = 0;
	char c[20] = {0};
	printf("please input the number:");
	scanf("%d", &m);
	s = m;
	n = 0;
	while(m != 0)
	{
		i = s % 2;
		a[n] = i;
		m = m / 2;
		s = m;
		n++;
	}
	n = n - 1;
	printf("the binary form is:");
	for(j = 0; j <= n; j++)
	{
		b[j] = a[n-j];
		printf("%d", b[j]);
	}
	printf("\n");
	printf("the helix form is:");
	n=n + 1;
	s=n % 4;
	q=n / 4;
	if(n > 4)
	{
		for(i = 0; i <= s - 1; i++)
			t += b[i] * pow(2, s - 1 - i);
		c[0] = t + 48;
		printf("%c", c[0]);
		
		for(j = 1; j <= q; j++)
		{
			t = b[s] * 8 + b[s + 1] * 4 + b[s + 2] * 2 + b[s + 3];
			if(t == 10)
				c[j] = 'A';
			if(t == 11)
				c[j] = 'B';
			if(t == 12)
				c[j] = 'C';
			if(t == 13)
				c[j] = 'D';
			if(t == 14)
				c[j] = 'E';
			if(t == 15)
				c[j] = 'F';
			if(t < 10)
				c[j] = t + 48;
			s = s + 4;
			printf("%c", c[j]);
		}
	}
	else
	{
		s = 0;
		t = 0;
		for(i = n - 1; i >= 0; i--)
			t = t + b[i] * pow(2, n-i-1);
		if(t == 10)
			c[i] = 'A';
		if(t == 11)
			c[i] = 'B';
		if(t == 12)
			c[i] = 'C';
		if(t == 13)
			c[i] = 'D';
		if(t == 14)
			c[i] = 'E';
		if(t == 15)
			c[i] = 'F';
		if(t < 10)
			c[i] = t + 48;
		printf("%c", c[i]);
	}
	printf("\n");
	return 0;
}
