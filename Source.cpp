#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
void CheckInput(int &); //Checks the user input if its a number.
void FillVector(vector <int> &, int); //Fills the vector with numbers of the Pascal's triangle.
int MaxNumberDigit(vector <int>); //Returns the maximum number's digits.
int DigitNumber(int); //Returns any number's digits.
void PrintVector(vector <int> &, int); //Prints the numbers of the Pascal's triangle in the shape of the triangle.
void SpaceOut(int); //Prints spaces in the command console.
bool Exit();

int main()
{
	do
	{
		system("cls");
		int rows;
		vector <int> triangle;
		cout << "Pascal's triangle application." << endl << endl;
		cout << "Input the number of rows of Pascal's triangle you wish to generate: ";
		CheckInput(rows);
		FillVector(triangle, rows);
		PrintVector(triangle, rows);
	} while (Exit());
}

void CheckInput(int & rows)
{
	bool again = false;
	string temp;
	getline(cin, temp);
	if (temp.size() != 0) //If input is just enter then temp.size() is zero and it becomes a problem.
	{
		for (int i = 0; i < temp.size(); i++)
		{
			if (i == 0 && !(temp[i] >= '1' && temp[i] <= '9')) //First digit of a number goes from 1-9.
			{
				again = true;
				break;
			}
			else if (i != 0 && !(temp[i] >= '0' && temp[i] <= '9'))
			{
				again = true;
				break;
			}
		}
	}
	else
		again = true;
	if (again)
	{
		cout << "Wrong input, please input a number: ";
		CheckInput(rows);
	}
	else
		rows = stoi(temp);		
}

void FillVector(vector <int> & triangle, int rows)
{
	
	int counter = 0; //Counter that keeps track of numbers in the vector.
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (i == 0 || j == 0 || j == i) //First and last number in the row are always 1.
			{
				triangle.push_back(1);
				counter++;
			}
			else
			{
				/*If you draw a Pascal's triangle with 3 rows and put a counter above each number:
				     1(0)
				  1(1) 1(2)
				1(3) 2(4) 1(5)
				you will see that the 4th number 2(counter=4) = 1(counter-i=2) + 1(counter-(i+1))=1*/
				triangle.push_back(triangle[counter - i] + triangle[counter - (i + 1)]);
				counter++;
			}
		}
	}
}

int MaxNumberDigit(vector <int> triangle)
{
	int digitNmb;
	int maxNmb = triangle[0];
	for (int i = 1; i < triangle.size(); i++)
	{
		if (maxNmb < triangle[i])
			maxNmb = triangle[i];
	}
	digitNmb = DigitNumber(maxNmb);
	return digitNmb;
}

int DigitNumber(int number)
{
	string temp = to_string(number);
	return temp.size();
}

//To print Pascal's vector in a valid triangle shape every number must occupy the same number of spaces in the command console so the numbers allign by their respective vertical lines. 
void PrintVector(vector <int> & triangle, int rows)
{
	cout << endl;
	int maxDigit = MaxNumberDigit(triangle);
	int digitNmb;
	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		SpaceOut((rows-(1+i))*maxDigit); //Spaces before the first number in the row, decreases the number of spaces depending on the row.
		for (int j = 0; j < i + 1; j++)
		{
			cout << triangle[counter];
			digitNmb = DigitNumber(triangle[counter]);
			SpaceOut(maxDigit*2-digitNmb); //Spaces after each number in the row, decreases by the digits of the number.
			counter++;
		}
		cout << endl;
	}
}

void SpaceOut(int space)
{
	for (int i = 0; i < space; i++)
	{
		cout << " ";
	}
}

bool Exit()
{
	cout << endl;
	string temp;
	cout << "Would you like to generate Pascal's triangle again? y/Y for yes or any other key for no." << endl;
	getline(cin, temp);
	if (temp[0] == 'Y' || temp[0] == 'y')
		return true;
	else
		return false;
}
