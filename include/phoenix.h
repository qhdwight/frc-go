typedef void CTalon;

#ifdef __cplusplus
extern "C" {
#endif

CTalon* CTRE_CreateTalon(int port);

void CTRE_Set(CTalon* talon, double output);

void CTRE_Follow(CTalon* master, CTalon* slave);

#ifdef __cplusplus
}
#endif
