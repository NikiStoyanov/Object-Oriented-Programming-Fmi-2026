#pragma once
#include "Track.h"
#include <vector>
#include <optional>
#include "EffectChain.h"
#include <algorithm>
class Playlist
{
	string name;
	vector<shared_ptr<Track>> tracks;

public:
	Playlist(const string& name);
	void addTrack(const shared_ptr<Track>& track);
	void removeTrack(const string& title);
	optional<shared_ptr<Track>> findTrack(const string& title) const;

	const string& getName() const;
	const vector<shared_ptr<Track>> getTracks() const;

	size_t size() const;
	void playAll() const;
	void applyEffects(EffectChain& effects);

	Playlist& operator+=(const Playlist& other);
	friend strong_ordering operator<=>(const Playlist& lhs, const Playlist& rhs);
	friend Playlist operator+(const Playlist& lhs, const Playlist& rhs);
};

