#include <iostream>

const int SIZE = 10; /** minimum 5 **/

class Watermap
{
	public:

		Watermap();
		~Watermap();

		void generate();

		void setSeed(int);
		int getSeed();

		void setRandom(bool);
		bool getRandom();

		void setCell(int, int, int);
		int getCell(int, int);
	
	public:
		
		int map[SIZE][SIZE];

		int seed;
		bool random;
};

std::ostream& operator<<(std::ostream&, Watermap);		
