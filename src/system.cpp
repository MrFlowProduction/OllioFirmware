#include <system.h>


#ifdef __cplusplus
  extern "C" {
#endif
 
uint8_t temprature_sens_read();
 
#ifdef __cplusplus
}
#endif
 
uint8_t temprature_sens_read();


float internal_temp(){
  return (temprature_sens_read() - 32) / 1.8;
}