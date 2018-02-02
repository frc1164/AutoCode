#ifndef Pos2_H
#define Pos2_H
#include "MidSwitch.h"
#include "AutoRun.h"

#include "Commands/Command.h"

class Pos2 : public Command {
public:
	Pos2();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Pos2_H
