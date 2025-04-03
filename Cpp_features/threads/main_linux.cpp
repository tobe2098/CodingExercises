#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>  // for wait() function
#include <unistd.h>    // for fork(), exec() functions
#include <cstring>     // for strerror()
#include <iostream>

// Signal handler function
void signalHandler(int signum) {
  std::cout << "Received signal: " << signum << std::endl;
}
int main(void) {
  // Create a child process
  pid_t pid = fork();

  // Check for errors in fork()
  if (pid < 0) {
    // fork() returns -1 on failure
    std::cerr << "Fork failed: " << strerror(errno) << std::endl;
    return 1;
  }

  if (pid == 0) {
    // This code runs in the child process (fork() returns 0 to the child)
    std::cout << "Child process with PID: " << getpid() << std::endl;

    // Replace the child process with a new program
    // execl() arguments:
    // 1. Path to the executable
    // 2. Argv[0] (convention: program name)
    // 3+ Additional arguments
    // Last argument must be NULL
    execl("/bin/ls", "ls", "-l", nullptr);

    // If execl() returns, it means there was an error
    // (successful execl() never returns)
    std::cerr << "Exec failed: " << strerror(errno) << std::endl;
    return 1;
  } else {
    // This code runs in the parent process
    // fork() returns the PID of the child to the parent
    std::cout << "Parent process with PID: " << getpid() << " created child with PID: " << pid << std::endl;

    // Wait for the child process to complete
    // waitpid() arguments:
    // 1. PID of the process to wait for (-1 for any child)
    // 2. Pointer to store exit status information
    // 3. Options (0 for default behavior)
    int   status;
    pid_t waited_pid = waitpid(pid, &status, 0);

    if (waited_pid == -1) {
      std::cerr << "Wait failed: " << strerror(errno) << std::endl;
      return 1;
    }

    if (WIFEXITED(status)) {
      // WIFEXITED macro checks if the child terminated normally
      // WEXITSTATUS extracts the exit status code
      std::cout << "Child exited with status: " << WEXITSTATUS(status) << std::endl;
    } else if (WIFSIGNALED(status)) {
      // WIFSIGNALED checks if the child was terminated by a signal
      // WTERMSIG extracts the signal number
      std::cout << "Child killed by signal: " << WTERMSIG(status) << std::endl;
    }
  }

  pid_t pid = fork();

  if (pid < 0) {
    std::cerr << "Fork failed" << std::endl;
    return 1;
  }

  if (pid == 0) {
    // Child process
    std::cout << "Child process running with PID: " << getpid() << std::endl;

    // Set up signal handler for SIGUSR1
    // signal() arguments:
    // 1. Signal number to handle
    // 2. Function pointer to handler
    signal(SIGUSR1, signalHandler);

    // Sleep to allow parent time to send signal
    sleep(5);
    std::cout << "Child process exiting" << std::endl;
    return 42;  // Exit with code 42

  } else {
    // Parent process
    std::cout << "Parent process running with PID: " << getpid() << ", child PID: " << pid << std::endl;

    // Send a signal to the child process
    // kill() arguments:
    // 1. PID of the process to signal
    // 2. Signal number to send
    sleep(2);
    std::cout << "Sending SIGUSR1 to child" << std::endl;
    kill(pid, SIGUSR1);

    // Wait for child process to complete
    int status;
    waitpid(pid, &status, 0);

    if (WIFEXITED(status)) {
      std::cout << "Child exited with status: " << WEXITSTATUS(status) << std::endl;
    }
  }

  return 0;
}