#include "RemoveTrackFromPlaylistCommand.h"

RemoveTrackFromPlaylistCommand::RemoveTrackFromPlaylistCommand(Playlist& p, const shared_ptr<Track>& t)
: playlist(p), track(t){
}

void RemoveTrackFromPlaylistCommand::execute()
{
	playlist.removeTrack(track->getTitle());
}

void RemoveTrackFromPlaylistCommand::undo()
{
	playlist.addTrack(track);
}
