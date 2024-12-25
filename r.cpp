#include <Windows.h>
#include <iostream>

// Copied from defs.h in the hexray sdk
template<class T> T __ROL__(T value, int count)
{
    const UINT nbits = sizeof(T) * 8;

    if (count > 0)
    {
        count %= nbits;
        T high = value >> (nbits - count);
        if (T(-1) < 0)
            high &= ~((T(-1) << count));
        value <<= count;
        value |= high;
    }
    else
    {
        count = -count % nbits;
        T low = value << (nbits - count);
        value >>= count;
        value |= low;
    }
    return value;
}

inline UINT8  __ROL1__(UINT8  value, int count) { return __ROL__((UINT8)value, count); }
inline UINT8  __ROR1__(UINT8  value, int count) { return __ROL__((UINT8)value, -count); }

// you can prob improve this code but it works so I am just going to leave it
std::string encrypt(std::string strInput) {
    std::string result = strInput;
    int order[] = { 1, 3, 4, 2, 1, 3, 2, 1, 2, 1, 3, 2, 3, 4, 2, 3 };
    int length = strInput.length();
    int mainI = 0;
    int v4 = 0;

    while (2) {
        switch (order[mainI]) {
        case 1:
            v4 = 0;
            for (; v4 < length; ++v4) {
                result[v4] ^= 0x54u;
            }
            break;
        case 2:
            v4 = 0;
            for (; v4 < length; ++v4) {
                result[v4] ^= 0x24u;
            }
            break;
        case 3:
            for (int i = 0; i < length; ++i) {
                result[i] = __ROL1__(result[i], 2);
            }
            break;
        case 4:
            for (int j = 0; j < length; ++j) {
                result[j] -= 21;
            }
            break;
        }
        if (++mainI >= 16) {
            return result;
        }
        continue;
    }
}

std::string decrypt(std::string strInput) {
    std::string result = strInput;
    int order[] = { 1, 3, 4, 2, 1, 3, 2, 1, 2, 1, 3, 2, 3, 4, 2, 3 };
    int length = strInput.length();
    int mainI = 0;
    int v4 = 0;

    while (2) {
        switch (order[16 - (mainI + 1)]) {
        case 1:
            v4 = 0;
            for (; v4 < length; ++v4) {
                result[v4] ^= 0x54u;
            }
            break;
        case 2:
            v4 = 0;
            for (; v4 < length; ++v4) {
                result[v4] ^= 0x24u;
            }
            break;
        case 3:
            for (int i = 0; i < length; ++i) {
                result[i] = __ROR1__(result[i], 2);
            }
            break;
        case 4:
            for (int j = 0; j < length; ++j) {
                result[j] += 21;
            }
            break;
        }
        if (++mainI >= 16) {
            return result;
        }
        continue;
    }
}



int main()
{
    std::string encrypted = encrypt("normal");
    std::cout << "the string \"normal\" encrypted: " << encrypted << "\n";
    std::string decrypted = decrypt(encrypted);
    std::cout << "the string \"" << encrypted << "\" decrypted: " << decrypted << "\n";
}