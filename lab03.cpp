//Charles Dunlap
//CS2315
// lab03
#include <lab03.h>
#include <cmath>// for abs

Rational Rational::add(const Rational& addend) const     // Addition
{
	Rational sum; // create local object
	
	int lcm = Rational::lcm(this->getDenominator(), addend.getDenominator());
	
	//populate the sum / modify the object
	sum.setNumerator(lcm / this->getDenominator() * this->getNumerator()+
					lcm / addend.getDenominator() * addend.getNumerator());
	
	sum.setDenominator(lcm);
	sum.reduce();
	// return object
	return sum;
	
}

Rational Rational::additiveInverse() const               // Returns the additive //   inverse
{
	Rational additiveInverse(this->getNumerator() * -1, this->getDenominator());
	
	return additiveInverse;
}

Rational Rational::subtract(const Rational& subtrahend) const // Subtraction
{
	Rational additiveInverse= subtrahend.additiveInverse();
	Rational difference = this->add(additiveInverse); // create and modify local object
	
	return difference;
	
}
Rational Rational::multiply(const Rational& multiplicand) const // Multiplication
{
	Rational product;// create local object
	// modify object
	product.setNumerator(this->getNumerator() * multiplicand.getNumerator());
	product.setDenominator(this->getDenominator() * multiplicand.getDenominator());
	product.reduce();
	return product;// return object
	
}
Rational Rational::divide(const Rational& divisor) const   // Division
{
	Rational quotient;

	quotient.setNumerator(this->getNumerator() * divisor.getDenominator());
	quotient.setDenominator(this->getDenominator() * divisor.getNumerator());
	quotient.reduce();
	return quotient;
}
ostream& Rational::print(ostream& os) const          // Print Rational to output //   stream
{
	os<< this->getNumerator() << "/" << this->getDenominator();
	return os;
}
istream& Rational::read(istream& is)                     // Read Rational from input//   stream
{
	int n, d;
	
	is >> n >> d;
	
	setNumerator(n);
	setDenominator(d); // may need to add this-> to the beginning
	
	return is;
}

int Rational::lcm(int m, int n) const                    // returns the least common //   multiple of m and n
{
	if (m==0 || n==0)
		return 0;
	else
		return abs(m * n) / gcd(m,n);
}