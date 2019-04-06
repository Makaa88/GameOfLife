#pragma once
#include <iostream>
#include <string>


namespace FileManagement
{
	class FileReader
	{
	public:
		FileReader(const std::string& path);
		void ReadSettingsFromFile(const std::string & path);
		int GetWidth() const;
		int GetHeight() const;
		std::string GetPreset() const;
	private:
		int _width;
		int _height;
		std::string _preset;
	};

}