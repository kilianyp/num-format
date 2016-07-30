#include "float.h"


typedef FloatBase<false, 23, 8> Float;
typedef FloatBase<false, 10, 5> Float16;

int main() {
    Float test1 = 9000.0f;
    Float test2 = 15.3;
    Float test3 = test1 + test2;
    Float test4 = test1 - test2;
    Float test5 = sinf(test1);
    Float test6 = test5 * 300124125123125123.0;
    Float test7 = 20;
    Float test8 = 11024.1521;
    Float test9 = 125125125*164;
    Float test13 = 512987123.59871251908230158912478915;
    Float test10 = 125125125*164;
    float min = 0.0000000000000000000000000000000000000000001;
    Float test14 = min;
    float max = pow(2,128);

    Float test15 = max;
    //test10 = test9;
    //Float test11 = test9;
    Float test12 = test9;
    test7 += sin(25.000) - sqrt(25.00);
    int test_int  = 12;
    Float test16 = test13 * test_int;


    std::cout.precision(15);
    std::cout << 1 << test2 << std::endl;
    std::cout << 2 << test3 << std::endl;
    std::cout << 3 << test4 << std::endl;
    std::cout << 4 << test5 << std::endl;
    std::cout << 5 << test6 << std::endl;
    std::cout << 6 << test1 << std::endl;
    std::cout << 7 << test7 << std::endl;
    std::cout << 8 << test8 << std::endl;
    std::cout << 9 << test9 << std::endl;
    std::cout << 10 << test10 << std::endl;
    //std::cout << test11 << std::endl;
    std::cout << 11 << test13 << std::endl;
    std::cout << 12 << test14 << std::endl;
    printf("%f\n", max);
    std::cout << 13 << test15 << std::endl;
    std::cout << 14 << test16 << std::endl;
    float test18 = 2.001;
    //calls constructor
    Float test17 = 125471205791123;
    //calls cast
    Float16 test19 = test17;
    //calls cast
    Float test20 = test19;
    std::cout << 15 << test17 << std::endl;
    std::cout << 16 << test19 << std::endl;
    std::cout << 17 << test20 << std::endl;
    Float test21 = 14.152f;
    std::cout << 18 << test21++ <<std::endl;
    //calls constructor
    Float test22 = (++test21) * 123.123f * test21;
    std::cout << 19 << test22 << std::endl;
    test22 *= 111238712;
    test22 *= 111231237812638712;
    std::cout << 20 << test22 << std::endl;
    test22 *= 111231237812638712;
    std::cout << 21 << test22 << std::endl;
    Float test23 = test21;
    std::cout << 22 << test23 << std::endl;
    //constructor is called
    //assignment of Numtype is called
    test23 = 12454.0f *  test23;
    std::cout << 23 << test23 << std::endl;
    //constructor is called again
    test23 =  test23 / 12454.0f;
    std::cout << 24 << test23 << std::endl;
    //constructor is called
    test23 = test23 + 1551521126878678612312311223125123123124.0;
    std::cout << 25 << test23 << std::endl;
    const float test24 = 12.0f;
    Float test25 = test24;
    std::cout << 26 << test25 << std::endl;
    test25 = test25 + test24;
    std::cout << 27 << test25 << std::endl;
    test25 /= test24;
    std::cout << 27 << test25 << std::endl;








}
