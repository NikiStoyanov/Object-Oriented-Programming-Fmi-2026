#include "AddTrackToPlaylistCommand.h"

AddTrackToPlaylistCommand::AddTrackToPlaylistCommand(Playlist& p, const shared_ptr<Track>& t)
	:playlist(p),track(t)
{

}

void AddTrackToPlaylistCommand::execute()
{
	playlist.addTrack(track);
}

void AddTrackToPlaylistCommand::undo()
{
	playlist.removeTrack(track->getTitle());
}
