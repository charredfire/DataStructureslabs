//Charles Dunlap
//Cs 2315
//lab 02

#include <lab02.h>
#include <cmath>

Rational::Rational()	                      // default constructor
{
	setDenominator(1);
	setNumerator(0);
}

Rational::Rational(int num, int denom)        // additional constructor
{
	setDenominator(denom);
	setNumerator(num);
}
	
void Rational::setNumerator(int num)          // set numerator to num
{
	r[0]= num;
}

void Rational::setDenominator(int denom)      // set denominator to denom
{
	if (denom != 0)
	r[1] = denom;
	else 
		r[1] = 1;
}

int Rational::getNumerator() const            // return numerator
{
	return r[0];//works
	//return *r;//works
	//return r; // wrong type
	//return this.r[0];// cannot select from a pointer
	//return *this.r[0];//won't work
	//return (*this)->r[0];//works
	//return this-> r;// works
	//return this ->*r//
	
}

int Rational::getDenominator() const          // return denominator
{
	return r[1];
}

void Rational::reduce()                       // Reduce to lowest terms and //   normalize
{
	int gcd = this->gcd(getNumerator(), getDenominator());
	
	if (getDenominator() < 0)
		gcd = -gcd;
	setNumerator(getNumerator()/gcd );
	setDenominator(getDenominator()/gcd);
	
}

int Rational::gcd(int m, int n) const         // returns the gcd of m and n
{
	int gcd, rem;
	
	if (m==0)
		gcd = abs(n);
	if (n==0)
		gcd = abs(m);
	else // euclids algorithm
	{
		m = abs(m);
		n = abs(n);
		rem = m%n;
		while (rem !=0)
		{
			m = n;
			n= rem;
			rem = m%n;
		}
	
	gcd = n;
	}
	
	return gcd;
}