#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;

struct Data {
	int ID;
	string name;
	string email;
	double GPA;
};

int main()
{
	Data studentRecords[15];
	List records;
	ifstream file("Records.txt");
	if (file) {
		for (int i = 0; i < 15; ++i) {
			int ID;
			string name;
			string email;
			double GPA;
			file >> name >> ID >> email >> GPA;
			studentRecords[i].ID = ID;
			studentRecords[i].name = name;
			studentRecords[i].email = email;
			studentRecords[i].GPA = GPA;

			records.Insert( ID, name, email, GPA );
		}
	}
	file.close();

	records.Display();
	while (true);
	return 0;
}