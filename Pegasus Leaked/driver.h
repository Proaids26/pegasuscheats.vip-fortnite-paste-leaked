#pragma once
#include "test/utils.h"
#include "test/encrpyt.h"
#include "driver.hpp"
#include "driver_structs.hpp"
#include "process.hpp"
#include <tchar.h>


std::mutex isuse;

class Driver
{
public:
	UINT ProcessId;
	
	const bool Init(const BOOL PhysicalMode) {
		this->bPhysicalMode = PhysicalMode;
		this->hDriver = CreateFileA((E("\\\\.\\\PEAuth")), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
		if (this->hDriver != INVALID_HANDLE_VALUE) {
			if (this->SharedBuffer = VirtualAlloc(0, sizeof(REQUEST_DATA), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE)) {
				UNICODE_STRING RegPath = RTL_CONSTANT_STRING(L"\\Registry\\Machine\\SOFTWARE\\ucflash");
				if (!RegistryUtils::WriteRegistry(RegPath, RTL_CONSTANT_STRING(L"xxx"), &this->SharedBuffer, REG_QWORD, 8)) {
					return false;
				}
				PVOID dwpid = (PVOID)GetCurrentProcessId();
				if (!RegistryUtils::WriteRegistry(RegPath, RTL_CONSTANT_STRING(L"xx"), &dwpid, REG_QWORD, 8)) {
					return false;
				}
				auto OLD_MAGGICCODE = this->MAGGICCODE;
				SendRequest(8999, 0);
				if (this->MAGGICCODE == OLD_MAGGICCODE)
					this->MAGGICCODE = (ULONG64)RegistryUtils::ReadRegistry<LONG64>(RegPath, RTL_CONSTANT_STRING(L"xxxx"));
				return true;
			}
		}
		return false;



	}

	const NTSTATUS SendRequest(const UINT type, const PVOID args) {
		std::scoped_lock lock(isuse);
		REQUEST_DATA req;
		NTSTATUS status;
		req.MaggicCode = &this->MAGGICCODE;
		req.Type = type;
		req.Arguments = args;
		req.Status = &status;
		memcpy(this->SharedBuffer, &req, sizeof(REQUEST_DATA));
		FlushFileBuffers(this->hDriver);
		return status;
	}

	NTSTATUS ReadProcessMemory(uint64_t src, void* dest, uint32_t size) {
		REQUEST_READ req;
		req.ProcessId = ProcessId;
		req.Src = src;
		req.Dest = dest;
		req.Size = size;
		req.bPhysicalMem = bPhysicalMode;
		return SendRequest(REQUEST_TYPE::READ, &req);
	}
	NTSTATUS WriteProcessMemory(PVOID src, PVOID dest, DWORD size) {
		REQUEST_WRITE req;
		req.ProcessId = ProcessId;
		req.Src = src;
		req.Dest = dest;
		req.Size = size;
		req.bPhysicalMem = bPhysicalMode;
		return SendRequest(REQUEST_TYPE::WRITE, &req);
	}

	const UINT GetProcessThreadNumByID(DWORD dwPID)
	{
		HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hProcessSnap == INVALID_HANDLE_VALUE) {
			return 0;
		}

		PROCESSENTRY32 pe32 = { 0 };
		pe32.dwSize = sizeof(pe32);

		BOOL bRet = Process32First(hProcessSnap, &pe32);

		while (bRet)
		{
			if (pe32.th32ProcessID == dwPID)
			{
				CloseHandle(hProcessSnap);

				return pe32.cntThreads;
			}

			bRet = Process32Next(hProcessSnap, &pe32);
		}

		return 0;
	}

	const UINT GetProcessId(const wchar_t* process_name) {
		DWORD dwRet = 0, dwThreadCountMax = 0;

		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);

		Process32First(hSnapshot, &pe32);

