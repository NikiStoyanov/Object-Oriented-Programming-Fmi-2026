#pragma once
#include <iostream>
#include <memory>
class Track;
using namespace std;
class Effect
{
	string name;
public:
	Effect(const string& name);
	const string& getName() const;

	virtual void applyToSong(Track& track) = 0;
	virtual void applyToPodcast(Track& track) = 0;
	virtual unique_ptr<Effect> clone() const = 0;
	virtual ~Effect() = default;
};

