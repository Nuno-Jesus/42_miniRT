# **Libnc**


## 📒 **About**
This library is an augment of the 42 library. It was designed to contain more data structures (other than just linked lists) to be used in the 42 projects. The library is still under development and more data structures and functions might be added in the future. Consider this as an early access version.

## 🚨 **Disclaimer**
At 42, the C projects are built following a bunch of rules that enforce good coding style. Some of them are:

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
	- No more than 5 local variables in 1 function
	- No more than 4 parameters per function
	... 

## 🔧 **Implementation**
The `libnc` is composed of what I like to call modules. Each module is a data structure or a set of functions that are related to each other. Each module is composed of a header file and a source file.

## 📚 **Modules**
There are the legacy modules that are already present in the 42 library (and some more)...

| Module | Description |
| ------ | ----------- |
| [**nc_conversions**](/includes/nc_conversions.h) | Functions to convert between data types |
| [**nc_is**](/includes/nc_is.h) | Functions that return booleans |
| [**nc_memory**](/includes/nc_memory.h) | Functions to manipulate memory |
| [**nc_print**](/includes/nc_print.h) | Functions to print to file descriptors |
| [**nc_str**](/includes/nc_str.h) | Functions to manipulate strings |
| [**nc_linked_list**](/includes/nc_linked_list.h) | Functions to manipulate linked lists |

... and the new ones, mainly data structures, which I missed during my time at 42. C doesn't have a lot of data structures, so I decided to implement some of them, even though they are not the most understandable ones.

| Module | Description |
| ------ | ----------- |
| [**nc_binary_search_tree**](/includes/nc_binary_search_tree.h) | Functions to manipulate Binary Search Trees (BST) |
| [**nc_dictionary**](/includes/nc_dictionary.h) | Functions to manipulate `Python` dictionaries / `C++` maps |
| [**nc_matrix**](/includes/nc_matrix.h) | Functions to manipulate matrices |
| [**nc_pair**](/includes/nc_pair.h) | Functions to manipulate `C++` pairs |
| [**nc_vector**](/includes/nc_vector.h) | Functions to manipulate `C++` vectors |

## 📦 **Compilation**
To compile the library you should run `make` in the terminal. 

Both rules generate a `libnc.a` file, which is zipped version of all the object files. Imagine you have a `main.c` file and you want to use your library in it. You can compile it by running the following command:

```sh
$ cc -Wall -Wextra -Werror main.c -lnc -L path/to/libnc/ -I path/to/libnc/header/folder
```

or

```sh
$ cc -Wall -Wextra -Werror main.c path/to/libnc/libnc.a -I path/to/libnc/header/folder
```

## 📞 **Contact me**
Feel free to ask me any questions through Slack (**ncarvalh**).

