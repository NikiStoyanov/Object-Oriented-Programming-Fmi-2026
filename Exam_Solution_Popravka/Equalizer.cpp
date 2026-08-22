#include "Equalizer.h"
#include "InvalidParametersException.h"
#include "Track.h"
static void validate(int number, const string& cause) {
	if (number < -12 || number >12) {
		throw InvalidParametersException(cause);
	}
}
Equalizer::Equalizer(const string& name, int _bass, int _mid, int _treble)
	:Effect(name)
{
	validate(_bass, "bass must be between -12 and 12");
	validate(_mid, "mid must be between -12 and 12");
	validate(_treble, "treble must be between -12 and 12");
	bass = _bass;
	mid = _mid;
	treble = _treble;
}

void Equalizer::applyToSong(Track& track)
{
	double avg = (bass + mid + treble) / 3;
	track.changeVolume(track.getVolume() + avg);
}

void Equalizer::applyToPodcast(Track& track)
{
	track.changeVolume(track.getVolume() + mid);
}

unique_ptr<Effect> Equalizer::clone() const
{
	return make_unique<Equalizer>(*this);
}
