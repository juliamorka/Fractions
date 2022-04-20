#include "Rational.h"
/*Rational::Rational(void) //setRat z 0,1
{
	setRational(0, 1);
}*/
Rational::Rational(int l, int m)
{
	setRational(l, m);
	shortening();
}
Rational::Rational(const Rational& u) //wywolac operator podstawienia *this=u
{
	*this = u;
}

double Rational::Value()
{
	return (double)(getNumerat() / getDenomin());
}
void Rational::setDenomin(int d)
{
	if (!d)
	{
		d = 1;
		cerr << "ERROR: mianownik = 0!";
	}
	mDenominat = d;
}
void Rational::setRational(int n, int d)
{
	setNumerat(n);
	setDenomin(d);
}
void Rational::setNumerat(int n)
{
	mNumerat = n;
}

int Rational::getNumerat() const
{
	return mNumerat;
}
int Rational::getDenomin() const
{
	return mDenominat;
}

const Rational operator + (const Rational& u1, const Rational& u2)
{
	Rational res(u1);
	res += u2;
	return res;
}
const Rational operator - (const Rational& u1, const Rational& u2)
{
	Rational res(u1);
	res -= u2;
	return res;
}
const Rational operator * (const Rational& u1, const Rational& u2)
{
	Rational res(u1);
	res *= u2;
	return res;
}
const Rational operator / (const Rational& u1, const Rational& u2)
{
	Rational res(u1);
	res /= u2;
	return res;
}

Rational& Rational::operator += (const Rational& u) //sprowadzenie do wspólnego mianownika
{
	Rational temp(u.getNumerat() * mDenominat, u.getDenomin() * mDenominat); 
	mDenominat = mDenominat * u.getDenomin();
	mNumerat = mNumerat * u.getDenomin() + temp.getNumerat(); 
	return *this;
}
Rational& Rational::operator -= (const Rational& u) //sprowadzenie do wspólnego mianownika
{
	Rational temp(u.getNumerat() * mDenominat, u.getDenomin() * mDenominat); 
	mDenominat = mDenominat * u.getDenomin();
	mNumerat = mNumerat * u.getDenomin() - temp.getNumerat();
	return *this;
}
Rational& Rational::operator /= (const Rational& u) //mno¿enie przez odwrotnoœæ
{
	Rational temp(u.getDenomin(), u.getNumerat());
	*this *= temp;
	return *this;
}
Rational& Rational::operator *= (const Rational& u) //mno¿enie l*l, m*m
{
	mNumerat = mNumerat * u.getNumerat();
	mDenominat = mDenominat * u.getDenomin();
	return *this;
}

Rational& Rational::operator = (const Rational& u)
{
	setRational(u.getNumerat(), u.getDenomin());
	return *this;
}
istream& operator >> (istream& in, Rational& u)
{
	int temp;
	in >> temp; u.setNumerat(temp);
	in >> temp; u.setDenomin(temp);
	return in;
}
ostream& operator << (ostream& out, const Rational& u)
{
	Rational temp(u);
	temp.shortening();
	out << temp.getNumerat() << "|" << temp.getDenomin();
	return out;
}
void Rational::shortening() //skracanie
{
	int nwd = Rational::nwd(mNumerat, mDenominat);
	mNumerat /= nwd;
	mDenominat /= nwd;
}
int Rational::nwd(int a, int b) //do skracania
{
	while(b) //b na pewno nie jest zerem bo jest w mianowniku
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
Rational operator - (const Rational& r)
{
	Rational res(r);
	res.setNumerat(-res.getNumerat());
	//gdy minus w liczniku i mianowniku to zrobic przypadek
	return res;
}
Rational::operator double()
{
	return (double)getNumerat() / getDenomin();
}
Rational::operator int()
{
	return getNumerat()/getDenomin();
}