#pragma once
#include "tinyxml2.h"
#include "Data.h"

//XMLReader is a class for implementation tinyxml2 instrumentum
//Also, tinyxml2 is installed from vcpkg. Documentation: https://vcpkg.io/en/index.html
//Tinyxml documentation: https://github.com/leethomason/tinyxml2

class XMLReader
{
public:
	explicit XMLReader(); //Using explicit modificator, becouse C++ 17 standard is used, in which the C++ developers themselves recommend using it
	virtual ~XMLReader();
public:
	FileInfo GetFileInfo(std::string xmlfile, unsigned int iterOfFile); //Get FileInfo filed structure
private:
	virtual void SetFileInfoAttribute(tinyxml2::XMLElement* el, FileInfo& fi) const; //Set the FileInfo fields
private:
	tinyxml2::XMLDocument* Document; //Just a pointer to XMLDocument object that will be used as XML functional
};

