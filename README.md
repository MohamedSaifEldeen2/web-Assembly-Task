# WebAssembly Calculator Demo

A simple demonstration project showcasing C to WebAssembly (WASM) compilation using Emscripten. This project features a basic averaging calculator written in C, compiled to WebAssembly, and running in a web browser.

## Overview

This project demonstrates how to:
- Write a simple C program
- Compile C code to WebAssembly using Emscripten
- Run WebAssembly modules in a web browser
- Interface between JavaScript and WebAssembly

The demo includes a C function that calculates the average of an array of numbers, demonstrating fundamental WebAssembly capabilities.

## Features

- **Simple C Implementation**: Clean, straightforward C code for calculating averages
- **WebAssembly Output**: Compiled WASM module for browser execution
- **Emscripten Integration**: Full HTML/JS boilerplate for running WASM in browsers
- **Interactive Demo**: Browser-based interface with console output

## Prerequisites

To build and run this project, you need:

- **Emscripten SDK**: For compiling C to WebAssembly
  - Download from: https://emscripten.org/docs/getting_started/downloads.html
- **Web Browser**: Any modern browser with WebAssembly support (Chrome, Firefox, Edge, Safari)
- **C Compiler** (optional): GCC or similar for native compilation and testing

## Project Structure

```
web-Assembly-Task/
├── main.c              # Source C code with calc_avg function
├── a.wasm              # Compiled WebAssembly binary
├── a.js                # Emscripten-generated JavaScript glue code
├── a.html              # Web interface to run the WASM module
├── .vscode/            # VSCode configuration files
│   ├── c_cpp_properties.json
│   ├── launch.json
│   └── settings.json
└── README.md           # This file
```

## Installation & Setup

### 1. Install Emscripten

```bash
# Clone the Emscripten SDK
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk

# Install and activate the latest SDK
./emsdk install latest
./emsdk activate latest

# Set up environment variables
source ./emsdk_env.sh
```

### 2. Clone This Repository

```bash
git clone https://github.com/MohamedSaifEldeen2/web-Assembly-Task.git
cd web-Assembly-Task
```

## Building from Source

To recompile the C code to WebAssembly:

```bash
# Using Emscripten compiler
emcc main.c -o a.html

# This generates three files:
# - a.wasm (the WebAssembly binary)
# - a.js (JavaScript glue code)
# - a.html (HTML interface)
```

### Compilation Options

For optimized builds:

```bash
# With optimization level 2
emcc main.c -O2 -o a.html

# With optimization level 3 (maximum optimization)
emcc main.c -O3 -o a.html

# For smaller file size
emcc main.c -Os -o a.html
```

## Running the Demo

### Method 1: Local Web Server (Recommended)

WebAssembly requires a web server to run properly due to CORS restrictions.

```bash
# Using Python 3
python3 -m http.server 8000

# Using Python 2
python -m SimpleHTTPServer 8000

# Using Node.js (if you have http-server installed)
npx http-server -p 8000
```

Then open your browser and navigate to:
```
http://localhost:8000/a.html
```

### Method 2: Emscripten's Built-in Server

```bash
emrun a.html
```

## Code Explanation

### main.c

The C source file contains:

```c
double calc_avg(const double *arr, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    
    return sum / size;
}

int main()
{
    double nums[] = {10.0, 20.0, 30.0, 40.0, 50.0};
    int size = 5;
    
    double avg = calc_avg(nums, size);
    printf("The average is: %.2f\n", avg);
    return 0;
}
```

**Key Components:**
- `calc_avg()`: Calculates the average of an array of doubles
- `main()`: Entry point that demonstrates the function with sample data
- Output: Displays "The average is: 30.00" in the browser console

## Expected Output

When you run the demo in a browser, you should see:
- An Emscripten-styled webpage
- A black canvas area
- A console output area displaying:
  ```
  The average is: 30.00
  ```

## Development Setup

### VSCode Configuration

The project includes VSCode configurations for C/C++ development:

- **c_cpp_properties.json**: IntelliSense configuration
- **launch.json**: Debugging configuration
- **settings.json**: Compiler and warning settings

## Troubleshooting

### WASM Module Not Loading

**Issue**: "failed to asynchronously prepare wasm"

**Solution**: Make sure you're serving the files through a web server, not opening the HTML file directly.

### CORS Errors

**Issue**: Cross-Origin Resource Sharing errors

**Solution**: Use a local web server as described in the "Running the Demo" section.

### Emscripten Not Found

**Issue**: `emcc: command not found`

**Solution**: Ensure Emscripten is installed and environment variables are set:
```bash
source /path/to/emsdk/emsdk_env.sh
```

## Learning Resources

- [Emscripten Documentation](https://emscripten.org/docs/)
- [WebAssembly Official Site](https://webassembly.org/)
- [MDN WebAssembly Guide](https://developer.mozilla.org/en-US/docs/WebAssembly)

## Contributing

Feel free to fork this repository and submit pull requests for improvements or bug fixes.

## License

This project is open source and available for educational purposes.

## Author

Mohamed Saif Eldeen

## Acknowledgments

- Emscripten team for the excellent C to WASM compiler
- WebAssembly community for documentation and support
