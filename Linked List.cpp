#include <iostream>
#include <fstream>
#include "List.h"

struct StudentData {
	int ID;
	std::string name;
	std::string email;
	float GPA;
};

int main()
{
	List records;
	StudentData data[15];
	std::ifstream file("File.txt");
	if (file) {
		for (int i = 0; i < 15; ++i) {
			int ID;
			std::string name;
			std::string email;
			float GPA;
			file >> ID >> name >> email >> GPA;

			data[i].ID = ID;
			data[i].name = name;
			data[i].email = email;
			data[i].GPA = GPA;

			records.Insert({ ID, name, email, GPA });
		}
	}
	file.close();

	std::cout << "Unsorted Array:\n";
	for (int i = 0; i < 15; ++i) {
		std::cout << "Name: " << data[i].name
			<< "\nID: " << data[i].ID
			<< "\nEmail: " << data[i].email
			<< "\nGPA: " << data[i].GPA
			<< std::endl << std::endl;
	}

	std::cout << "Sorted Linked List:\n";
	records.Print();
	while (true);
	return 0;
}