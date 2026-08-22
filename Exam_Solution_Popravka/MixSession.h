#pragma once
#include "Playlist.h"
#include "EffectChain.h"
class MixSession
{
	string sessionName;
	Playlist playlist;
	EffectChain effectChain;

public:
	MixSession(const string& sessionName, const Playlist& playlsit, const EffectChain& effectChain);
	void mix();
};

