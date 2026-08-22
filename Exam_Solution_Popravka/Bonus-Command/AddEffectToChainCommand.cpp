#include "AddEffectToChainCommand.h"

AddEffectToChainCommand::AddEffectToChainCommand(EffectChain& chain, unique_ptr<Effect> effect)
	: chain(chain), effect(std::move(effect)) {
}

void AddEffectToChainCommand::execute()
{
	chain.add(effect->clone());
}

void AddEffectToChainCommand::undo()
{
	chain.remove(effect->getName());
}
