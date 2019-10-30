typedef void CTalon;

#ifdef __cplusplus
extern "C" {
#endif

CTalon* CTRE_CreateTalon(int port);

void CTRE_Set(CTalon* talon, double output);

void CTRE_Follow(CTalon* slave, CTalon* master);

#ifdef __cplusplus
}
#endif
