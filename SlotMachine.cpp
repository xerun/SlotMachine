#include "SlotMachine.h"
#include <iostream>
#include <sstream>
#include <iomanip>
/**
 Have reel Rk point at a random shape
 call the make shape function with int 
 parameter inside it
 */
void SlotMachine::make_shapes()
{
	for (int k = 0; k < 3; ++k) 
	{// have reel Rk point at a random shape
		make_shape(k);
	}
}

/**
 Three reels are represented by three unique 
 pointers reel[0], reel[1], reel[2], all
 currently pointing at nullptr.
 */
void SlotMachine::make_shape(int k)
{
	int n = rand() % 4; // Generate a random integer n, 0 <= n <= 3
	int w = rand() % 25 + 1; // Generate a random width w, 1 <= w <= 25
	
	if (n == 0)
	{
		reel[k].reset(new Rhombus(w, "Diamond")); // Let reel Rk point to a Rhombus object of width w
	}
	else if (n == 1)
	{
		reel[k].reset(new AcuteTriangle(w, "Acute triangle")); // Let reel Rk point to a AccuteTriangle object of width w
	}
	else if (n == 2)
	{
		reel[k].reset(new RightTriangle(w, "Right triangle")); // Let reel Rk point to a RightTriangle object of width w
	}
	else
	{
		int h = rand() % 25 + 1; // Generate a random height h, 1 <= h <= 25
		reel[k].reset(new Rectangle(w, h, "Rectangle")); // Let reel Rk point to aRectangle object of width w and height h
	}
}

/**
 The function display() prints the three bounding 
 boxes side by side in a row, with their 
 top borders aligned.
 */
void SlotMachine::display()
{	
	Grid box_0 = reel[0]->draw();
	Grid box_1 = reel[1]->draw();
	Grid box_2 = reel[2]->draw();
	int arr[3] = { box_0.size() ,box_1.size() ,box_2.size() }; // add all 3 box sizes into an array
	int* maxSize = max_element(std::begin(arr), std::end(arr)); // find the max value from the array 

	for (int r = 0; r < (*reel[0]).boxWidth()+3; ++r) // for each row vector in the grid
	{
		if (r == 0) { cout << "+"; } else {	cout << "-"; }	
	}
	for (int r = 0; r < (*reel[1]).boxWidth() + 3; ++r) // for each row vector in the grid
	{
		if (r == 0) { cout << "+"; } else { cout << "-"; }
	}
	for (int r = 0; r < (*reel[2]).boxWidth() + 3; ++r) // for each row vector in the grid
	{
		if (r == 0) { cout << "+"; } else { cout << "-"; }
	}
	cout << "+" << endl;
	for (int k = 0; k < *maxSize; ++k) // for each row vector in the grid
	{
		cout << "| ";
		if(k < box_0.size())
		{
			for (auto& element : box_0[k]) // for each element (char) in the row vector
			{
				cout << element;
			}
		}
		else 
		{
			for (auto& element : box_0[0]) // for each element (char) in the row vector
			{
				cout << " ";
			}
		}
		cout << " | ";
		if (k < box_1.size())
		{
			for (auto& element : box_1[k]) // for each element (char) in the row vector
			{
				cout << element;
			}
		}
		else
		{
			for (auto& element : box_1[0]) // for each element (char) in the row vector
			{
				cout << " ";
			}
		}
		cout << " | ";
		if (k < box_2.size())
		{
			for (auto& element : box_2[k]) // for each element (char) in the row vector
			{
				cout << element;
			}
		}
		else
		{
			for (auto& element : box_2[0]) // for each element (char) in the row vector
			{
				cout << " ";
			}
		}
		cout << " |";
		cout << endl; // line break
	}
	for (int r = 0; r < (*reel[0]).boxWidth() + 3; ++r) // for each row vector in the grid
	{
		if (r == 0) { cout << "+"; }
		else { cout << "-"; }
	}
	for (int r = 0; r < (*reel[1]).boxWidth() + 3; ++r) // for each row vector in the grid
	{
		if (r == 0) { cout << "+"; }
		else { cout << "-"; }
	}
	for (int r = 0; r < (*reel[2]).boxWidth() + 3; ++r) // for each row vector in the grid
	{
		if (r == 0) { cout << "+"; }
		else { cout << "-"; }
	}
	cout << "+" << endl;
}

