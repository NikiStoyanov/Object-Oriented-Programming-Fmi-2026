#include "EffectChain.h"
#include "Track.h"
#include "TrackOrEffectAlreadyExistsException.h"
void EffectChain::free()
{
	effects.clear();
}

void EffectChain::copyFrom(const EffectChain& other)
{
	for (const auto& el : other.effects) {
		effects.push_back(el->clone());
	}
}

void EffectChain::add(unique_ptr<Effect> effect)
{
	for (const auto& eff : effects) {
		if (eff->getName() == effect->getName()) {
			throw TrackOrEffectAlreadyExistsException("effect already exists");
		}
	}
	effects.push_back(std::move(effect));
}

void EffectChain::remove(const string& name)
{
	erase_if(effects, [&name](const unique_ptr<Effect>& e) {
		return e->getName() == name;
		});
}

void EffectChain::applyAll(Track& track)
{
	for (const auto& effect : effects) {
		track.applyEffect(*effect.get());
	}
}

EffectChain::EffectChain(const EffectChain& other)
{
	copyFrom(other);
}

EffectChain& EffectChain::operator=(const EffectChain& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
	// TODO: insert return statement here
}

EffectChain& EffectChain::operator+=(const EffectChain& other)
{
	for (const auto& effect : other.effects) {
		effects.push_back(effect->clone());
	}
	return *this;
	// TODO: insert return statement here
}

EffectChain operator+(const EffectChain& lhs, const EffectChain& rhs)
{
	EffectChain result(lhs);
	result += rhs;
	return result;
}
