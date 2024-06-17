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

# 🧾 Summary

### DDA (Digital Differential Analyzer) Algorithm

- **Calculation Method**: The DDA algorithm calculates the intermediate points of the line by incrementing one coordinate and calculating the corresponding value of the other coordinate using a floating-point addition. It uses the equation of the line y=mx+b to calculate each point.
    
    $y=mx+by = mx + b$
    
- **Steps**:
    - Determine the number of steps required, based on the greater of the absolute differences in the x and y coordinates (steps=max(abs(dx),abs(dy))).
        
        $steps=max⁡(abs(dx),abs(dy))\text{steps} = \max(\text{abs}(dx), \text{abs}(dy))$
        
    - Calculate the increments in the x and y coordinates for each step (xincrement=stepsdx, yincrement=stepsdy).
        
        $xincrement=dx stepsx_{\text{increment}} = \frac{dx}{\text{steps}}$
        
        $yincrement=dystepsy_{\text{increment}} = \frac{dy}{\text{steps}}$
        
    - Start from the initial point and add the increments to generate subsequent points.
- **Performance**:
    - Requires floating-point arithmetic, which can be slower and less efficient than integer arithmetic.
    - Simple and easy to implement.
- **Accuracy**:
    - Can suffer from rounding errors due to floating-point calculations.

### Bresenham's Line Algorithm

- **Calculation Method**: Bresenham's algorithm uses integer arithmetic to determine the points of the line. It decides the best approximation for the next pixel based on an error term that is incrementally updated.
- **Steps**:
    - Start from the initial point and calculate the differences dx and dy.
        
        dxdx
        
        dydy
        
    - Determine the step directions (signs of increments) based on the start and end points.
    - Initialize the error term $err=dx−dy$
        
        $err=dx−dy\text{err} = dx - dy$
        
    - For each point, adjust the error term and decide the next pixel based on the error term. If the error exceeds a threshold, adjust the primary and secondary coordinates accordingly.
- **Performance**:
    - Uses only integer arithmetic, making it faster and more efficient than DDA.
    - Optimized for drawing lines with a high degree of accuracy.
- **Accuracy**:
    - Provides exact pixel positions, making it more accurate and less prone to rounding errors.
