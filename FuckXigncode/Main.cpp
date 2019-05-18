#include "includes.h"
#include "Fuctions.h"
#define xingcode 0x00728000 
void Get_proces_id(const char* _proces_Name);
DWORD ProcId = 0;
int i = 1;
int main() {
	int i = 1;
	SetConsoleTitle("FuckXigncode");
	const char* _proces_Name = "OPERATION7.exe";

	Get_proces_id(_proces_Name);
	
	do {
		byte _del[] = {0xB8, 0x01, 0x00, 0x00, 0x00,0x90, 0x90, 0x90,};
		    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 13);	
			HANDLE _process = OpenProcess(PROCESS_ALL_ACCESS, false, ProcId);	
			BypassDriver(ProcId);
			WriteProcessMemory(_process, (LPVOID)xingcode, _del, sizeof(_del), NULL);
		std::cout << "FuckXigncode!\n";
	
		Sleep(500);																							
		system("cls");
	} while (i == 1);

}
void Get_proces_id(const char* _proces_Name) {

	PROCESSENTRY32   pe32;
	HANDLE         hSnapshot = NULL;

	pe32.dwSize = sizeof(PROCESSENTRY32);
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (Process32First(hSnapshot, &pe32))
	{
		do {
			if (strcmp(pe32.szExeFile, _proces_Name) == 0)
				break;
		} while (Process32Next(hSnapshot, &pe32));
	}

	if (hSnapshot != INVALID_HANDLE_VALUE)
		CloseHandle(hSnapshot);

	ProcId = pe32.th32ProcessID;
}