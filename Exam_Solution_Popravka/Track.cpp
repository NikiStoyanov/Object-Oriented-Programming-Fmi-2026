#include "Track.h"
#include "InvalidParametersException.h"
Track::Track(const string& title, unsigned duration, unsigned volume) : title(title)
{
	if (volume > 100) {
		throw InvalidParametersException("volume must be between 0 and 100");
	}
	if (duration == 0) {
		throw InvalidParametersException("volume must be > 0 ");
	}
	this->volume = volume;
	this->duration = duration;
}

void Track::changeVolume(unsigned volume)
{
	this->volume = volume;
}

unsigned Track::getVolume() const
{
	return volume;
}

unsigned Track::getDuration() const
{
	return duration;
}

const string& Track::getTitle() const
{
	return title;
	// TODO: insert return statement here
}
