#pragma once
#include "targetver.h"
#include "Games.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>
#include "windows.h"
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::to_string;
using std::string;
using std::ostream;
using std::vector;
using std::ios;
using std::stringstream;

Games::Games() :gameName(""), gamePrice(0.0), gamePublisher(""), gameGenre(""),quantity(0)
{
	/*gameName = " ";
	gamePrice = 0.0;
	gamePublisher = " ";
	gameGenre = " ";*/
}

Games::Games(string gName, double gPrice, string gPublisher, string gGenre,int q)
{
	gameName = gName;
	gamePrice = gPrice;
	gamePublisher = gPublisher;
	gameGenre = gGenre;
	quantity = q;
}

Games::~Games()
{
}

void Games::setGameName(string gName)
{
	gameName = gName;
}

void Games::setGamePrice(double gPrice)
{
	gamePrice = gPrice;
}

void Games::setGamePublisher(string gPublisher)
{
	gamePublisher = gPublisher;
}

void Games::setGameGenre(string gGenre)
{
	gameGenre = gGenre;
}

void Games::setQuantity(int q)
{
	quantity = q;
}

string Games::getGameName()const
{
	return gameName;
}

double Games::getGamePrice() const
{
	return gamePrice;
}


string Games::getGamePublisher()const
{
	return gamePublisher;
}


string Games::getGameGenre()const
{
	return gameGenre;
}

int Games::getQuantity() const
{
	return quantity;
}

void Games::displayGameInfo() const
{
	cout << "\n" << "Games List\n----------------" << "\n" << "Game Name: " << getGameName()
		<< "\n" << "Game Price: €" << getGamePrice()
		<< "\n" << "Game Publisher: " << getGamePublisher()
		<< "\n" << "Game Genre: " << getGameGenre() <<
		"\n"<< "Games Quantity: "<< getQuantity() << endl << endl;
}

ostream& operator<<(ostream& out, Games& g)
{
	out << "Games......." << '\n' << "Name: " << g.gameName << '\n'
		<< "Price: " << g.gamePrice << '\n' << "Publisher: " << g.gamePublisher
		<< '\n' << "Genre: " << g.gameGenre <<'\n' <<"Quantity: " << g.quantity<< endl << endl;

	return out;
}

ofstream& operator<<(ofstream& out, const Games& g)
{
	out << g.gameName << " "
		<< g.gamePrice << " " << g.gamePublisher
		<< " " << g.gameGenre << " " << g.quantity <<'\n';

	return out;
}

ifstream& operator>>(ifstream& in, Games &g)
{
	vector<Games> games;
	in >> g.gameName >> g.gamePrice >> g.gamePublisher >> g.gameGenre >> g.quantity;
	return in;
}

bool Games::operator==(string gName)
{
	return gameName == gName;
}

bool compareName(Games &g1, Games &g2)
{
	return g1.getGameName() < g2.getGameName();
}

bool comparePrice (Games &g1, Games &g2)
{
	return g1.getGamePrice() < g2.getGamePrice();
}

bool comparePublisher(Games &g1, Games &g2)
{
	return g1.getGamePublisher() < g2.getGamePublisher();
}

bool compareGenre(Games &g1, Games &g2)
{
	return g1.getGameGenre() < g2.getGameGenre();
}