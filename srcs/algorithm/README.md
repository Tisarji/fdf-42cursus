# FDF - Fil de Fer


FDF is a 42 project, honing in on 3D programming. It takes a map input and creates a 3D representation of it. Essentially, it's about transforming a 2D map into a 3D model.

The project's name, translated from French, means "Iron Wire". This ties in with the central theme of the project, which revolves around "Wireframe modelling".

# ⭐️ Key Focus

The central aim of this project is to deepen your understanding of graphics, particularly transformations and rendering. We're given a map via a file (more specifics to come), which we then convert into a 2D graphical representation (rendering), as depicted below:

# **🧮 Line Tracing**

## 🧠 DDA (Digital Differential Analyzer) Algorithm

**Calculation Method**: The DDA algorithm calculates the intermediate points of the line by incrementing one coordinate and calculating the corresponding value of the other coordinate using a floating-point addition. It uses the equation of the line $y=mx+b$ to calculate each point. 

$y=mx+by = mx + b$

```c
static void draw_dda_line(t_fdf *fdf, t_point start, t_point end)
{
	float dx = end.x - start.x;
	float dy = end.y - start.y;
	int steps = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);

	float xIncrement = dx / (float)steps;
	float yIncrement = dy / (float)steps;

	float x = start.x;
	float y = start.y;
	int i = 0;

	while (i++ <= steps)
	{
		put_pixel(fdf, (int)x, (int)y, start.color);
		x += xIncrement;
		y += yIncrement;
	}
}
```

### **Steps**:

- Determine the number of steps required, based on the greater of the absolute differences in the x and y coordinates $(steps=max(abs(dx),abs(dy)))$
    
    $steps=max⁡(abs(dx),abs(dy))\text{steps} = \max(\text{abs}(dx), \text{abs}(dy))$
    
- Calculate the increments in the x and y coordinates for each step (xincrement=stepsdx, yincrement=stepsdy).
    
    $xincrement=dx stepsx_{\text{increment}} = \frac{dx}{\text{steps}}$
    
    $yincrement=dystepsy_{\text{increment}} = \frac{dy}{\text{steps}}$
    
- Start from the initial point and add the increments to generate subsequent points.

### **Performance**:

- Requires floating-point arithmetic, which can be slower and less efficient than integer arithmetic.
- Simple and easy to implement.

### **Accuracy:**

- Can suffer from rounding errors due to floating-point calculations.

---

## 💥 Bresenham's Line Algorithm

**Calculation Method**: Bresenham's algorithm uses integer arithmetic to determine the points of the line. It decides the best approximation for the next pixel based on an error term that is incrementally updated.

```c
static void draw_bresenham_line(t_fdf *fdf, t_point start, t_point end)
{
	int dx = ft_abs((int)end.x - (int)start.x);
	int dy = ft_abs((int)end.y - (int)start.y);
	int sx = start.x < end.x ? 1 : -1;
	int sy = start.y < end.y ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (1)
	{
		put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		if ((int)start.x == (int)end.x && (int)start.y == (int)end.y)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			start.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			start.y += sy;
		}
	}
}
```

### **Steps**:

- Start from the initial point and calculate the differences dx and dy.
    
    dxdx
    
    dydy
    
- Determine the step directions (signs of increments) based on the start and end points.
- Initialize the error term $err=dx−dy$.
    
    $err=dx−dy\text{err} = dx - dy$
    
- For each point, adjust the error term and decide the next pixel based on the error term. If the error exceeds a threshold, adjust the primary and secondary coordinates accordingly.

### **Performance**:

- Uses only integer arithmetic, making it faster and more efficient than DDA.
- Optimized for drawing lines with a high degree of accuracy.

### **Accuracy**:

- Provides exact pixel positions, making it more accurate and less prone to rounding errors.

---

## 🎨 Color Draw Line

The map has a color type; we just need to input the color into the map. It's easy to do so in the program.

