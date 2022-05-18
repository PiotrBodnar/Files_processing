#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "IFile.h"
#include "Point.h"
#include "FileError.h"

class CsvFile  : public IFile
{
public:
	CsvFile(const std::string, const std::string);
	~CsvFile();

	IFile::Error Write(const std::vector<Point>&) override;
	IFile::Error Read(std::vector<Point>&) override;
	IFile::Error Read(Point&, const unsigned long) override;
};
