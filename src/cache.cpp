#include "cache.hpp"

Block :: Block()
{

}

void Block :: setBlock(const long long int &block)
{
	this->blockNum = block;
}

void Block :: setTime(const long long int &time)
{
	this->timeStamp = time;
}

long long int Block :: getBlock()
{
	return this->blockNum;
}

long long int Block :: getTime()
{
	return this->timeStamp;
}

Cache :: Cache()
{
	this->numBlock = cacheSize/blockSize;
	this->cache.resize(this->numBlock);
	for(int i=0;i<this->numBlock;i++)
	{
		this->cache[i].setBlock(-1);
		this->cache[i].setTime(-1);
	}
	this->replPolicy = replPolicy;
	this->associativity = associativity;
}

void Cache :: reset()
{
	for(int i=0;i<this->numBlock;i++)
	{
		this->cache[i].setBlock(-1);
		this->cache[i].setTime(-1);
	}
}

void Cache :: set(const char &associativity,const char& replPolicy)
{
	this->replPolicy = replPolicy;
	this->associativity = associativity;
}

bool Cache :: exist(const long long int &address)
{
	long long int block = address/blockSize;
	int index = block%(this->numBlock);
	if(this->associativity == 'd')
	{
		if(this->cache[index].getBlock() == block)
			return true;
	}
	else
	{
		if(this->cache[index].getBlock() == block)
			return true;
		if(index%2 == 0)
		{
			if(this->cache[index+1].getBlock() == block)
				return true;
		}
		else
		{
			if(this->cache[index-1].getBlock() == block)
				return true;
		}
	}
	return false;
}

void Cache :: update(const long long int &address)
{
	long long int block = address/blockSize;
	for(int i=0;i<(this->numBlock);i++)
	{
		if(this->cache[i].getBlock() == -1)
			continue;
		if((this->cache[i].getBlock() == block))
		{
			this->cache[i].setTime(1);
		}
		else
		{
			this->cache[i].setTime(this->cache[i].getTime()+1);
		}
	}
}

void Cache :: add(const long long int &address)
{
	long long int block = address/blockSize;
	int index = block%(this->numBlock);
	int nextIndex = index+1;
	if(this->associativity == 'd')
	{
		this->cache[index].setBlock(block);
	}
	else
	{
		if(index%2)
			nextIndex = index-1;
		if(this->cache[index].getBlock() == -1)
		{
			this->cache[index].setBlock(block);
			return ;
		}
		else if(this->cache[nextIndex].getBlock() == -1)
		{
			this->cache[nextIndex].setBlock(block);
			return ;
		}
		if(this->cache[index].getTime() > this->cache[nextIndex].getTime())
		{
			this->cache[index].setBlock(block);
		}
		else
		{
			this->cache[nextIndex].setBlock(block);
		}
	}
}

void Cache :: print()
{
	cout<<this->replPolicy<<this->associativity<<endl;
}