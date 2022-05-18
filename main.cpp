#include "BinaryFile.h"
#include "CsvFile.h"
#include "FileFactory.h"
#include "IFile.h"
#include "RNG.h"
#include "Point.h"
#include <iostream>
#include <vector>

int main()
{
	/*BinaryFile fileBin("test.bin", "r");
	Point wynik;
	fileBin.Read(wynik, 0);
	std::cout << wynik.x << "\t" << wynik.y << "\t" << wynik.z << std::endl;
	delete &fileBin;

	CsvFile fileCsv("test.csv", "r");
	Point wynik1;
	fileCsv.Read(wynik1, 0);
	std::cout << wynik1.x << "\t" << wynik1.y << "\t" << wynik1.z << std::endl;
	delete &fileCsv;*/



	//--------------------------------------------------------Saving check------------------------------------------------
	/*FileFactory file1;
	IFile* pFileBin = file1.Open("test.bin", "w");
	std::vector<Point> p1;
	p1.push_back(Point());
	p1[0].x = 1;
	p1[0].y = 2;
	p1[0].z = 3;
	p1.push_back(Point());
	p1[1].x = 4;
	p1[1].y = 5;
	p1[1].z = 6;
	pFileBin->Write(p1);
	delete pFileBin;*/

	/*FileFactory file2;
	IFile* pFileCsv = file2.Open("test.csv", "w");
	std::vector<Point> p2;
	p2.push_back(Point());
	p2[0].x = 1;
	p2[0].y = 2;
	p2[0].z = 3;
	p2.push_back(Point());
	p2[1].x = 4;
	p2[1].y = 5;
	p2[1].z = 6;
	pFileCsv->Write(p2);
	delete pFileCsv;*/



	//--------------------------------------------------------Reading check------------------------------------------------
	/*FileFactory file1;
	IFile* pFileBin = file1.Open("test.bin", "r");
	std::vector<Point> p1;
	pFileBin->Read(p1);
	delete pFileBin;*/

	/*FileFactory file2;
	IFile* pFileCsv = file2.Open("test.csv", "r");
	std::vector<Point> p2;
	pFileCsv->Read(p2);
	std::cout << p2[1].x << "\t" << p2[1].y << "\t" << p2[1].z << std::endl;
	delete pFileCsv;*/



	//--------------------------------------------------------Line reading check------------------------------------------------
	FileFactory file1;
	IFile* pFileBin = file1.Open("test.bin", "r");
	Point wynik;
	pFileBin->Read(wynik, 1);
	std::cout << wynik.x << "\t" << wynik.y << "\t" << wynik.z << std::endl;
	delete pFileBin;

	FileFactory file2;
	IFile* pFileCsv = file2.Open("test.csv", "r");
	Point wynik1;
	pFileCsv->Read(wynik1, 1);
	std::cout << wynik1.x << "\t" << wynik1.y << "\t" << wynik1.z << std::endl;
	delete pFileCsv;
}
