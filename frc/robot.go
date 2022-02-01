package frc

import (
	"go-frc/frc/phoenix"
)

const (
	DefaultPeriod = 0.02 // Seconds, should correspond to running the robot loop 50 times a second
)

type Robot struct {
	right, left *phoenix.Talon
}

func (robot Robot) getPeriod() float64 {
	return DefaultPeriod
}

func (robot Robot) robotInit() {
	robot.right = phoenix.NewTalon(6)
	phoenix.NewSlaveTalon(5, robot.right)
	phoenix.NewSlaveTalon(4, robot.right)
	robot.left = phoenix.NewTalon(1)
	phoenix.NewSlaveTalon(2, robot.left)
	phoenix.NewSlaveTalon(3, robot.left)
}

func (robot Robot) disabledInit() {

}

func (robot Robot) disabledPeriodic() {

}

func (robot Robot) robotPeriodic() {

}

func (robot Robot) testInit() {

}

func (robot Robot) testPeriodic() {

}

func (robot Robot) autonomousInit() {

}

func (robot Robot) autonomousPeriodic() {
}

func (robot Robot) teleopInit() {

}

func (robot Robot) teleopPeriodic() {
	throttle := getJoystickAxis(0, 1)
	turn := getJoystickAxis(0, 0)
	robot.left.Set(turn - throttle)
	robot.right.Set(turn + throttle)
}
