#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hexToDec.hpp"
#include "cache.hpp"

using namespace std;

long long int ctr,total;
double missRatio;

Cache cache;

void sim(const string &str)
{
	long long int address = hexToDec(str);
	//cout<<address<<" "<<address/blockSize<<" "<<(address/blockSize)%8<<endl;
	if(cache.exist(address))
	{
		cache.update(address);
	}
	else
	{
		ctr++;
		cache.add(address);
		cache.update(address);
	}
	total++;
}

void simulate(ifstream &inFile,const char &asso,const char &repl)
{
	inFile.seekg(ios::beg);
	string str;
	cache.set(asso,repl);
	while(inFile>>str)
	{
	//	cache.print();
		sim(str);
	}
	missRatio = (double)ctr/total;
	cout<<fixed<<missRatio<<endl;
}

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		cout<<"Less Nubmer of Arguments.\n";
		return  0;
	}

	preCompute();
	
	ifstream inFile;
	inFile.open(argv[1]);
	if(inFile.fail())
	{
		cout<<"Failed to open input file : "<<argv[1]<<endl;
		return 0;
	}

	char asso,repl;
	cin>>asso>>repl;
	simulate(inFile,asso,repl);
	
	inFile.close();
	return 0;
}