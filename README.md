# **miniRT**
This project was graded <strong>125/100</strong>.

## 📝 **Authorship**

- [Mario Henriques](https://github.com/maricard18) ([**maricard**](https://profile.intra.42.fr/users/maricard))
- [Nuno Jesus](https://github.com/Nuno-Jesus) ([**ncarvalh**](https://profile.intra.42.fr/users/ncarvalh))

## 🧬 **Cloning**

This repository uses a **git submodule**, a git repo nested in this one (the **libnc** folder). By default, cloning this repo will ignore the submodule, which comes out as an empty folder. To successfully clone both, use this command

```shell
git clone --recurse-submodules https://github.com/Nuno-Jesus/42_miniRT.git 
```

## 📒 **About**
Rendering a 3-dimensional images can be done using Ray Tracing, an expensive technique, which is based on casting rays from the camera into the space and illuminate shapes.

This isn't an advanced Ray Tracer, since it's implemented in C, but it definitely is functional and has a bit of our own bonus in it too!

## **Mandatory Part**

<table align=center>
	<thead>
		<tr>
			<th colspan=2>Images</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><image src=https://github.com/Nuno-Jesus/42_miniRT/assets/93390807/732f9349-d5b9-45a2-8920-a97ad2934c01></td>
			<td><image src=https://github.com/Nuno-Jesus/42_miniRT/assets/93390807/c71155e9-41df-44a5-9a1c-ed1f6aa50df0></td>
		</tr>
		<tr>
			<td><image src=https://github.com/Nuno-Jesus/42_miniRT/assets/93390807/90438e64-7050-481a-a096-55fd8353db96></td>
			<td><image src=https://github.com/Nuno-Jesus/42_miniRT/assets/93390807/28501715-e0cf-4456-84c6-ef077b7f78da></td>
		</tr>
	</tbody>
</table>

The mandatory part features:
	
	- Map file parser
	- Ambient and diffuse lighting
	- Display of planes, spheres and cylinders
	- Shapes intersections
	- Hard shadows
	- Ray tracing (without recursive steps)

## **Bonus Part**

<table align=center>
	<thead>
		<tr>
			<th colspan=2>Images</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><image src=https://github.com/Nuno-Jesus/42_miniRT/assets/93390807/b75fe0c8-63fe-410b-b110-dc8c020aae4c></td>
			<td><image src=https://github.com/Nuno-Jesus/42_miniRT/assets/93390807/cf5fcef6-e292-4845-8623-4567ac43cedf></td>
		</tr>
		<tr>
			<td><image src=https://github.com/Nuno-Jesus/42_miniRT/assets/93390807/ac27602e-443c-42cb-ab93-874b2de96dc9></td>
			<td><image src=https://github.com/Nuno-Jesus/42_miniRT/assets/93390807/ac7d3304-ce92-4ac5-b580-7a46c6200f54></td>
		</tr>
	</tbody>
</table>

The bonus part features the mandatory and also the following:

	- Phong Illumination Model (ambient + diffuse + specular)
	- Checkerboarded planes
	- Multi-spot lights
	- Colored light sources
	- Multithreaded rendering (our bonus)
	- Interectable menu (our bonus)

## 🎥 **Demo**

Here's a small demo with one of our maps.

https://github.com/Nuno-Jesus/42_miniRT/assets/93390807/ba59d829-5d08-402f-b527-e04b804afc38

## 🚨 **Disclaimer**
At 42, the C projects are built following a bunch of rules that enforce good coding style, stated in a file called **Norminette**. Some of them are:

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
	- No more than 5 local functions in 1 function
	- No more than 4 parameters in 1 function
	... 


## 📦 **Compilation**
To compile the mandatory part of the ray tracer you should run `make` in the terminal.

This rule will generate a `miniRT` file, which is the zipped version of all the object files. Running `make bonus` will compile the bonus part of the ray tracer. 

> **Note**
> The rules `make fast` and `make bfast` use threads to compile WAAAY faster the mandatory and bonus parts, respectively.

To launch the executable you should follow this syntax...

```sh
$ ./miniRT scene_name
```

> **Warning**
> On macOS, the `mlx_destroy_display` function does not exist, which will cause a compilation error, unless you comment it (`world.c` and `world_bonus.c`)

Where `scene_name` is the name of a file that represents the world map. The scene must have a `.rt` extension. You can find example scenes in the `scenes` folder.

## 🕹️ **Controls**

Mandatory:
- **W** - increments the camera y coordinate
- **A** - decrements the camera x coordinate
- **S** - decrements the camera y coordinate
- **D** - increments the camera x coordinate

Bonus:
- **M** - toggles/untoggles the menu, which displays several other commands you can try

## 💫 **Testing**

This project was tested using self-made tests.


## 📞 **Contact me**

Feel free to ask me any questions through Slack (**ncarvalh**).

