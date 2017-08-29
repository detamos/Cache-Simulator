#include <bits/stdc++.h>

using namespace std;

string toHex(long long int num)
{
	string ret;
	for(int i=0;i<10;i++)
	{
		int rem = num%16;
		num /= 16;
		if(rem <= 9)
			ret.insert(ret.begin(),'0'+rem);
		else
			ret.insert(ret.begin(),'A'+rem-10);
	}
	return ret;
}

int main()
{
	srand(time(NULL));
	int n = 8192;
	for(int i=0;i<10000;i++)
	{
		long long int num = rand()%n;
		cout<<toHex(num)<<endl;
	}
	return 0;
}