#include "XMLReader.h"

XMLReader::XMLReader()
{
	// Create new XMLDocument object
	Document = new tinyxml2::XMLDocument();
}

XMLReader::~XMLReader()
{
	// On the destructor we just delete Document and free the memory
	if (Document)
	{
		delete Document;
	}
}

FileInfo XMLReader::GetFileInfo(std::string xmlfile, unsigned int iterOfFile)
{
	FileInfo fi; //Create FileInfo varible

	Document->LoadFile(xmlfile.c_str()); //Load the xml file
	tinyxml2::XMLElement* el = Document->FirstChildElement("config"); //Get root element

	if (el) //If root element exists
	{
		el = el->FirstChildElement("file"); // Find the first element <file>
		if (iterOfFile > 0) //If we need to find the next ones, then we use this
		{
			for (int i = 0; i < iterOfFile; i++)
			{
				el = el->NextSiblingElement("file");
				if (iterOfFile - i == 1) //This is done in order not to call the function once again when it was not required
				{
					SetFileInfoAttribute(el, fi); // Find the next element
				}
			}
		}
		else
		{
			SetFileInfoAttribute(el, fi); // Set FileInfo fields
		}
	}
	

	return fi;
}

void XMLReader::SetFileInfoAttribute(tinyxml2::XMLElement* el, FileInfo& fi) const
{
	fi.destinationPath = el->Attribute("destination_path"); //Set the "destination_path" in FileInfo
	fi.soucePath	   = el->Attribute("source_path"); //Set the "source_path" in FileInfo
	fi.fileName		   = el->Attribute("file_name"); //Set the "file_name" in FileInfo
}