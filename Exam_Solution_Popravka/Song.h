#pragma once
#include "Track.h"
#include "Artist.h"
class Song : public Track
{
	string artistName;
	unsigned releaseYear;
public:
	Song(const string& title, unsigned duration, unsigned volume, const string& artistName, unsigned _releaseYear);

	void play() const override;
	void applyEffect(Effect& effect) override;
};

