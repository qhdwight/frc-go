typedef void CTalon;

CTalon* CTRE_CreateTalon(int port);

void CTRE_Set(CTalon* talon, double output);

void CTRE_Follow(CTalon* slave, CTalon* master);
