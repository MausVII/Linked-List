#include "List.h"

void List::Append(stuInfo node)
{
	stuInfo* pNewNode;
	stuInfo* pNodes;

	pNewNode = new stuInfo(node);
	if (pTop == nullptr) {
		pTop = pNewNode;
		pNewNode = nullptr;
	 }
	else {
		pNodes = pTop;
		while (pNodes->pNext != nullptr) {
			pNodes = pNodes->pNext;
		}
		pNodes->pNext = pNewNode;
	}
}

void List::Insert(int ID, string name, string email, double GPA)
{
	stuInfo* NewNodeptr = nullptr;
	stuInfo* pNodes = nullptr;
	stuInfo* pPrevious = nullptr;

	NewNodeptr = new stuInfo;
	NewNodeptr->ID = ID;
	NewNodeptr->name = name;
	NewNodeptr->email = email;
	NewNodeptr->GPA = GPA;


	if (pTop == nullptr) {
		pTop = NewNodeptr;
		NewNodeptr->pNext = nullptr;
	}
	else {
		pNodes = pTop;

		// Will iterate up pNodes until it finds a number greater in alphabetical order
		// Saves position where it found it, and takes that new position
		while (pNodes != nullptr && (pNodes->ID <= NewNodeptr->ID)) {
			pPrevious = pNodes;
			pNodes = pNodes->pNext;
		}

		// Case there were no nodes
		if (pPrevious == nullptr) {
			pTop = NewNodeptr;
			pTop->pNext = pNodes;
		}
		// Makes previous point to new node and the new node to whatever previous was pointing before
		else {
			pPrevious->pNext = NewNodeptr;
			NewNodeptr->pNext = pNodes;
		}
	}
}

void List::Delete(int ID)
{
	stuInfo* pNodes = pTop;
	stuInfo* pPrevious = nullptr;

	while (pNodes != nullptr && pNodes->ID != ID) {
		pPrevious = pNodes;
		pNodes = pNodes->pNext;
	}

	pPrevious->pNext = pNodes->pNext;
	pNodes = nullptr;
}

void List::Display()
{
	stuInfo* pNodes;
	pNodes = pTop;
	while (pNodes != nullptr) {
		pNodes->Print();
		pNodes = pNodes->pNext;
	}
}

void List::stuInfo::Print()
{
	cout << "///////////////" << endl;
	cout << "Student name: " << name << endl
		<< "Student ID: " << ID << endl
		<< "Student Email: " << email << endl
		<< "Student GPA: " << GPA << endl
		<< endl;
	cout << "///////////////" << endl << endl;
}
