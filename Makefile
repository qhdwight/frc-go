export GOOS := linux
export GOARCH := arm
export CGO_ENABLED := 1
export CC := $(HOME)/.gradle/toolchains/frc/2022/roborio/bin/arm-frc2022-linux-gnueabi-gcc
export CXX := $(HOME)/.gradle/toolchains/frc/2022/roborio/bin/arm-frc2022-linux-gnueabi-g++
WPI_LIB_VER := 2022.2.1
NI_LIB_VER := 2022.2.3

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

deps:
	mkdir -p build && cd build; \
	wget -nc https://frcmaven.wpi.edu/artifactory/release/edu/wpi/first/ni-libraries/visa/$(NI_LIB_VER)/visa-$(NI_LIB_VER)-linuxathena.zip; \
	wget -nc https://frcmaven.wpi.edu/artifactory/release/edu/wpi/first/ni-libraries/chipobject/$(NI_LIB_VER)/chipobject-$(NI_LIB_VER)-linuxathena.zip; \
	wget -nc https://frcmaven.wpi.edu/artifactory/release/edu/wpi/first/ni-libraries/netcomm/$(NI_LIB_VER)/netcomm-$(NI_LIB_VER)-linuxathena.zip; \
	wget -nc https://frcmaven.wpi.edu/artifactory/release/edu/wpi/first/ni-libraries/runtime/$(NI_LIB_VER)/runtime-$(NI_LIB_VER)-linuxathena.zip; \
	wget -nc https://frcmaven.wpi.edu/artifactory/release/edu/wpi/first/wpiutil/wpiutil-cpp/$(WPI_LIB_VER)/wpiutil-cpp-$(WPI_LIB_VER)-linuxathena.zip; \
	wget -nc https://frcmaven.wpi.edu/artifactory/release/edu/wpi/first/hal/hal-cpp/$(WPI_LIB_VER)/hal-cpp-$(WPI_LIB_VER)-linuxathena.zip; \
	unzip -jo "./*.zip"; \
	rm ./*.so.debug; \
	for f in ./*.so.*; do mv "$$f" "$${f%.so.*}.so"; done;