		do
		{
			if (_tcsicmp(pe32.szExeFile, process_name) == 0)

			{
				DWORD dwTmpThreadCount = GetProcessThreadNumByID(pe32.th32ProcessID);

				if (dwTmpThreadCount > dwThreadCountMax)
				{
					dwThreadCountMax = dwTmpThreadCount;
					dwRet = pe32.th32ProcessID;
				}
			}
		} while (Process32Next(hSnapshot, &pe32));

		CloseHandle(hSnapshot);

		return dwRet;
	}

	const bool Attach(const wchar_t* Processname, const wchar_t* Classname = 0) {
		if (Classname) {
			while (!FindWindowW(Classname, 0)) { Sleep(50); }
		}
		if (this->ProcessId = this->GetProcessId(Processname))
			return true;
		return false;
	}

	const uint64_t GetModuleBase(const wchar_t* ModuleName = 0) {
		if (bPhysicalMode) {
			REQUEST_MAINBASE req;
			uint64_t base = NULL;
			req.ProcessId = ProcessId;
			req.OutAddress = (PBYTE*)&base;
			SendRequest(REQUEST_TYPE::MAINBASE, &req);
			return { base };
		}
		else {
			if (!ModuleName)
				return { 0 };
			REQUEST_MODULE req;
			uint64_t base = NULL;
			DWORD size = NULL;
			req.ProcessId = ProcessId;
			req.OutAddress = (PBYTE*)&base;
			req.OutSize = &size;
			wcscpy_s(req.Module, sizeof(req.Module) / sizeof(req.Module[0]), ModuleName);
			SendRequest(REQUEST_TYPE::MODULE, &req);
			return { base };
		}
	}


private:
	PVOID SharedBuffer;
	HANDLE hDriver;
	ULONG64 MAGGICCODE = 0x59002360218c1e2dul;
	BOOL bPhysicalMode = TRUE;
	typedef enum _REQUEST_TYPE : UINT {
		WRITE,
		READ,
		PROTECT,
		ALLOC,
		FREE,
		MODULE,
		MAINBASE,
		THREADCALL,
	} REQUEST_TYPE;

	typedef struct _REQUEST_DATA {
		ULONG64* MaggicCode;
		UINT Type;
		PVOID Arguments;
		NTSTATUS* Status;
	} REQUEST_DATA, * PREQUEST_DATA;

	typedef struct _REQUEST_WRITE {
		DWORD ProcessId;
		PVOID Dest;
		PVOID Src;
		DWORD Size;
		BOOL bPhysicalMem;
	} REQUEST_WRITE, * PREQUEST_WRITE;

	typedef struct _REQUEST_READ {
		DWORD ProcessId;
		void* Dest;
		uint64_t Src;
		uint32_t Size;
		BOOL bPhysicalMem;
	} REQUEST_READ, * PREQUEST_READ;

	typedef struct _REQUEST_PROTECT {
		DWORD ProcessId;
		PVOID Address;
		DWORD Size;
		PDWORD InOutProtect;
	} REQUEST_PROTECT, * PREQUEST_PROTECT;

	typedef struct _REQUEST_ALLOC {
		DWORD ProcessId;
		PVOID OutAddress;
		DWORD Size;
		DWORD Protect;
	} REQUEST_ALLOC, * PREQUEST_ALLOC;

	typedef struct _REQUEST_FREE {
		DWORD ProcessId;
		PVOID Address;
	} REQUEST_FREE, * PREQUEST_FREE;

	typedef struct _REQUEST_MODULE {
		DWORD ProcessId;
		WCHAR Module[0xFF];
		PBYTE* OutAddress;
		DWORD* OutSize;
	} REQUEST_MODULE, * PREQUEST_MODULE;

	typedef struct _REQUEST_MAINBASE {
		DWORD ProcessId;
		PBYTE* OutAddress;
	} REQUEST_MAINBASE, * PREQUEST_MAINBASE;

	typedef struct _KERNEL_COPY_REQUEST {
		ULONG ProcessId;
		PVOID Destination;
		PVOID Source;
		SIZE_T Size;
	} KERNEL_COPY_REQUEST, * PKERNEL_COPY_REQUEST;



};

