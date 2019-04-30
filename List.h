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
	public:
		Node* pNext = nullptr;
		std::string GetName() const;
	};
	Node* pTop = nullptr;
public:
	void Append(Node node);
	void Insert(Node node);
	void Delete(std::string);
	void Print();
	void Print(std::string);
	bool isEmpty();
};