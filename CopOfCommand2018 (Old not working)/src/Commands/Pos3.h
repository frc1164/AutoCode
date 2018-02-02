#ifndef Pos3_H
#define Pos3_H
#include "ScoreSwitch.h"
#include "ScoreScale.h"
#include "AutoRun.h"

#include <Commands/Command.h>

class Pos3 : public Command {
public:
	Pos3();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Pos3_H
