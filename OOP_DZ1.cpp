#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

class Power {
private:
	float a = 1.3;
	float b = -2;
public:
	void _fastcall set_ab(float _val1, float _val2 ) { a = _val1; b = _val2;}
	void _fastcall calculate() { cout << "a * b = " << pow(a, b) << endl; }
};

void inline Task1() {
	Power P1;
	P1.calculate();
	P1.set_ab(2.5, -3);
	P1.calculate();
}

class RGBA {
private:
	uint8_t m_red = 0;
	uint8_t m_green = 0;
	uint8_t m_blue = 0;
	uint8_t m_alpha = 255;
public:
	RGBA(uint8_t _val1, uint8_t _val2, uint8_t _val3, uint8_t _val4) {
		m_red = _val1;
		m_green = _val2;
		m_blue = _val3;
		m_alpha = _val4;
	}
	void _fastcall print() {
		cout << "m_red = " << m_red << endl << "m_green =" << m_green << endl << "m_blue = "<< m_blue << endl << "m_alpha = " << m_alpha << endl;
	}
};

void inline Task2() {
	RGBA M(16, 64, 125, 225);
	M.print();
}

class Stack {
private:
	unsigned Arr[10];
	unsigned k;
public:
	void _fastcall reset() {
		k = 0;
		for (size_t i = 0; i < 10; i++) {
			Arr[i] = 0;
		}
	}

	bool push(int _val) {
		if (k == 10) {
			return false;
		} else {
		Arr[k] = _val;
		k++;
		return true;
		}	
	}

	int pop() { return Arr[--k];}

	void _fastcall print() {
		cout << "( ";
		for (size_t i = 0; i < k; i++) {
			cout << Arr[i] << " ";
		}
		cout << ")" << endl;
	}
};


void inline Task3() {
	Stack stack;
	stack.reset();
	stack.print();
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();
	stack.pop();
	stack.print();
	stack.pop();
	stack.pop();
	stack.print();
}

int main()
{
	Task1();
	Task2();
	Task3();
	return 0;
}

