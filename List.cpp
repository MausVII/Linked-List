#include "List.h"

void List::Append(Node node)
{
	Node* pNewNode;
	Node* pNodes;

	pNewNode = new Node(node);
	if (List::isEmpty()) {
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

void List::Insert(Node node)
{
	Node* pNewNode = nullptr;
	Node* pNodes = nullptr;
	Node* pPrevious = nullptr;

	pNewNode = new Node(node);

	if (isEmpty()) {
		pTop = pNewNode;
		pNewNode->pNext = nullptr;
	}
	else {
		pNodes = pTop;

		// Will iterate up pNodes until it finds a number greater in alphabetical order
		// Saves position where it found it, and takes that new position
		while (pNodes != nullptr && (pNodes->GetName().compare(pNewNode->GetName())) <= 0) {
			pPrevious = pNodes;
			pNodes = pNodes->pNext;
		}

		// Case there were no nodes
		if (pPrevious == nullptr) {
			pTop = pNewNode;
			pTop->pNext = pNodes;
		}
		// Makes previous point to new node and the new node to whatever previous was pointing before
		else {
			pPrevious->pNext = pNewNode;
			pNewNode->pNext = pNodes;
		}
	}
}

void List::Delete(std::string name)
{
	Node* pNodes = pTop;
	Node* pPrevious = nullptr;

	while (pNodes != nullptr && pNodes->GetName() != name) {
		pPrevious = pNodes;
		pNodes = pNodes->pNext;
	}

	pPrevious->pNext = pNodes->pNext;
	pNodes = nullptr;
}

void List::Print()
{
	Node* pNodes;
	pNodes = pTop;
	while (pNodes != nullptr) {
		pNodes->Print();
		pNodes = pNodes->pNext;
	}
}

void List::Print(std::string name)
{
	Node* pNewNode = nullptr;
	Node* pNodes = nullptr;

	if (List::isEmpty()) {
		std::cout << "List is empty.\n";
	}
	else {
		pNodes = pTop;
		Node* pPrevious = nullptr;

		// Will iterate up pNodes until it finds a number greater in alphabetical order
		// Saves position where it found it, and takes that new position
		while (pNodes != nullptr && (pNodes->GetName().compare(pNewNode->GetName())) == 0) {
			pPrevious = pNodes;
			pNodes = pNodes->pNext;
		}
		pNodes->Print();
	}
}

bool List::isEmpty()
{
	return pTop == nullptr;
}

std::string List::Node::GetName() const
{
	return name;
}

void List::Node::Print()
{
	std::cout << "Name: " << name
		<< "\nID: " << ID
		<< "\nEmail: " << email
		<< "\nGPA: " << GPA
		<< "\n\n";
}
