// #undef UNICODE
#define UNICODE
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <windows.h>
#include <iostream>
wchar_t* ConvertCharToWChar(const char* charStr) {
  // Only in pure Windows, Visual studio?
  int      sizeNeeded = MultiByteToWideChar(CP_UTF8, 0, charStr, -1, NULL, 0);
  wchar_t* wStr       = new wchar_t[sizeNeeded];  // Allocate memory
  MultiByteToWideChar(CP_UTF8, 0, charStr, -1, wStr, sizeNeeded);
  return wStr;  // Remember to delete[] when done
}
constexpr int buffsize = 100;

int main(void) {
#ifndef _WIN32
  // Linux
  int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  // O_RDONLY/O_WRONLY
  // O_RDWR readwrite
  // O_CREAT create if does not exist
  // O_TRUNC overwrite
  // O_APPEND append
  if (fd == -1) {
    perror("open");
    return 1;
  }
  const char* msg = "Hello, Low-Level I/O!\n";
  write(fd, msg, strlen(msg));
  lseek(fd, 5, SEEK_SET);  // Move to the 5th byte

  // SEEK_SET from start
  // SEEK_CUR from current
  // SEEK_END from end
  write(fd, "XYZ", 3);  // Overwrite next 3 bytes
  close(fd);
  char* buffer = static_cast<char*>(malloc(buffsize));
  fd           = open("example.txt", O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }
  ssize_t bytesRead = read(fd, buffer, buffsize);
  if (bytesRead == -1) {
    perror("read");
  } else {
    buffer[bytesRead] = '\0';
    std::cout << "Read: " << buffer;
  }
  std::cout << "File descriptor: " << fd << std::endl;
  close(fd);
  free(buffer);
#else
  const WCHAR* bufff;
  HANDLE       hFile = CreateFile(ConvertCharToWChar("example.txt"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
  if (hFile == INVALID_HANDLE_VALUE) {
    std::cerr << "Failed to open file." << std::endl;
    return 1;
  }

  OVERLAPPED overlapped  = { 0 };
  char       buffer[100] = { 0 };
  DWORD      bytesRead;

  BOOL result = ReadFile(hFile, buffer, sizeof(buffer) - 1, &bytesRead, &overlapped);

  if (!result && GetLastError() == ERROR_IO_PENDING) {
    // The read is in progress, and we can continue doing other work
    std::cout << "Reading file in non-blocking mode..." << std::endl;
    Sleep(100);  // Simulate doing something else while waiting
    GetOverlappedResult(hFile, &overlapped, &bytesRead, TRUE);
  }

  std::cout << "Read: " << buffer << std::endl;
  CloseHandle(hFile);
#endif
  return 0;
}