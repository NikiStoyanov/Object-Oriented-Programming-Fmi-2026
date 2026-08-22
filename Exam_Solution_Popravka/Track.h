#pragma once
#include <iostream>
#include "Effect.h"
using namespace std;

class Track
{
protected:
	string title;
	unsigned duration;
	unsigned volume;

public:
	Track(const string& title, unsigned duration, unsigned volume);
	void changeVolume(unsigned volume);
	unsigned getVolume() const;
	unsigned getDuration() const;
	const string& getTitle() const;
	virtual void play() const = 0;
	virtual void applyEffect(Effect& effect) = 0;
	virtual ~Track() = default;

};

