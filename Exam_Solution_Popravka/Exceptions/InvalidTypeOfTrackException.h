#pragma once
#include "MusicPlatformException.h"
class InvalidTypeOfTrackException : public MusicPlatformException
{
public:
	using MusicPlatformException::MusicPlatformException;
};

