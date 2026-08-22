#include "TrackFactory.h"
#include "Song.h"
#include "Podcast.h"
#include "InvalidTypeOfTrackException.h"
shared_ptr<Track> TrackFactory::create(const string& type)
{
    if (type == "song") {
        string title,artistName;
        unsigned duration, volume,releaseYear;
        cout << "Enter: Title, ArtistName, Duration, Volume, ReleaseYear\n";
        cin >> title >> artistName >> duration >> volume>>releaseYear;
        return make_shared<Song>(title, duration, volume, artistName, releaseYear);
    }
    if (type == "podcast") {
        string title, hostName;
        unsigned duration, volume, episodeNumer;
        cout << "Enter: Title, HostName, Duration, Volume, EpisodeNumber\n";
        cin >> title >> hostName >> duration >> volume >> episodeNumer;
        return make_shared<Podcast>(title, duration, volume,episodeNumer, hostName);
    }
    throw InvalidTypeOfTrackException("The type provided is invalid");
}
