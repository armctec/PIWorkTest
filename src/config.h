//----------------------------------------------------------------------------
#ifndef __CONFIG_H__
#define __CONFIG_H__
//----------------------------------------------------------------------------
#include <bcm2835.h>
//----------------------------------------------------------------------------
/*
PINOS:

 1 - CSA - 23
 2 - CSB - 24
 3 - VSS - 
 4 - VDD - 
 5 - VO  - 
 6 - RS  - 7
 7 - RW  - 8
 8 - E   - 25
 9 - DB0 - 4
10 - DB1 - 17
11 - DB2 - 27
12 - DB3 - 22
13 - DB4 - 10
14 - DB5 - 9
15 - DB6 - 11
16 -z DB7 - 15
17 - RST - 14
18 - VEE - 
19 - A   -
20 - K   -
*/
//----------------------------------------------------------------------------
#define RS_DISPLAY      RPI_GPIO_P1_26
#define RW_DISPLAY      RPI_GPIO_P1_24
#define EN_DISPLAY      RPI_GPIO_P1_22
#define CS2_DISPLAY     RPI_GPIO_P1_18
#define CS1_DISPLAY     RPI_GPIO_P1_16
#define RST_DISPLAY     RPI_GPIO_P1_08

#define DATA_DISP_1     RPI_GPIO_P1_07
#define DATA_DISP_2    	RPI_GPIO_P1_11
#define DATA_DISP_3    	RPI_GPIO_P1_13
#define DATA_DISP_4    	RPI_GPIO_P1_15
#define DATA_DISP_5    	RPI_GPIO_P1_19
#define DATA_DISP_6    	RPI_GPIO_P1_21
#define DATA_DISP_7    	RPI_GPIO_P1_23
#define DATA_DISP_8    	RPI_GPIO_P1_10
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------
