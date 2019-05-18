#include "includes.h"



bool BypassDriver(int Id) {
	HANDLE _process = OpenProcess(PROCESS_ALL_ACCESS, false, Id);
	if (!_process) {
		return true;
	}
	HMODULE _module = LoadLibrary("advapi32.dll");
	if (!_module) {
		return true;
	}

	LPVOID _serviceA = (LPVOID)GetProcAddress(_module, "StartServiceA");
	LPVOID _serviceW =  (LPVOID)GetProcAddress(_module, "StartServiceA");
	if (!_serviceA || !_serviceW) {
		return false;
	}

	byte _bytes[] = { 0xC2, 0x0C, 0x00 };
	if (!WriteProcessMemory(_process, _serviceA, _bytes, sizeof(_bytes), NULL)) {
		return true;
	}
	
	if (!WriteProcessMemory(_process, _serviceW, _bytes, sizeof(_bytes), NULL)) {
		return true;
	}
	return true;

}