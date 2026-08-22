#include "MixSession.h"

MixSession::MixSession(const string& sessionName, const Playlist& playlist, const EffectChain& effectChain)
: sessionName(sessionName), playlist(playlist), effectChain(effectChain){
}

void MixSession::mix()
{
	playlist.applyEffects(effectChain);
	for (const auto& t : playlist.getTracks()) {
		cout << t->getTitle() << t->getVolume()<<endl;
	}
}