static Driver* driver = new Driver;

template <typename T>
T read(const uintptr_t address)
{
	T buffer{ };
	driver->ReadProcessMemory(address, &buffer, sizeof(T));
	return buffer;
}
template <typename T>
T write(const uintptr_t address, T buffer)
{
	driver->WriteProcessMemory((PVOID)&buffer, (PVOID)address, sizeof(T));
	return buffer;
}
std::string readwtf(uintptr_t Address, void* Buffer, SIZE_T Size)
{
	driver->ReadProcessMemory(Address, Buffer, Size);

	char name[255] = { 0 };
	memcpy(&name, Buffer, Size);

	return std::string(name);
}
uint64_t ReadChain(uint64_t base, const std::vector<uint64_t>& offsets) {
	uint64_t result = read<uint64_t>(base + offsets.at(0));
	for (int i = 1; i < offsets.size(); i++) {
		result = read<uint64_t>(result + offsets.at(i));
	}
	return result;
}

std::uintptr_t scan_pattern(const char* sig, const char* mask)
{
	auto buffer = std::make_unique<std::array<std::uint8_t, 0x100000>>();
	auto data = buffer.get()->data();

	for (std::uintptr_t i = 0u; i < (2u << 25u); ++i)
	{
		ReadRaw(GetProcessBase() + i * 0x100000, data, 0x100000);

		if (!data)
			return 0;

		for (std::uintptr_t j = 0; j < 0x100000u; ++j)
		{
			if ([](std::uint8_t const* data, std::uint8_t const* sig, char const* mask)
				{
					for (; *mask; ++mask, ++data, ++sig)
					{
						if (*mask == 'x' && *data != *sig) return false;
					}
					return (*mask) == 0;
				}(data + j, (std::uint8_t*)sig, mask))
			{
				std::uintptr_t result = GetProcessBase() + i * 0x100000 + j;
				std::uint32_t rel = 0;

				ReadRaw(result + 3, &rel, sizeof(std::uint32_t));

				if (!rel)
					return 0;

				return result + rel + 7;
			}
		}
	}

	return 0;
}


void PathSystemObBlock()
{
	BYTE pattern[] = { 0x84, 0x00, 0x00, 0x00, 0x00, 0x49, 0x8B, 0x4E, 0x00, 0x48, 0x85, 0xC9, 0x0F, 0x85 };
	BYTE mask[] = { 'c', '?', '?', '?', '?', 'c', 'c', 'c', '?', 'c', 'c', 'c', 'c', 'c',0 };
}

bool Cleaner() {
	BYTE buffer[26] = { 'i', 0x00, 'q', 0x00, 'v', 0x00, 'w', 0x00, '6', 0x00, '4', 0x00, 'e', 0x00, '.', 0x00, 's', 0x00, 'y', 0x00, 's', 0x00, 0x00, 0x00, 0x00, 0x00 };
	UNICODE_STRING intelDrv;
	RtlInitUnicodeString(&intelDrv, (PCWSTR)buffer);// L"iqvw64e.sys");  << if you modify your kdmapper driver name modify this buffer too!!!!!!!!
}

typedef struct _REQUEST_MODULE {
	DWORD ProcessId;
	WCHAR Module[0xB9];
	PBYTE* OutAddress;
	DWORD* OutSize;
} REQUEST_MODULE, * PREQUEST_MODULE;


BYTE orig[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

BYTE shell_code[] = { 0xFF, 0x4F }; // mov rax, xxx
BYTE shell_code_end[] = { 0xDA, 0xEC }; //jmp rax
BYTE InjectBytes[] = { 0x90, 0x48, 0xB8, 0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE, 0xFF, 0xE0 };
SIZE_T bytes = 0;

