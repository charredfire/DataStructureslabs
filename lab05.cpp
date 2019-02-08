//Charles Dunlap
//CS 2315
//lab 05

#include <lab05.h>

 bool Rational::isEqualTo(const Rational& other) const    // *this == other
 {
	 Rational lhs(this->getNumerator(),this->getDenominator());
	 Rational rhs(other.getNumerator(), other.getDenominator());
	 
	 lhs.reduce();
	 rhs.reduce();
	 
	 int lcm = Rational::lcm(lhs.getDenominator(),rhs.getDenominator());
	 
	 return lcm / lhs.getDenominator() * lhs.getNumerator() ==
			lcm / rhs.getDenominator() * rhs.getNumerator();
 }
 bool Rational::isNotEqualTo(const Rational& other) const // *this != other
 {
	return !(this->isEqualTo(other));
 }
 bool Rational::isLessThan(const Rational& other) const   // *this < other
 {
	Rational lhs(this->getNumerator(),this->getDenominator());
	 Rational rhs(other.getNumerator(), other.getDenominator());
	 
	 lhs.reduce();
	 rhs.reduce();
	 
	 int lcm = Rational::lcm(lhs.getDenominator(),rhs.getDenominator());
	 
	 return lcm / lhs.getDenominator() * lhs.getNumerator() <
			lcm / rhs.getDenominator() * rhs.getNumerator();
 }
 bool Rational::isLessThanOrEqualTo(const Rational& other) const // *this <= other
 {
	 return this->isLessThan(other) || this->isEqualTo(other);
 }
 bool Rational::isGreaterThan(const Rational& other) const // *this > other
 {
	 return !this->isLessThanOrEqualTo(other) && !this->isEqualTo(other);
 }
 bool Rational::isGreaterThanOrEqualTo(const Rational& other) const // *this >= other
 {
	 return !this->isLessThan(other);
 }