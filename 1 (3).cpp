#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

unsigned char VM[200] = { 0x01,0x6D,0x65,0x6F,0x77,0x07,0x02,0x03,0x61,0x72,
0x63,0x68,0x07,0x04,0x1C,0x01,0x69,0x6E,0x63,0x6F,0x72,0x72,0x65,0x63,0x74,0x07,0x05,0x25,0x01,0x63,0x6F,0x72,
0x72,0x65,0x63,0x74,0x07,0x06,0xFF,0x9 };


int main() 
{
    setlocale(LC_ALL, "ru");
    int index=0;
    int addr = 0;
    char buffer[255];
    int b = 0;

    while (VM[index] != 0x9)
    {
        b = 0;
        switch (VM[index])
        {
        case 0x1:
            index++;            
            while (VM[index] != 0x7)
            {
                buffer[b] = VM[index];
                b++;
                index++;
                buffer[b] = 0;
            }
            printf("address = %X  command = %X  copying string '%s' from bytes of VM to stack and output it on screen\n", addr, VM[addr], buffer);
            index++;
            addr = index;
            break;
        case 0x2:
            index++;
            printf("address = %X   command = %X This command output to screen string 'enter:', and waiting our input from console\n", addr, VM[addr]);
            addr = index;
            break;
        case 0x3:
            index++;
            while (VM[index] != 0x7)
            {
                buffer[b] = VM[index];
                b++;
                index++;
                buffer[b] = 0;
            }
            printf("address = %X command = %X copying string '%s' from bytes of VM to memory\n", addr, VM[addr], buffer);
            index++;
            addr = index;
            break;
        case 0x4:
            index++;
            printf("address %X command = %X This command it is conditional jump, if string entered from console equal to bytes after command 0x3 next command will be at address %X\n", addr, VM[addr], VM[index]);
            addr = VM[index];
            index=addr;
            break;
        case 0x6:
            index++;
            printf("address %X command = %X This command make output to screen string 'press any key to exit.' and waiting our input.\n", addr, VM[addr]);
            addr = index;
            break;
        case 0xff:
            index++;
            printf("address %X command = %X This command just termingating this VM\n", addr, VM[addr]);
            break;
        }    
    }
}