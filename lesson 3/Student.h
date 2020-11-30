#pragma once
class Student
{
public:
	enum class Gender {MALE, FEMALE, UNDEFINED};
	void setName(const char* name);
	const char* getName() const;
	void addMark(size_t mark);
	void print() const;
	void setGender(Gender gender);
	const char* getGenderStr() const;
	Gender getGender() const;
	size_t getId() const;
	const size_t& getCountMarks() const;
	static size_t getCountOfStudents(); //static method!!
	static int compareStudentsByRate(const Student& one,const Student& two);
	double getAverageMark() const;
	static int compareStudentsByName(const Student& one, const Student& two);
	Student& operator = (const Student & other);

	explicit Student(const char* name, Gender gender=Gender::UNDEFINED);
	Student();
	Student(const Student & other); // copy ctor
	~Student();
private:
	size_t id = 0;
	char* name = nullptr;
	size_t countMarks = 0;
	size_t* marks = 0;
	Gender gender = Gender::UNDEFINED;
	static size_t countStudents; // static field, one for all class objects
	//help method for copy marks
	void setOtherMarks(const Student& other);//size_t* otherMarks, size_t size);
};
inline	const char* Student::getName() const
{
	return name;
}

inline  const size_t& Student::getCountMarks() const
{
	return countMarks;
}

inline void Student::setGender(Gender gender)
{
	if (gender >= Gender::MALE && gender <= Gender::UNDEFINED)
	{
		this->gender = gender;
	}
	else
		this->gender = Gender::UNDEFINED;
}

inline Student::Gender Student::getGender() const
{
	return Gender();
}

inline size_t Student::getId() const
{
	return id;
}

inline size_t Student::getCountOfStudents()
{
	return countStudents;
}

