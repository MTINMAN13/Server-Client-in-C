

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
		return 1;
	}

	pid_t serverPID = atoi(argv[1]);

	// pid_t is a data type used to represent process IDs (PIDs). It stands for "process ID type."

	// Register the signal handler for SIGUSR1
	signal(SIGUSR1, reloadConfig);

	// Send SIGUSR1 to the specified process
	if (kill(serverPID, 0) == 0) {
		printf("Sending SIGUSR1 to process %d\n", serverPID);
		kill(serverPID, SIGUSR1);
	} else {
		fprintf(stderr, "Error: Process with PID %d not found.\n", serverPID);
		return 1;
	}

	return 0;
}
