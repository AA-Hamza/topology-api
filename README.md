# Topology API
This is a C++ API library for handling electronic topologies in JSON format.
## How to run?
```
meson setup build
cd build/
meson compile

# to run tests
meson test

# to run example
./example ../test/topologies/ex1.json ../test/topologies/ex2.json 

```

## Why CPP?
I considered something with buit-in support for JSON like Node.js but I wanted to take the challenge and implement it in C++.

## API
* you can [see docs online](https://aa-hamza.github.io/topology-api/hierarchy.html) 
* or try using it [example](./example.cpp)
* also you might notice that `writeJSON` doesn't preserve order with JSON objects (it does with JSON arrays), [but this isn't an issue](https://stackoverflow.com/questions/7214293/is-the-order-of-elements-in-a-json-list-preserved)

## Dependencies
* [nlohmann/json](https://github.com/nlohmann/json)

## Tools used
* Meson build system
* Doxygen for the documentation
* clang-format for formatting the code

## Tested Platforms
* Runs on linux, see [github actions](https://github.com/AA-Hamza/topology-api/actions)
* Runs on Windows with GCC, see [github actions](https://github.com/AA-Hamza/topology-api/actions)