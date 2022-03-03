#include <iostream>
#include <vector>
#include <string>
using namespace std;

class EMPLOYEE {
    private:
 string organization;
 string position;
	double experience;
 string name;
	char gender;
	int age;
	double salary;
public:
	static int count;
	EMPLOYEE (string organization, string position, double experience, string name, char gender, int age, double salary) {
		this->organization = organization;
		this->position = position;
		this->experience = experience;
		this->name = name;
		this->gender = gender;
		this->age = age;
		this->salary = salary;
		count++;
	}
    void GetWorkInfo() {
        cout << "Место работы: " << organization << endl;
        cout << "Должность: " << position << endl;
        cout << "Стаж работы: " << experience << endl;
        cout << "Заработная плата: " << salary << endl;
        }
    void SetPosition(string position) {
        this->position = position;
    }
    void SetSalary(double plus_salary) {
        salary = salary + plus_salary;
    }
    void GetPersonalInfo() {
        cout << "Ф.И.О: " << name << endl;
        cout << "Пол: " << gender << endl;
        cout << "Возраст: " << age << endl;
    }
    bool operator < (EMPLOYEE const& other) {             // Перегрузка оператора <
        return this->experience < other.experience;
    }
    bool operator == (EMPLOYEE const& other) {            // Перегрузка оператора ==
        return this->experience == other.experience;
    }
    EMPLOYEE& operator = (EMPLOYEE const& other) {         // Перегрузка оператора =
        this->position = other.position;
        return *this;
    }
    void ExpComparsion(EMPLOYEE& second) {                 // Сравнение опыта двух сотрудников
        if (*this < second) {
            cout << second.name << " больше опыта, чем " << this->name << endl;
        }
        else if (*this == second) {
            cout << second.name << " одинаковый опыт c " << this->name << endl;
        }
        else {
            cout << this->name << " больше опыта, чем " << second.name << endl;
        }
    }
    void ObjectAssigment(EMPLOYEE& second) {        
        this->position = second.position;
    }
    static int GetCount() {
        return count;
    }
    ~EMPLOYEE() {  
        count--;
    }
};
int EMPLOYEE::count = 0;

int main() {
	setlocale(LC_ALL, "Russian");
	EMPLOYEE emp1("Nadya", 17, "REU", 1, "Student", 2000, 1 'w',);
	EMPLOYEE emp2("Kate", 18, "REU", 32, "Student", 2000, 1 'w');
	EMPLOYEE emp3("Anton", 19, "Adidas", 2, "Manager", 30000, 2 'm', );
	
	const int len = 3;
    EMPLOYEE mas[len] = { emp1, emp2, emp3 };// Создание массива объектов класса EMPLOYEE.
	emp1.showCount();
	cout << endl;
	cout << "Личные данные и информация о работе " << endl;
	cout << endl;
	for (int i = 0; i < len; i++) {
		mas[i].ShowPrivate();
		mas[i].ShowWork();
	}
	double raise_salary;
	cout << "Введите начисление зарплаты ";
	cin >> raise_salary;
	cout << endl;
	cout << "Зарплата 1 человека ";
	mas[0].AccrualofSalary(raise_salary);
	cout << "Зарплата 2 человека ";
	mas[1].AccrualofSalary(raise_salary);
	cout << "Зарплата 3 человека ";
	mas[3].AccrualofSalary(raise_salary);
	cout << endl;
	mas[0] = mas[1];
	mas[0].Comparison(mas[1]);
	cout << endl;
	for (int i = 0; i < len; i++) {
		mas[i].ShowPrivate();
		mas[i].ShowWork();
	}
	cout << endl;
	return 0;
}




  