export GOOS := linux
export GOARCH := arm
export CGO_ENABLED := 1
export CC := $(HOME)/.gradle/toolchains/frc/2022/roborio/bin/arm-frc2022-linux-gnueabi-gcc
export CXX := $(HOME)/.gradle/toolchains/frc/2022/roborio/bin/arm-frc2022-linux-gnueabi-g++

all:
	go build -o build/frcUserProgram go-frc

kill:
	ssh -t admin@roborio-$(TEAM)-frc.local "/usr/local/frc/bin/frcKillRobot.sh -t 2> /dev/null"

check-team:
ifndef TEAM
	$(error TEAM is undefined)
endif

deploy: check-team all kill
    scp build/frcUserProgram admin@roborio-$(TEAM)-frc.local:/home/lvuser/frcUserProgram
