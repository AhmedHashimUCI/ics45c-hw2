#include <iostream>
#include "coins.hpp"

using namespace std;

int main(){

	Coins piggyBank(50, 50, 50, 50);
	Coins pocket(8, 3, 6, 8);
		
	cout << piggyBank << endl;
	cout << pocket << endl;


}
