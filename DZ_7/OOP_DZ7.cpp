
#include <iostream>
using namespace std;

class Date
{
	int day_;
	int month_;
	int year_;
public:
	Date(int day, int month, int year) :day_(day), month_(month), year_(year){}
	int GetDay() const {return day_;}
	int GetMonth() const {return month_;}
	int GetYear() const {return year_;}
	void SetDay(int day) {day_ = day;}
	void SetMonth(int month) {month_ = month;}
	void SetYear(int year) {year_ = year;}

	friend ostream& operator<<(ostream& out, Date& data) {
	out << "Day: " << data.day_ << endl <<"Month: " << data.month_ << endl << "Year: " << data.year_;
	return out;
	};
};

unique_ptr<Date>& CompareData(unique_ptr<Date>& data1, unique_ptr<Date>& data2)
{
	if (data1->GetYear() > data2->GetYear()) {return data1;}
	else if (data1->GetMonth() > data2->GetMonth()){return data1;}
	else if (data1->GetDay() > data2->GetDay()){return data1;}
	else{return data2;}
}

void SwapData(unique_ptr<Date>& data1, unique_ptr<Date>& data2)
{
	data1.swap(data2);
}



int main()
{
	//===================================Task1=========================================

	auto today = make_unique<Date>(5, 6, 2022);
	unique_ptr<Date> date;
	today->SetDay(3);
	today->SetMonth(6);
	today->SetYear(2022);
	cout << *today << endl;
	cout << today << endl;
	cout << date << endl;
	today.swap(date);
	cout << *date << endl;
	date.reset();
	cout << today << endl;
	cout << date;
	cout << endl;
	//===================================Task2=========================================

	auto date1 = make_unique<Date>(7, 6, 2022);
	auto date2 = make_unique<Date>(9, 6, 2022);
	cout << "CompareData():" << endl;
	cout << *CompareData(date1, date2) << endl;
	cout << "Before SwapData():" << endl;
	cout << *date1 << endl;
	cout << *date2 << endl;
	SwapData(date1, date2);
	cout << "After SwapData():" << endl;
	cout << *date1 << endl;
	cout << *date2 << endl;

	return 0;
}