#include "Artist.h"
Artist::Artist(const string& name, const Genre& g) : name(name), genre(g)
{
}

Artist::Artist(const string& name, const Genre& g, const string& biography): name(name), genre(g), biography(biography)
{
}

string genreToString(const Genre& g)
{
	switch (g) {
	case Genre::Other: return "Other";
	case Genre::Classical: return "Classical";
	case Genre::Comedy: return "Comedy";
	case Genre::Jazz: return "Jazz";
	case Genre::Pop: return "Pop";
	case Genre::Rock: return "Rock";
	}
	return string();
}

ostream& operator<<(ostream& os, const Artist& a)
{
	string genre = genreToString(a.genre);
	os << "Name: " << a.name << endl;
	os << "Genre: " << genre << endl;
	os << "Biography: " << a.biography << endl;
	return os;
}
