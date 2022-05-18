#include "CsvFile.h"
#include <vector>
#include <string>


CsvFile::CsvFile(const std::string filePath, const std::string mode) : IFile(filePath, mode)
{

}

CsvFile::~CsvFile()
{
	
}

void LineToPoint(const std::string str, Point& p)
{
	std::string word = "";
	int flag = 0;
	for (auto x : str)
	{
		if (x == ',' || x == ';')
		{
			switch (flag)
			{
			case 0:
				p.x = ::atof(word.c_str());
				flag++;
				break;
			case 1:
				p.y = ::atof(word.c_str());
				flag++;
				break;
			}

			word = "";
		}
		else {
			word = word + x;

			if (flag == 2)
			{
				p.z = ::atof(word.c_str());
			}
		}
	}
}

IFile::Error CsvFile::Write(const std::vector<Point>& v)
{  
	IFile::Error retVal = IFile::Error(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = IFile::Error(FILE_INVALID);
	}
	else if (openMode & std::fstream::out)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (i == 0)
			{
				file << v[i].x << ";" << v[i].y << ";" << v[i].z;
			}
			else
			{
				file << std::endl << v[i].x << ";" << v[i].y << ";" << v[i].z;
			}
			
		}

		retVal = IFile::Error(SUCCESS);
	}
	 
	return retVal;
}

IFile::Error CsvFile::Read(std::vector<Point>& v)
{
	IFile::Error retVal = IFile::Error(ACCESS_DENIED);

	if (!file.is_open())
	{
		retVal = IFile::Error(FILE_INVALID);
	}
	else if (openMode & std::fstream::in)
	{
		file.clear();
		file.seekg(0, std::fstream::beg);

		std::string s;
		int lineTotal = 0;

		while (!file.eof()) {
			std::getline(file, s);
			lineTotal++;
		}

		file.clear();
		file.seekg(0, std::fstream::beg);

		v.clear();
		v.resize(lineTotal);

		int i = 0;

		while (!file.eof()) {
			std::getline(file, s);
			LineToPoint(s, v[i]);
			i++;
		}

		retVal = IFile::Error(SUCCESS);
	}

	return retVal;
}


IFile::Error CsvFile::Read(Point & p, const unsigned long idx)
{
	IFile::Error retVal = IFile::Error(ACCESS_DENIED);

	file.clear();
	file.seekg(0, std::fstream::beg);

	std::string s;
	int lineTotal = 0;

	while (!file.eof()) {
		std::getline(file, s);
		lineTotal++;
	}

	file.clear();
	file.seekg(0, std::fstream::beg);

	if (!file.is_open())
	{
		retVal = IFile::Error(FILE_INVALID);
	}
	else if (idx >= lineTotal)
	{
		retVal = IFile::Error(OUT_OF_BOUNDS);
	}
	else if (openMode & std::fstream::in)
	{
		int line_no = 0;
		std::string sLine = "";
		while (line_no != (idx+1) && std::getline(file, sLine)) {
			++line_no;
		}

		if (line_no == (idx+1)) {
			LineToPoint(sLine, p);
		}

		retVal = IFile::Error(SUCCESS);
	}

	return retVal;
}
