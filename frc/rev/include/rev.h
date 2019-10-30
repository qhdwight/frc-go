typedef void CSpark;

#ifdef __cplusplus
extern "C" {
#endif

CSpark* REV_CreateSpark(int port);

void REV_Set(CSpark* spark, double output);

#ifdef __cplusplus
}
#endif
