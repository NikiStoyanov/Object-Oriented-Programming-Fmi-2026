#include "Playlist.h"
#include "TrackOrEffectAlreadyExistsException.h"
Playlist::Playlist(const string& name) : name(name)
{
}

void Playlist::addTrack(const shared_ptr<Track>& track)
{
    auto found = find_if(tracks.begin(), tracks.end(), [&](const shared_ptr<Track>& t) {
        return t->getTitle() == track->getTitle();
        });
    if (found != tracks.end()) throw TrackOrEffectAlreadyExistsException("track already exists");
    tracks.push_back(track);
}

void Playlist::removeTrack(const string& title)
{
    erase_if(tracks, [&title](const shared_ptr<Track>& track) {
        return track->getTitle() == title;
        });
}

optional<shared_ptr<Track>> Playlist::findTrack(const string& title) const
{
    for (const auto& t : tracks) {
        if (t->getTitle() == title) {
            return t;
        }
    }
    return nullopt;
}
size_t Playlist::size() const {
    return tracks.size();
}
const string& Playlist::getName() const {
    return name;
}
const vector<shared_ptr<Track>> Playlist::getTracks() const
{
    return tracks;
}
void Playlist::playAll() const
{
    for (const auto& t : tracks) {
        t->play();
    }
}

void Playlist::applyEffects(EffectChain& effects)
{
    for (const auto& t : tracks) {
        effects.applyAll(*t.get());
    }
}

Playlist& Playlist::operator+=(const Playlist& other)
{
    for (const auto& t : other.tracks) {
        if (findTrack(t->getTitle()).has_value()) {
            continue;
        }
        tracks.push_back(t);
    }
    return *this;
    // TODO: insert return statement here
}

strong_ordering operator<=>(const Playlist& lhs, const Playlist& rhs)
{
    unsigned trackDurationOfLhs = 0;
    for (const auto& track : lhs.tracks) {
        trackDurationOfLhs += track->getDuration();
    }
    unsigned trackDurationOfRhs = 0;
    for (const auto& track : rhs.tracks) {
        trackDurationOfRhs += track->getDuration();
    }
    if (trackDurationOfLhs == trackDurationOfRhs) {
        return lhs.getName() <=> rhs.getName();
    }
    return trackDurationOfLhs <=> trackDurationOfRhs;
}

Playlist operator+(const Playlist& lhs, const Playlist& rhs)
{
    Playlist result(lhs);
    result += rhs;
    return result;
}
