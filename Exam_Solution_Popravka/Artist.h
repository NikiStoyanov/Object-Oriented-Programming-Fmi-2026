#pragma once
#include <iostream>
using namespace std;
enum class Genre {
	Rock,
	Jazz,
	Pop,
	Classical,
	Comedy,
	Other
};
class Artist
{
	string name;
	Genre genre;
	string biography = "";

public:
	Artist(const string& name, const Genre& g);
	Artist(const string& name, const Genre& g, const string& biography);

	friend ostream& operator<<(ostream& os, const Artist& a);
};

