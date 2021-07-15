#include <iostream>
#include "FileHandler.h"

void FileHandler::CopyFile(FileInfo& fi) const
{
    setlocale(LC_ALL, "Russian"); //Was set, becouse error code did not shows correctly
    try
    {
        //Call a method from std::filesystem to copy the file
        std::filesystem::copy_file(fi.soucePath+char(92)+ fi.fileName, fi.destinationPath + char(92) + fi.fileName, std::filesystem::copy_options::overwrite_existing);
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        // In case of an error
        std::cerr <<"Filesystem error while coping a file: "<< e.what()<<std::endl;
    }
}
