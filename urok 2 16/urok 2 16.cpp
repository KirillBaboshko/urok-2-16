#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <cassert>
using namespace std;
class Fraction
{
private:
	int numerator;
	int dernumerator;
	void nod() 
	{
		int n = numerator;
		int d = dernumerator;
		while (n!=0&&d!=0) 
		{
			if (n > d) 
			{
				n%=d;
			}
			else
			{
				d %= n;
			}
		}
		numerator = numerator / (n + d);
		dernumerator = dernumerator / (n + d);
	}
public:

	Fraction(int numerator = 0, int dernumerator = 1)
	{
		this->numerator = numerator;
		if (dernumerator != 0) 
		{
			this->dernumerator = dernumerator;
		}
		else
			this->dernumerator = 1;
		nod();
	}
	void setdernumerator(int dernumerator)
	{
		if (dernumerator != 0)
		{
			this->dernumerator = dernumerator;
		}
		else
			this->dernumerator = 1;
		nod();
	}
	void setnumerator(int numerator)
	{
		this->numerator = numerator;
		nod();
	}
	int getnumerator() { return numerator; }
	int getdernumerator() { return dernumerator; }
	void print()
	{
		cout << numerator << "/" << dernumerator << endl;
	}
	Fraction Plus(const Fraction& fobj) 
	{
		Fraction temp;
		temp.numerator = this->numerator * fobj.dernumerator + fobj.numerator * dernumerator;
		temp.dernumerator = this->dernumerator * fobj.dernumerator;
		temp.nod();
		return temp;
	}
	void add(const Fraction& fobj)
	{
		this->numerator = this->numerator * fobj.dernumerator + fobj.numerator * dernumerator;
		this->dernumerator = this->dernumerator * fobj.dernumerator;
		nod();
		
	}
};
class DEarray
{
	int* items;
	int size;
public:
	DEarray(int size = 0)
	{
		items = new int[size];
	}
	~DEarray()
	{
		delete[] items;
	}
};
int main()
{
	srand(time(NULL));
	Fraction f1(2,3);
	Fraction f2(25,30);
	Fraction f3(3, 8);

	f1.Plus(f2).Plus(f3).print();

	Fraction* pf{ new Fraction(2,4) };

	pf->print();

	DEarray* array=new DEarray(10);
	delete array;

	return 0;
}