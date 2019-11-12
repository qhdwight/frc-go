# Golang for FRC Robotics

## What?

[Go](https://golang.org) is a compiled language made by some very smart people at Google which is an interesting combination of... C and Python? It has a garbage collector but also the ability to manage your own memory if you know what you are doing. It also has a very nice standard library useful for many modern programming tasks. Also has reflection and a nice emphasis on multi-threading.

## Why?

Go is fast and hits those sweet fifty updates per second. And also it has cgo, which allows it to link natively into C code making this all possible. I also just really like writing Go.

## Okay, how?

I yoinked the built binaries for HAL etc. and use cgo to link them into Go. Go also has the ability to cross-compile for ARM processors, which is what the roboRIO is.

## Project Layout?

`starter.go` Has the main function, starts the program

`frc/include` Header file for the HAL

`frc/lib` Libraries for HAL

`frc/rev/` Support for the low-level Spark Max code (untested as of right now)

`frc/phoenix` Support for the CTRE Talon