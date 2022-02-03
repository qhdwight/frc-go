package frc

import (
	"go-frc/frc/phoenix"
	"go-frc/frc/wpi"
)

const (
	DefaultPeriod = 0.02 // Seconds, should correspond to running the robot loop 50 times a second
)

type Robot struct {
	right, left *phoenix.Talon
}

func (robot Robot) GetPeriod() float64 {
	return DefaultPeriod
}

func (robot Robot) RobotInit() {
	robot.right = phoenix.NewTalon(6)
	phoenix.NewSlaveTalon(5, robot.right)
	phoenix.NewSlaveTalon(4, robot.right)
	robot.left = phoenix.NewTalon(1)
	phoenix.NewSlaveTalon(2, robot.left)
	phoenix.NewSlaveTalon(3, robot.left)
}

func (robot Robot) DisabledInit() {

}

func (robot Robot) DisabledPeriodic() {

}

func (robot Robot) RobotPeriodic() {

}

func (robot Robot) TestInit() {

}

func (robot Robot) TestPeriodic() {

}

func (robot Robot) AutonomousInit() {

}

func (robot Robot) AutonomousPeriodic() {
}

func (robot Robot) TeleopInit() {

}

func (robot Robot) TeleopPeriodic() {
	throttle := wpi.GetJoystickAxis(0, 1)
	turn := wpi.GetJoystickAxis(0, 0)
	robot.left.Set(turn - throttle)
	robot.right.Set(turn + throttle)
}
