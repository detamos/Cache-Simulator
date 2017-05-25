#include "hexToDec.hpp"

vector<long long int> power(10);

void preCompute()
{
	long long int num = 1;
	for(int i=0;i<9;i++)
	{
		power[i] = num;
		num *= 16;
	}
}

long long int hexToDec(const string &hex)
{	
	long long int ret = 0;
	int n = hex.size();

	for(int i=0;i<n;i++)
	{
		if(hex[i] >= '0' && hex[i] <= '9')
			ret += (power[n-i-1]*(hex[i]-'0'));
		else
			ret += (power[n-i-1]*(hex[i]-'A'+10));
	}

	return ret;
}
