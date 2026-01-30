# File Service (C++ / Oat++)

## Day 1

### Setup Environment
- Installed CMake
- Installed vcpkg
  - Integrated vcpkg with CMake
  - Installed oatpp library
- Configured build using CMake and MSVC

### Result
- Successfully built and ran a simple REST API
- Implemented endpoint: `GET /hello`

### Test API
```bash
curl http://localhost:8000/hello

Response:

{
  "message": "Hello Intern"
}
