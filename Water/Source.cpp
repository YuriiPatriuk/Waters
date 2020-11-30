#include <iostream>
#include "Water.h"
using std::cout;
using std::endl;

int main()
{
	Water lakes[3];
	lakes[0].setName("Test1");
	lakes[0].setTypeWater(Water::TypeWater::LAKE);
	lakes[1].setName("Test2");
	lakes[1].setLength(4);
	lakes[1].setWidth(4);
	lakes[1].setTypeWater(Water::TypeWater::LAKE);
	lakes[2].setName("Test3");
	lakes[2].setTypeWater(Water::TypeWater::OCEAN);

	Water lake("Lake1", Water::TypeWater::OCEAN);
	Water lake2("Lake2", Water::TypeWater::LAKE);
	//lake.setName("Lake1");
	lake.setWidth(23);
	lake.setLength(6);
	lake2.setWidth(23);
	lake2.setLength(16);
	lake.setMaxDepth(3);
	lake.print();
	cout << "------------------" << endl;
	//cout << "Volume: " << lake.volume() << endl;
	//cout << "Square: " << lake.square() << endl;
	/*bool check = Water::compareIdenticalType(lake,lake2);
	cout <<std::boolalpha<< check << endl;*/
	/*int res = Water::compareSquares(lake, lake2);
	cout << "Res: " << res << endl;*/
	//Water::findTheBigestWater(lakes, 3, Water::TypeWater::LAKE);


	return 0;
}