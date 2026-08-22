#pragma once
#include "MusicPlatformException.h"
class TrackOrEffectAlreadyExistsException : public MusicPlatformException
{
public:
	using MusicPlatformException::MusicPlatformException;
};

