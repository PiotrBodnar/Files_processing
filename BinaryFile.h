#pragma once
#include <fstream>
#include <vector>
#include "IFile.h"
#include "Point.h"
#include "FileError.h"

class BinaryFile : public IFile
{
public:
	BinaryFile(const std::string, const std::string);
	~BinaryFile();

	IFile::Error Write(const std::vector<Point>&) override;
	IFile::Error Read(std::vector<Point>&) override;
	IFile::Error Read(Point&, const unsigned long) override;
};

