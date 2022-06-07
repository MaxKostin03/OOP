

#include <iostream>
#include <string>
using namespace std;

class Figure {
public:
	Figure() = default;
	virtual ~Figure() {};
	virtual void area() = 0;
};

class Parallelogram : public Figure {
protected:
	unsigned int base;
	unsigned int height;
public:
	Parallelogram(unsigned int _base, unsigned int _height) :base(_base), height(_height) {}
	void area() override {
		cout << "Parallelogram area " << base * height << endl;
	}
};

class Circle : public Figure {
protected:
	unsigned int R;
public:
	Circle(unsigned int _R) : R(_R) {}
	void area() override {
		cout << "Circle area " << 3.14 * pow(R, 2) << endl;
	}
};

class Rectangle : public Parallelogram {
public:
	Rectangle(unsigned int _base, unsigned int _height) : Parallelogram(_base, _height) {}
	void area() override {
		cout << "Rectangle area " << base * height << endl;
	}
};

class Square : public Parallelogram {
public:
	Square(unsigned int _base, unsigned int _height) : Parallelogram(_base, _height) {}
	void area() override {
		cout << "Square area " << base * height << endl;
	}
};

class Rhombus : public Parallelogram {
public:
	Rhombus(unsigned int _base, unsigned int _height) : Parallelogram(_base, _height) {}
	void area() override {
		cout << "Rhombus area " << base * height << endl;
	}
};

//============================================================

class Car {
protected:
	string company;
	string model;
	string getCompany() { return company; }
	string getModel() { return model;}
public:
	Car(string _company, string _model) : company(_company), model(_model) {
		cout <<"Car company: " << getCompany() << ", Model: " << getModel() << endl;
	}
};

class PassengerCar : virtual public Car {
public:
	PassengerCar(string _company, string _model) : Car(_company, _model) {
	 cout << "Passenger car company: " << getCompany() << ", Model: " << getModel()<< endl;
	}
};

class Bus : virtual public Car {
public:
	Bus(string _company, string _model) : Car(_company, _model) {
		cout << "Bus company: " << getCompany() << ", Model: " << getModel() << endl;
	}
};

class Minivan : public PassengerCar, public Bus {
public:
	Minivan(string _company, string _model) : Car(_company, _model), PassengerCar(_company, _model), Bus(_company, _model) {
		cout << "Minivan company: " << getCompany() << ", Model: " << getModel() << endl;
	}
};

//============================================================

class Fraction {
private:
	int n;
	int d;
public:
	Fraction(int _n = 1, int _d = 1) { n = _n; d = _d; check(); }
	void check() {
		if (d == 0) {
			throw std::overflow_error("denominator is zero");
		}
	}
	
	void print() {
		cout << n << "/" << d << endl;
	}

	Fraction operator+(Fraction& r_op) {
		int _n = n * r_op.d + d * r_op.n;
		int _d = d * r_op.d;
		return Fraction(_n, _d);
	}

	Fraction operator-(Fraction& r_op) {
		int _n = n * r_op.d - d * r_op.n;
		int _d = d * r_op.d;
		return Fraction(_n, _d);
	}

	Fraction operator*(Fraction& r_op) {
		int _n = n * r_op.n;
		int _d = d * r_op.d;
		return Fraction(_n, _d);
	}

	Fraction operator/(Fraction& r_op) {
		int _n = d * r_op.n; 
		int _d = n * r_op.d;
		return Fraction(_n, _d);
	}

	Fraction operator-() const {
		return Fraction(-n, d);
	};

	
	bool operator==(Fraction& r_op) {
		if ((n * r_op.d) == (d * r_op.n)) {
			return true;
		} else return false;
	}

	bool operator!=(Fraction& r_op) {
		if ((n * r_op.d) != (d * r_op.n)) {
			return true;
		} else return false;
	}

	bool operator<(Fraction& r_op) {
		if ((n * r_op.d) < (d * r_op.n)) {	
			return true;
		} else return false;
	}
	
	bool operator<=(Fraction& r_op) {
		if ((n * r_op.d) <= (d * r_op.n)) {
			return true;
		} else return false;
	}

	bool operator>=(Fraction& r_op) {
		if ((n * r_op.d) >= (d * r_op.n)) {
			return true;
		} else return false;
	}

	bool operator>(Fraction& r_op) {
		if ((n * r_op.d) > (d * r_op.n)) {
			return true;
		} else return false;
	}
	
};



int main()
{
//============================Task1============================
	
	Parallelogram A(2, 4);
	A.area();
	Circle B(6);
	B.area();
	Rectangle C(3, 4);
	C.area();
	Square D(1, 7);
	D.area();
	Rhombus E(2, 8);
	E.area();
	cout << endl;

//============================Task2============================
	
	Car _1("Opel", "V100");
	PassengerCar _2("BMW", "X5");
	Bus _3("MAN", "L17");
	Minivan _4("KIA", "Curens");
	cout << endl;

//============================Task3============================

	Fraction S1(1, 5);
	Fraction S2(2, 3);
	Fraction S4(3, 4);
	Fraction S5(3, 5);
	Fraction S6(3, 5);
	Fraction S3;
	S3 = S1 + S2;
	S3.print();
	S3 = S1 - S2;
	S3.print();
	S3 = S1 * S2;
	S3.print();
	S3 = S1 / S2;
	S3.print();
	S3 = -S1;
	S3.print();
	if (S5 == S6) {cout << "S5 = S6" << endl;}
	if (S1 != S2) {cout << "S1 != S2" << endl;}
	if (S1 < S2) {cout << "S1 < S2"<< endl;}
	if (S1 <= S2) {cout << "S5 <= S6" << endl;}
	if (S2 > S1) {cout << "S2 > S1" << endl;}
	if (S2 >= S1) {cout << "S2 >= S1" << endl;}
	
	//============================Task4============================

	class Card
{
protected:

    enum Suit { TAMBOURINE, SPADE, CLUBS, HEARTS };
    enum Value { ACE, KING, QUEEN, JACK, TEN, NINE, EIGHT, SEVEN, SIX, FIVE, FOUR, THREE, TWO };
    bool Position = false;
    Value value;
    Suit suit;


    Suit initSuit()
    {
        Suit suit = static_cast<Suit>(rand() % 3);
        return suit;
    }

    Value initValue()
    {
        Value value = static_cast<Value>(rand() % 12);
        return value;
    }

public:

    Card()
    {
        value = initValue();
        suit = initSuit();
    }

    void Flip()
    {
        if (Position)
            Position = false;
        else if (!Position)
            Position = true;
    }

    Value getEnumValue() const
    {
        return value;
    }

    int getCardValue() const
    {
        switch (value)
        {
        case ACE: return 1;
        case KING: return 10;
        case QUEEN: return 10;
        case JACK: return 10;
        case TEN: return 10;
        case NINE: return 9;
        case EIGHT: return 8;
        case SEVEN: return 7;
        case SIX: return 6;
        case FIVE: return 5;
        case FOUR: return 4;
        case THREE: return 3;
        case TWO: return 2;
        }
    }
};
	return 0;
}
