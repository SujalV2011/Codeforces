#include <iostream>
#include <unistd.h>  // for fork()
using namespace std;

int main() {
    pid_t pid1 = fork();  // First fork
    pid_t pid2 = fork();  // Second fork

    // Optional third fork if both first and second were successful (only in original case)
    if (pid1 > 0 && pid2 > 0) {
        fork(); // Third fork
    }

    cout << "Hello from PID " << getpid() << endl;
    return 0;
}
