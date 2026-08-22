#include "MusicPlatformException.h"

MusicPlatformException::MusicPlatformException(const string& message) : message(message)
{
}

const char* MusicPlatformException::what() const noexcept
{
	return message.c_str();
}
