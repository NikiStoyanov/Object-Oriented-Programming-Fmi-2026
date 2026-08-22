#pragma once
#include <iostream>
using namespace std;
class MusicPlatformException : public std::exception
{
	string message;
public:
	explicit MusicPlatformException(const string& message);

	const char* what() const noexcept override;
};

