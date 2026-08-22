#pragma once
#include "ICommand.h"
#include <vector>
#include <memory>
using namespace std;
class CommandHistory
{
	vector<unique_ptr<ICommand>> undoStack;

public:
	void execute(unique_ptr<ICommand> command);

	void undo();
};

