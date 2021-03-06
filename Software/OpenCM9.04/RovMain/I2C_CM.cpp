//----------------------------------------------------------------------------
//    프로그램명 	: I2C
//
//    만든이     	: Baram ( chcbaram@paran.com )
//
//    날  짜     : 
//    
//    최종 수정  	: 
//
//    MPU_Type	: 
//
//    파일명     	: I2C.cpp
//----------------------------------------------------------------------------
/*
	Based on Multiwii : https://github.com/multiwii/multiwii-firmware
*/
       

#include <Arduino.h> 
#include "I2C_CM.h"
#include "I2Cdev.h"



cI2C I2C;







/*---------------------------------------------------------------------------
     TITLE   : I2C
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
cI2C::cI2C()
{	
}




/*---------------------------------------------------------------------------
     TITLE   : begin
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
void cI2C::begin( void )
{
     HwI2C.begin();
}




/*---------------------------------------------------------------------------
     TITLE   : rep_start
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
void cI2C::rep_start(uint8_t address) 
{
}





/*---------------------------------------------------------------------------
     TITLE   : stop
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
void cI2C::stop(void) 
{
}





/*---------------------------------------------------------------------------
     TITLE   : stop
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
void cI2C::write(uint8_t data ) 
{
}





/*---------------------------------------------------------------------------
     TITLE   : read_ack
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
uint8_t cI2C::read_ack(void) 
{
     return 0;
}





/*---------------------------------------------------------------------------
     TITLE   : read_ack
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
uint8_t cI2C::read_nak(void) 
{
	return 0;
}




/*---------------------------------------------------------------------------
     TITLE   : read_reg_to_buf
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
void cI2C::read_reg_to_buf(uint8_t add, uint8_t reg, uint8_t *buf, uint8_t size) 
{
     if( I2Cdev::readBytes( add, reg, size, buf ) < 0 ) i2c_errors_count++;     
}





/*---------------------------------------------------------------------------
     TITLE   : get_six_raw_adc
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
void cI2C::get_six_raw_adc(uint8_t add, uint8_t reg) 
{
	read_reg_to_buf(add, reg, rawADC, 6);
}





/*---------------------------------------------------------------------------
     TITLE   : write_reg
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
void cI2C::write_reg(uint8_t add, uint8_t reg, uint8_t val) 
{
     if( I2Cdev::writeByte( add, reg, val ) < 0 ) i2c_errors_count++;
}





/*---------------------------------------------------------------------------
     TITLE   : read_reg
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
uint8_t cI2C::read_reg(uint8_t add, uint8_t reg) 
{
	uint8_t val;

	read_reg_to_buf(add, reg, &val, 1);

	return val;
}
