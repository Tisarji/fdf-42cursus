# FDF - Fil de Fer

FDF is a 42 project, honing in on 3D programming. It takes a map input and creates a 3D representation of it. Essentially, it's about transforming a 2D map into a 3D model.

The project's name, translated from French, means "Iron Wire". This ties in with the central theme of the project, which revolves around "Wireframe modelling".

# ⭐️ Key Focus

The central aim of this project is to deepen your understanding of graphics, particularly transformations and rendering. We're given a map via a file (more specifics to come), which we then convert into a 2D graphical representation (rendering), as depicted below:

![FDF%20-%20Fil%20de%20Fer%2009af84282ec549b09de72c8808f12272/Untitled.png](FDF%20-%20Fil%20de%20Fer%2009af84282ec549b09de72c8808f12272/Untitled.png)

To create such a scene, we utilized a basic graphics library that helped us manage windows and draw pixels. At my campus, we could opt for an advanced version of this library. This open-source library is accessible [here](https://github.com/codam-coding-college/MLX42).

```c
void	ft_render(t_fdfvariables *fdf)
{
	int	i;
	int	aux;

	ft_memset(fdf->img->pixels, 0, fdf->img->width * \
	fdf->img->height * sizeof(int));
	i = -1;
	while (++i < ((fdf->map_height * fdf->map_width)))
	{
		aux = i;
		if ((i + 1) % fdf->map_width != 0)
		{
			if (fdf->map[i].z < fdf->map[i + 1].z)
				aux = i + 1;
			bresenham(aux, coords(fdf->map[i].x_draw, fdf->map[i].y_draw), \
			coords(fdf->map[i + 1].x_draw, fdf->map[i + 1].y_draw), fdf);
		}
		if (i / fdf->map_width != fdf->map_height - 1)
		{
			if (fdf->map[i].z < fdf->map[i + fdf->map_width].z)
				aux = i + fdf->map_width;
			bresenham(aux, coords(fdf->map[i].x_draw, fdf->map[i].y_draw), \
			coords(fdf->map[i + fdf->map_width].x_draw, \
			fdf->map[i + fdf->map_width].y_draw), fdf);
		}
	}
}
```

The above code pertains to rendering.

# **Bresenham's Line Algorithm**

A line, bridging two points, is a fundamental element in graphics. Drawing a line requires two points between which the line can be drawn, and an algorithm to facilitate this. [Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm), which uses integer calculations, is faster than methods utilizing floats. This algorithm is essential for drawing a line at any angle and direction, not just from the [origin](https://en.wikipedia.org/wiki/Origin_(mathematics)). On our screen, the origin is the top-left corner: `y` increases as we move downwards, and `x` increases as we move right.

The algorithm essentially has two cases:

- If `deltaX(x1 - x0) > deltaY(y1 - y0)`, `x` increases each iteration, and we decide whether to keep `y` constant or increment it by a step (1 or -1, depending on the line's direction). This case applies when the line's slope is less than 45 degrees.
- If `deltaX(x1 - x0) < deltaY(y1 - y0)`, `y` increases each iteration, and we decide whether to keep `x` constant or increment it by a step (1 or -1, depending on the line's direction). This case applies when the line's slope is more than 45 degrees.

Let's illustrate this.

![FDF%20-%20Fil%20de%20Fer%2009af84282ec549b09de72c8808f12272/Untitled%201.png](FDF%20-%20Fil%20de%20Fer%2009af84282ec549b09de72c8808f12272/Untitled%201.png)

![FDF%20-%20Fil%20de%20Fer%2009af84282ec549b09de72c8808f12272/Untitled%202.png](FDF%20-%20Fil%20de%20Fer%2009af84282ec549b09de72c8808f12272/Untitled%202.png)

![FDF%20-%20Fil%20de%20Fer%2009af84282ec549b09de72c8808f12272/Untitled%203.png](FDF%20-%20Fil%20de%20Fer%2009af84282ec549b09de72c8808f12272/Untitled%203.png)

![FDF%20-%20Fil%20de%20Fer%2009af84282ec549b09de72c8808f12272/Untitled%204.png](FDF%20-%20Fil%20de%20Fer%2009af84282ec549b09de72c8808f12272/Untitled%204.png)

## Bresenham Function

The Bresenham function applies Bresenham's line algorithm to draw a line between two points on a grid. It accepts an initial position, two coordinates, and a 'fdfvariables' structure pointer. It calculates the differences in x and y, determines the line's direction, and places points along the line until it reaches the end. It's a common tool in computer graphics.

```c
void	bresenham(int position, t_coords c1, t_coords c2, t_fdfvariables *fdf)
{
	t_bresenham	brshm;

	brshm.dx = ft_abs(c2.x - c1.x);
	brshm.dy = ft_abs(c2.y - c1.y);
	if (c1.x < c2.x)
		brshm.sx = 1;
	else
		brshm.sx = -1;
	if (c1.y < c2.y)
		brshm.sy = 1;
	else
		brshm.sy = -1;
	brshm.err = brshm.dx - brshm.dy;
	brshm.x = c1.x;
	brshm.y = c1.y;
	while (brshm.x != c2.x || brshm.y != c2.y)
	{
		ft_putrgba((ft_abs(brshm.x - 1) * 4) + \
		(fdf->img->width * ft_abs(brshm.y - 1) * 4), fdf, position);
		brshm.e2 = 2 * brshm.err;
		bresenham_aux(&brshm);
	}
}
```

## 🗺️ Map

**Understanding the map format**

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

**Drawing a map without transformation**

Consider the following example map:

```
0 0 0
0 1 0
0 0 0

```

The shape resembles a square with one point elevated on the **z** axis by 1. If we draw the shape without any transformation, it would look something like this:

![https://miro.medium.com/v2/resize:fit:1400/1*eE4g9DtxW6nArG5faqdwng.png](https://miro.medium.com/v2/resize:fit:1400/1*eE4g9DtxW6nArG5faqdwng.png)

The altitude (z-axis) is not displayed here because we're viewing the shape from above without any transformation. To gain a better perspective, we'll employ the Isometric projection, as specified by the project's requirements. To achieve this, we'll first rotate around the z-axis by 45 degrees using the following matrix:

![https://miro.medium.com/v2/resize:fit:932/1*IqgXsMbPwW37dC3YC4zF8A.png](https://miro.medium.com/v2/resize:fit:932/1*IqgXsMbPwW37dC3YC4zF8A.png)

Then, rotate around the **x** axis by *arctan*(√2)

![https://miro.medium.com/v2/resize:fit:1044/1*vNKhdfMn0A_fxh0TDYg_Aw.png](https://miro.medium.com/v2/resize:fit:1044/1*vNKhdfMn0A_fxh0TDYg_Aw.png)

After doing these rotations, we will now have a shape similar to:

![https://miro.medium.com/v2/resize:fit:1400/1*HMuq0cIANg5biHu3E2dA_A.png](https://miro.medium.com/v2/resize:fit:1400/1*HMuq0cIANg5biHu3E2dA_A.png)

It looks like a pyramid but it’s not XD

It seems like a 2D shape because the point with the higher altitude meets the other points, i am going to increase the altitude, so that we can see the difference, i am going to change altitude of 1 to 2.

![https://miro.medium.com/v2/resize:fit:1400/1*Eyw6sMciRe4EKueRpaStcQ.png](https://miro.medium.com/v2/resize:fit:1400/1*Eyw6sMciRe4EKueRpaStcQ.png)