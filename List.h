
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
		void Print();
	};
	stuInfo* pTop = nullptr;
public:
	void Append(stuInfo  node);
	void Insert(int ID, string name, string email, double GPA);
	void Delete(int ID);
	void Display();
};