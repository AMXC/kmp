#include <stdio.h>
#include <string.h>

void getNext(char *par,int len,int *next)
{
	int j,k;
	next[0] = -1;
	j = 0;
	k = -1;
	while(j < len-1)
	{
		if(k==-1 || par[j] == par[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int kmp(char *tar,char *par)
{
	int next[100];
	int i = 0;
	int j = 0;
	int t_len = 0;
	int p_len = 0;
	t_len = strlen(tar);
	p_len = strlen(par);
	
	getNext(par,p_len,next);

	while(i<t_len)
	{
		if(j==-1||par[j]==tar[i])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
		if(j==p_len) return i-p_len;
	}
	return 0;
}

int main()
{
	kmp("ababababababababababbcdeddabcdefg","abcabcabcdef");
	return 0;
}