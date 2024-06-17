# Fil de Fer (FDF)

<img width="1325" alt="Screenshot_2567-06-17_at_09 43 33" src="https://github.com/Tisarji/fdf-42cursus/assets/48820052/767aec19-1f14-43f6-bf5d-3d0168ab02a7">

## 📝 Introduction

**Fil de Fer (FDF)** is a project from the 42 programming school curriculum. It involves creating a simplified 3D graphic representation of a wireframe model, where each point is connected by lines. The project is primarily focused on enhancing your skills in computer graphics, working with C programming, and manipulating graphical libraries.

## 🧨 Objectives

- Implement a wireframe model renderer.
- Practice working with basic graphics libraries.
- Understand the fundamentals of 3D projection.
- Improve your skills in C programming.

## 🧾 Requirements

- The project must be written in C.
- You must use the MiniLibX library for rendering graphics.
- The program must read a map file and display a corresponding wireframe model.
- Implement basic rotation and zoom functionalities.

## ✨ Getting Started

### 📚 Prerequisites

Before you begin, ensure you have the following installed on your system:

- GCC (GNU Compiler Collection)
- Make
- MiniLibX (provided by 42)

### ⚙️ Installation

1. **Clone the repository:**

   ```sh
   git clone https://github.com/Tisarji/fdf-42cursus.git
   cd fdf-42cursus
   ```

2. **Compile the project:**

   ```sh
   make
   ```

3. **Run the program:**

   ```sh
   ./fdf [map_file]
   ```

### 🗺️ Map Files

The map file is a simple text file containing a grid of integers, where each number represents the height of the corresponding point in the wireframe model. Example:

```
0 0 0 0 0
0 1 1 1 0
0 1 2 1 0
0 1 1 1 0
0 0 0 0 0
```

## 🖌️ Implementation Details

### 🧠 Main Components

- **Parsing:** Read and parse the map file to create a 2D array of heights.
- **Projection:** Implement an isometric projection to convert 3D points to 2D.
- **Rendering:** Use MLX42 to draw the wireframe model on the screen.

### 🗄️ Files Structure

- **src/**
  - `fdf.c` - Entry point of the program.
  - `map_parser.c` - Functions for reading and parsing the map file.
  - `render.c` - Functions for rendering the wireframe model.
  - `load_map.c` - Function for loading map.
- **include/**
  - `fdf.h` - Header file containing function prototypes and struct definitions.
- **Makefile** - Script to compile the project.

## 🎨 MLX42

MLX42 is a small graphics library that makes it easy to create simple graphical applications. It provides functions for creating windows, drawing shapes, and handling keyboard/mouse events.

### Useful MLX42 Functions

- `mlx_init()` - Initialize the connection to the graphical server.
- `mlx_pixel_put()` - Draw a pixel on the screen.
- `mlx_key_hook()` - Handle keyboard events.
- `mlx_loop()` - Enter the event loop.

## 🔔 Tips

- Start by implementing the map parser to read and store the grid of heights.
- Implement the isometric projection to convert 3D coordinates to 2D.
- Use the MiniLibX library to create a window and draw the initial wireframe model.
- Add rotation and zoom functionalities to enhance the interactivity of your program.
