#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdlib.h>

// Simple XOR encryption key
#define ENCRYPTION_KEY 0xAA
#define PAGE_SIZE 4096

// Encrypted flag (just an example)
unsigned char encrypted_flag[] = { 
    0xAB, 0xC9, 0xC8, 0xC8, 0xC1, 0xAA, 0xAF, 0xC1, 
    0xC1, 0xA8, 0xAA, 0x00  // Encoded "flag{test_flag}"
};

// Function to decrypt the flag in memory
void decrypt_flag(char* flag, size_t length) {
    for (size_t i = 0; i < length; i++) {
        flag[i] ^= ENCRYPTION_KEY;
    }
}

// Function to detect if a debugger is present
int is_debugger_present() {
    // ptrace is used to check if a debugger is attached
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
        return 1; // Debugger is present
    }
    return 0; // No debugger
}

// Function to check execution time
void timing_check() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Simulate a short delay (normally less than 1 second)
    for (volatile long i = 0; i < 100000000; i++);  // Busy wait

    gettimeofday(&end, NULL);
    long elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    
    // If execution takes longer than 1 second, behave differently
    if (elapsed_time > 1000000) { // 1 second in microseconds
        printf("Execution too slow! Possible debugging detected.\n");
        exit(1);
    }
}

// Custom VM to execute operations
void custom_vm_execute() {
    // Simulated instructions for VM (in this case, decrypting and printing the flag)
    printf("Executing VM logic...\n");
    
    // Decrypt the flag inside the VM
    decrypt_flag((char*)encrypted_flag, strlen((char*)encrypted_flag));
    printf("Decrypted flag: %s\n", encrypted_flag);
}

int main() {
    // Check for debugger presence
    if (is_debugger_present()) {
        printf("Debugger detected! Exiting...\n");
        return 1;
    }

    // Step 1: Allocate executable memory for self-modifying code
    char *code = (char *)mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (code == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Step 2: Write initial code into the memory (simple print statement)
    unsigned char initial_code[] = {
        0x48, 0x31, 0xC0,  // xor rax, rax
        0xB8, 0x01, 0x00, 0x00, 0x00,  // mov eax, 1 (syscall: write)
        0xBF, 0x01, 0x00, 0x00, 0x00,  // mov edi, 1 (stdout)
        0x48, 0xBE, 'H', 'e', 'l', 'l', 'o', '\n', 0x00, 0x00,  // movabs rsi, "Hello\n"
        0xBA, 0x06, 0x00, 0x00, 0x00,  // mov edx, 6 (length)
        0x0F, 0x05,  // syscall
        0xC3  // ret
    };
    
    // Copy code to the executable memory
    memcpy(code, initial_code, sizeof(initial_code));

    // Step 3: Execute the initial code ("Hello" message)
    ((void(*)())code)();

    // Step 4: Modify the code in runtime (change "Hello" to "Bye")
    code[11] = 'B';
    code[12] = 'y';
    code[13] = 'e';

    // Timing check before executing modified code
    timing_check();

    // Execute the modified code ("Bye" message)
    ((void(*)())code)();

    // Step 5: Execute custom VM logic
    custom_vm_execute();

    // Clean up
    munmap(code, PAGE_SIZE);
    
    return 0;
}
