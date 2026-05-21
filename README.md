# C++ Compilation, Linking & GLFW Exploration

This project is a learning-focused C++ sandbox designed to understand how C++ programs are compiled, linked, and executed with external libraries such as GLFW and OpenGL.

The goal is NOT to build a game, but to understand how the C++ toolchain works under the hood:

- compilation process
- linking process
- library integration
- runtime dependencies (DLLs)

---

# 📌 What this project demonstrates

- How C++ compilation works using g++
- How header files are resolved using `-I` include paths
- How libraries are linked using `-L` and `-l` flags
- Difference between static libraries (`.a`) and dynamic libraries (`.dll`)
- How GLFW integrates with OpenGL
- How executables depend on runtime DLLs on Windows

---

# 📁 Project Structure

```

bin/
├── game.exe
├── glfw3.dll   (required at runtime)

glfw/
├── include/
│   └── GLFW
│       ├── glfw3.h
│       ├── glfw3native.h
│
├── lib-mingw-w64/
│   ├── glfw3.dll
│   ├── libglfw3.a
│   ├── libglfw3dll.a

src/
├── main.cpp    (entry point)
├── game.cpp    (logic / experimentation)
├── game.h      (class declarations)

```

---

# ⚙️ Requirements

- MinGW-w64 (g++)
- GLFW 3.4 (precompiled Windows binaries)
- OpenGL (built into Windows via `opengl32`)

---

# 🧪 Build / Compile Command

Run this from the project root:

```bash
g++ src/main.cpp src/game.cpp -o bin/game.exe -Iglfw/include -Lglfw/lib-mingw-w64 -lglfw3dll -lopengl32
```

---

# 📌 What this command means

## 🟦 Compile source files

```bash
src/main.cpp src/game.cpp
```

These are the C++ source files being compiled.

---

## 🟩 Output executable

```bash
-o bin/game.exe
```

Creates the final executable program.

---

## 🟨 Include paths

```bash
-Iglfw/include
```

Tells the compiler where to find header files.

This allows:

```cpp
#include <GLFW/glfw3.h>
```

---

## 🟪 Library path

```bash
-Lglfw/lib-mingw-w64
```

Tells the linker where to find library files.

---

## 🔗 Linking libraries

### GLFW

```bash
-lglfw3dll
```

Links the GLFW library (dynamic version).

Provides functions like:

- glfwInit()
- glfwCreateWindow()
- glfwPollEvents()

---

### OpenGL (Windows system library)

```bash
-lopengl32
```

Links built-in Windows OpenGL support.

---

# ▶️ Running the program

After building:

```bash
cd bin
game.exe
```

⚠️ Important:
`glfw3.dll` must be inside the `bin/` folder or the program will fail to start.

---

# 🎮 Controls (if enabled in code)

- W → Move up
- S → Move down
- A → Move left
- D → Move right

---

# 🧠 Technical Concepts Covered

## Compilation

Source `.cpp` files are converted into machine code.

## Linking

External functions (GLFW/OpenGL) are connected using `.a` import libraries.

## Runtime Dependencies

DLL files are loaded when the program starts.

## Rendering

Uses legacy OpenGL (immediate mode: `glBegin/glEnd`).

## Windowing/Input

Handled by GLFW.

---

# ⚙️ Full Compile Command (Windows-friendly format)

```bash
g++ src/main.cpp src/game.cpp -o bin/game.exe ^
-Iglfw/include ^
-Lglfw/lib-mingw-w64 ^
-lglfw3dll -lopengl32
```

---

# 🧠 Summary of Flags

| Flag | Meaning               |
| ---- | --------------------- |
| `-I` | Path to header files  |
| `-L` | Path to library files |
| `-l` | Link a library        |

---

# 🎯 Project Purpose

This project exists to understand:

- how C++ builds executables
- how external libraries are connected
- how linking works internally
- how runtime dependencies (DLLs) affect execution

It is a **C++ toolchain and build system learning environment**.

```

```
