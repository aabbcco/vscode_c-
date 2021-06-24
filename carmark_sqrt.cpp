#include<iostream>
#include<cmath>

using namespace std;

const u_int32_t magic_digit = 0x5f3759df;

union conb_32
{
    uint32_t    ints;
    float floats;
};

float carmark_invsqrt(float x)
{
    float xhalf = 0.5f * x;
    conb_32 xx;
    xx.floats = x;
    xx.ints = magic_digit - (xx.ints >> 1);
    return xx.floats * (1.5f - xhalf * xx.floats * xx.floats);
}


int main()
{
    float x = 114514;
    std::cout <<"normal:\t"<< 1.0f / sqrtf32(x)<<"\ncarmark:" << carmark_invsqrt(x) << endl;
}