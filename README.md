# Quadruples in C
An implementation of Three Address Code, in C. Quadruples can be used to store intermediate code during compilation.

### Building
To build the static library,  run the following commands from the terminal:
```bash
mkdir build && cd build && cmake .. && make ; cd ..
```
This will build ```libQuad.a``` in ```./bin``` directory.

### Usage
Include ```Quad.h``` in the source file and link to ```libQuad.a``` while compiling the source file.

See ```include/Quad.h``` for information about functionality provided by this module.
