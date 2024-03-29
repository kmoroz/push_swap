![codam logo](https://www.datocms-assets.com/4526/1560770259-logocodamblack-copy.svg)

## ❔ Basic Overview

The goal is to sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you have to manipulate various types of algorithms and choose the one (of many) most appropriate solutions for optimized data sorting.

## 👮‍♀️ Rules 

* The game is composed of 2 stacks named `a` and `b`.
* `a` contains a random number of either positive or negative numbers without
any duplicates and `b` is empty.
* The goal is to sort numbers into stack `a` in ascending order.
* To do this you have the following operations at your disposal: 

| Operation Acronym | Meaning | Description |
| --- | --- | --- |
| `sa` | `swap a` | swap the first 2 elements at the top of `stack a`. (Do nothing if there is only one or no elements).
| `sb` | `swap b` | swap the first 2 elements at the top of `stack b`. (Do nothing if there is only one or no elements).
| `ss` | `swap a` + `swap b` | `sa` and `sb` at the same time.
| `pa` | `push a` | take the first element at the top of `b` and put it at the top of `a`. (Do nothing if `b` is empty).
| `pb` | `push b` | take the first element at the top of `a` and put it at the top of `b`. (Do nothing if `a` is empty).
| `ra` | `rotate a` | shift up all elements of stack `a` by 1. The first element becomes the last one.
| `rb` | `rotate b` | shift up all elements of stack `b` by 1. The first element becomes the last one.
| `rb` | `rotate b` | shift up all elements of stack `b` by 1. The first element becomes the last one.
| `rr` | `rotate a` + `rotate b` | `ra` and `rb` at the same time.
| `rra` | `reverse rotate a` | shift down all elements of stack `a` by 1. The last element becomes the first one.
| `rrb` | `reverse rotate b` | shift down all elements of stack `b` by 1. The last element becomes the first one.
| `rrr` | `reverse rotate a` + `reverse rotate b` | `rra` and `rrb` at the same time.