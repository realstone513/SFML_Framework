#pragma once
#include "Animator.h"
#include <string>
#include "ResourceMgr.h"

class Animatable
{
protected:
	enum class States
	{
		None = -1,
		Idle,
		Move,
		Attack,
		Special,
		Hit,
		Death,
		Others
	};
	Animator anim;
	States currState;

public:
	void SetState(States newState)
	{
		if (currState == newState)
			return;
		currState = newState;
	}

	virtual void SetAnimations() = 0;
	void AddClipFast(string clipId, int frame)
	{
		anim.AddClip(*RESOURCE_MGR->GetAnimationClip(clipId));
		AnimationEvent ev;
		ev.clipId = clipId;
		ev.frame = frame;
		anim.AddEvent(ev);
	}
};