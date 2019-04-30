#include "pch.h"
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
	Node* pNewNode;
	Node* pNodes;

	pNewNode = new Node(node);

	if (List::isEmpty()) {
		pTop = pNewNode;
		pNewNode = nullptr;
	}
	else {
		pNodes = pTop;
		Node* pPrevious = nullptr;

		// Will iterate up pNodes until it finds a number greater in alphabetical order
		// Saves position where it found it, and takes that new position
		while (pNodes != nullptr && (pNodes->GetName().compare(pNewNode->GetName())) >= 0) {
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
			pNewNode->pNext = pNewNode;
		}
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
