
// You must create a communication program in the form of a client and a server.


So understanding this task is all about understanding Process IDs and Signals, which are sent using the kill command.
We can ONLY use SIGUSR1 and SIGUSR2.

so we will use
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

And (STATIC vs GLOBAL) so you really want to know static vars. are block only, global are for whole .c file.


// ◦ write
// ◦ ft_printf and any equivalent YOU coded ◦ signal

// ◦ sigemptyset  |  int sigemptyset(sigset_t *set); Explanation: Initializes an empty signal set.
// ◦ sigaddset  |  int sigaddset(sigset_t *set, int signum); Explanation: Adds the specified signal to the signal set.
// ◦ sigaction  |  int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact); Explanation: Examines and changes the action to be taken when a specified signal is delivered.
// ◦ kill  |  int kill(pid_t pid, int sig); Explanation: Sends a signal to a process or a group of processes.
// ◦ getpid  |  pid_t getpid(void); Explanation: Returns the process ID of the calling process.
<!-- // ◦ malloc  -->
<!-- // ◦ free -->
// ◦ pause  |  int pause(void); Explanation: Causes the calling process to sleep until a signal is received.
// ◦ sleep  |  sleep(unsigned int seconds); Explanation: Suspends the execution of the calling thread for a specified number of seconds.
// ◦ usleep  | int usleep(useconds_t usec); Explanation: Suspends the execution of the calling thread for a specified number of microseconds.
// ◦ exit  |   exit(int status); Explanation: Terminates the calling process with the specified exit status.


1. • The server must be started first. After its launch, it has to print its PID.
2.   The client takes two parameters:
		◦ The server PID.  (PROCESS ID)
		◦ The string to send.
3. • The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
4.   The server has to display the string pretty quickly.
5.   Your server should be able to receive strings from several clients in a row without needing to restart.
6.   The communication between your client and your server has to be done only using UNIX signals.
		more precisely:
		SIGUSR1 and SIGUSR2.  (USER SIGNAL 1   &&    USER SIGNAL 2)


Bonus list:
• The server acknowledges every message received by sending back a signal to the client.
• Unicode characters support!





- `int sigemptyset(sigset_t *set);`
- `int sigaddset(sigset_t *set, int signum);`
- `int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);`
- `int kill(pid_t pid, int sig);`
- `pid_t getpid(void);`
- `int pause(void);`
- `unsigned int sleep(unsigned int seconds);`
- `int usleep(useconds_t usec);`
- `void exit(int status);`



----

### Mandatory

- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**

### Bonus

- Add reception acknowledgement system
- Support Unicode characters

### Allowed Functions

- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)
- [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)
- [`sigemptyset & sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)
- [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)
- [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)
- [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)
- [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)
