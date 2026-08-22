#include "CommandHistory.h"

void CommandHistory::execute(unique_ptr<ICommand> command)
{
	command->execute();
	undoStack.push_back(std::move(command));
}

void CommandHistory::undo()
{
	if (undoStack.empty()) return;
	undoStack.back()->undo();
	undoStack.pop_back();
}

