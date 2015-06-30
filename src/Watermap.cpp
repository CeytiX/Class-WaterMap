#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Watermap.h"

using namespace std;

/**************
* constructor *
**************/

Watermap::Watermap()
{
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			map[i][j] = 0;
		}
	}

	seed = 1;
	
	random = true;
}

/*************
* destructor *
*************/

Watermap::~Watermap()
{
	/** void **/
}

/******************
* void generate() *
******************/

void Watermap::generate()
{
	if(random) seed = time(0);
	srand(seed);
	
	/** boat 1 **/
	bool boat1 = false;
	while(!boat1)
	{
		int direction = rand()%2 + 1;
		int x(SIZE+1), y(SIZE+1);
		if(direction == 1)
		{
			do
			{
				x = rand()%SIZE;
				y = rand()%(SIZE-4) + 2;
			} while(map[x][y-2]!=0 || map[x][y-1]!=0 || map[x][y]!=0 || map[x][y+1]!=0 || map[x][y+2]!=0);
			
			map[x][y-2] = 2;
			map[x][y-1] = 2;
			map[x][y] = 2;
			map[x][y+1] = 2;
			map[x][y+2] = 2;
			
			boat1 = true;
		}
		else
		{
			do
			{
				x = rand()%(SIZE-4) + 2;
				y = rand()%SIZE;
			} while(map[x-2][y]!=0 || map[x-1][y]!=0 || map[x][y]!=0 || map[x+1][y]!=0 || map[x+2][y]!=0);
			
			map[x-2][y] = 2;
			map[x-1][y] = 2;
			map[x][y] = 2;
			map[x+1][y] = 2;
			map[x+2][y] = 2;
			
			boat1 = true;
		}
	}
	/** end boat 1 **/
	
	/** boat 2 **/
	bool boat2 = false;
	while(!boat2)
	{
		int direction = rand()%2 + 1;
		int x(SIZE+1), y(SIZE+1);
		if(direction == 1)
		{
			do
			{
				x = rand()%SIZE;
				y = rand()%(SIZE-3) + 2;
			} while(map[x][y-2]!=0 || map[x][y-1]!=0 || map[x][y]!=0 || map[x][y+1]!=0);
			
			map[x][y-2] = 3;
			map[x][y-1] = 3;
			map[x][y] = 3;
			map[x][y+1] = 3;
			
			boat2 = true;
		}
		else
		{
			do
			{
				x = rand()%(SIZE-3) + 2;
				y = rand()%SIZE;
			} while(map[x-2][y]!=0 || map[x-1][y]!=0 || map[x][y]!=0 || map[x+1][y]!=0);
			
			map[x-2][y] = 3;
			map[x-1][y] = 3;
			map[x][y] = 3;
			map[x+1][y] = 3;
			
			boat2 = true;
		}
	}
	/** end boat 2 **/
	
	/** boat 3 **/
	bool boat3 = false;
	while(!boat3)
	{
		int direction = rand()%2 + 1;
		int x(SIZE+1), y(SIZE+1);
		if(direction == 1)
		{
			do
			{
				x = rand()%SIZE;
				y = rand()%(SIZE-2) + 1;std::ostream &operator<<(ostream&, Watermap);
			} while(map[x][y-1]!=0 || map[x][y]!=0 || map[x][y+1]!=0);
			
			map[x][y-1] = 4;
			map[x][y] = 4;
			map[x][y+1] = 4;
			
			boat3 = true;
		}
		else
		{
			do
			{
				x = rand()%(SIZE-2) + 1;
				y = rand()%SIZE;
			} while(map[x-1][y]!=0 || map[x][y]!=0 || map[x+1][y]!=0);
			
			map[x-1][y] = 4;
			map[x][y] = 4;
			map[x+1][y] = 4;
			
			boat3 = true;
		}
	}
	/** end boat 3 **/
	
	/** boat 4 **/
	bool boat4 = false;
	while(!boat4)
	{
		int direction = rand()%2 + 1;
		int x(SIZE+1), y(SIZE+1);
		if(direction == 1)
		{
			do
			{
				x = rand()%SIZE;
				y = rand()%(SIZE-1) + 1;
			} while(map[x][y-1]!=0 || map[x][y]!=0);
			
			map[x][y-1] = 5;
			map[x][y] = 5;
			
			boat4 = true;
		}
		else
		{
			do
			{
				x = rand()%(SIZE-1) + 1;
				y = rand()%SIZE;
			} while(map[x-1][y]!=0 || map[x][y]!=0);
			
			map[x-1][y] = 5;
			map[x][y] = 5;
			
			boat4 = true;
		}
	}
	/** end boat 4 **/
}

/********************
* void setSeed(int) *
********************/

void Watermap::setSeed(int value)
{
	seed = abs(value);
}

/****************
* int getSeed() *
***************/

int Watermap::getSeed()
{
	return seed;
}

/***********************
* void setRandom(bool) *
***********************/

void Watermap::setRandom(bool value)
{
	random = value;
}

/*******************
* bool getRandom() *
*******************/

bool Watermap::getRandom()
{
	return random;
}

/******************************
* void setCell(int, int, int) *
******************************/

void Watermap::setCell(int x, int y, int value)
{
	if(x>=0 && x<SIZE && y>=0 && y<SIZE && value>=0 && value <=7)
	{
		map[x][y] = value;
	}
}

/************************
* int getCell(int, int) *
************************/

int Watermap::getCell(int x, int y)
{
	if(x>=0 && x<SIZE && y>=0 && y<SIZE)
	{
		return map[x][y];
	}
	else
	{
		return -1;
	}
}

/******************************************
* ostream& operator<<(ostream&, Watermap) *
******************************************/

ostream& operator<<(ostream& stream, Watermap map)
{
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			if(map.getCell(j, i) == 0)
			{
				cout << ". ";
			}
			else if(map.getCell(j, i) == 6)
			{
				cout << "o ";
			}
			else if(map.getCell(j, i) >=2 && map.getCell(j, i) <= 5)
			{
				cout << "# ";
			}
			else if(map.getCell(j, i) == 7)
			{
				cout << "x ";
			}
		}
		
		cout << endl;
	}
}
