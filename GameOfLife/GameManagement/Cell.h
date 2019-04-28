#pragma once


class Cell
{
public:
	Cell(bool deadOrAlive = false);
	bool GetCell() const;
	void SetCell(bool value);
	void SetCell(char sign);

private:
	bool _is_cell_alive;
};