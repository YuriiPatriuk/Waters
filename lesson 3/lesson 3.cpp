#include <iostream>
#include <string>
using namespace std;
#include "Student.h"

Student stud3("Ivan", Student::Gender::MALE);

//int main()
//{
//	cout << "Count of students: " << Student::getCountOfStudents() << endl;
//	stud3.print();
//	cout << endl;
//	/*
//	lesson 2
//	for (size_t i = num; i >1; i--)
//	{
//		if (num%i==0&&denom%i==0)
//		{
//			num /= i;
//			denom /= i;
//			break;
//		}
//	}*/
//	Student stud1("Petro", Student::Gender::MALE);
//	stud1.addMark(10);
//	stud1.addMark(9);
//	stud1.addMark(7);
//	stud1.print();
//	cout << endl;
//
//	Student* stud2=new Student("Sophia", Student::Gender::FEMALE);
//	stud2->addMark(10);
//	stud2->print();
//
//	int res = Student::compareStudentsByName(stud1, *stud2);
//	if (res == 0)
//		cout << "Name`s a same" << endl;
//	else if (res == -1)
//		cout << "Name Petro" << endl;
//	else if (res == 1)
//		cout << "Name Sophia" << endl;
//
//	int result = Student::compareStudentsByRate(stud1, *stud2);
//	if (result == 0)
//		cout << "Average`s same" << endl;
//	else if (result == 1)
//		cout << "Average Petra bigger" << endl;
//	else if (result == -1)
//		cout << "Average Sophia bigger" << endl;
//	
//
//
//	cout << "\nCount of students: " << Student::getCountOfStudents() << endl;
//	delete stud2;
//
//	cout << "End of main!!" << endl;
//}

void demoCopyCtorAndAssign()
{
	Student Ann("Ann", Student::Gender::FEMALE);
	Ann.addMark(12);
	Ann.addMark(7);
	Ann.addMark(10);
	Ann.print();

	Student clone = Ann; //working default ctor copy, which get shallow(поверхневу) copy
	//this ctor doesn't good for dynamic variable
	cout << "Clone print: " << endl;
	clone.print(); 

	Student Maria("Maria", Student::Gender::FEMALE);
	Maria.addMark(12);
	Maria.addMark(7);
	Maria.addMark(10);
	Maria.print();

	Student* pointer = &Maria;
	Maria = *pointer;
	//clone = Maria = Ann; //operator =, default operation shallow copy 
	
}
void testFunc(const Student& student)
{
	cout << "Test Func works" << endl;
	student.print();
	cout << "Test Func ended" << endl;
	/*if (student.getCountMarks()>0)
	{
		student.addMark(12);
	}*/
}

int main()
{
	Student stud("Petro", Student::Gender::MALE);
	stud.addMark(10);
	stud.addMark(9);
	stud.addMark(7);
	stud.setGender(Student::Gender::FEMALE);
	stud.print();
	testFunc(stud);
	stud.print();
	cout << "--------------------" << endl;
	char name[]="Ivan";
	//testFunc(name); //ctor with 1 parametr compilator used for convert from char* to Student P.S: if without explisit
	testFunc(Student(name)); 
	cout << endl;
	testFunc(Student{ "Oleg", Student::Gender::MALE });



}
