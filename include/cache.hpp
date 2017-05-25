#ifndef CACHE_HPP
#define CACHE_HPP

#include <iostream>
#include <vector>

using namespace std;

const int blockSize = 16;
const int cacheSize = 128;

class Block
{
	long long int blockNum;
	long long int timeStamp;
public:
	Block();
	void setBlock(const long long int &);
	void setTime(const long long int &);
	long long int getTime();
	long long int getBlock();
};

class Cache
{
	vector<Block> cache;
	int numBlock;
	char replPolicy,associativity;
public:
	Cache();
	void set(const char &,const char &);
	void reset();
	bool exist(const long long int &);
	void update(const long long int &);
	void add(const long long int &);
	void print();
};

#endif