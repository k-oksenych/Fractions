#pragma once

class Fraction
{
public:
	Fraction(const int numerator);
	Fraction(const int numerator, const int denominator);

	int GetDenominator() const;
	int GetNumerator() const;
	void SetDenominator(int newD);
	void SetNumerator(int newN);

	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

private:
	int m_numerator;
	int m_denominator;
};

Fraction operator-(const Fraction& fraction);
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator<(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);