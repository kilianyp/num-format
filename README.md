A simple tool to simulate different float behaviour.

# Usage

```
#include "float.h"
typedef FloatBase<false, 23, 8> Float;

int main () {
    Float test1 = 9000.0f;
    Float test2 = 15.3;
    Float test3 = test1 + test2;
}

```

To check the Demo:

```
make
./demo
```

# Supports
- Prefixing
- Postfixing
- Addition
- Subtraction
- Multiplication
- Comparison


## TODO
- [ ] Rounding
