#include <iostream>
#include "coins.hpp"

using namespace std;

Coins:: Coins(int q, int d, int n, int p)
	:quarters(q), dimes(d), nickels(n), pennies(p){

	}


void Coins:: deposit_coins(Coins& coins){

	quarters += coins.quarters;
	dimes += coins.dimes;
	nickels += coins.nickels;
	pennies += coins.pennies;

	coins.quarters = 0;
    coins.dimes = 0;
    coins.nickels = 0;
    coins.pennies = 0;

}

bool Coins:: has_exact_change_for_coins(const Coins& coin){

	
	if (quarters >= coins.quarters && dimes >= coins.dimes 
		&& nickels >= coins.nickels && pennies >= coins.pennies){
		
			return true;
	
		} else 
		return false;
}


Coins Coins::  extract_exact_change(const Coins& coins){

	quarters -= coins.quarters;
	dimes -= coins.dimes;
	nickels -= coins.nickels;
	pennies -= coins.pennies;


	return coins;


}

void Coins:: print(std:: ostream& out) const{

	out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << pennies << " pennies";

}

std::ostream& operator<<(ostream& out, const Coins& coins) {

	coins.print(out);
    return out;

}

Coins coins_required_for_cents(int amount_in_cents){

	
	int q = amount_in_cents / CENTS_PER_QUARTER;
	amount_in_cents %= CENTS_PER_QUARTER;

	int d = amount_in_cents / CENTS_PER_DIME;
	amount_in_cents %= CENTS_PER_DIME;

	int n = amount_in_cents / CENTS_PER_NICKEL;
	amount_in_cents %=  CENTS_PER_NICKEL;

	int p = amount_in_cents/1;

	return Coins(q, d, n, p);


}





