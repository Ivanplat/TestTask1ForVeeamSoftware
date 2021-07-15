#pragma once
#include <filesystem>
#include "Data.h"

//This class is using std::filesystem
//C++ 17 standart

class FileHandler
{
public:
	explicit FileHandler() = default; //Using explicit modificator, becouse C++ 17 standard is used, in which the C++ developers themselves recommend using it
	virtual ~FileHandler() = default;
public:
	virtual void CopyFile(FileInfo& fi) const; // Function to copy the file
};

