
#include <string>
#include <iostream>
using namespace std;

class List {
private:
	struct stuInfo {
		int ID;
		string name;
		string email;
		double GPA;

		stuInfo* pNext = nullptr;
		void Print() {
			cout << "///////////////" << endl;
			cout << "Student name: " << name << endl
				<< "Student ID: " << ID << endl
				<< "Student Email: " << email << endl
				<< "Student GPA: " << GPA << endl;
			cout << "///////////////" << endl << endl;
		}
	};
	stuInfo* pTop = nullptr;
public:
	void Insert(int ID, string name, string email, double GPA) {
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
	void Delete(int ID) {
		stuInfo* pNodes = pTop;
		stuInfo* pPrevious = nullptr;

		while (pNodes != nullptr && pNodes->ID != ID) {
			pPrevious = pNodes;
			pNodes = pNodes->pNext;
		}

		pPrevious->pNext = pNodes->pNext;
		pNodes = nullptr;
	}
	void Display() {
		stuInfo* pNodes;
		pNodes = pTop;
		while (pNodes != nullptr) {
			pNodes->Print();
			pNodes = pNodes->pNext;
		}
	}
};