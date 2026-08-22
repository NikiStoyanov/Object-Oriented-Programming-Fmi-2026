#pragma once
#include "Track.h"
class TrackFactory
{
public:
	static shared_ptr<Track> create(const string& type);
};

