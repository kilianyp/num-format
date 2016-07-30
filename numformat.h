#pragma once

#include <iostream>
#include <math.h>

template < typename type>
class NumFormat {
public:
    NumFormat(type value) : _value(value) {};
    // it is not possible to make pure otherwise linking error
    virtual type getValue() {return _value;};

    virtual type convertTo(type value) {return _value;};

    virtual NumFormat<type> & operator = (NumFormat<type> assign) {
        //printf("assignment %f\n", assign.getValue());
        _value = convertTo(assign.getValue());
        return *this;
    }

    //is not called
    template<typename any_type> NumFormat<type> & operator = (any_type assign) {
        //printf("assignment type %f\n", assign);
        _value = convertTo(assign);
        return *this;
    }


    //prefix
    virtual NumFormat<type> & operator ++ () {
        _value = convertTo(this->getValue() + 1.0);
        return *this;
    }

    virtual NumFormat<type> & operator -- () {
        _value = convertTo(this->getValue() - 1.0);
        return *this;
    }

    //Postfix not properly implemented yet
    virtual NumFormat<type> & operator ++ (int) {
        _value = convertTo(this->getValue() + 1.0);
        return *this;
    }

    virtual NumFormat<type> & operator -- (int) {
        type tmp = convertTo(this->getValue() - 1.0);
        return *this;
    }


    virtual NumFormat<type> & operator += (NumFormat<type> addend) {
        _value = convertTo(this->getValue() + addend.getValue());
        return *this;
    }

    virtual NumFormat<type> & operator -= (NumFormat<type> subtrahend) {
        _value = convertTo(this->getValue() - subtrahend.getValue());
        return *this;
    }

    virtual NumFormat<type> & operator *= (NumFormat<type> multiplicand) {
        _value = convertTo(this->getValue() * multiplicand.getValue());
        return *this;
    }

    virtual NumFormat<type> & operator /= (NumFormat<type> dividend) {
        _value = convertTo(this->getValue() / dividend.getValue());
        return *this;
    }

    //format this is saved to is not clear yet, dont convert
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

//allow different order e.g. float + Float
template<typename type, typename any_type> type operator + (any_type add_1, NumFormat<type> add_2) {
    return add_1 + add_2.getValue();
}

template<typename type, typename any_type> type operator - (any_type sub_1, NumFormat<type> sub_2) {
    return sub_1 - sub_2.getValue();
}

template<typename type, typename any_type> type operator * (any_type mul_1, NumFormat<type> mul_2) {
    return mul_1 * mul_2.getValue();
}

template<typename type, typename any_type> type operator / (any_type div_1, NumFormat<type> div_2) {
    return div_1 / div_2.getValue();
}




template<typename type> float sinf(NumFormat<type> value) {return sinf(value.getValue());};
template<typename type> float cosf(NumFormat<type> value) {return cosf(value.getValue());};
template<typename type> float expf(NumFormat<type> value) {return expf(value.getValue());};
template<typename type> float sqrtf(NumFormat<type> value) {return sqrtf(value.getValue());};

enum eRoundingType {RoundToClosest, RoundToNext};
