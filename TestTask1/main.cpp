#include <iostream>
#include "XMLReader.h"
#include "FileHandler.h"
//Program for Veeam Software as a test task
//This program using C++ 17 standart
//Author: Ivan Platonov | Ivanplateam@gmail.com

int main()
{
	XMLReader Reader; //Create a XML reader object
	FileHandler Fh; //Create a FileHandler object
	std::string currentPath = std::filesystem::current_path().string(); //Get current directory and convert this to string
	FileInfo fi = Reader.GetFileInfo(currentPath +char(92)+"test.xml", 2); // Get FileInfo filed structure
	Fh.CopyFile(fi); // Call MoveFile function from FileHandler

	system("pause");
}