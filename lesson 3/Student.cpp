#include <iostream>
using std::cout;
using std::endl;
#include "Student.h"
size_t Student::countStudents = 0;

void Student::setName(const char* name)
{
	if (name == nullptr || strlen(name) == 0)
	{
		return;
	}
	if(this->name != nullptr)
	{
		delete[] this->name;
	}
	size_t size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}

Student::Student(const char* name, Gender gender)
{
	setName(name);
	setGender(gender);
	id = ++countStudents;
	cout << "<<<<<<Ctor for " << name << endl;
}
Student::Student()
	: Student("Noname")
{}
Student::Student(const Student & other)
{
	setName(other.name);
	setOtherMarks(other);
	gender = other.gender;
	id = ++countStudents;
}
Student::~Student()
{
	cout << "Dtor for " << (name != nullptr ? name : "Empty") << endl;
	if (name!=nullptr)
	{
		delete[]name;
		name = nullptr;
	}
	if (marks != nullptr)
	{
		delete[]marks;
		marks = nullptr;
	}
	--countStudents;
}
void Student::setOtherMarks(const Student& other)
{
	if (this->marks!=nullptr)
	{
		delete[] marks;
	}
	/*countMarks = other.countMarks;*/
	marks = new size_t[countMarks = other.countMarks];
	for (size_t i = 0; i < countMarks; i++)
	{
		marks[i] = other.marks[i];
	}
}
void Student::addMark(size_t mark)
{
	if (mark > 0)
	{
		size_t* temp = new size_t[++countMarks];
		for (size_t i = 0; i < countMarks - 1; i++)
		{
			temp[i] = marks[i];
		}
		temp[countMarks - 1] = mark;
		delete[]marks;
		marks = temp;
	}
}

void Student::print() const
{
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout <<"Gender: "<< getGenderStr() << endl;
	cout << "Marks: ";
	for (size_t i = 0; i < countMarks; i++)
	{
		cout << marks[i] << " ";
	}
	cout << "\nAverage mark: " << getAverageMark() << endl;
	cout << endl;
}

const char* Student::getGenderStr() const
{
	static const char* nameGender[]{ "Male","Female","Undefined" };
	return nameGender[(int)gender]; 
}
//compare stud by average
//if = , return 0
//if < , return -1
//if > , return 1
int Student::compareStudentsByRate(const Student& one, const Student& two)
{
	double res = one.getAverageMark() - two.getAverageMark();
	if(res<0)
		return -1;
	if (res > 0)
		return 1;
	return 0;
}

double Student::getAverageMark() const
{
	double sum = 0;
	for (size_t i = 0; i < countMarks; i++)
	{
		sum += marks[i];
	}
	return sum / (countMarks > 0 ? countMarks : 1);
}

int Student::compareStudentsByName(const Student& one, const Student& two)
{
	return strcmp(one.name, two.name);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		setName(other.name);
		setOtherMarks(other);
		gender = other.gender;
		id = other.id;
	}
	else
		cout << "Warning!!" << endl;
	return *this;
}

//strcmp()
