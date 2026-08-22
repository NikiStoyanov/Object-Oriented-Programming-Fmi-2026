#include "Podcast.h"
#include "Effect.h"
#include "InvalidParametersException.h"
Podcast::Podcast(const string& title, unsigned duration, unsigned volume, unsigned episodeNumber, const string& hostName)
: Track(title,duration,volume), hostName(hostName){
	if (episodeNumber == 0) {
		throw InvalidParametersException("episodeNumber cannot be 0");
	}
	this->episodeNumber = episodeNumber;
}

void Podcast::play() const
{
	cout << title <<"   "<< episodeNumber << endl;
}

void Podcast::applyEffect(Effect& effect)
{
	effect.applyToPodcast(*this);
}
