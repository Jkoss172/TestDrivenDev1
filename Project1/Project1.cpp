//Jeff Koss
//MS549 - Data Structures and Testing, Professor Jill Coddington
// Date: 03/10/2024
// Title: Assignment 1.1 Test Driven Development


// Here are the preprocessor directives
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <time.h>
#include <Windows.h>
#include <cassert>


// Declerations, Directives, and things I should not use
using namespace std; // a decleration to make life easy

//Some global variables
bool gameLoop = true;
int myRoom;// I use this for a placeholder so we can use an inventory then jump back to the room the player is in.
int playerHealth;



//start = clock();
//end = clock();
//assert(function_name("condition") = "predicted result");
//some vectors to hold stuff
vector <string> playerInventory;
vector <string>::iterator myIterator;
vector <string>::const_iterator iter;


// Protype Functions:
void MainMenu();
void Directions();
string CharacterName(string playerName);
int PlayerStrength(int playerStr, string playerName);
int PlayerIntelligence(int playerInt, int playerStr, string playerName);
int PlayerWillpower(int playerWil, int playerInt, int playerStr, string playerName);
int PlayerDexterity(int playerDex, int playerWil, int playerInt, int playerStr, string playerName);
int PlayerConstitution(int playerCon, int playerDex, int playerWil, int playerInt, int playerStr, string playerName);
int PlayerCharisma(int playerCha, int playerCon, int playerDex, int playerWil, int playerInt, int playerStr, string playerName);
string PlayerClothes(string playerRobe, string playerName, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
bool QuitGame(bool gameLoop);

int CharacterSheet(int myRoom, int playerHealth, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void TrophyCase(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void PlayerInventory(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);

void HomiltonsShop(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void HomiltonsOffice(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void OutsideHomiltons(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void PathToDungeon(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void DungeonEnter(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void EastCatwalk(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void WestCatwalk(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void TheCrypt(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void WizardsTomb(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void KnightsTomb(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void ClericsTomb(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
void ThiefTomb(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha);
// Note: I +had a hard time coping with passing variables and return values,
// my mind was set on global variables, so I forced myself to use parimiters and it worked!
// This is why you see the prototype fuctions add more and more variables to pass through... good exercise.


// The Main Function, cant do much wiothout it.
int main()
{
	srand(static_cast<unsigned int>(time(0)));// I seed the random number generator here for future use


	while (gameLoop == true) // This is the main game loop the game will continue to run until gameLoop == false
	{


		MainMenu();// This is where I call my game, it is the front door into the game and all things after are handled by it.
		return 0; // This exits the Main Function
	}
}

/* Here are the Function Declerations, I have many, and I designed this game to work
with functions and use them as a sort of psudo-class structure, allthough they are not classes
they do work with eachother to combine into complex instructions and I/O*/

void MainMenu()// The main menu, this is the heart of the program
{
	system("CLS");

	cout << "\t\t\t\t\t\t***********************" << endl;
	cout << "\t\t\t\t\t\t* The Wizard's Helper *" << endl;
	cout << "\t\t\t\t\t\t*   By: Jeff Koss     *" << endl;
	cout << "\t\t\t\t\t\t***********************" << endl;// end of title 
	cout << "\n\nGreetings adventurer and welcome to The Wizard's Helper," << endl;
	cout << "a fantasy adventure game made just for you!" << endl;
	cout << "\n\nYou can choose from the following: " << endl;
	cout << "\n 1 - Directions" << endl;
	cout << " 2 - Play Game" << endl;
	cout << " 3 - Quit" << endl;
	cout << "\n Please Make your choice: ";

	string menuChoice;
	

	getline(cin, menuChoice);

	if (menuChoice == "1")// this is the part of the function that will look for a choice and do something depending on the choice.
	{
		Directions();
	}
	else if (menuChoice == "2")
	{
		CharacterName("");
	}
	else if (menuChoice == "3")
	{
		QuitGame(gameLoop);
	}
	else
	{
		cout << "\nPlease make another choice." << endl;
		system("pause");
		MainMenu();

		return;

	}
	
}


void Directions()// This is a set of directions for the player, it introduces the game mechanics
{
	clock_t start1, ends1;
	start1 = clock();
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*     Directions     *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title
	cout << "\n\nGreetings fellow adventurer and welcome to The Wizard's Helper." << endl;
	cout << "In this game you will start out as the apprentece to a wize wizard." << endl;
	cout << "The goal of this game is to collect some stolen items and return them to the wizard's trophy case." << endl;
	cout << "Through this adventure you will be given choices and you must choose wisley." << endl;
	cout << "You will see a set of choices, they will look like Go (N)orth, (U)se Item, (A)ttack Monster and more." << endl;
	cout << "To make a choice, simply type in the character between the parentheses that you wish to do." << endl;
	cout << "\n\nYour character will have stats like Strength, Willpower and so on." << endl;
	cout << "These stats will determine what you can and can not do, so roll your stats wisley." << endl;
	cout << "Remember that no mortal is perfect so you can not roll perfect scores for your stats, do the best you can." << endl;
	cout << "\nYour Health measures how long you will live, if it reaches 0 you will die and the game will be over." << endl;
	cout << "Your Armor Class will determine how easy you can be hit and the lower it is the better." << endl;
	cout << "You can carry a weapon and defend yourself if needed, but you are too young to cast magic spells yet." << endl;
	cout << "You can access your (I)nventory, (C)haracter Sheet, (U)se Items such as healing potions, and (A)ttack." << endl;
	cout << "\nGood Luck Adventrer, you will need it!" << endl;
	cout << "" << endl;
	ends1 = clock();
	cout << (ends1 - start1);
	cout << "" << endl;

	system("pause");

	MainMenu();// after the player reads the directions the game will jump back into the main menu loop.
	return;

}

string CharacterName(string playerName)// This function starts the character creation process, it passes a string to get the player name and returns it.
{
	clock_t  start2, ends2;
	start2 = clock();
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t* Character Creation *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nBefore we start on your adventure you will need to:" << endl;
	cout << "Choose a name, roll some stats, and pick out some clothes." << endl;
	cout << "\nLet's begin, what would you like your name to be, please enter a first and last name." << endl;

	std::getline(cin, playerName);

	cout << "\n\nYour name is: " << playerName << endl;
	cout << "Next we will roll some stats." << endl;
	ends2 = clock();
	cout << "" << endl;
	cout << (ends2 - start2);
	cout << "" << endl;

	system("pause");

	PlayerStrength(0, playerName);// This calls the next function in the character creation process
	
	return playerName;// returns the string playerName for future use
}

int PlayerStrength(int playerStr, string playerName)// This is where the game starts to create info about the character, notice I pass the previous playerName in it, and it worked!
{
	bool isOk = true;

	while (isOk == true)// while isOk == true the game will loop through rolling a random number for Strength until the player is satisfied
	{
		system("CLS");
		cout << "\t\t\t\t\t\t**********************" << endl;
		cout << "\t\t\t\t\t\t* Character Creation *" << endl;
		cout << "\t\t\t\t\t\t**********************" << endl;//end title

		cout << "\n\nStrength is a measurement of brute force, it dictates how much" << endl;
		cout << "dammage you can do, how well you can break open a door or smash a chest." << endl;
		cout << "\nRolling for Strength..." << endl;

		int die = rand();// I set an interger called die (as in one dice) to the random number generator

		int playerStr = (die % 15) + 3;// this creates a random number between 3 and 18, just like old school DnD.


		cout << "\nYou rolled a " << playerStr << " out of a possable 18, will you keep the roll y/n?" << endl;

		string choice;
		getline(cin, choice);

		if (choice == "y" || choice == "Y")// this loops through until the pl;ayer is satisfied with the roll they made
		{
			cout << "\nYour name is: " << playerName << endl;
			cout << "\nYour Strength score is: " << playerStr << endl;
			cout << "\nExcelent, lets move on to Intelligence." << endl;
			system("pause");
			PlayerIntelligence(playerStr, 0, playerName);
			return playerStr;
		}

		else if (choice == "n" || choice == "N")
		{
			cout << "\nLet's roll again!" << endl;
			isOk = true;
		}
		else
		{
			cout << "\nPlease try again." << endl;
			isOk = true;
			system("pause");
		}
	}
}

int PlayerIntelligence(int playerStr, int playerInt, string playerName)// this rolls for Intelligence, notice how I keep adding more variables to pass through it.
{
	bool isOk = true;

	while (isOk == true)
	{
		system("CLS");
		cout << "\t\t\t\t\t\t**********************" << endl;
		cout << "\t\t\t\t\t\t* Character Creation *" << endl;
		cout << "\t\t\t\t\t\t**********************" << endl;

		cout << "\n\nIntelligence is a measure of how smart you are." << endl;
		cout << "It helps you determine if you can solve riddles, puzzles, and traps." << endl;
		cout << "\nRolling for Intelligence..." << endl;

		int die = rand();//set int die to random number generator

		int playerInt = (die % 15) + 3;// rolls a number from 3 to 18


		cout << "\nYou rolled a " << playerInt << " out of a possable 18, will you keep the roll y/n?" << endl;

		string choice;
		getline(cin, choice);

		if (choice == "y" || choice == "Y")// loop through a set of choices
		{
			cout << "\nYour name is: " << playerName << endl;
			cout << "\nYour Strength score is: " << playerStr << endl;
			cout << "Your Intelligence score is: " << playerInt << endl;
			cout << "\nExcelent, lets move on to Willpower." << endl;
			system("pause");
			isOk = false;
			PlayerWillpower(0, playerInt, playerStr, playerName);//notice I call the next function in a series of character creation stats, each having the prievious parimiters to pass
			return playerInt;// returns the players intelligence score for future use.
		}

		else if (choice == "n" || choice == "N")
		{
			cout << "\nLet's roll again!" << endl;
			isOk = true;
		}
		else
		{
			cout << "\nPlease try again." << endl;
			isOk = true;
			system("pause");
		}

	}
}

int PlayerWillpower(int playerWil, int playerInt, int playerStr, string playerName)// This acts just like the previous functions for character creation it just keeps adding variables to pass
{
	bool isOk = true;


	while (isOk == true)
	{
		system("CLS");
		cout << "\t\t\t\t\t\t**********************" << endl;
		cout << "\t\t\t\t\t\t* Character Creation *" << endl;
		cout << "\t\t\t\t\t\t**********************" << endl;

		cout << "\n\nWillpower is a measure of how determined you are." << endl;
		cout << "It helps you determine if you can overcome spells, or survive in a bad place." << endl;
		cout << "\nRolling for Willpower..." << endl;

		int die = rand();// set the random number

		int playerWil = (die % 15) + 3;


		cout << "\nYou rolled a " << playerWil << " out of a possable 18, will you keep the roll y/n?" << endl;

		string choice;
		getline(cin, choice);

		if (choice == "y" || choice == "Y")//the loop acts exactly like the previous function loops
		{
			cout << "\nYour name is: " << playerName << endl;
			cout << "\nYour Strength score is: " << playerStr << endl;
			cout << "Your Intelligence score is: " << playerInt << endl;
			cout << "Your Willpower score is: " << playerWil << endl;
			cout << "\nExcelent, lets move on to Dexterity." << endl;
			system("pause");
			isOk = false;
			PlayerDexterity(0, playerWil, playerInt, playerStr, playerName);//I call the next function, more and more variables!!!
			return playerWil;//returns the players Willpower score
		}

		else if (choice == "n" || choice == "N")
		{
			cout << "\nLet's roll again!" << endl;
			isOk = true;
		}
		else
		{
			cout << "\nPlease try again." << endl;
			isOk = true;
			system("pause");
		}

	}
}

int PlayerDexterity(int playerDex, int playerWil, int playerInt, int playerStr, string playerName)// function to get the players dexterity, more and more variables its getting big!, there is a method to my madness.
{
	bool isOk = true;

	while (isOk == true)
	{
		system("CLS");
		cout << "\t\t\t\t\t\t**********************" << endl;
		cout << "\t\t\t\t\t\t* Character Creation *" << endl;
		cout << "\t\t\t\t\t\t**********************" << endl;// end title

		// I should mention that in all of these functions I reserve this space for outputting a decription to the player
		cout << "\n\nDexterity is a measure of how quick and nimble you are." << endl;
		cout << "It helps you determine how fast you are and helps with Armor Class." << endl;
		cout << "\nRolling for Dexterity..." << endl;

		int die = rand();// sets the random number

		int playerDex = (die % 15) + 3;//again rolls 3 to 18


		cout << "\nYou rolled a " << playerDex << " out of a possable 18, will you keep the roll y/n?" << endl;

		string choice;
		getline(cin, choice);

		if (choice == "y" || choice == "Y")
		{
			//Notice how each stat is being displayed, the player character is taking shape.
			cout << "\nYour name is: " << playerName << endl;
			cout << "\nYour Strength score is: " << playerStr << endl;
			cout << "Your Intelligence score is: " << playerInt << endl;
			cout << "Your Willpower score is :" << playerWil << endl;
			cout << "Your Dexterity score is: " << playerDex << endl;
			cout << "\nExcelent, lets move on to Constitution." << endl;
			system("pause");
			isOk = false;
			PlayerConstitution(0, playerDex, playerWil, playerInt, playerStr, playerName);//calling the next function in the character creation series
			return playerDex;
		}

		else if (choice == "n" || choice == "N")
		{
			cout << "\nLet's roll again!" << endl;
			isOk = true;
		}
		else
		{
			cout << "\nPlease try again." << endl;
			isOk = true;
			system("pause");
		}

	}
}

int PlayerConstitution(int playerCon, int playerDex, int playerWil, int playerInt, int playerStr, string playerName)//By now you should see the pattern I am using to create a character, I know there may be easier ways, but I wanted the practice.
{
	bool isOk = true;

	while (isOk == true)//the loop
	{
		system("CLS");
		cout << "\t\t\t\t\t\t**********************" << endl;
		cout << "\t\t\t\t\t\t* Character Creation *" << endl;
		cout << "\t\t\t\t\t\t**********************" << endl;//end title

		cout << "\n\nConstitution is a measure of how hearty and healthy you are." << endl;
		cout << "It helps you determine how you survive the elements and how much health you have." << endl;
		cout << "\nRolling for Constitution..." << endl;

		int die = rand();//set the random number generator

		int playerCon = (die % 15) + 3;//roll a number from 3 to 18


		cout << "\nYou rolled a " << playerCon << " out of a possable 18, will you keep the roll y/n?" << endl;

		string choice;
		getline(cin, choice);

		if (choice == "y" || choice == "Y")
		{
			cout << "\nYour name is: " << playerName << endl;
			cout << "\nYour Strength score is: " << playerStr << endl;
			cout << "Your Intelligence score is: " << playerInt << endl;
			cout << "Your Willpower score is :" << playerWil << endl;
			cout << "Your Dexterity score is: " << playerDex << endl;
			cout << "Your Constitution score is: " << playerCon << endl;
			cout << "\nExcelent, lets move on to Charisma." << endl;
			system("pause");
			isOk = false;

			PlayerCharisma(0, playerCon, playerDex, playerWil, playerInt, playerStr, playerName);// This calls the next function
			return playerCon;
		}

		else if (choice == "n" || choice == "N")
		{
			cout << "\nLet's roll again!" << endl;
			isOk = true;
		}
		else
		{
			cout << "\nPlease try again." << endl;
			isOk = true;
			system("pause");
		}

	}
}

int PlayerCharisma(int playerCha, int playerCon, int playerDex, int playerWil, int playerInt, int playerStr, string playerName)// This is the last function for player stats!
{
	bool isOk = true;

	while (isOk == true)//loop through the random number generation for Charisma
	{
		system("CLS");
		cout << "\t\t\t\t\t\t**********************" << endl;
		cout << "\t\t\t\t\t\t* Character Creation *" << endl;
		cout << "\t\t\t\t\t\t**********************" << endl;// end title... I give every part a title description

		// some output to the player
		cout << "\n\nCharisma is a measure of how good looking you are." << endl;
		cout << "It helps determine how well you do with other people and sometimes even monsters." << endl;
		cout << "\nRolling for Charisma..." << endl;

		int die = rand();//sets the random number generator to an interger called die

		int playerCha = (die % 15) + 3;//rolls a random number from 3 to 18


		cout << "\nYou rolled a " << playerCha << " out of a possable 18, will you keep the roll y/n?" << endl;

		string choice;
		getline(cin, choice);

		if (choice == "y" || choice == "Y")
		{
			//Outputs player stats for the player to review
			cout << "\nYour name is: " << playerName << endl;
			cout << "\nYour Strength score is: " << playerStr << endl;
			cout << "Your Intelligence score is: " << playerInt << endl;
			cout << "Your Willpower score is :" << playerWil << endl;
			cout << "Your Dexterity score is: " << playerDex << endl;
			cout << "Your Constitution score is: " << playerCon << endl;
			cout << "Your Charisma score is: " << playerCha << endl;
			cout << "\nExcelent, lets move on to some clothes." << endl;
			system("pause");
			isOk = false;

			PlayerClothes("None", playerName, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);// calles the next function

			return playerCha;
		}

		else if (choice == "n" || choice == "N")
		{
			cout << "\nLet's roll again!" << endl;
			isOk = true;
		}
		else
		{
			cout << "\nPlease try again." << endl;
			isOk = true;
			system("pause");
		}

	}
}

string PlayerClothes(string playerRobe, string playerName, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)//This function lets the player choose armor, and starts the prelude to the game
{
	system("CLS");
	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*    The Prelude     *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	// Some descriptive output to the player
	cout << "\n\nIt is obvious you are in a dream, shapes and patterns swirl " << endl;
	cout << "as colors merge into the darkness. A booming voice can be heard " << endl;
	cout << playerName << ",  " << "you must heed my cry! My name is Homilton and I " << endl;
	cout << "am a powerful wizard! You must come to my aid, my shop was raided " << endl;
	cout << "and they took everything!. Before you, I have placed 6 robes of power." << endl;
	cout << "\nThe Red Robe represents Strength and will give you a Strength bonus." << endl;
	cout << "\nThe Yellow Robe represents Intelligence and will give you an Intelligence bonus." << endl;
	cout << "\nThe Blue Robe represents Willpower and will give you a Willpower bonus." << endl;
	cout << "\nThe Green Robe represents Dexterity and will give you a Dexterity bonus. " << endl;
	cout << "\nThe Purple Robe represents Constitution and will give you a Constitution bonus." << endl;
	cout << "\nThe White Robe represents Charisma and will give you a Charisma bonus." << endl;
	cout << "\nHomilton continues to speak, you may choose only one so choose wizely and come through the portal." << endl;

	cout << "\nWhat Robe do you choose: " << endl;
	cout << "\nThe (R)ed Robe\t The (Y)ellow Robe" << endl;
	cout << "The (B)lue Robe\t The (G)reen Robe" << endl;
	cout << "The (P)urple Robe   The (W)hite Robe" << endl;
	cout << "\nMake your choice: " << endl;

	string choice;// sets a string called choice, used to choose what robe the player starts with
	getline(cin, choice);// gets input from player and passes it to the string choice.

	if (choice == "R" || choice == "r")//cycles through a loop regarding what robe the player has taken.
	{
		cout << "\nYou picked the Red Robe." << endl;
		playerRobe = "Red Robe";
	}
	else if (choice == "Y" || choice == "y")
	{
		cout << "\nYou picked the Yellow Robe." << endl;
		playerRobe = "Yellow Robe";
	}
	else if (choice == "B" || choice == "b")
	{
		cout << "\nYou picked the Blue Robe." << endl;
		playerRobe = "Blue Robe";
	}
	else if (choice == "G" || choice == "g")
	{
		cout << "\nYou picked the Green Robe." << endl;
		playerRobe = "Green Robe";
	}
	else if (choice == "P" || choice == "p")
	{
		cout << "\nYou picked the Purple Robe." << endl;
		playerRobe = "Purple Robe";
	}
	else if (choice == "W" || choice == "w")
	{
		cout << "\nYou picked the White Robe." << endl;
		playerRobe = "White Robe";
	}
	else
	{
		cout << "Please choose again." << endl;
		system("pause");
		PlayerClothes(playerRobe, playerName, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}

	cout << "\n\nThe voice of Homilton fades as a portal of shimmering light surrounds you" << endl;
	cout << "You wake up and find yourself in Homilton's Shop" << endl;
	system("pause");
	HomiltonsShop(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	return playerRobe;
}

// this functon takes all the input from the player and passes it here to show stats.
int CharacterSheet(int myRoom, int playerHealth, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{
	playerHealth = 100;// sets player health 

	//this set of if statements will assign a bonus depending on what robe is being worn.
	if (playerRobe == "Red Robe")
	{
		playerStr = playerStr + 2;
	}
	if (playerRobe == "Yellow Robe")
	{
		playerInt = playerInt + 2;
	}
	if (playerRobe == "Blue Robe")
	{
		playerWil = playerWil + 2;
	}
	if (playerRobe == "Green Robe")
	{
		playerDex = playerDex + 2;
	}
	if (playerRobe == "Purple Robe")
	{
		playerCon = playerCon + 2;
	}
	if (playerRobe == "White Robe")
	{
		playerCha = playerCha + 2;
	}

	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*   Character Sheet  *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title
	cout << "\n\nName: " << playerName << "          " << "Armor: " << playerRobe << endl;
	cout << "\nHealth: " << playerHealth << endl;
	cout << "\n\nPlayer Stats: " << endl;
	cout << "\nStrength: " << playerStr << endl;
	cout << "Intelligence: " << playerInt << endl;
	cout << "Willpower: " << playerWil << endl;
	cout << "Dexterity: " << playerDex << endl;
	cout << "Constitution: " << playerCon << endl;
	cout << "Charisma: " << playerCha << endl;

	system("pause");

	// this set of if statements returns the player to the correct room after it jumps to inventory.
	if (myRoom == 1)
	{
		HomiltonsShop(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 2)
	{
		OutsideHomiltons(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 3)
	{
		PathToDungeon(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 4)
	{
		DungeonEnter(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 5)
	{
		EastCatwalk(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 6)
	{
		WestCatwalk(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 7)
	{
		TheCrypt(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 8)
	{
		WizardsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 9)
	{
		KnightsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 10)
	{
		ClericsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 11)
	{
		ThiefTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return playerHealth;

}

// this function stores the items need to win the game, if the player puts a treasure in the case it will register and give a score
// Note: this is not fully implemented yet as I ran out of time
void TrophyCase(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{
	const int MAX_TROPHY = 5;
	string trophies[MAX_TROPHY];
	int numTrophies = 0;

	system("cls");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*     Trophy Case    *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nInside the Trophy Case you see: ";

	if (numTrophies == 0)
	{
		cout << "\n\nThere is nothing in the case." << endl;
	}
	else
	{
		cout << "\n\nInside the Trophy Case you see: " << endl;
		for (int i = 0; i < numTrophies; i++)
		{
			cout << i << endl;
		}
	}

	system("pause");
	HomiltonsShop(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
}

//This is the player inventory, it works but I ran out of time to populate the world with items
void PlayerInventory(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*     Inventory      *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nYou are carrying: " << endl;

	for (iter = playerInventory.begin(); iter != playerInventory.end(); ++iter)
	{
		cout << *iter << endl;

	}

	system("pause");

	// this set of if statements puts the player back where they left off when they use inventory
	if (myRoom == 1)
	{
		HomiltonsShop(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 2)
	{
		OutsideHomiltons(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 3)
	{
		PathToDungeon(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 4)
	{
		DungeonEnter(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 5)
	{
		EastCatwalk(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 6)
	{
		WestCatwalk(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 7)
	{
		TheCrypt(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 8)
	{
		WizardsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 9)
	{
		KnightsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 10)
	{
		ClericsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (myRoom == 11)
	{
		ThiefTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return;

}

// the following functions are all rooms (places) the player can visit
// I ran out of time, but in the future there will be puzzles to solve, monsters and bosses to fight, and items to get.
void HomiltonsShop(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{

	myRoom = 1;
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*    Homiltons Shop  *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nYou stand inside the shop of Homilton The Wize," << endl;
	cout << "The shop is ransacked with trash everywhere." << endl;
	cout << "There is a Trophy Case in the back of the room." << endl;
	cout << "There is a door that leads to Homilton's Office." << endl;
	cout << "There is a door that leads outside the shop." << endl;
	cout << "A set of humanoid footprints leads Outside. " << endl;

	cout << "\n\nYou may do the following: \n" << endl;
	cout << "Go through (H)omilton's Office Door" << endl;
	cout << "Go through the (O)utside Door" << endl;
	cout << "Examine (T)rophy Case" << endl;
	cout << "\nYou may also: \n" << endl;
	cout << "(C)haracter Sheet" << endl;
	cout << "(I)nventory" << endl;
	cout << "(Q)uit Game" << endl;

	string choice;
	getline(cin, choice);

	if (choice == "H" || choice == "h")
	{
		HomiltonsOffice(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "O" || choice == "o")
	{
		OutsideHomiltons(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);

	}
	else if (choice == "T" || choice == "t")
	{
		TrophyCase(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "C" || choice == "c")
	{
		CharacterSheet(myRoom, playerHealth, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "I" || choice == "i")
	{
		PlayerInventory(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "Q" || choice == "q")
	{
		QuitGame(gameLoop);
	}
	else
	{
		cout << "\nPlease make another choice." << endl;
		system("pause");
		HomiltonsShop(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return;
}

void PathToDungeon(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{
	myRoom = 3;
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*     Dungeon Path   *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nYou are on a narrow path that leads to an old cave," << endl;
	cout << "The place has been overgrown by bushes and forgotten by time." << endl;
	cout << "There is a path leading back to Homilton's to the East." << endl;
	cout << "There is a forboding staircase leading down into the unknown." << endl;
	cout << "A set of humanoid footprints stops at the staircase." << endl;

	cout << "\n\nYou may do the following: \n" << endl;
	cout << "Go (E)ast" << endl;
	cout << "Go (D)own the staircase" << endl;
	cout << "\nYou may also: \n" << endl;
	cout << "(C)haracter Sheet" << endl;
	cout << "(I)nventory" << endl;
	cout << "(Q)uit Game" << endl;

	string choice;
	getline(cin, choice);

	if (choice == "E" || choice == "e")
	{
		OutsideHomiltons(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "D" || choice == "d")
	{
		DungeonEnter(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);

	}
	else if (choice == "C" || choice == "c")
	{
		CharacterSheet(myRoom, playerHealth, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "I" || choice == "i")
	{
		PlayerInventory(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "Q" || choice == "q")
	{
		QuitGame(gameLoop);
	}
	else
	{
		cout << "\nPlease make another choice." << endl;
		system("pause");
		PathToDungeon(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return;
}


void HomiltonsOffice(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*  Homilton's Office *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title
	cout << "\n\nYou open the door and peer inside." << endl;
	cout << "You see Homilton sitting at his desk with a look of disapointment." << endl;
	cout << "He looks up and sees you and shouts have you found my trophies yet?" << endl;
	cout << "There are 5 of them, do not rturn to me until you have placed all 5 in the trophy case!" << endl;
	cout << "\nYou run out of the room shutting the door behind you." << endl;
	system("pause");
	HomiltonsShop(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	return;

}
void OutsideHomiltons(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{
	{
		myRoom = 2;
		system("CLS");

		cout << "\t\t\t\t\t\t**********************" << endl;
		cout << "\t\t\t\t\t\t*     Outside Shop   *" << endl;
		cout << "\t\t\t\t\t\t**********************" << endl;// end title

		cout << "\n\nYou stand outside the shop of Homilton The Wize," << endl;
		cout << "it is a nice warm day. To the North is a door to Homilton's Shop." << endl;
		cout << "To the East a winding road lead out of town." << endl;
		cout << "A set of humanoid footprints leads to the East " << endl;

		cout << "\n\nYou may do the following: \n" << endl;
		cout << "Go through (H)omilton's Shop Door" << endl;
		cout << "Go through (W)est" << endl;
		cout << "\nYou may also: \n" << endl;
		cout << "(C)haracter Sheet" << endl;
		cout << "(I)nventory" << endl;
		cout << "(Q)uit Game" << endl;

		string choice;
		getline(cin, choice);

		if (choice == "H" || choice == "h")
		{
			HomiltonsShop(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
		}
		else if (choice == "W" || choice == "w")
		{
			PathToDungeon(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);

		}
		else if (choice == "C" || choice == "c")
		{
			CharacterSheet(myRoom, playerHealth, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
		}
		else if (choice == "I" || choice == "i")
		{
			PlayerInventory(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
		}
		else if (choice == "Q" || choice == "q")
		{
			QuitGame(gameLoop);
		}
		else
		{
			cout << "\nPlease make another choice." << endl;
			system("pause");
			OutsideHomiltons(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
		}
		return;
	}

}

void DungeonEnter(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{

	myRoom = 4;
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*  Dungeon Entrance  *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nYou stand midway on a large forboding staircase leading down," << endl;
	cout << "Above you is the Exit to the Dungeon." << endl;
	cout << "To the East is the Eastern Catwalk around the staircase." << endl;
	cout << "To the West is the Western Catwalk around the staircase. " << endl;
	cout << "You can see that the staircase continues downward." << endl;

	cout << "\n\nYou may do the following: \n" << endl;
	cout << "Go (U)p and Exit the Dungeon" << endl;
	cout << "Go (E)ast to the East Catwalk" << endl;
	cout << "Go (W)est to the West Catwalk" << endl;
	cout << "Go (D)own the rest of the Staircase" << endl;

	cout << "\nYou may also: \n" << endl;
	cout << "(C)haracter Sheet" << endl;
	cout << "(I)nventory" << endl;
	cout << "(Q)uit Game" << endl;

	string choice;
	getline(cin, choice);

	if (choice == "U" || choice == "u")
	{
		PathToDungeon(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "E" || choice == "e")
	{
		EastCatwalk(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);

	}
	else if (choice == "W" || choice == "w")
	{
		WestCatwalk(0, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "D" || choice == "d")
	{
		TheCrypt(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "C" || choice == "c")
	{
		CharacterSheet(myRoom, playerHealth, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "I" || choice == "i")
	{
		PlayerInventory(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "Q" || choice == "q")
	{
		QuitGame(gameLoop);
	}
	else
	{
		cout << "\nPlease make another choice." << endl;
		system("pause");
		DungeonEnter(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return;
}

void EastCatwalk(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{
	myRoom = 5;
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*    East Catwalk    *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nYou are standing on the East Catwalk." << endl;
	cout << "You see a pile of rubbish and trash in the corner." << endl;
	cout << "To the West is the Dungeon Entrance." << endl;
	cout << "You look down and can clearly see that the Dungeon Staircase goes down to a Crypt.. " << endl;

	cout << "\n\nYou may do the following: \n" << endl;
	cout << "Go (W)est to the Dungeon Entrance" << endl;

	cout << "\nYou may also: \n" << endl;
	cout << "(C)haracter Sheet" << endl;
	cout << "(I)nventory" << endl;
	cout << "(Q)uit Game" << endl;

	string choice;
	getline(cin, choice);

	if (choice == "W" || choice == "w")
	{
		DungeonEnter(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "C" || choice == "c")
	{
		CharacterSheet(myRoom, playerHealth, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "I" || choice == "i")
	{
		PlayerInventory(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "Q" || choice == "q")
	{
		QuitGame(gameLoop);
	}
	else
	{
		cout << "\nPlease make another choice." << endl;
		system("pause");
		EastCatwalk(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return;

}

void WestCatwalk(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{
	myRoom = 6;
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*    West Catwalk    *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nYou are standing on the West Catwalk." << endl;
	cout << "You see an old skeleton in the corner it has been stripped bare." << endl;
	cout << "To the East is the Dungeon Entrance." << endl;
	cout << "You look down and can clearly see that the Dungeon Staircase goes down to a Crypt.. " << endl;

	cout << "\n\nYou may do the following: \n" << endl;
	cout << "Go (E)ast to the Dungeon Entrance" << endl;

	cout << "\nYou may also: \n" << endl;
	cout << "(C)haracter Sheet" << endl;
	cout << "(I)nventory" << endl;
	cout << "(Q)uit Game" << endl;

	string choice;
	getline(cin, choice);

	if (choice == "E" || choice == "e")
	{
		DungeonEnter(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "C" || choice == "c")
	{
		CharacterSheet(myRoom, playerHealth, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "I" || choice == "i")
	{
		PlayerInventory(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "Q" || choice == "q")
	{
		QuitGame(gameLoop);
	}
	else
	{
		cout << "\nPlease make another choice." << endl;
		system("pause");
		WestCatwalk(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return;

}

void TheCrypt(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{

	myRoom = 7;
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*      The Crypt     *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nYou stand in the center of a large Crypt," << endl;
	cout << "The smell of rot and decay fills your nose.." << endl;
	cout << "There is a large sarcophagus in the center of the room." << endl;
	cout << "To the South is a Staircase leading up. " << endl;
	cout << "To the North is a door with a Magic Rune on it." << endl;
	cout << "To the West is a door with a Sword and Shield on it." << endl;
	cout << "To the East is a door with a Holy Symbol on it." << endl;

	cout << "\n\nYou may do the following: \n" << endl;
	cout << "Go (S)outh to the Staircase" << endl;
	cout << "Go (N)orth through the door with the Magic Rune " << endl;
	cout << "Go (W)est through the door with the Sword and Shield" << endl;
	cout << "Go (E)ast through the door with the Holy Symbol" << endl;
	cout << "(L)ook at the Sarcophagus" << endl;

	cout << "\nYou may also: \n" << endl;
	cout << "(C)haracter Sheet" << endl;
	cout << "(I)nventory" << endl;
	cout << "(Q)uit Game" << endl;

	string choice;
	getline(cin, choice);

	if (choice == "S" || choice == "s")
	{
		DungeonEnter(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "N" || choice == "n")
	{
		WizardsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);

	}
	else if (choice == "W" || choice == "w")
	{
		KnightsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "E" || choice == "e")
	{
		ClericsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "L" || choice == "l")
	{
		ThiefTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "C" || choice == "c")
	{
		CharacterSheet(myRoom, playerHealth, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "I" || choice == "i")
	{
		PlayerInventory(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "Q" || choice == "q")
	{
		QuitGame(gameLoop);
	}
	else
	{
		cout << "\nPlease make another choice." << endl;
		system("pause");
		TheCrypt(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return;
}

void WizardsTomb(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{

	myRoom = 8;
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*    Wizard's Tomb   *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nYou stand in the tomb of an Ancient Wizard." << endl;
	cout << "The air crackles with enchantment." << endl;
	cout << "There is a large sign on the North wall that reads: Homilton Was Here 01/31/2021." << endl;
	cout << "To the South is a Door. " << endl;

	cout << "\n\nYou may do the following: \n" << endl;
	cout << "Go (S)outh through the door" << endl;

	cout << "\nYou may also: \n" << endl;
	cout << "(C)haracter Sheet" << endl;
	cout << "(I)nventory" << endl;
	cout << "(Q)uit Game" << endl;

	string choice;
	getline(cin, choice);

	if (choice == "S" || choice == "s")
	{
		TheCrypt(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "C" || choice == "c")
	{
		CharacterSheet(myRoom, playerHealth, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "I" || choice == "i")
	{
		PlayerInventory(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "Q" || choice == "q")
	{
		QuitGame(gameLoop);
	}
	else
	{
		cout << "\nPlease make another choice." << endl;
		system("pause");
		WizardsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return;
}

void KnightsTomb(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{

	myRoom = 9;
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*   Knight's Tomb    *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nYou stand in the tomb of an Ancient Knight." << endl;
	cout << "The walls are decorated with stories of battle." << endl;
	cout << "There is a large Weapon Rack on the North wall." << endl;
	cout << "To the East is a Door. " << endl;

	cout << "\n\nYou may do the following: \n" << endl;
	cout << "Go (E)ast through the door" << endl;

	cout << "\nYou may also: \n" << endl;
	cout << "(C)haracter Sheet" << endl;
	cout << "(I)nventory" << endl;
	cout << "(Q)uit Game" << endl;

	string choice;
	getline(cin, choice);

	if (choice == "E" || choice == "e")
	{
		TheCrypt(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "C" || choice == "c")
	{
		CharacterSheet(myRoom, playerHealth, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "I" || choice == "i")
	{
		PlayerInventory(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "Q" || choice == "q")
	{
		QuitGame(gameLoop);
	}
	else
	{
		cout << "\nPlease make another choice." << endl;
		system("pause");
		KnightsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return;
}

void ClericsTomb(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{

	myRoom = 10;
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*    Cleric's Tomb   *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nYou stand in the tomb of an Ancient Cleric." << endl;
	cout << "The air is calm and peaceful." << endl;
	cout << "There is a large Alter on the North wall." << endl;
	cout << "To the West is a Door. " << endl;

	cout << "\n\nYou may do the following: \n" << endl;
	cout << "Go (W)est through the door" << endl;

	cout << "\nYou may also: \n" << endl;
	cout << "(C)haracter Sheet" << endl;
	cout << "(I)nventory" << endl;
	cout << "(Q)uit Game" << endl;

	string choice;
	getline(cin, choice);

	if (choice == "W" || choice == "w")
	{
		TheCrypt(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "C" || choice == "c")
	{
		CharacterSheet(myRoom, playerHealth, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "I" || choice == "i")
	{
		PlayerInventory(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "Q" || choice == "q")
	{
		QuitGame(gameLoop);
	}
	else
	{
		cout << "\nPlease make another choice." << endl;
		system("pause");
		ClericsTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return;
}

void ThiefTomb(int myRoom, string playerName, string playerRobe, int playerStr, int playerInt, int playerWil, int playerDex, int playerCon, int playerCha)
{

	myRoom = 11;
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*    Thief's Tomb    *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nYou fall through a secret chamber!" << endl;
	cout << "You stand in the tomb of an Ancient Thief." << endl;
	cout << "There is Treasure all around you." << endl;
	cout << "There is a large scale on the North wall that holds many Gems." << endl;
	cout << "There is a way to climb out leading Up. " << endl;

	cout << "\n\nYou may do the following: \n" << endl;
	cout << "Go (U)p through the hole" << endl;

	cout << "\nYou may also: \n" << endl;
	cout << "(C)haracter Sheet" << endl;
	cout << "(I)nventory" << endl;
	cout << "(Q)uit Game" << endl;

	string choice;
	getline(cin, choice);

	if (choice == "U" || choice == "u")
	{
		TheCrypt(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "C" || choice == "c")
	{
		CharacterSheet(myRoom, playerHealth, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "I" || choice == "i")
	{
		PlayerInventory(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	else if (choice == "Q" || choice == "q")
	{
		QuitGame(gameLoop);
	}
	else
	{
		cout << "\nPlease make another choice." << endl;
		system("pause");
		ThiefTomb(myRoom, playerName, playerRobe, playerStr, playerInt, playerWil, playerDex, playerCon, playerCha);
	}
	return;
}


// This function will end the game
bool QuitGame(bool gameLoop)// This function, when called, will end the game.
{
	system("CLS");

	cout << "\t\t\t\t\t\t**********************" << endl;
	cout << "\t\t\t\t\t\t*     Quit Game      *" << endl;
	cout << "\t\t\t\t\t\t**********************" << endl;// end title

	cout << "\n\nGoodBye Adventurer, and Thank You for playing!" << endl;
	system("pause");


	return false;// this will set the gameLoop bool to false and will cause the game to end.
}