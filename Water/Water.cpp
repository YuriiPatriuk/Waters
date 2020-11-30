#include <iostream>
#include "Water.h"
using std::cout;
using std::endl;
size_t Water::count = 0;

void Water::print() const
{
	cout << "Name: " << name << endl;
	cout << "Type: " << getTypeStr() << endl;
	cout << "Width: " << width << endl;
	cout << "Length: " << length << endl;
	cout << "Max depth: " << maxDepth << endl;
	cout << "Count of waters: " << count << endl;
}
 
Water::Water()
	:Water("Noname")
{
}

const size_t Water::volume() const
{
	return width*length*maxDepth;
}

const size_t Water::square() const
{
	return width*length;
}

bool Water::compareIdenticalType(const Water& one, const Water& second)
{
	if (one.type==second.type)
		return true;

	return false;
}

int Water::compareSquares(const Water& one, const Water& second)
{
	if (one.square() == second.square())
		return 0;
	else if (one.square() >= second.square())
		return 1;
	else
		return -1;
}

void Water::findTheBigestWater(Water waters[], const size_t& size, const Water::TypeWater& type)
{
	Water max=waters[0];
	for (size_t i = 1; i < size; i++)
	{
		if (waters[i].type == type && max.square() < waters[i].square())
			max = waters[i];
	}
	cout << "The largest:" << endl;
	max.print();
}

Water::Water(const char* name, TypeWater type)
{
	setName(name);
	setTypeWater(type);
	++count;
}

void Water::setName(const char* name)
{
	if (name == nullptr || strlen(name) == 0)
	{
		return;
	}
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
	size_t size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}

void Water::setWidth(const size_t width)
{
	this->width = width;
}

void Water::setLength(const size_t length)
{
	this->length = length;
}

void Water::setMaxDepth(const size_t max)
{
	this->maxDepth = max;
}

void Water::setTypeWater(TypeWater type)
{
	if (type >= TypeWater::LAKE && type <= TypeWater::SEA)
	{
		this->type = type;
	}
	else
		this->type = TypeWater::LAKE;
}

