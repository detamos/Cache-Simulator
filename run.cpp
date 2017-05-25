#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		cout<<"Wrong Numbebr of arguments\n";
		return 0;
	}

	ifstream inFile;
	inFile.open("./input/input");
	if(inFile.fail())
	{
		cout<<"Error : Couldnt open file : "<<"./input/input\n";
		return 0;
	}

	string str;
	cout<<"\t    LRU\t   FIFO\n";
	cout<<"Direct : ";
	int ctr = 0;
	while(cin>>str)
	{
		string args = argv[1];
		args = args + " " + str;
		string command = "./bin/cacheSimulator ";
		command += args;
		system(command.c_str());
		ctr++;
		if(ctr == 2)
			cout<<endl<<"2-Way  : ";
	}
	cout<<endl;

	inFile.close();

	return 0;
}