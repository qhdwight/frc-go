# Golang for FRC Robotics

## What?

[Go](https://golang.org) is a compiled language made by some very smart people at Google which is an interesting combination of... C and Python? It has a garbage collector but also the ability to manage your own memory if you know what you are doing. It also has a very nice standard library useful for many modern programming tasks. Also has reflection and a nice emphasis on multi-threading.

## Why?

Go is fast and hits those sweet fifty updates per second. And also it has CGo, which allows it to link natively into C code making this all possible. I also just really like writing Go.

## Okay, how?

I yoinked the built binaries for HAL etc. and use CGo to link them into Go. Go also has the ability to cross-compile for ARM processors, which is what the roboRIO is.

## Project Layout?

`starter.go` Has the main function, starts the program

`frc/include` Header file for the HAL

`frc/lib` Libraries for HAL

`frc/rev/` Support for the low-level Spark Max code (untested as of right now)

`frc/phoenix` Support for the CTRE Talon

## What is this not?

Anything special. I do not call it Go-WPILib since it is only really the HAL right now. A lot of stuff is missing and must be added manually to work.

## How are C++ headers linked with CGo?

Glad you asked about this nightmare. CGo does not play nice with C++, so you will notice I have a C to C++ wrapper in `frc/phoenix/include` named `phoenix.h`, which has linkage to `frc/phoenix/phoenix.cpp`, which actually takes care of the C++ implementation since CGo can compile that. Same idea with the Sparks. The C only sees the speed controller objects as a void pointer, and the bridges cast them into their proper types. It seems sketchy but it works really well. The only annoying part is that a new function must be created in the "bridge" file every time, unlike the HAL where everything is in native C.

## How to build it?

So there is a lot of setup that must happen since we are cross-compiling to ARM using the roboRIO athena toolchain.

The following environment variables must be set:

* `GOOS=linux`
* `GOARCH=arm`
* `GOARM=7`
* `CGO_ENABLED=1`
* `CC=<home>/.gradle/toolchains/frc/2019/roborio/bin/arm-frc2019-linux-gnueabi-gcc`
* `CXX=<home>/.gradle/toolchains/frc/2019/roborio/bin/arm-frc2019-linux-gnueabi-g++`

And then to build, `go build go-frc`. I use GoLand from JetBrains to set up these tasks so it is a lot easier.
