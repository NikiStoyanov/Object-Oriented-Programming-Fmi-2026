#pragma once
#include "Effect.h"
class Reverb : public Effect
{
	float roomSize;
	float decay;
public:

	Reverb(const string& name, float _roomSize, float _decay);
	// Inherited via Effect



	// Inherited via Effect
	void applyToSong(Track& track) override;

	void applyToPodcast(Track& track) override;


	// Inherited via Effect
	unique_ptr<Effect> clone() const override;

};

