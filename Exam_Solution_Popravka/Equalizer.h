#pragma once
#include "Effect.h"
class Equalizer : public Effect
{
	int bass;
	int mid;
	int treble;
public:
	Equalizer(const string& name, int _bass, int _mid, int _treble);

	// Inherited via Effect
	void applyToSong(Track& track) override;

	void applyToPodcast(Track& track) override;


	// Inherited via Effect
	unique_ptr<Effect> clone() const override;

};

