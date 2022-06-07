#include <iostream>
#include <exception>

using namespace std;

exception DivisionByZero() {
	exception div_exception("Denominator must not be zero");
	return div_exception;
}
template<typename T>
T Div(T num, T den) {
	if (den == 0) {throw DivisionByZero();}
	else{
		T result = num / den;
		return result;
	}
}
//=====================================
class Ex{
public:
	double x_;
	Ex(const double& x): x_(x) {}
};

class Bar{
	double y_;
public:
	Bar(double y = 0.0) : y_(y) {}
	void Set(double a){
		if (y_ + a > 100){
			throw Ex(a * y_);
		}
		else{
			y_ = a;
		}
	}
};

//====================================



const int SIZE = 10;

class OffTheField
{
	int x_current_;
	int y_current_;
	int x_desired_;
	int y_desired_;

public:

	OffTheField(int x_c, int y_c, int x_d, int y_d) :x_current_(x_c), y_current_(y_c), x_desired_(x_d), y_desired_(y_d) {}

	void what()
	{
		cerr << "Cannot move from coordinates (x) = " << x_current_ + 1 << ", (y) = " << y_current_ + 1
			<< "\nto the coordinates (x) = " << x_desired_ + 1 << ", (y) = " << y_desired_ + 1
			<< "!\nDesired coordinates are out of the map!\n";
	}
};

class IllegalCommand
{
	int x_current_;
	int y_current_;
	int x_desired_;
	int y_desired_;

public:

	IllegalCommand(int x_c, int y_c, int x_d, int y_d):x_current_(x_c), y_current_(y_c), x_desired_(x_d), y_desired_(y_d) {}

	void what()
	{
		cerr << "Cannot move from coordinates (x) = " << x_current_ + 1 << ", (y) = " << y_current_ + 1
			<< "\nto the coordinates (x) = " << x_desired_ + 1 << ", (y) = " << y_desired_ + 1
			<< "!\nDesired coordinates are out of the reach!\n";
	}

};

class Robot
{
	int x_;
	int y_;
	char map_[SIZE][SIZE];
	enum Moves { CURRENT_POSITION = 'X', POSSIBLE_MOVE = '+', NO_MOVE = '-' };

public:

	Robot(int x = 0, int y = 0):x_(x), y_(y) {}

	void CreateMap()
	{
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				map_[i][j] = NO_MOVE;

		map_[y_][x_] = CURRENT_POSITION;
		map_[y_ + 1][x_] = POSSIBLE_MOVE;
		map_[y_][x_ + 1] = POSSIBLE_MOVE;
		map_[y_ + 1][x_ + 1] = POSSIBLE_MOVE;

		if (x_ > 0)
		{
			map_[y_][x_ - 1] = POSSIBLE_MOVE;
			map_[y_ + 1][x_ - 1] = POSSIBLE_MOVE;
		}
		if (y_ > 0)
		{
			map_[y_ - 1][x_] = POSSIBLE_MOVE;
			map_[y_ - 1][x_ + 1] = POSSIBLE_MOVE;
		}
		if (y_ > 0 && x_ > 0)
		{
			map_[y_ - 1][x_ - 1] = POSSIBLE_MOVE;
		}
	}

	void PrintMap()
	{
		for (int i = 0; i < SIZE; i++)
			cout << i + 1 << "  ";
		cout << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << "\n " << i + 1 << "\t";
			for (int j = 0; j < SIZE; j++)
			{
				cout << map_[i][j] << "  ";
			}
			cout << endl;
		}
		cout << "\n\n";
	}

	void Move(int x, int y)
	{
		if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
		{
			throw OffTheField(x_, y_, x, y);
		}
		else if (map_[y][x] == NO_MOVE)
		{
			throw IllegalCommand(x_, y_, x, y);
		}
		else
		{
			x_ = x;
			y_ = y;
			CreateMap();
			PrintMap();
		}
	}
};



int main()
{
//====================================Task1=================================

	try{
		cout << Div<int>(10, 0) << endl;
	}
	catch (exception& exception){
		cerr << "Exception: " << exception.what() << endl;
	}

//====================================Task2=================================

	Bar b;
	int n;

	do{
		cout << "Enter an integer value: ";
		cin >> n;
		try{
			b.Set(n);
		}
		catch (Ex& exception) {
			cout << "Exception: " << exception.x_ << endl;
		}
	} while (n != 0);

//====================================Task3=================================

	Robot r(6, 4);
	r.CreateMap();
	r.PrintMap();
	try
	{
		r.Move(3, 6);
	}
	catch (OffTheField& otf)
	{
		otf.what();
	}
	catch (IllegalCommand& ic)
	{
		ic.what();
	}
}