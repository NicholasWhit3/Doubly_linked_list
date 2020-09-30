#pragma once
#include <iostream>


class Student														//Node
{
public:
	Student(int number);
	~Student();
	void setName(std::string name);
	void setGroup(std::string group);
	void setMark(int mark);	
	void setNext(Student* next) { this->next = next; };	
	void setNumber(int number) { this->number = number; };
	void setPrev(Student* prev) { this->prev = prev; };
	void print();
	std::string getName() { return name; };
	std::string getGroup() { return group; };
	int getMark() { return mark; };
	int getNumber() { return number; };


	Student* getNext() { return next; };
	Student* getPrev() { return prev; };
private:
	int number;
	std::string name = "Eric";
	std::string group = "31A";
	int mark = 1;
	Student* next = nullptr;
	Student* prev = nullptr;
	
};

class ListOfStudents												//List(head)
{
public:
	ListOfStudents();
	~ListOfStudents();
	void print();
	void pushBack(Student* newStudent = nullptr);			
	void pushFront(Student* newStudent = nullptr);			
	Student* read();
	Student* purgeBack();									
	Student* purgeFront();
	Student* purge(int number);
	void deleteBack();
	void deleteFront();
	void deleteNumber(int number);
	void InsertPosition(Student* newStudent, int position);
	int getCounterOfStudent() { return counterOfStudent; };		//счетчик студентов за всё время.
	Student* findStudent(std::string name);
	ListOfStudents* findStudents(std::string name);

private:
	int counterOfStudent;
	Student* head = nullptr;
	Student* tail = nullptr;
	int countOfStudents = 0;
	int currentIndex = 0;
	Student* currentStudent = nullptr;
};



