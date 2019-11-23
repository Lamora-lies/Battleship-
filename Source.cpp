//program for playing battleship with two non-computer players. 
using namespace std; 
#include <iostream>
#include <iomanip>
const int ARRAYSIZE = 64;
// all variables formatted shipNumber are variables holding the size of the available ships
const int shipOne = 5; 
const int shipTwo = 4; // this variable is used twice to place a ship
const int shipThree = 3;
const int shipFour = 2;

void showBoard(char myArray[], char letterArray[])//function to output the board that the player sees. 
{
	cout << "     ";
	for (int k = 0; k < 8; k++) //outputs the letter array
	{
		cout << letterArray[k] << setw(5);
	}
	cout << "\n"; cout << "\n";
	cout << "0" << setw(5);
	for (int i = 0; i < 8; i++)
{
	cout << myArray[i] << setw(5);
}

cout << "\n"; cout << "\n";
cout << "1" << setw(5);
for (int i = 8; i < 16; i++)
{
	cout << myArray[i] << setw(5);
}
cout << "\n"; cout << "\n";
cout << "2" << setw(5);
for (int i = 16; i < 24; i++)
{
	cout << myArray[i] << setw(5);
}
cout << "\n"; cout << "\n";
cout << "3" << setw(5);
for (int i = 24; i < 32; i++)
{
	cout << myArray[i] << setw(5);
}
cout << "\n"; cout << "\n";
cout << "4" << setw(5);
for (int i = 32; i < 40; i++)
{
	cout << myArray[i] << setw(5);
}
cout << "\n"; cout << "\n";
cout << "5" << setw(5);
for (int i = 40; i < 48; i++)
{
	cout << myArray[i] << setw(5);
}
cout << "\n"; cout << "\n";
cout << "6" << setw(5);
for (int i = 48; i < 56; i++)
{
	cout << myArray[i] << setw(5);
}
cout << "\n"; cout << "\n";
cout << "7" << setw(5);
for (int i = 56; i < 64; i++)
{
	cout << myArray[i] << setw(5);
}
cout << "\n";
}

int genRand()//function generates a random number between 8 and 64.
{
	srand(time(NULL)); //sets the seed for rand as the current system time
	int test = rand() % 8 * 8;//create int test and assign it the random number value
	return test;
}

int shipCheckLegal(char hitArray[], int coorOne, int shipSize)
//function used to check if a ship has already been placed in the anticipated location used by placeShip
{
	int count = 0;
	for (int i = coorOne; i < shipSize; i++) 
	{
		if (hitArray[i] == 'H') 
		{
			count++;
		}
		
	}
	return count;
}
void placeShips(char hitArray[], int shipSize)//function used to place ships onto the hit array
{
	int coorOne = genRand(); //coordinate used to determining ships starting place in hit array
	 while (coorOne + shipSize > ARRAYSIZE) 
		//this loops check if the ship size plus the randomly generated number
		//assigned to coorOne is greater than the size of the array in order to prevent overrun errors
		// or a tragic loss of life at sea. 
	{
		coorOne = genRand();
	}
	 
	int shipTest = shipCheckLegal(hitArray, coorOne, shipSize);
	//if shiptest is greater than one, that means that there's already a ship in part of the array that's been slated
	//for ship placement. The following while loop assigns a new value to coorOne and re checks it until the space is
	//clear
	while (shipTest > 0)
	{
		coorOne = genRand();
		shipCheckLegal(hitArray, coorOne, shipSize);
	} 
	
	for (int i = 0; i < shipSize; i++)
	{
		hitArray[coorOne] = 'H';
		cout << hitArray[coorOne];
		coorOne++;
		
	}
}

void hitOrMiss(char showArray[], char hitArray[])
{
	char letCoor = 'a';// player entered letter coordinate
	int convCoord;// player entered letter coordinate after being translated to an integer value
	int numCoor; // player entered number coordinate 
	cout << "Please enter a letter coordinate followed by a number coordinate. \nLetter: ";
	cin >> letCoor;
	cout << "Number: ";
	cin >> numCoor;
	if (letCoor == 'a')
	{
		convCoord = 0;
	}
	else if (letCoor == 'b')
	{
		convCoord = 1;
	}
	else if (letCoor == 'c')
	{
		convCoord = 2;
	}
	else if (letCoor == 'd')
	{
		convCoord = 3;
	}
	else if (letCoor == 'e')
	{
		convCoord = 4;
	}
	else if (letCoor == 'f')
	{
		convCoord = 5;
	}
	else if (letCoor == 'g')
	{
		convCoord = 6;
	}
	else if (letCoor == 'h')
	{
		convCoord = 7;
	}
	/* this is where I'm signing off for now. The next big thing to deal with is mapping the array to the user entered
	coordinates. For example, which array indice is G6? Off hand, I have no idea. I've made a little for loop that 
	outputs each indice of the array as well it's location in the array. I think I can just make a little map, hand drawn.
	there's probably a way to program it, but that sounds like a hassle and of no real use to the program. For now,
	good job Will. You've made tons of progress! I'm proud of you.
	*/
}

int main() 
{	char boardLet[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g','h'}; //letter labels array
	char showArray[64] = //array used as the board display
	{
		'*', '*', '*', '*', '*', '*', '*','*',
		'*', '*', '*', '*', '*', '*', '*','*',
		'*', '*', '*', '*', '*', '*', '*','*',
		'*', '*', '*', '*', '*', '*', '*','*',
		'*', '*', '*', '*', '*', '*', '*','*',
		'*', '*', '*', '*', '*', 'f', '*','*',
		'*', '*', '*', '*', '*', '*', '*','*',
		'*', '*', '*', '*', '*', '*', '*','*'
	};
	char hitArray[64] = //array used to hold ships and calculate hits and misses
	{
		'*', '*', '*', '*', '*', '*', '*','*' ,'*', '*', '*', '*', '*', '*', '*','*' ,
		'*', '*', '*', '*', '*', '*', '*','*','*', '*', '*', '*', '*', '*', '*','*',
		'*', '*', '*', '*', '*', '*', '*','*','*', '*', '*', '*', '*', '*', '*','*',
		'*', '*', '*', '*', '*', '*', '*','*','*', '*', '*', '*', '*', '*', '*','*'
	};
		

	//showBoard(showArray, boardLet);
	//placeShips(hitArray, shipOne);
	//hitOrMiss(showArray, hitArray);
	int count = 0;
	/* for (int i = 0; i < 65; i++)
	{
		cout << " Array Number is: " << count << endl;
		cout << " Array contents are: " << showArray[i];
		count++;
	 } */
	cout << endl << endl;
	system("pause");
}
