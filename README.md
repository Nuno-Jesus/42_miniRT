# **miniRT**
This project was graded <strong>125/100</strong>.

## 📝 **Authorship**

- [Mario Cardoso](https://github.com/jscaetano) ([**maricard**](https://profile.intra.42.fr/users/maricard))
- [Nuno Jesus](https://github.com/Nuno-Jesus) ([**ncarvalh**](https://profile.intra.42.fr/users/ncarvalh))

## 📒 **About**


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


## **Bonus Part**
![bonus_texture]()
![bonus_colored_multi_spot_lights]()

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

## 🚨 **Disclaimer**
At 42, the C projects are built following a bunch of rules that enforce good coding style, stated in a file called **Norminette**. Some of them are:

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
	- No more than 5 local functions in 1 function
	- No more than 4 parameters in 1 function
	... 

## 🔧 **Implementation**

<table align=center>
	<thead>
		<tr>
			<th>File Name</th>
			<th>Functionality</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><strong>libft/</strong> </td>
			<td>Contains 42 library functions and a few others added in the project</td>
		</tr>
		<tr>
			<td><strong>srcs/</strong> </td>
			<td>Contains all the source files</td>
		</tr>

		<tr>
			<td><strong>srcs/commands/</strong> </td>
			<td>Contains all the builtin commands</td>
		</tr>
		<tr>
			<td><strong>srcs/debug/</strong> </td>
			<td>A file with debugging helper functions</td>
		</tr>
		<tr>
			<td><strong>srcs/executor/</strong> </td>
			<td>Pre and post execution of processes handling</td>
		</tr>
		<tr>
			<td><strong>srcs/parser/</strong> </td>
			<td>Lexeme list and AST formation when input is received</td>
		</tr>
		<tr>
			<td><strong>srcs/signals/</strong> </td>
			<td>Has the signal installers and signal handlers</td>
		</tr>
		<tr>
			<td><strong>srcs/utils/</strong> </td>
			<td>Contains all the utility functions</td>
		</tr>
		<tr>
			<td><strong>input.c</strong> </td>
			<td>Infinite while loop to read input and where the main stages of input parsing are called</td>
		</tr>
		<tr>
			<td><strong>main.c</strong> </td>
			<td>Entry point of the program</td>
		</tr>
	</tbody>
</table>


## 📦 **Compilation**
To compile minishell you should run `make` in the terminal.

This rule will generate a `minishell` file, which is the zipped version of all the object files. To launch the executable you should follow this syntax...

```sh
$ ./minishell
```

## 💫 **Testing**

This project was tested using self-made tests and other colleagues pressure tests.


## 📞 **Contact me**

Feel free to ask me any questions through Slack (**ncarvalh**).

