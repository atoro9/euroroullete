#include "rouletteTable.h"
#include "player.h"

#define DEBUG false //change this to true to help verify and debug your code 

using namespace std;

//--------------------------------------------------
void Player::setCurrentAmount(int amountValue)
{ 		
	currentAmount = amountValue;
}
//--------------------------------------------------
int Player::getCurrentAmount()
{
		return (currentAmount);
}
//--------------------------------------------------
bool Player::isWinner(vector <int> numbersBetOn, int winningNumber)
{
	bool win = false;

	//Go through the entire betting vector to see if there is a match
	for (int i = 0; i < numbersBetOn.size(); i++)
	{
			if (numbersBetOn[i] == winningNumber)
				win = true; 
	} 

	return win;
}
//--------------------------------------------------
int Player::winnings(bool winBet, int amountBet, int houseOdds)
{
		if (winBet) // is true then
		{
			return(houseOdds*amountBet);
		}
		else // I will assume that this will return negative earnings to be added to net worth
		{
			return(-1 * amountBet);
		}
}
//--------------------------------------------------
bool Player::betStreet(int which, int amountBet, int rolledValue)
//If you are having trouble getting started, I will give you this
//function. However, you can deviate from this approach if you would 
//like!! It is up to you!!
{

	//Do a little error checking to make sure your client uses your function correctly
 	if ((which < 1) || (which > 12)) //then error
	{
		//ask me in class about the difference between cerr and cout
		cerr << "Not a valid entry for street bet" << endl;
		return true; //this hijacks the outOfMoney sentinel to quit for the day
	}

 	if ( (currentAmount - amountBet) < 0) //then desired bet is not possible
	{
		//therefore bet the rest of your money!!!
		amountBet = currentAmount;
	}

	 vector <int> temp(3); //each set for a street bet is 3 numbers 

	 //please note that these values came from Appendix A
	 //check over them to make sure there is no mistake! 
	 switch (which)
	 {
	  case 1: temp = {1,2,3}; break;
	  case 2: temp = {4,5,6}; break;
	  case 3: temp = {7,8,9}; break;
	  case 4: temp = {10,11,12}; break;
	  case 5: temp = {13,14,15}; break;
	  case 6: temp = {16,17,18}; break;
	  case 7: temp = {19,20,21}; break;
	  case 8: temp = {22,23,24}; break;
	  case 9: temp = {25,26,27}; break;
	  case 10: temp = {28,29,30}; break;
	  case 11: temp = {31,32,33}; break;
	  case 12: temp = {34,35,36}; break;
	 }

	if (DEBUG)// this can help with validating and runtime debugging	
			cout << rolledValue<< ":: " << currentAmount 
				  << ": " << winnings(isWinner(temp, rolledValue), amountBet, 11)
				  << endl;

	//now change the amount that the player has based on the bet!! 
	 currentAmount += winnings(isWinner(temp, rolledValue), amountBet, 11);

	if (currentAmount <= 0)
			return (true); // You are out of money and let global function know it! 
	else
			return (false); //You still have money so you can keep going
}