```jsx
0,0xff0000 -1,0xff0000 0,0xff0000 -1,0xff0000
0,0xff0000 -1,0xff0000 0,0xff0000 -1,0xff0000
1,0xff0000 2,0xff0000 1,0xff0000 2,0xff0000
1,0xff0000 2,0xff0000 1,0xff0000 2,0xff0000
```

Here's the complete function:

```c
static void	parse_line(t_map *map, char **split_line, int line_index)
{
	int		column_index;
	char	*color;

	column_index = 0;
	while (column_index < map->width)
	{
		map->matrix[line_index][column_index].x = (float)column_index;
		map->matrix[line_index][column_index].y = (float)line_index;
		map->matrix[line_index][column_index].z = (float)(ft_atoi \
			(split_line[column_index]));
		if (map->matrix[line_index][column_index].z > map->z_max)
			map->z_max = map->matrix[line_index][column_index].z;
		color = ft_strchr(split_line[column_index], ',');
		if (color)
			map->matrix[line_index][column_index].color = \
				apply_alpha(ft_hex_to_dec(color + 1));
		else
		{
			if (map->matrix[line_index][column_index].z <= 0)
				map->matrix[line_index][column_index].color = 0xffffffff;
			else
				map->matrix[line_index][column_index].color = 0xffffffff;
		}
		column_index++;
	}
}
```

---

## 📝 Summary Line Tracing

This document examines two line-drawing algorithms: the DDA (Digital Differential Analyzer) and Bresenham's Line Algorithm. The DDA algorithm utilizes floating-point arithmetic to determine a line's intermediate points but may face rounding errors. In contrast, Bresenham's algorithm employs integer arithmetic to identify line points. This provides precise pixel positions, making it more accurate and efficient. Additionally, the document outlines the process of creating a gradient color for a line. This involves isolating and manipulating the RGB components of hexadecimal colors and calculating color increments for each pixel position.

---

# **🗺️ Map**

## **Understanding the map format**

We start with a map that follows these criteria:

- The horizontal position corresponds to the **x** axis.
- The vertical position corresponds to the **y** axis.
- The value corresponds to the **z** axis, with an optional color (RGBA) separated by a comma.

For instance:

```
0 1
2 3,0xFFFFFFFF

```

There are four points, named from left to right and top to bottom, according to the alphabet.

A(0, 0, 0), B(1, 0, 1), C(0, 1, 2), D(1, 1, 3)

The point **D** has the optional color set to white (0xFFFFFFFF).

## **Drawing a map without transformation**

Consider the following example map:

```
0 0 0
0 1 0
0 0 0

```

The shape resembles a square with one point elevated on the **z** axis by 1. If we draw the shape without any transformation, it would look something like this:

![https://miro.medium.com/v2/resize:fit:1400/1*eE4g9DtxW6nArG5faqdwng.png](https://miro.medium.com/v2/resize:fit:1400/1*eE4g9DtxW6nArG5faqdwng.png)


It looks like a pyramid but it’s not XD

It seems like a 2D shape because the point with the higher altitude meets the other points, i am going to increase the altitude, so that we can see the difference, i am going to change altitude of 1 to 2.

![https://miro.medium.com/v2/resize:fit:1400/1*Eyw6sMciRe4EKueRpaStcQ.png](https://miro.medium.com/v2/resize:fit:1400/1*Eyw6sMciRe4EKueRpaStcQ.png)

# **🫀 Summarize**

FDF is a project focusing on 3D programming and wireframe modeling. It utilizes Bresenham's

**Delve into the world of 3D programming and wireframe modeling with the FDF project.** This project leverages the efficient Bresenham's Line Algorithm to render and transform flat 2D maps into captivating 3D representations. By tackling this project, you'll gain a deeper understanding of fundamental graphics concepts, including transformations and rendering techniques.

**FDF utilizes a simple yet powerful approach.** Maps are defined by coordinates, and colors can be optionally added for enhanced visualization. Transformations, like isometric projection, are then applied to create a more intuitive and visually appealing 3D perspective.
