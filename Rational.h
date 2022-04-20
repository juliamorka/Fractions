#pragma once
#include <iostream>
using namespace std;
class Rational
{
public: 
	//Rational(void); //setRat z 0,1
	Rational(int l=0, int m=1);
	Rational(const Rational& u); //wywolac operator podstawienia *this=u

	double Value();
	void setDenomin(int d);
	void setRational(int n, int d);
	void setNumerat(int n);

	int getNumerat() const;
	int getDenomin() const;

	friend const Rational operator + (const Rational& u1, const Rational& u2);
	friend const Rational operator - (const Rational& u1, const Rational& u2);
	friend const Rational operator * (const Rational& u1, const Rational& u2);
	friend const Rational operator / (const Rational& u1, const Rational& u2);
	//jako zaprzyjazniona mozna dodac minus unarny
	friend Rational operator - (const Rational& r);

	Rational& operator += (const Rational& u);
	Rational& operator -= (const Rational& u);
	Rational& operator /= (const Rational& u);
	Rational& operator *= (const Rational& u);

	Rational& operator = (const Rational& u);
	friend istream& operator >> (istream& in, Rational& u);
	friend ostream& operator << (ostream& out, const Rational& u);

	operator double();
	operator int();

private:
	int mNumerat; //licznik
	int mDenominat; //mianownik
	void shortening(); //skracanie
	int nwd(int a, int b); //do skracania
};