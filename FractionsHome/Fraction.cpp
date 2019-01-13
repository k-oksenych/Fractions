#include "Fraction.h"

Fraction::Fraction(const int numerator) :
	m_numerator(numerator),
	m_denominator(1)
{
}

Fraction::Fraction(const int numerator, const int denominator) :
	m_numerator(numerator),
	m_denominator(denominator)
{
}

int Fraction::GetDenominator() const
{
	return m_denominator;
}

int Fraction::GetNumerator() const
{
	return m_numerator;
}

void Fraction::SetDenominator(int newD)
{
	m_denominator = newD;
}

void Fraction::SetNumerator(int newN)
{
	m_numerator = newN;
}

Fraction& Fraction::operator++()
{
	m_numerator += m_denominator;

	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction new_f = *this;

	m_numerator += m_denominator;

	return new_f;
}

Fraction& Fraction::operator--()
{
	m_numerator -= m_denominator;

	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction new_f = *this;

	m_numerator -= m_denominator;

	return new_f;
}

Fraction operator-(const Fraction& fraction)
{
	Fraction new_f = fraction;

	int newN = -(new_f.GetNumerator());
	int newD = -(new_f.GetDenominator());

	new_f.SetNumerator(newN);
	new_f.SetDenominator(newD);

	return new_f;
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction new_f = left;

	int newN;
	int newD;

	if (left.GetDenominator() == right.GetDenominator())
	{
		newN = left.GetNumerator() + right.GetNumerator();
		
		new_f.SetNumerator(newN);
	}
	else
	{
		newN = left.GetNumerator() * right.GetDenominator() + left.GetDenominator() * right.GetNumerator();
		newD = left.GetDenominator() * right.GetDenominator();

		new_f.SetNumerator(newN);
		new_f.SetDenominator(newD);
	}

	return new_f;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction new_f = left;

	int newN;
	int newD;

	if (left.GetDenominator() == right.GetDenominator())
	{
			newN = left.GetNumerator() - right.GetNumerator();

			new_f.SetNumerator(newN);
	}
	else
	{
			newN = left.GetNumerator() * right.GetDenominator() - left.GetDenominator() * right.GetNumerator();
			newD = left.GetDenominator() * right.GetDenominator();

			new_f.SetNumerator(newN);
			new_f.SetDenominator(newD);
	}

	return new_f;
}

Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction new_f = left;

	int newN;
	int newD;

	newN = left.GetNumerator() * right.GetNumerator();
	newD = left.GetDenominator() * right.GetDenominator();

	new_f.SetNumerator(newN);
	new_f.SetDenominator(newD);

	return new_f;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction new_f = left;

	int newN;
	int newD;

	newN = left.GetNumerator() * right.GetDenominator();
	newD = left.GetDenominator() * right.GetNumerator();

	new_f.SetNumerator(newN);
	new_f.SetDenominator(newD);

	return new_f;
}

bool operator==(const Fraction& left, const Fraction& right)
{
	return left.GetNumerator() * right.GetDenominator() == right.GetNumerator() * left.GetDenominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return left.GetNumerator() * right.GetDenominator() != right.GetNumerator() * left.GetDenominator();
}

bool operator<(const Fraction& left, const Fraction& right)
{
	return left.GetNumerator() * right.GetDenominator() < right.GetNumerator() * left.GetDenominator();
}

bool operator>(const Fraction& left, const Fraction& right)
{
	return left.GetNumerator() * right.GetDenominator() > right.GetNumerator() * left.GetDenominator();
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return left.GetNumerator() * right.GetDenominator() <= right.GetNumerator() * left.GetDenominator();
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return left.GetNumerator() * right.GetDenominator() >= right.GetNumerator() * left.GetDenominator();
}