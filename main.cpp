

#include <fstream>
#include <cstdint>
#include <bitset>
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <WinUser.h>
#include <thread>
#include <chrono>
#include <string>
#include <functional>
#include <vector>
#include <array>
#include <iterator>
#include <TlHelp32.h>
#include <tchar.h>
#include <dinput.h>
#include <CommCtrl.h>
#include <random>
#include <algorithm>
#include <cctype>
#include <atomic>
#include <mutex>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <cmath>


int main(int argc, char* argv[])
{
	srand(time(NULL));
	int random = rand();
	std::string arg = argv[1];
	std::ifstream sFile(arg, std::ios::binary | std::ios::ate);
	DWORD size = sFile.tellg();

	BYTE* buffer = (BYTE*)malloc(size);
	sFile.seekg(0, std::ios::beg);
	sFile.read((char*)buffer, size);
	sFile.close();

	PIMAGE_NT_HEADERS pNT = (PIMAGE_NT_HEADERS)(buffer + ((PIMAGE_DOS_HEADER)buffer)->e_lfanew);
	pNT->FileHeader.TimeDateStamp = random;

	//Write to file
	std::ofstream file_ofstream(arg, std::ios_base::out | std::ios_base::binary);
	file_ofstream.write((char*)buffer, size);
	file_ofstream.close();

}