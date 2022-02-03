package wpi

type TimedRobot interface {
	GetPeriod() float64
	RobotInit()
	DisabledInit()
	DisabledPeriodic()
	RobotPeriodic()
	TestInit()
	TestPeriodic()
	AutonomousInit()
	AutonomousPeriodic()
	TeleopInit()
	TeleopPeriodic()
}
