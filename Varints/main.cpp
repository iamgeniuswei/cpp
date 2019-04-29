#include <iostream>

using namespace std;



/**
 * @brief encode
 * @param str
 * @return the original int32_t encoded in varints
 */
uint32_t decode(char *str, char *limit, int len)
{
    uint32_t result = 0;
    for (uint32_t shift = 0; shift <= 28 && str < limit; shift += 7)
    {
        uint32_t byte = *(reinterpret_cast<const unsigned char*>(str++));
        if(byte & 128)
        {
            result |= ((byte & 127) << shift);
        }
        else {
            result |= (byte << shift);
        }
    }
    return result;

}

char* encode (char *dst, int src)
{
    const int B = 128;
    char *ptr = dst;
    if( src < (1 << 7))
    {
        *(ptr++) = src;
    }
    else if (src < (1 << 14)) {
        *(ptr++) = src | 128;
        *(ptr++) = src >> 7;
    }
    else if (src < (1 << 21)) {
        *(ptr++) = src | 128;
        *(ptr++) = (src>>7) | 128;
        *(ptr++) = src >> 14;
    }
    else if (src < (1 << 28)) {
        *(ptr++) = src | 128;
        *(ptr++) = (src>>7) | 128;
        *(ptr++) = (src >> 14) | 128;
        *(ptr++) = src >> 21;
    }
    else {
        *(ptr++) = src | 128;
        *(ptr++) = (src>>7) | 128;
        *(ptr++) = (src >> 14) | 128;
        *(ptr++) = (src >> 21) | 128;
        *(ptr++) = src >> 28;
    }
    return  ptr;
}



int main()
{
    cout << "Hello World!" << endl;

    int32_t ori = -1;
    uint32_t m1 = ori << 1;
    uint32_t m2 = ori >> 31;
    uint32_t enc = m1 ^ m2;
    cout << "enc: " << enc << endl;

    char *dst = new char[3];
    memset(dst, 0, 3);
    encode(dst, 300);
//    char *str = new char[2];
//    *str = 172;
//    *(str+1) = 2;
////    char *str = reinterpret_cast<char*>(&test);
    uint32_t ret = decode(dst, dst+2, 2);
    cout << "ret: " << ret << endl;
    return 0;
}
