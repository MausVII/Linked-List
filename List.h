#pragma once
#include <string>
#include <iostream>

class List {
private:
	class Node {
	private:
		int ID;
		std::string name;
		std::string email;
		float GPA;
	public:
		Node(int ID, std::string name, std::string email, float GPA)
			:
			ID(ID),
			name(name),
			email(email),
			GPA(GPA)
		{}
		Node* pNext = nullptr;
		std::string GetName() const;
		void Print();
	};
	Node* pTop = nullptr;
public:
	void Append(Node node);
	void Insert(Node node);
	void Delete(std::string name);
	void Print();
	void Print(std::string name);
	bool isEmpty();
};