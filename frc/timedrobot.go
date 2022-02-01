package frc

type timedrobot interface {
	getPeriod() float64
	robotInit()
	disabledInit()
	disabledPeriodic()
	robotPeriodic()
	testInit()
	testPeriodic()
	autonomousInit()
	autonomousPeriodic()
	teleopInit()
	teleopPeriodic()
}
