#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

void createProcess(int waitSeconds) {
    pid_t pid = fork();

    if (pid == 0) { 
        sleep(waitSeconds); 
        std::cout << "Process " << waitSeconds << " seconds done.\n";
        _exit(0);
    }
}

int main() {

    createProcess(1);
    createProcess(2);
    createProcess(3);

    while (wait(nullptr) > 0); 

    std::cout << "All processes completed.\n";
    return 0;
}
