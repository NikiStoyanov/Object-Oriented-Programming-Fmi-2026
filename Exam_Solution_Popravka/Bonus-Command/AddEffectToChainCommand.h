#pragma once
#include "Playlist.h"
#include "ICommand.h"
class AddEffectToChainCommand : public ICommand
{
	EffectChain& chain;
	unique_ptr<Effect> effect;

public:
	AddEffectToChainCommand(EffectChain& chain, unique_ptr<Effect> effect);



	// Inherited via ICommand
	void execute() override;

	void undo() override;

};

