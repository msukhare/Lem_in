# Lem_in

## About Lem_in

* The goal of lem_in is to find the bests paths to cross an anthill from "start" room to "end" room.

* A number of ants is define in anthill, only one ant can be placed on the path per turn.

* Ants can't be in the same room at the same time.

* Using [backtracking](https://en.m.wikipedia.org/wiki/Backtracking) to find the paths, and an graph algorithm.

## What do you need to compile push_swap ?

* gcc or clang

* make

* C library

* ar

## How to compile Lem_in ?

* Use `make` to compile `lem_in`.

## How does Lem_in work ?

* `./lem_in < MAP` map is define like that:
```
3 ##it's the number of ants

##start

0 1 12

##end

1 5 0

2 5 4

3 13 0

0-2

2-3

3-1
```
- `##start` is the room where ant are, `##end` is the room where the ant must go.

- for exemple `01 1 12`, `01`--> name of room can be string or number, `1`--> x coordinate, `12`--> y coordinate.

-`0-2` --> connection between rooms, means room `0` connecte to `2` and `2` connecte to `0`.

- this map give you this result:

```
L1-2

L1-3 L2-2

L1-1 L2-3 L3-2

L2-1 L3-3

L3-1

```
- `L1-2` `Lnumber` means ant number, `2` is the name of room where the ant is. 


## Rules of Makefile:

all: compile `libft.a`, `lem_in`

clean: delete objects

fclean: call clean and delete `libft.a`, `lem_in`

re: call fclean and all
