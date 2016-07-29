#pragma once

#include <iostream>
#include <math.h>

template < typename type>
class NumFormat {
public:
    NumFormat(type value) : _value(value) {};
    // it is not possible to make pure otherwise linking error
    virtual type getValue() {return _value;};


    virtual NumFormat<type> & operator = (NumFormat<type> assign) {
        //printf("123 %f", assign.getValue());
        _value = assign.getValue();
        return *this;
    }


    //prefix
    virtual NumFormat<type> & operator ++ () {
        _value = this->getValue() + 1.0;
        return *this;
    }

    virtual NumFormat<type> & operator -- () {
        _value = this->getValue() - 1.0;
        return *this;
    }

    //Postfix not properly implemented yet
    virtual NumFormat<type> & operator ++ (int) {
        _value = this->getValue() + 1.0;
        return *this;
    }

    virtual NumFormat<type> & operator -- (int) {
        type tmp = this->getValue() - 1.0;
        return *this;
    }


    virtual NumFormat<type> & operator += (NumFormat<type> addend) {
        _value = this->getValue() + addend.getValue();
        return *this;
    }

    virtual NumFormat<type> & operator -= (NumFormat<type> subtrahend) {
        _value = this->getValue() - subtrahend.getValue();
        return *this;
    }

    virtual NumFormat<type> & operator *= (NumFormat<type> multiplicand) {
        _value = this->getValue() * multiplicand.getValue();
        return *this;
    }

    virtual NumFormat<type> & operator /= (NumFormat<type> dividend) {
        _value = this->getValue() / dividend.getValue();
        return *this;
    }

    virtual type operator + (NumFormat<type> addend) {
        return this->getValue() + addend.getValue();
    }

    virtual type operator - (NumFormat<type> subtrahend) {
        return this->getValue() - subtrahend.getValue();
    }

    virtual type operator * (NumFormat<type> multiplicand) {
        return this->getValue() * multiplicand.getValue();
    }

    virtual type operator / (NumFormat<type> dividend) {
        return this->getValue() / dividend.getValue();
    }

    //comparisons
    virtual bool operator > (NumFormat<type> cmp) {
        return this->getValue() > cmp.getValue();
    }

    virtual bool operator >= (NumFormat<type> cmp) {
        return this->getValue() >= cmp.getValue();
    }

    virtual bool operator < (NumFormat<type> cmp) {
        return this->getValue() < cmp.getValue();
    }

    virtual bool operator <= (NumFormat<type> cmp) {
        return this->getValue() <= cmp.getValue();
    }

    virtual bool operator == (NumFormat<type> cmp) {
        return this->getValue() == cmp.getValue();
    }

    virtual bool operator != (NumFormat<type> cmp) {
        return this->getValue() != cmp.getValue();
    }

    virtual bool operator && (NumFormat<type> cmp) {
        return this->getValue() && cmp.getValue();
    }

    virtual bool operator || (NumFormat<type> cmp) {
        return this->getValue() || cmp.getValue();
    }

    //ostream
    friend std::ostream& operator<< (std::ostream &out, NumFormat<type> &value) {
        value.print(out);
        return out;
    };
    //this function can be overloaded
    virtual void print(std::ostream& out) const {
        out << " " << _value << " ";
    }


protected:
    type _value;
};




template<typename type> float sinf(NumFormat<type> value) {return sinf(value.getValue());};
template<typename type> float cosf(NumFormat<type> value) {return cosf(value.getValue());};
template<typename type> float expf(NumFormat<type> value) {return expf(value.getValue());};
template<typename type> float sqrtf(NumFormat<type> value) {return sqrtf(value.getValue());};

enum eRoundingType {RoundToClosest, RoundToNext};
