
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template<typename Type>
class Pair1 {
	Type firstElement;
	Type secondElement;
public:
	Pair1(Type first, Type second) : firstElement(first), secondElement(second) {}
	Type first() const {
		return firstElement;
	}
	Type second() const{
		return secondElement;
	}
};

template<typename FirstElemType, typename SecondElemType>
class Pair {
	FirstElemType firstElement;
	SecondElemType secondElement;
public:
	Pair(FirstElemType first, SecondElemType second) :firstElement(first), secondElement(second) {}
	FirstElemType first() const {
		return firstElement;
	}
	SecondElemType second() const {
		return secondElement;
	}
};

template <typename T2>
class StringValuePair : public Pair<std::string, T2>
{
public:
	StringValuePair(const std::string& first, const T2& second) : Pair<std::string, T2>(first, second) {}
};

//============================Task4====================================

//class GenericPlayer : public Hand
//{
//	string name;
//protected:
//	GenericPlayer(string s_name):name(s_name) {}
//	virtual bool isHitting() = 0;
//	bool isBoosted() {
//		if (this->getValue() > 21) {
//			return true;
//		}else return false;
//	}
//	void boost() {
//		cout << this->name << " That's too much! "<< endl;
//	}
//};

int main()
{
//============================Task1====================================
	Pair1<int> P1(6, 9);
	cout << "Pair: " << P1.first() << ", " << P1.second() << endl;
	Pair1<double> P2(3.4, 7.8);
	cout << "Pair: " << P2.first() << ", " << P2.second() << endl;
	cout << endl;

//============================Task2====================================
	Pair<int, double> P3(6, 7.8);
	cout << "Pair: " << P3.first() << ", " << P3.second() << endl;
	Pair<double, int> P4(3.4, 5);
	cout << "Pair: " << P4.first() << ", " << P4.second() << endl;
	cout << endl;

//============================Task3====================================
	StringValuePair<int> svp("Amazing", 7);
	cout << "Pair: " << svp.first() << ' ' << svp.second() << endl;

	return 0;
}