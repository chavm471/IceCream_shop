# Dessert Shop Program

## Overview

This program simulates a dessert shop where customers can place orders for various desserts including Ice Cream Cakes, Milkshakes, and Waffle Cones. The orders are managed using a B-tree data structure to efficiently store and display the desserts.

## Features

- Add orders for different types of desserts.
- Display all current orders.
- Remove all orders from the system.

## File Structure

- `btree.h`: Header file containing the class definitions for the Node and Btree classes.
- `btree.cpp`: Implementation file for the Node and Btree classes.
- `dessert.h`: Header file containing the class definitions for the Dessert and its derived classes (IceCreamCake, MilkShake, WaffleCone).
- `dessert.cpp`: Implementation file for the Dessert classes.
- `main.cpp`: Main driver file for the program.

## Dependencies

- C++11 or higher

## Compilation Instructions

This program was written and tested in a Linux environment. The following instructions assume the use of `g++` as the compiler.

1. Open a terminal window.
2. Navigate to the directory containing the source files.
3. Compile the program using the following command:

make

run the executable: ./shop
