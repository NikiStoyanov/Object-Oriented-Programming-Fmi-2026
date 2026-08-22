#include "Song.h"
#include "Effect.h"
#include "InvalidParametersException.h"
Song::Song(const string& title, unsigned duration, unsigned volume, const string& artistName, unsigned _releaseYear)
	: Track(title,duration,volume),artistName(artistName)
{
	if (_releaseYear <= 1900) {
		throw InvalidParametersException("Invalid_Argument Exception");
	}
}

void Song::play() const
{
	cout << title<<"   "<< artistName << endl;
}

void Song::applyEffect(Effect& effect)
{
	effect.applyToSong(*this);
}
