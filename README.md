# 0x16. C - Simple Shell

This is a simple UNIX command interpreter.

## Description

**hsh** is a simple sh-compatible command language interpreter that executes commands read from standard input or file.

### Invocation

Usage: **hsh**

**hsh** is invoked by compiling all `.c` files in the repository and running the resulting executable files:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./shs
```

**hsh** can be invoked interactively.
Example:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also can be invoked non-interactively.
Example:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
### Environment

When invoked, **hsh** receives and copies the environment of the parent process in which it is executed. This environment is an array of *name-value* strings describing variables *NAME=VALUE*.

## Authors

* John Nyokabi <[JohnNyokabi](https://github.com/JohnNyokabi)>
* Samuel Ng'ang'a <[Sammie2022](https://github.com/Sammie2022)>
