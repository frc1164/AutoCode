#ifndef AutoForward_H
#define AutoForward_H

#include "Commands/Command.h"

class AutoForward : public frc::Command {
public:
	AutoForward(double UserTargetDistance, double UserSpeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double TargetDistance;
	double speed;
	double distance;
};

#endif  // AutoForward_H
