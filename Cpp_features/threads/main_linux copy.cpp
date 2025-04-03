#include <spawn.h>
#include <sys/wait.h>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <vector>
int main(void) {
  pid_t pid;

  // Set up arguments for the new process
  // Must be a NULL-terminated array of C strings
  char* argv[] = { const_cast<char*>("ls"), const_cast<char*>("-l"), nullptr };

  // Environment variables for the new process
  // Use current environment
  extern char** environ;

  // File actions and attributes (can be used to set up redirections, etc.)
  posix_spawn_file_actions_t file_actions;
  posix_spawnattr_t          attrs;

  // Initialize file_actions and attrs
  posix_spawn_file_actions_init(&file_actions);
  posix_spawnattr_init(&attrs);

  // posix_spawn() arguments:
  // 1. Pointer to store the PID of the new process
  // 2. Path to the executable
  // 3. File actions (or NULL)
  // 4. Attributes (or NULL)
  // 5. Argument array
  // 6. Environment variables array
  int result = posix_spawn(&pid, "/bin/ls", &file_actions, &attrs, argv, environ);

  // Clean up resources
  posix_spawn_file_actions_destroy(&file_actions);
  posix_spawnattr_destroy(&attrs);

  if (result != 0) {
    std::cerr << "posix_spawn failed: " << strerror(result) << std::endl;
    return 1;
  }

  std::cout << "Created process with PID: " << pid << std::endl;

  // Wait for the child process to complete
  int status;
  if (waitpid(pid, &status, 0) == -1) {
    std::cerr << "waitpid failed: " << strerror(errno) << std::endl;
    return 1;
  }

  if (WIFEXITED(status)) {
    std::cout << "Child exited with status: " << WEXITSTATUS(status) << std::endl;
  }

  return 0;
}