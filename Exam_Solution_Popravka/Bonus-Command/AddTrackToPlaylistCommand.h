#pragma once
#include <iostream>
#include "Playlist.h"
#include "ICommand.h"
using namespace std;
class AddTrackToPlaylistCommand : public ICommand
{
	Playlist& playlist;
	shared_ptr<Track> track;
public:
	AddTrackToPlaylistCommand(Playlist& p, const shared_ptr<Track>& t);

	// Inherited via ICommand
	void execute() override;
	void undo() override;
};

