#ifndef MONEY_H
#define MONEY_H

#include <string>

class Money
{

private:
	int _denominations;
	long _counts;

	public:

//--------- Constructors and Destructor -----------	
#pragma region 
		Money();
		Money(int denominations = 0, long counts = 0);
		Money(const Money& other);
		Money(Money&& other) noexcept;
		~Money();

#pragma endregion
//--------------------------- Gets / Sets --------------------------------
#pragma region 
		int getDenominations() const;
		long getCounts() const;
		bool setDenominations(int denominations);
		bool setCounts(long counts);
#pragma endregion

//------------------------ Overloaded Operators --------------------------
#pragma region

		Money operator+(const Money& other) const;
		Money operator-(const Money& other) const;
		Money& operator=(const Money& other);
		Money& operator=(Money&& other) noexcept;
		bool operator==(const Money& other) const;
		bool operator!=(const Money& other) const;
		bool operator<(const Money& other) const;
		bool operator<=(const Money& other) const;
		bool operator>(const Money& other) const;
		bool operator>=(const Money& other) const;
		operator std::string() const;	
		Money& operator++();           // Prefix increment
		Money operator++(int);         // Postfix increment
		Money& operator--();           // Prefix decrement
		Money operator--(int);         // Postfix decrement

#pragma endregion
};

#endif // MONEY_H