/**
 prompts the user for a non-negative number (>= 0)
 reads in the number and check
 keeps re-prompting user if the input is invalid (negative)
 returns the non-negative input
*/
int SlotMachine::getNumber()
{
	int number;
	while((cin>>number).fail() || number < 0 || number > 15 || cin.peek() != '\n')
	{ //prompts the user for a non-negative number (>= 0)
		cin.clear();
		while (cin.get() != '\n') {
			continue;
			cin >> number;
		}
		if (number < 0) {
			cout << "No negative bets, try again!" << endl; // keeps re-prompting user if the input is invalid (negative)
		}
		else if (number > 15) {
			cout << "You can't bet more than 15, try again!" << endl; // keeps re-prompting user if the input is invalid (15)
		}
		else
		{
			cout << "Please input valid positive number, try again!" << endl;
		}
	}
	return number; // returns the non-negative input
}

/**
Prepare an array R of three elements to 
represent the three reels of the slot 
machine. Each element(reel) is a pointer 
to a Shape object managed dynamically.
Print the three reels side by side horizontally.
Based on the symbols on the payline, compute 
the prize payout (tokens won)
*/
void SlotMachine::run()
{
	cout << "Welcome to 3 - Reel Lucky Slot Machine Game !" << endl;
	cout << "Each reel will randomly display one of four shapes, each in 25 sizes." << endl;
	cout << "To win 3 x bet Get 2 similar shapes AND 2 shapes with equal Scr Areas" << endl;
	cout << "To win 2 x bet Get 3 similar shapes" << endl;
	cout << "To win 1 x bet Get(Middle) Scr Area > (Left + Right) Scr Areas" << endl;
	cout << "To win or lose nothing Get same Left and Right shapes" << endl;
	cout << "Otherwise, you lose your bet." << endl;
	cout << "You start with 10 free slot tokens!" << endl;	
	
	int token{ 10 }; // initialize token
	unsigned bet; // declare bet	
	srand(time(0)); // time reset so that the random value gets different sequence each time
	while (true) // loop until the token is zero or the bet is zero
	{
		cout << "\nHow much would you like to bet(enter 0 to quit)? ";
		bet = getNumber(); // get the number from user input and store in bet
		if (bet == 0) {
			cout << "Thank you for playing, come back soon!" << endl;
			cout << "Be sure you cash in your remaing " << token << " tokens at the bar!" << endl;
			cout << "Game Over." << endl;
			break; // break out of loop if user input zero
		}
		make_shapes(); // have reel Rk point at a random shape
		try
		{ 
			display(); // Print the three reels side by side horizontally.
		}
		catch (exception& e) {}
		
		if (((*reel[0]).getName() == (*reel[1]).getName() || (*reel[1]).getName() == (*reel[2]).getName() 
			|| (*reel[2]).getName() == (*reel[0]).getName()) && ((*reel[0]).screenArea() == (*reel[1]).screenArea() || (*reel[1]).screenArea() == (*reel[2]).screenArea()
				|| (*reel[2]).screenArea() == (*reel[0]).screenArea())) 
		{// if any two symbols are similar in shape and any two match in screen areas
			cout << "(" << (*reel[0]).getName() << ", " << (*reel[0]).boxWidth() << ", " << (*reel[0]).boxHeight() << "), ";
			cout << "(" << (*reel[1]).getName() << ", " << (*reel[1]).boxWidth() << ", " << (*reel[1]).boxHeight() << "), ";
			cout << "(" << (*reel[2]).getName() << ", " << (*reel[2]).boxWidth() << ", " << (*reel[2]).boxHeight() << "), " << endl;

			token = token + (3 * bet);
			cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas" << endl;
			cout << "Congratulations! You win 3 times your bet : " << bet*3 << endl;
			cout << "You now have " << token <<" tokens" << endl;
		}

		else if ((*reel[0]).getName() == (*reel[1]).getName() && (*reel[1]).getName() == (*reel[2]).getName()
			&& (*reel[2]).getName() == (*reel[0]).getName()) // if all three symbols are similar in shape
		{
			cout << "(" << (*reel[0]).getName() << ", " << (*reel[0]).boxWidth() << ", " << (*reel[0]).boxHeight() << "), ";
			cout << "(" << (*reel[1]).getName() << ", " << (*reel[1]).boxWidth() << ", " << (*reel[1]).boxHeight() << "), ";
			cout << "(" << (*reel[2]).getName() << ", " << (*reel[2]).boxWidth() << ", " << (*reel[2]).boxHeight() << "), " << endl;
			token = token + (2 * bet);
			cout << "Three similar shapes" << endl;
			cout << "Congratulations! You win 2 times your bet : " << bet*2 << endl;
			cout << "You now have " << token << " tokens" << endl;
		}

		else if ((*reel[1]).screenArea() > ((*reel[0]).screenArea() + (*reel[2]).screenArea())) 
		{// if screen area of middle symbol>sum of screen areas of left and right symbols
			cout << "(" << (*reel[0]).getName() << ", " << (*reel[0]).boxWidth() << ", " << (*reel[0]).boxHeight() << "), ";
			cout << "(" << (*reel[1]).getName() << ", " << (*reel[1]).boxWidth() << ", " << (*reel[1]).boxHeight() << "), ";
			cout << "(" << (*reel[2]).getName() << ", " << (*reel[2]).boxWidth() << ", " << (*reel[2]).boxHeight() << "), " << endl;
			token = token + (1 * bet);
			cout << "Middle > Left + Right , in Screen Areas" << endl;
			cout << "Congratulations! You win 1 times your bet : " << bet * 1 << endl;
			cout << "You now have " << token << " tokens" << endl;
		}

		else if ((*reel[0]).getName() != (*reel[1]).getName() && (*reel[1]).getName() != (*reel[2]).getName()
			&& (*reel[2]).getName() == (*reel[0]).getName()) // if the left and right symbols are similar
		{
			cout << "(" << (*reel[0]).getName() << ", " << (*reel[0]).boxWidth() << ", " << (*reel[0]).boxHeight() << "), ";
			cout << "(" << (*reel[1]).getName() << ", " << (*reel[1]).boxWidth() << ", " << (*reel[1]).boxHeight() << "), ";
			cout << "(" << (*reel[2]).getName() << ", " << (*reel[2]).boxWidth() << ", " << (*reel[2]).boxHeight() << "), " << endl;

			cout << "Lucky this time !" << endl;
			cout << "You don't win, you don't lose, your are safe ! " << endl;
			cout << "You now have " << token << " tokens" << endl;
		}
		else
		{ // otherwise user lose
			cout << "(" << (*reel[0]).getName() << ", " << (*reel[0]).boxWidth() << ", " << (*reel[0]).boxHeight() << "), ";
			cout << "(" << (*reel[1]).getName() << ", " << (*reel[1]).boxWidth() << ", " << (*reel[1]).boxHeight() << "), ";
			cout << "(" << (*reel[2]).getName() << ", " << (*reel[2]).boxWidth() << ", " << (*reel[2]).boxHeight() << "), " << endl;
			token = token - bet;
			if (token < 0)token = 0;
			cout << "Oh No!" << endl;
			cout << "You lose your bet " << endl;
			cout << "You now have " << token << " tokens" << endl;
		}
		if (token < 1) break; // break out of loop if user input zero
	}
}
