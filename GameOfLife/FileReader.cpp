#include "FileReader.h"
#include <fstream>

namespace FileManagement
{
	FileReader::FileReader(const std::string & path)
		:_width{0},
		_height{ 0 },
		_preset{ "" }
	{
		ReadSettingsFromFile(path);
	}

	void FileReader::ReadSettingsFromFile(const std::string& path)
	{
		std::fstream file;
		file.open(path, std::ios::in);
		std::string dump;

		file >> dump >> dump >> _width >> dump >> dump;
		file >> _height >> dump >> dump >> dump >> dump;
		file >> _preset;

		std::cout << _width << " " << _height << " " << _preset << std::endl;
	}

	int FileReader::GetWidth() const
	{
		return _width;
	}

	int FileReader::GetHeight() const
	{
		return _height;
	}

	std::string FileReader::GetPreset() const
	{
		return _preset;
	}

}
