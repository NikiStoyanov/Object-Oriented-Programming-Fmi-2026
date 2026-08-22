#pragma once
#include "MusicPlatformException.h"
class InvalidParametersException : public MusicPlatformException
{
public:
	using MusicPlatformException::MusicPlatformException;
};

