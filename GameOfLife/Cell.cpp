#include "Cell.h"

Cell::Cell(bool deadOrAlive)
	:_is_cell_alive{deadOrAlive}
{
}

bool Cell::GetCell() const
{
	return _is_cell_alive;
}

void Cell::SetCell(bool value)
{
	_is_cell_alive = value;
}

void Cell::SetCell(char sign)
{
	if (sign == 'o')
		_is_cell_alive = true;
	else
		_is_cell_alive = false;
}
