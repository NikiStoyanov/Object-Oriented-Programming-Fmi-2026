#include "Reverb.h"
#include "InvalidParametersException.h"
#include "Track.h"
Effect::Effect(const string& name) : name(name)
{
}

const string& Effect::getName() const
{
	return name;
	// TODO: insert return statement here
}

Reverb::Reverb(const string& name, float _roomSize, float _decay) : Effect(name)
{
	if (_roomSize < 0 || _roomSize>1.00) {
		throw InvalidParametersException("Invalid room size");
	}
	if (_decay< 0) {
		throw InvalidParametersException("Invalid decay");
	}
	roomSize = _roomSize;
	decay = _decay;
}

void Reverb::applyToSong(Track& track)
{

	track.changeVolume(track.getVolume() + (roomSize * 10));
}

void Reverb::applyToPodcast(Track& track)
{
	track.changeVolume(track.getVolume() + (roomSize * 5));
}

unique_ptr<Effect> Reverb::clone() const
{
	return std::make_unique<Reverb>(*this);
}


