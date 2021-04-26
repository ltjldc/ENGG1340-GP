#include "function.h"
#include <iostream>
#include <unistd.h>
#include "global.h"
#include <fstream>
#include <sstream>

using namespace std;

int RandMax()	// returns a large (8-digit) random int
{
	int tmp = 0;  //tmp is temporary integer
	for (int i = 1; i <= 8; i++)
		tmp = tmp * 10 + rand() % 10;
	return tmp;
}

int Rand(int l, int r)	// return a random int between l and r
{
	return l + RandMax() % (r - l + 1);
}

void animation(string sentence) // animation to generate the valley and heros
{
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			for (int k = 1; k <= j * j; k++)
				cout << '.';
			cout << endl;
			usleep(150000 * i);
		}
	}
	cout << sentence << endl;
	cout << endl;
}

void grow_array(Player *&array, int size)	//increase the size of the player array by the inputed number of players. 
{
	if (array == NULL)
		return;

	int newSize = 1 + size;

	Player *tmp = new Player[newSize]; 

	delete[] array;

	array = tmp;
	size = newSize;
}

void save(Boss *&boss, Player player[], int num)	// save the status of boss, player and number of players into data.txt
{ // num is number of players
	ofstream fout;
	fout.open("data.txt");

	if (fout.fail())
	{
		cout << "Error in file opening!" << endl;
		exit(1);
	}

	// the first line of file is the number of players
	fout << num << endl;

	fout << boss->name << endl;
	fout << boss->hp << endl;
	fout << boss->upgrade << endl;

	for (int i = 1; i < num + 1; i++)
	{
		fout << player[i].name << endl;
		fout << player[i].type << endl;
		fout << player[i].hp << endl;
		fout << player[i].mp << endl;
		fout << player[i].ind << endl;
		fout << player[i].shield << endl;
	}

	fout.close();
}

int get_NUM(string a)	// a is the file name and returns the number of players from the first line of the file
{
	int num;
	string numstring;
	ifstream fin_num;
	fin_num.open(a.c_str());
	if (fin_num.fail())
	{
		cout << "No saved file!" << endl;
		exit(1);
	}
	stringstream stream;
	getline(fin_num, numstring);
	stream << numstring;
	stream >> num;
	fin_num.close();
	return num;
}

void load(string filename, Boss *boss, Player *&player)	// load and assign the values of the boss and players from the file,
{
	ifstream fin;
	fin.open(filename.c_str());
	string loadString;  //loadString is used for getline(fin,loadstring), first read a string from file
	int loadInt; //loadInt is used for stringstream to convert string to int

	stringstream stream;

	if (fin.fail())
	{
		cout << "No saved file!" << endl;
		exit(1);
	}

	if (!fin)
	{
		cout << "No svaed file!" << endl;
		exit(0);
	}

	getline(fin, loadString);
	stream << loadString;		// to convert string into int
	stream >> NUM;
	stream.clear();

	getline(fin, loadString);
	(*boss).name = loadString;

	getline(fin, loadString);
	stream << loadString;
	stream >> loadInt;
	(*boss).hp = loadInt;
	stream.clear();

	getline(fin, loadString);
	stream << loadString;
	stream >> loadInt;
	(*boss).upgrade = loadInt;
	stream.clear();

	for (int i = 1; i <= NUM; i++)
	{
		getline(fin, loadString);
		player[i].name = loadString;
		getline(fin, loadString);
		stream << loadString;
		stream >> loadInt;
		player[i].type = loadInt;
		stream.clear();
		getline(fin, loadString);
		stream << loadString;
		stream >> loadInt;
		player[i].hp = loadInt;
		stream.clear();
		getline(fin, loadString);
		stream << loadString;
		stream >> loadInt;
		player[i].mp = loadInt;
		stream.clear();
		getline(fin, loadString);
		stream << loadString;
		stream >> loadInt;
		player[i].ind = loadInt;
		stream.clear();
		getline(fin, loadString);
		stream << loadString;
		stream >> loadInt;
		player[i].shield = loadInt;
		stream.clear();
	}

	fin.close();
}
