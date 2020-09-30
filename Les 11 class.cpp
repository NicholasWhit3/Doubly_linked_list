#include <iostream>
#include "ListOfStudents.h"



int main()
{
	ListOfStudents* classNote = new ListOfStudents;
	classNote->pushFront();
	Student* newStudent = new Student(0);
	newStudent->setName("John");
	Student* newAStudent = new Student(1);
	newAStudent->setName("Henry");
	Student* newBStudent = new Student(2);
	newBStudent->setName("Louca");
	Student* newCStudent = new Student(3);
	newCStudent->setName("Rick");
	classNote->pushBack(newStudent);
	classNote->pushFront(newAStudent);
	classNote->pushBack(newBStudent);
	classNote->pushBack(newCStudent);

	ListOfStudents newList;
	classNote->print();
	//newList.pushBack(classNote->purgeBack());
	newList.pushFront(classNote->purge(5));
	std::cout << "Purge:" << std::endl;
	classNote->print();
	std::cout << std::endl;
	newList.print();

	classNote->deleteNumber(1);
	std::cout << std::endl;
	classNote->print();
	
	
}