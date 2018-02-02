#ifndef pos1_H
#define pos1_H
#include "ScoreSwitch.h"
#include "ScoreScale.h"
#include "AutoRun.h"

#include <Commands/Command.h>

class pos1 : public Command {
public:
	pos1();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // pos1_H
