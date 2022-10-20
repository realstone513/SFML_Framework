#pragma once
#include "Animator.h"
#include <string>
#include "ResourceMgr.h"

class Animatable
{
protected:
	Animator anim;
	int currState;

public:
	void SetState(int newState)
	{
		if (currState == newState)
			return;
		currState = newState;
	}
	// 추가 예정

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