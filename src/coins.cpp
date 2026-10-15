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

bool Coins:: has_exact_change_for_coins(const Coins& coins) const{

	
	if (quarters >= coins.quarters && dimes >= coins.dimes 
		&& nickels >= coins.nickels && pennies >= coins.pennies){
		
			return true;
	
		} else {
	
	return false;


}
	return false;
}


Coins Coins::  extract_exact_change(const Coins& coins){

	 if (!has_exact_change_for_coins(coins)) {
        return Coins(0, 0, 0, 0);
    }

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
void print_cents(int cents, std::ostream& out){

	int dollar = cents/100;
	int centsremain = cents % 100;

	out << '$' << dollar << '.';

	if (centsremain < 10){
		out << '0'<< centsremain;

	}else{
	
		out << centsremain;

	}


}
int Coins::total_value_in_cents() const{

	int q = quarters * CENTS_PER_QUARTER;
	int d = dimes * CENTS_PER_DIME;
	int n = nickels * CENTS_PER_NICKEL;
	int p = pennies * 1;

	return q + d + n + p;
}


Coins ask_for_coins(std::istream& in, std::ostream& out){

int q;
int d;
int n;
int p;

	out << "How much Quarters?";
	in >> q;

	out << "How much Dimes?";
	in >> d;

	out << "How much Nickels?";
	in >> n;

	out << "Finally, Pennies?";
	in >> p;


	Coins myCoins(q, d, n, p);
	return myCoins;
}


void coins_menu(std::istream& in, std::ostream& out){

	int option = 0;
	Coins myCoins(0,0,0,0);

	while(option != 4){

	out << "\n1. Deposit" << endl;
    out << "2. Extract" << endl;
	out << "3. Print balance" << endl;
    out << "4. Exit" << endl;
    out << "Please choose an option: ";

	in >> option;

	

	if (option == 1){

	Coins dep = ask_for_coins(in, out);
	myCoins.deposit_coins(dep);

	}else if (option == 2){

	Coins req = ask_for_coins(in, out);

	if (myCoins.has_exact_change_for_coins(req)){

		myCoins.extract_exact_change(req);

		}else {

		out << "None Sufficent Balance, try again later!" << endl;

		}

	}else if (option == 3){

		int cents = myCoins.total_value_in_cents();
		print_cents(cents, out);
		out << endl;

	}else if (option == 4){

		option = 4;

		}

	}
}

