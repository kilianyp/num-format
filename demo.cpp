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
    std::cout << test2 << std::endl;
    std::cout << test3 << std::endl;
    std::cout << test4 << std::endl;
    std::cout << test5 << std::endl;
    std::cout << test6 << std::endl;
    std::cout << test1 << std::endl;
    std::cout << test7 << std::endl;
    std::cout << test8 << std::endl;
    std::cout << test9 << std::endl;
    std::cout << test10 << std::endl;
    //std::cout << test11 << std::endl;
    std::cout << test13 << std::endl;
    std::cout << test14 << std::endl;
    printf("%f\n", max);
    std::cout << test15 << std::endl;
    std::cout << test16 << std::endl;
    float test18 = 2.001;
    Float test17 = 125471205798123;
    Float16 test19 = test17;
    Float test20 = test19;
    if(test17 >= test18) {
        printf("true %f\n", test18);
        std::cout << test17 << std::endl;
    }
    std::cout << test19 << std::endl;
    std::cout << test20 << std::endl;


}
