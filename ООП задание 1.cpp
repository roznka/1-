#include <iostream>
using namespace std;
const int LNAME = 25;
    classSTUDENT {
private:
        char name[LNAME];
        int age;
        float grade;
public:
        STUDENT () {
            for (int i=0; i<=25; i++) {
                name[i] = 0;
            }
            age = 0;
            grade = 0;
        }
        char* GetName() {
            return name;

        int GetAge() const {
            return age;
            }
        float GetGrade() const {
            return grade;
            }
            void SetName(char* name) {
                int i = 0;
                while (*name!=0) { //посимвольный перебор всего имени
                    this->name[i] = *name; //присваивание его массиву
                    name++;
                    i++;
                } 
            }
            void SetAge(int age) {
                this->age = age;
            }
            void SetGrade(float grade) {
                this->grade = grade;
            }
            void Set(char* name, int age, float grade) {
                int i = 0;
                while (*name != '\0') {
                    this->name[i] = *name;
                    name++;
                    i++;
                }
                this->age = age;
                this->grade = grade;
            }
            void Show() {
                cout << "Имя студента : " << name << endl;
                cout << "Возраст студента : " << age << endl;
                cout << "Рейтинг студента : " << grade << endl;
            }
        }
int main() {
    setlocale(LC_ALL, "Russian");
    STUDENT human;      
    char name[25];
    int age;
    float grade;
    cout << "Введите имя студента(используйте латиницу, не более 24 символов): ";
    cin >> name;
    cout << endl << "Введите возраст студента: ";
    cin >> age;
    cout << endl << "Введите рейтинг студента: ";
    cin >> grade;
    student.SetName(name);
    cout << "Имя студента : " << student.GetName() << endl;
    student.SetAge(age);
    cout << "Возраст студента : " << student.GetAge() << endl;
    student.SetGrade(grade);
    cout << "Рейтинг студента : " << student.GetGrade() << endl << endl;
    cout << "Функционал общего set и show." << endl;
    student.Set(name, age, grade);
    student.Show();
    
    return 0;
}


    }