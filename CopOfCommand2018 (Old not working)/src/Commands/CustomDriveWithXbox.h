#ifndef CustomDriveWithXbox_H
#define CustomDriveWithXbox_H

#include "Commands/Command.h"

class CustomDriveWithXbox : public frc::Command {
public:
	CustomDriveWithXbox();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CustomDriveWithXbox_H
