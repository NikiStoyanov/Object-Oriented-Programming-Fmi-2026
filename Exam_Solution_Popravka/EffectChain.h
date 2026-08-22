#pragma once
#include "Effect.h"
#include <vector>
class EffectChain
{
	vector<unique_ptr<Effect>> effects;

	void free();
	void copyFrom(const EffectChain& other);
public:
	EffectChain() = default;
	void add(unique_ptr<Effect> effect);
	void remove(const string& name);
	void applyAll(Track& track);

	EffectChain(const EffectChain& other);
	EffectChain& operator=(const EffectChain& other);

	EffectChain& operator+=(const EffectChain& other);

	friend EffectChain operator+(const EffectChain& lhs, const EffectChain& rhs);
};

