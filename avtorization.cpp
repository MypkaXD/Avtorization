#include <iostream>
#include <string>
#include <ctime>

class Avorization {
private:
	std::string* massiveOfName;
	int* massiveOfPassword;
	int m_lenght;
public:
	Avorization(int lenght){
		m_lenght = lenght;
		massiveOfName = new std::string[m_lenght];
		massiveOfPassword = new int[m_lenght];
	}
	~Avorization() {
		delete[] massiveOfName;
		delete[] massiveOfPassword;
	}
	void genetratePassword() {
		int tempPassword = rand() % 100 * 1 * 2 * 132;
		massiveOfPassword[m_lenght] = tempPassword;
	}
	void setUsers(std::string name, int password, int count) {
		massiveOfName[count] = name;
		massiveOfPassword[count] = password;
	}
	void printAllUsers() {
		for (int count = 0; count < m_lenght; count++) {
			std::cout << "Name " << count + 1 << " is " << massiveOfName[count] << "\tPassword " << count + 1 << " is " << massiveOfPassword[count] << std::endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	int lenght;
	std::cout << "Enter the number of users." << std::endl;
	std::cin >> lenght;
	Avorization avorization(lenght);
	for (int count = 0; count < lenght; count++) {
		std::cout << "Введите свое имя: " << std::endl;
		std::string name;
		std::cin >> name;
		std::cout << "Введите свой пароль" << std::endl;
		int password;
		std::cin >> password;
		avorization.setUsers(name, password, count);
	}
	avorization.printAllUsers();
	return 0;
}
