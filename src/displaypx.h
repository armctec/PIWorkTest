//----------------------------------------------------------------------------
#ifndef __DISPLAYPX_H__
#define __DISPLAYPX_H__
//----------------------------------------------------------------------------
#include "config.h"
//----------------------------------------------------------------------------
void ini_displaypx();

void write_data_display(unsigned char byte);
unsigned char read_data_display(void);

void write_displaypx(unsigned char byte);
void sety_displaypx(unsigned char byte);
void setx_displaypx(unsigned char byte);

void envdata_displaypx(unsigned char byte);
void envcom_displaypx(unsigned char byte);

unsigned char read_data_displaypx(void);
unsigned char read_com_displaypx(void);

void busy_displaypx(void);
//----------------------------------------------------------------------------
extern unsigned char modo;
//----------------------------------------------------------------------------
#endif
