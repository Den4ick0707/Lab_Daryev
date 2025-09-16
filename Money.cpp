#include "Money.h"
#include <iostream>	


//---------------------- Constructors and Destructor ----------------------
#pragma region
Money::Money()
{
	_denominations = 0;
	_counts = 0;
	std::cout << "Money::Money() called" << std::endl;
}

Money::Money(int denominations, long counts)
	: _denominations(denominations), _counts(counts)
{
	std::cout << "Money::Money(int denominations, long counts) called" << std::endl;
}

Money::Money(const Money& other)
	: _denominations(other._denominations), _counts(other._counts)
{
	std::cout << "Money::Money(const Money& other) called" << std::endl;
}

Money::Money(Money&& other) noexcept
{
	_denominations = other._denominations;
	_counts = other._counts;
	other._denominations = 0;
	other._counts = 0;
	std::cout << "Money::Money(Money&& other) called" << std::endl;
}

Money::~Money()
{
	_denominations = 0;
	_counts = 0;
	std::cout << "Money::~Money called" << std::endl;
}
#pragma endregion
//--------------------------- Gets / Sets --------------------------------
#pragma region
int Money::getDenominations() const
{
	return _denominations;
}

long Money::getCounts() const
{
	return _counts;
}

bool Money::setDenominations(int denominations)
{
	if (denominations >= 0)
	{
		_denominations = denominations;
		return true;
	}
	else return false;
}

bool Money::setCounts(long counts)
{
	if (counts >= 0)
	{
		_counts = counts;
		return true;
	}
	else return false;
}
#pragma endregion

//------------------------ Overloaded Operators --------------------------
#pragma region
Money Money::operator+(const Money& other) const
{
	if(_denominations<0)
		return Money(0, _counts + other._counts);

	if (_counts < 0)
		return Money(_denominations, 0);

	return Money(_denominations+other._denominations, _counts+other._counts);
}

Money Money::operator-(const Money& other) const
{
	{
		if (_denominations < 0)
			return Money(0, _counts - other._counts);

		if (_counts < 0)
			return Money(_denominations- other._denominations, 0);

		return Money(_denominations - other._denominations, _counts - other._counts);
	}
}

Money& Money::operator=(const Money& other)
{
	return *this = Money(other);
}

Money& Money::operator=(Money&& other) noexcept
{
	return *this = Money(std::move(other));
}

bool Money::operator==(const Money& other) const
{
	if (_denominations == other._denominations && _counts == other._counts)
		return true;
	else
		return false;
}

bool Money::operator!=(const Money& other) const
{
	if (_denominations == other._denominations || _counts == other._counts)
		return false;
	else
		return true;
}

bool Money::operator<(const Money& other) const
{
	if (_denominations < other._denominations && _counts < other._counts)
		return true;

	if (_denominations == other._denominations && _counts < other._counts)
		return true;
	if (_denominations < other._denominations && _counts == other._counts)
		return true;

}

bool Money::operator<=(const Money& other) const
{
	return false;
}

bool Money::operator>(const Money& other) const
{
	return false;
}

bool Money::operator>=(const Money& other) const
{
	return false;
}
