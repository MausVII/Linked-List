#include <iostream>
#include <fstream>
#include "List.h"

int main()
{
	List records;
	std::ifstream file("File.txt");
	if (file) {
		for (int i = 0; i < 15; ++i) {
			int ID;
			std::string name;
			std::string email;
			float GPA;
			file >> ID >> name >> email >> GPA;
			records.Insert({ ID, name, email, GPA });
		}
	}
	file.close();

	records.Print();
	while (true);
	return 0;
}