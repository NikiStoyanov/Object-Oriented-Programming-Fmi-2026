#pragma once
#include "Track.h"
#include "Artist.h"
class Podcast : public Track
{
	unsigned episodeNumber;
	string hostName;
public:
	Podcast(const string& title, unsigned duration, unsigned volume, unsigned episodeNumber, const string& hostName);



	// Inherited via Track
	void play() const override;

	void applyEffect(Effect& effect) override;

};

