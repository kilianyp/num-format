#pragma once

#include "numtype.h"


// IEEE 754 standard of doube precision
#define MANT_DIG 52
#define EXPO_DIG 11
#define SIGN_DIG 1
#define OFFSET -1023
#define SIGN(sign) (1-2*sign)

typedef union {
  double f;
  struct {
    unsigned long mant : MANT_DIG;
    unsigned int expo : EXPO_DIG;
    unsigned int sign : SIGN_DIG;
} structure;
} uFloat;


template< bool TDebug, unsigned TMant_dig, unsigned TExpo_dig>
class FloatBase : public NumFormat<double> {
public:

    FloatBase(double value) : NumFormat(value) {
        _value = TDebug ? value : convertTo(value);
    };

    inline static int getMaxExponent() {
        int maxExponent = (1 << (TExpo_dig-1))-1;
        //printf("%d\n", maxExponent);
        return maxExponent;
    }

    inline static int getMinExponent() {
        int minExponent = -((1 << (TExpo_dig-1))-2);
        //printf(" %d ", minExponent);
        return minExponent;
    }

    static double getMinValue() {
        return pow(2,getMinValue());
    }

    static double convertTo(double value) {
        uFloat helper;
        helper.f = value;

        //easy extraction
        // printf("sign = %d\n",helper.structure.sign);
        // printf("exponent = %d\n",helper.structure.expo);
        // printf("mantisa = %d\n",helper.structure.mant);

        int minExponent = getMinExponent();
        int maxExponent = getMaxExponent();

        if(helper.structure.expo == 0 && helper.structure.mant == 0)
        {
            value = SIGN(helper.structure.sign) * 0.0;
        }
        else if(maxExponent < helper.structure.expo + OFFSET)
        {
            value = SIGN(helper.structure.sign) * INFINITY;
        }
        else if (minExponent > helper.structure.expo + OFFSET)
        {
            value = pow(2,minExponent);
        }
        else
        {
            // get the mant_dig significant digits of the mantisse
            long mantMask = ~((1l << (MANT_DIG - TMant_dig))-1);
            //printf("mask %ld mant %ld\n", mantMask, helper.structure.mant);
            helper.structure.mant &=  mantMask;
            //printf("mask %ld mant %ld\n", mantMask, helper.structure.mant);
            value = helper.f;
        }

        // printf("sign = %d\n",helper.structure.sign);
        // printf("exponent = %d\n",helper.structure.expo);
        // printf("mantisa = %d\n",helper.structure.mant);
        // printf("value %f\n", helper.f);
        // printf("%d %d \n", minExpo, maxExpo);
        return value;
    };

    virtual void print(std::ostream& out) const {
        out << " " << _value << " ";
        if(TDebug)
        {
            out << " " << convertTo(_value) << " " << (float)(_value) << " ";
        }
    };

    //CASTING
    //returns for other format the value. The constructor will then convert it
    //correctly
    template< bool TDebug2, unsigned TMant_dig2, unsigned TExpo_dig2>
    operator FloatBase<TDebug2, TMant_dig2, TExpo_dig2>() {
        return _value;
    };


};
