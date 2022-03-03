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
	EMPLOYEE object1("Nadya", 17, "REU", 1, "Student", 2000, 1 'w',);
	EMPLOYEE object2("Kate", 18, "REU", 32, "Student", 2000, 1 'w');
	EMPLOYEE object3("Anton", 19, "Adidas", 2, "Manager", 30000, 2 'm', );
	
EMPLOYEE employees[3] = { object1, object2, object3 };

 cout << "Насчитывается " << EMPLOYEE::GetCount() << " сотрудника." << endl << endl;
    for (int i = 0; i < 3; i++) 
    {
 employees[i].GetPersonalInfo();
 employees[i].GetWorkInfo();
        cout << endl;
    }
    cout << endl;
 employees[2].SetSalary(50000); // Повышаем зарплату третьего сотрудника на 50000
    cout << endl;
 employees[0].ExpComparsion(employees[1]); // Сравниваем опыт двух сотрудников
    cout << endl;
 employees[2].ObjectAssigment(employees[0]); // Присваиваем должность первого сотрудника третьему
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
 employees[i].GetPersonalInfo();
 employees[i].GetWorkInfo();
        cout << endl;
    }
}




  
