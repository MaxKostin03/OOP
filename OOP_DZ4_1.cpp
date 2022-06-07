#include <iostream>
#include <cassert>
#include <vector>
#include <set>
using namespace std;
class ArrayInt
{
    int m_length;
    int* m_data;

public:

    ArrayInt() : m_length(0), m_data(nullptr) { }

    ArrayInt(int length) : m_length(length) {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt() {
        delete[] m_data;
        m_data = nullptr;
    }
    int* begin() {
        return&m_data[0];
    }
    int* end() {
        return m_data + m_length;
    }
    void fill(int v) { // заполнение случайными числами
        for (size_t i = 0; i < m_length; i++) {
            m_data[i] = rand() % v;
        }
    }
    int size() {
        return m_length;
    }
    void erase() {
        if (m_data != nullptr) {
            delete[] m_data;
            m_data = nullptr;
            m_length = 0;
        }
    }
    void print() {
        assert(m_length > 0);
        for (int i = 0; i < m_length; i++)
            cout << m_data[i] << " ";
        cout << endl;
    }
    int operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    void resize(int newSize) {
        if (newSize == m_length) {
            return;
        }
        if (newSize <= 0) {
            erase();
            return;
        }
        int* newData = new int[newSize] {0};
        int N_copy = (newSize >= m_length) ? m_length : newSize;
        for (size_t i = 0; i < N_copy; i++) {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_length = newSize;
    }
    void insert(int val, int index) {
        int* newData = new int[m_length + 1]{ 0 };
        newData[index] = val;
        for (size_t i = 0; i < index; i++) {
            newData[i] = m_data[i];
        }
        for (size_t i = index; i < m_length; i++) {
            newData[i + 1] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_length++;
    }
    void popBack() {
        if (m_length == 0) {
            return;
        }
        resize(m_length - 1);
    }
    void popFront()
    {
        if (m_length == 0) {
            return;
        }
        if (m_length - 1 == 0) {
            erase();
            return;
        }
        int* data = new int[m_length - 1];
        for (int index = 1; index < m_length; ++index) {
            data[index - 1] = m_data[index];
        }
        delete[] m_data;
        m_data = data;
        m_length--;
    }
    void sort() {
        for (int i = 0; i < m_length - 1; i++) {
            for (int j = 0; j < m_length - i - 1; j++) {
                if (m_data[j] > m_data[j + 1]) {
                    int temp;
                    temp = m_data[j];
                    m_data[j] = m_data[j + 1];
                    m_data[j + 1] = temp;
                }
            }
        }
    }

};
//===============================Task3============================//класс из ДЗ №3
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
//===============================Task3============================
class Hand : public Card
{
    vector<Card*> hand;

public:

    void add(Card* card)
    {
        hand.push_back(card);
    }

    void clear()
    {
        hand.erase(hand.begin(), hand.end());
    }

    int getValue()
    {
        assert(hand.size() != 0);
        int sum = 0;

        for (int i = 0; i < hand.size(); i++)
        {
            if (hand.at(i)->getEnumValue() == ACE && sum + 11 < 21)
                sum += 11;
            else
                sum += hand.at(i)->getCardValue();
        }
        return sum;
    }
};


int main()
{
//===============================Task1============================
    srand(time(0));
    srand(time(0));
    ArrayInt A(10);
    A.fill(30);
    A.print();
    cout << A[2] << endl;
    A.resize(20);
    A.print();
    A.insert(333, 4);
    A.print();
    A.fill(30);
    A.print();
    A.popBack();
    A.print();
    A.popFront();
    A.print();
    A.sort();
    A.print();
    cout << endl;

//===============================Task2============================

    vector<int> vec;
    vec.reserve(20);
    for (int i = 0; i < vec.capacity(); i++) {
        vec.push_back(rand() % 30);
    }
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    set<int> s(vec.begin(), vec.end());
    cout << s.size() << " Different values out of " << vec.size() << endl;
      
    return 0;
}

