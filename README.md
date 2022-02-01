[![Actions Status](https://github.com/qhdwight/frc-go/workflows/Go/badge.svg)](https://github.com/qhdwight/frc-go/actions)

# Golang for FRC Robotics

## What?

[Go](https://golang.org) is a compiled language made by some very smart people at Google which is an interesting combination of... C and Python? It has a garbage collector but also the ability to manage your own memory if you know what you are doing. The standard library is extensive and makes many modern programming tasks easy. In addition to his, it has reflection and a nice emphasis on multi-threading. I also feel that the overall code footprint is smaller compared to most languages for the same tasks, but yes that is just my opinion.

## Why?

Go is fast and hits those sweet fifty updates per second. It also has CGo, which allows it to link natively into C code making this all possible. The main reason why though is because I really enjoy writing Go.

## Okay, how?

I yoinked the built binaries for HAL etc. and use CGo to link them into Go. Go also has the ability to cross-compile for ARM processors, which is what the roboRIO has.

## Project Layout?

`starter.go` Has the main function, starts the program

`frc/robot.go` Contains the code for interacting with the driver station and running corresponding behavior. Right now, it is just set up with P-Drive for our 2017 team 8 robot "Vali" which had a 6 motor CIM drive-train using Talons. This is where you edit code if you want to make your robot work with this project.

`**/include` Header files

`**/lib` Libraries built for roborRIO ARM processor

`frc/rev/` Support for the low-level Spark MAX library (untested as of right now)

`frc/phoenix` Support for the CTRE Talon SRX

## What is this not?

Anything special. I'm not call it Go-WPILib since it is only really works with the HAL right now. A lot of stuff is missing and must be added manually to work.

## How are C++ headers linked with CGo?

Glad you asked about this nightmare. CGo does not play nice with C++, so you will notice I have a C to C++ wrapper in `frc/phoenix/include` named `phoenix.h`, which has linkage to `frc/phoenix/phoenix.cpp`, which actually takes care of the C++ implementation since CGo can compile that. Same idea with the Sparks. The C only sees the speed controller objects as a void pointer, and the bridges cast them into their proper types. It seems sketchy but it works really well. The only annoying part is that a new function must be created in the "bridge" file every time, unlike the HAL where everything is in native C.

## How do I build it?

[Install Go](https://golang.org/doc/install) and make sure that it is added to your PATH.
The toolchain can be installed in any C++ robot project with the `installRoboRioToolchain` task.

### Using the makefile (EASY)

Install the toolchain and run `make` in the root directory

### Manually (Windows)

The following environment variables must be set:

* `GOOS=linux`
* `GOARCH=arm`
* `GOARM=7`
* `CGO_ENABLED=1`
* `CC=<home>/.gradle/toolchains/frc/2022/roborio/bin/arm-frc2022-linux-gnueabi-gcc`
* `CXX=<home>/.gradle/toolchains/frc/2022/roborio/bin/arm-frc2022-linux-gnueabi-g++`

And then to build, `go build -o build/Build_RoboRIO_linux go-frc`. I use GoLand from JetBrains to set up these tasks so it is a lot easier.

## How do I put this on my robot?

### Using the makefile (EASY)

`make deploy TEAM=<your team number>`

### Manually (Windows)

You must copy the binary to `/home/lvuser/frcUserProgram` on the roboRIO somehow, since this is the executable that it wants to run. I recommend using WinSCP/`scp`to do so and then restarting code in the driver station.
