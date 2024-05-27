# Line Drawing Utility

This utility provides functions to draw lines on an image using the Bresenham line algorithm. The primary functions included are for drawing vertical lines, horizontal lines, and lines at arbitrary angles.

## Functions

### draw_vertical

This function draws a vertical line between two points on the image.

**Parameters:**
- `line`: A pointer to the `t_draw_line` structure containing the image and other drawing parameters.
- `convert_matrix`: A 2D array of floats representing the points to be connected.
- `start`: The starting point index in the `convert_matrix`.
- `end`: The ending point index in the `convert_matrix`.

### draw_horizontal

This function draws a horizontal line between two points on the image.

**Parameters:**
- `line`: A pointer to the `t_draw_line` structure containing the image and other drawing parameters.
- `convert_matrix`: A 2D array of floats representing the points to be connected.
- `start`: The starting point index in the `convert_matrix`.
- `end`: The ending point index in the `convert_matrix`.

### draw_line_x_axis

This function draws a line along the x-axis between two points on the image using the Bresenham line algorithm.

**Parameters:**
- `line`: A pointer to the `t_draw_line` structure containing the image and other drawing parameters.
- `convert_matrix`: A 2D array of floats representing the points to be connected.
- `start`: The starting point index in the `convert_matrix`.
- `end`: The ending point index in the `convert_matrix`.

### draw_line_y_axis

This function draws a line along the y-axis between two points on the image using the Bresenham line algorithm.

**Parameters:**
- `line`: A pointer to the `t_draw_line` structure containing the image and other drawing parameters.
- `convert_matrix`: A 2D array of floats representing the points to be connected.
- `start`: The starting point index in the `convert_matrix`.
- `end`: The ending point index in the `convert_matrix`.

### draw_line

This function selects the appropriate line drawing function (vertical, horizontal, x-axis, or y-axis) based on the given points and draws the line on the image.

**Parameters:**
- `img`: A pointer to the `mlx_image_t` structure representing the image.
- `convert_matrix`: A 2D array of floats representing the points to be connected.
- `start`: The starting point index in the `convert_matrix`.
- `end`: The ending point index in the `convert_matrix`.
