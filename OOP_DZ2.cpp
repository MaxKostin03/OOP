#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

class Person {
protected:
    string Name;
    int Age;
    string Gender;
    int Weight;
public:
    void changeName(string _val) { Name = _val; }
    void changeAge(unsigned int _val) { Age = _val; }
    void changeWeight(int _val) { Weight = _val; }
};

class Student : public Person {
private:
    static int count;
    int Year;
public: 
    Student(string name, int age, string gender, int weight, int year) { 
        Name = name;
        Age = age;
        Gender = gender;
        Weight = weight;
        Year = year;
        count++; };
    void printCount() { cout << count << endl; }
    void changeYear(int _val) { Year = _val ; }
    void incYear(int _val) { _val++; }
    void print() { cout << Name << " " << Age << " " << Gender << " " << Weight << " " << Year << endl; }
};
int Student::count = 0;

class Fruit {
protected:
    string name;
    string color;
public:
    void setName(string _name){
        name = _name;
    }
    void setColor(string _color){
        color = _color;
    }
    string getName() { return name; }
    string getColor() { return color; }
};

class Apple : public Fruit {
public:
    Apple(string color = "") {
        if (color == "")
            color = "green";
        setName("apple");
        setColor(color);
    }
};

class Banana : public Fruit {
public:
    Banana(std::string color = "") {
        if (color == "")
            color = "yellow";
        setName("banana");
        setColor(color);
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith() {
        setName("Granny Smith " + Apple::getName());
    }  
};




int main()
{ 
//============================Task1==========================
    Student P1("Ivanov", 19, "M", 65, 2021);
    Student P2("Petrov", 18, "M", 60, 2022);
    Student P3("Sidorov", 19, "M", 63, 2022);
    P1.print();
    P2.print();
    P3.print();
    P1.printCount();
//============================Task2==========================
        
    Apple a("red");
    Banana b;
    GrannySmith c;
    cout << "My " << a.getName() << " is " << a.getColor() << endl;
    cout << "My " << b.getName() << " is " << b.getColor() << endl;
    cout << "My " << c.getName() << " is " << c.getColor() << endl;
    
    return 0;
}
//============================Task3==========================
//1. Класс игрок - базовый класс, производные игрок и дилер
//2. Класс карта (номинал, масть, вес карты) - базовый класс, производный колода
//3. Класс набор карт на руках - базовый, производные карты игрока и дилера
//4. Класс Блэк Джек
//5. Класс игра (текущая колода, текущий дилер, текущий игрок)
