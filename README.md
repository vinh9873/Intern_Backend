# File Service (C++ / Oat++)

## Day 1

### Setup Environment
- Installed CMake
- Installed vcpkg
  - Integrated vcpkg with CMake
  - Installed oatpp library
- Configured build using CMake and MSVC


```
git clone https://github.com/microsoft/vcpkg
cd vcpkg
bootstrap-vcpkg.bat
vcpkg install oatpp
```


### How to run
```bash
rmdir /s /q build
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/Users/T470s/Desktop/intern-backend/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build

build\Debug\file-service.exe
```


### Result
- Successfully built and ran a simple REST API
- Implemented endpoint: `GET /hello`

### Test API
```bash
curl http://localhost:8080/hello

Response:

{
  "message": "Hello Intern"
}
```

```bash
curl "http://localhost:8080/sum" --data-raw "{\"a\":1, \"b\":2}"
```

# Dependency system
vcpkg: install, lookup dependency