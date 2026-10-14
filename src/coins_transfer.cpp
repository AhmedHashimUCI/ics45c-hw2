#include <iostream>
#include "coins.hpp"

using namespace std;

constexpr int CENTS_FOR_CHIPS = 149;

int main(){

	Coins piggyBank(50, 50, 50, 50);
	Coins pocket(8, 3, 6, 8);
		
	cout << piggyBank << endl;
	cout << pocket << endl;

	Coins chips = pocket.extract_exact_change(coins_required_for_cents(CENTS_FOR_CHIPS));

	cout << "Chips cost " << chips << endl;

	Coins transfer = piggyBank.extract_exact_change(coins_required_for_cents(405));

	cout << "Transfered: " <<  transfer << endl;

	pocket.deposit_coins(transfer);

	//SOFA THINGY
	Coins sofa(10, 10, 10, 10);
	cout << "Sofa Before deposit: " << sofa << endl;
	piggyBank.deposit_coins(sofa);
	cout << "Sofa: " << sofa << endl;
	cout << "PiggyBank: " << piggyBank << endl;


	//BALANCE
	int piggycents = piggyBank.total_value_in_cents();
	print_cents(piggycents, cout);

	cout << endl;
}
