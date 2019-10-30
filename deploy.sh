ssh -t admin@roborio-8-frc.local "/usr/local/frc/bin/frcKillRobot.sh -t 2> /dev/null"
scp build/Build_RoboRIO_linux admin@roborio-8-frc.local:/home/lvuser/frcUserProgram