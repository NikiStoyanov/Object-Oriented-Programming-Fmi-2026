#pragma once
#include <iostream>
#include "Playlist.h"
#include "ICommand.h"
class RemoveTrackFromPlaylistCommand : public ICommand
{
	Playlist& playlist;
	shared_ptr<Track> track;

public:
	RemoveTrackFromPlaylistCommand(Playlist& p, const shared_ptr<Track>& t);


	// Inherited via ICommand
	void execute() override;

	void undo() override;

};

