#undef UNICODE
#include <windows.h>
#include <iostream>
#include <string>

int main() {
  // Structures to hold process and thread information
  STARTUPINFO         si;
  PROCESS_INFORMATION pi;

  // Initialize the structures
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);  // Set the size of the structure
  ZeroMemory(&pi, sizeof(pi));

  // Command line for the process to create
  // Must be writable
  char cmdLine[] = "cmd.exe /c dir";

  // CreateProcess() arguments:
  // 1. Application name (optional)
  // 2. Command line (optional if application name is provided)
  // 3. Process security attributes (NULL for default)
  // 4. Thread security attributes (NULL for default)
  // 5. Inherit handles flag
  // 6. Creation flags
  // 7. Environment block (NULL to use parent's)
  // 8. Current directory (NULL to use parent's)
  // 9. STARTUPINFO structure
  // 10. PROCESS_INFORMATION structure to receive process info
  BOOL success = CreateProcess(NULL,     // No application name (use command line)
                               cmdLine,  // Command line
                               NULL,     // Process security attributes
                               NULL,     // Thread security attributes
                               FALSE,    // Don't inherit handles
                               0,        // No creation flags
                               NULL,     // Use parent's environment
                               NULL,     // Use parent's current directory
                               &si,      // STARTUPINFO
                               &pi       // PROCESS_INFORMATION
  );

  if (!success) {
    std::cerr << "CreateProcess failed. Error code: " << GetLastError() << std::endl;
    return 1;
  }

  std::cout << "Process created with ID: " << pi.dwProcessId << std::endl;
  std::cout << "Main thread ID: " << pi.dwThreadId << std::endl;

  // Wait for the process to complete
  // WaitForSingleObject() arguments:
  // 1. Handle to wait for
  // 2. Timeout in milliseconds (INFINITE = wait indefinitely)
  WaitForSingleObject(pi.hProcess, INFINITE);

  // Get the exit code
  DWORD exitCode;
  if (GetExitCodeProcess(pi.hProcess, &exitCode)) {
    std::cout << "Process exited with code: " << exitCode << std::endl;
  } else {
    std::cerr << "GetExitCodeProcess failed. Error code: " << GetLastError() << std::endl;
  }

  // Close process and thread handles
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

  char cmdLine2[] = "notepad.exe";

  if (!CreateProcess(NULL, cmdLine2, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
    std::cerr << "CreateProcess failed. Error: " << GetLastError() << std::endl;
    return 1;
  }

  std::cout << "Process created with ID: " << pi.dwProcessId << std::endl;

  // Wait for 3 seconds
  Sleep(3000);

  // Terminate the process
  // TerminateProcess() arguments:
  // 1. Handle to the process
  // 2. Exit code to set
  std::cout << "Terminating process..." << std::endl;
  if (!TerminateProcess(pi.hProcess, 1)) {
    std::cerr << "TerminateProcess failed. Error: " << GetLastError() << std::endl;
  }

  // Wait for process to actually terminate
  WaitForSingleObject(pi.hProcess, INFINITE);

  // Get exit code
  if (GetExitCodeProcess(pi.hProcess, &exitCode)) {
    std::cout << "Process exited with code: " << exitCode << std::endl;
  }

  // Close handles
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

  return 0;
}