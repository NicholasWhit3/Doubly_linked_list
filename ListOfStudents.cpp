#include "ListOfStudents.h"

ListOfStudents::ListOfStudents()
{

}

ListOfStudents::~ListOfStudents()
{

}

void ListOfStudents::print()
{
	currentStudent = head;
	for (int i = 0; i < countOfStudents; i++)
	{
		
		std::cout << i + 1 << ") ";
		currentStudent->print();
		currentStudent = currentStudent->getNext();
	}
}

void ListOfStudents::pushBack(Student* newStudent)
{
	
	if (!newStudent)
	{
		newStudent = new Student(counterOfStudent + 1);
	}
	else
	{
		newStudent->setNumber(counterOfStudent + 1);
	}
	if (!tail)
	{
		head = tail = newStudent;
		countOfStudents++;
		counterOfStudent++;
	}
	else
	{
		newStudent->setPrev(tail);
		tail->setNext(newStudent);
		tail = newStudent;
		countOfStudents++;
		counterOfStudent++;
	}

}

void ListOfStudents::pushFront(Student* newStudent)
{
	if (!newStudent)
	{
		newStudent = new Student(counterOfStudent + 1);
	}
	else
	{
		newStudent->setNumber(counterOfStudent + 1);
	}
	if (!head)
	{
		head = tail = newStudent;
		countOfStudents++;
		counterOfStudent++;
	}
	else
	{
		newStudent->setNext(head);
		head->setPrev(newStudent);
		head = newStudent;	
		countOfStudents++;
		counterOfStudent++;
	}
	
}

Student* ListOfStudents::purgeBack()
{
	Student* purgeStudent = tail;


	if (tail == head)
	{
		tail = head = nullptr;
	}
	else
	{
		tail = tail->getPrev();
		tail->setNext(nullptr);

	}
	countOfStudents--;
	return purgeStudent;
}														

Student* ListOfStudents::purgeFront()					
{
	Student* purgeStudent = head;

	if (head == tail)
	{
		head = tail = nullptr;
	}
	else 
	{
		head = head->getNext();
		head->setPrev(nullptr);
	}
	countOfStudents--;
	
	return purgeStudent;
}

Student* ListOfStudents::purge(int number)				
{
	Student* purgeStudent = head;						
	Student* prevStudent = nullptr;
	Student* nextStudent = nullptr;
	number--;
	if (head)
	{
		for (int i = 0; i < number; i++)
		{
			prevStudent = purgeStudent;
			purgeStudent = purgeStudent->getNext();
			nextStudent = purgeStudent->getNext();
		}
		prevStudent->setNext(nextStudent);
		countOfStudents--;
		return purgeStudent;
	}

	return nullptr;
}  

void ListOfStudents::deleteBack()
{
	Student* prevNext;
	Student* purgeStudent;

	if (head)
	{
		purgeStudent = head;
		while (purgeStudent->getNext())
		{
			prevNext = purgeStudent;
			purgeStudent = purgeStudent->getNext();
		}
		prevNext = nullptr;
		countOfStudents--;
		delete purgeStudent;
	}
}

void ListOfStudents::deleteFront()
{
	Student* purgeStudent = head;
	if (head)
	{
		head = head->getNext();
	}
	countOfStudents--;
	delete purgeStudent;
}

void ListOfStudents::deleteNumber(int number)  
{
	Student* purgeStudent = head;
	Student* prevStudent = tail;
	Student* nextStudent = nullptr;

	
	if (number > 1 && number < countOfStudents)
	{
		for (int i = 0; i < number; i++)
		{
			prevStudent = purgeStudent;
			purgeStudent = purgeStudent->getNext();
			nextStudent = purgeStudent->getNext();
		}
		
		purgeStudent->setPrev(prevStudent);
		prevStudent->setNext(nextStudent);
		countOfStudents--;
		delete purgeStudent;
	}
	else if (number == countOfStudents)
	{
		for (int i = 0; i < number; i++)
		{
			prevStudent = purgeStudent;
			purgeStudent = purgeStudent->getNext();
		}
		
		prevStudent->setNext(purgeStudent);
		purgeStudent->setNext(nextStudent);
	
		countOfStudents--;
		delete purgeStudent;					
	}
	else if (number == 1)						
	{
		head = head->getNext();
		nextStudent = head->getNext();

		delete purgeStudent;
		countOfStudents--;
	}

	
}

void ListOfStudents::InsertPosition(Student* newStudent, int position)
{
	
		if (position == 0)
		{
			pushFront(newStudent);
		}
		else 
		{
			pushBack(newStudent);
		}
	
}

Student* ListOfStudents::findStudent(std::string name)
{
	Student* findingStudent = head;
	
	for (int i = 0; i < countOfStudents; i++)
	{
		if (findingStudent->getName() == name)
		{
			findingStudent->print();
			
		}
		findingStudent = findingStudent->getNext();
	}
	return findingStudent;
						
}

ListOfStudents* ListOfStudents::findStudents(std::string name)
{
	ListOfStudents* newList = nullptr;
	Student* findingStudent = head;

	if (head != nullptr)
	{
		newList = new ListOfStudents();
		for (int i = 0; i < countOfStudents; i++)
		{
			if (findingStudent->getName() == name)
			{
				findingStudent->print();
				newList->pushBack(findingStudent);
			}
			findingStudent = findingStudent->getNext();
		}
	}
	
	return newList;
}

Student::Student(int number)
{
	this->number = number;
	//this->data = new Data();
	std::cout << "Student: " << std::endl;
}

Student::~Student()
{
	
}

void Student::setName(std::string name)
{
	this->name = name;
}

void Student::setGroup(std::string group)
{
	this->group = group;
}

void Student::setMark(int mark)
{
	this->mark = mark;
}

void Student::print()
{
	std::cout << this->getNumber() << ". " << this->getName() << " " << this->getGroup() << " " << this->getMark() << std::endl;
	
}


