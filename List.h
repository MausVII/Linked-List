#pragma once
#include <string>

class List {
private:
	class Node {
	private:
		int ID;
		std::string name;
		std::string email;
		float GPA;
		Node* pNext = nullptr;
	};
	Node* pTop = nullptr;
public:
	void Append(Node);
	void Insert(Node);
	void Delete(std::string);
	void Print();
	void Print(std::string);
};