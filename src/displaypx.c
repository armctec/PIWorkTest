#ifndef __DISPLAYPX_C__
#define __DISPLAYPX_C__
//----------------------------------------------------------------------------
#include "config.h"
#include "displaypx.h"
//----------------------------------------------------------------------------
unsigned char modo = 0;
//----------------------------------------------------------------------------
void modo_entrada_display(void)
{
	bcm2835_gpio_fsel(DATA_DISP_1, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(DATA_DISP_2, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(DATA_DISP_3, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(DATA_DISP_4, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(DATA_DISP_5, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(DATA_DISP_6, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(DATA_DISP_7, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(DATA_DISP_8, BCM2835_GPIO_FSEL_INPT);
	
	bcm2835_gpio_set_pud(DATA_DISP_1, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(DATA_DISP_2, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(DATA_DISP_3, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(DATA_DISP_4, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(DATA_DISP_5, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(DATA_DISP_6, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(DATA_DISP_7, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(DATA_DISP_8, BCM2835_GPIO_PUD_UP);
	
	modo = 0;
}
//----------------------------------------------------------------------------
void modo_saida_display(void)
{
	if(modo == 1)
		return;

	bcm2835_gpio_fsel(DATA_DISP_1, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(DATA_DISP_2, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(DATA_DISP_3, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(DATA_DISP_4, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(DATA_DISP_5, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(DATA_DISP_6, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(DATA_DISP_7, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(DATA_DISP_8, BCM2835_GPIO_FSEL_OUTP);
	
	bcm2835_gpio_set_pud(DATA_DISP_1, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(DATA_DISP_2, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(DATA_DISP_3, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(DATA_DISP_4, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(DATA_DISP_5, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(DATA_DISP_6, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(DATA_DISP_7, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(DATA_DISP_8, BCM2835_GPIO_PUD_OFF);	
	
	modo = 1;
}
//----------------------------------------------------------------------------
void reset_default_pins(void)
{
	bcm2835_gpio_set_pud(RS_DISPLAY, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RW_DISPLAY, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(EN_DISPLAY, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(CS2_DISPLAY, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(CS1_DISPLAY, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RST_DISPLAY, BCM2835_GPIO_PUD_OFF);
	
	modo_entrada_display();

	bcm2835_gpio_fsel(RS_DISPLAY, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(RW_DISPLAY, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(EN_DISPLAY, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(CS2_DISPLAY, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(CS1_DISPLAY, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(RST_DISPLAY, BCM2835_GPIO_FSEL_OUTP);
}
//----------------------------------------------------------------------------
void ini_displaypx()
{
    reset_default_pins();

    bcm2835_gpio_clr(RST_DISPLAY);
    bcm2835_delayMicroseconds(100);
    bcm2835_gpio_set(RST_DISPLAY);
	
    
    bcm2835_gpio_clr(CS1_DISPLAY);
    bcm2835_gpio_clr(CS2_DISPLAY);
    bcm2835_delayMicroseconds(100);	

    envcom_displaypx(0x3F);
    bcm2835_gpio_set(CS1_DISPLAY);
    bcm2835_gpio_set(CS2_DISPLAY);
}
//----------------------------------------------------------------------------
void write_data_display(unsigned char byte)
{
    modo_saida_display();

    bcm2835_gpio_write(DATA_DISP_1, byte&0x01!=0?HIGH:LOW);
    bcm2835_gpio_write(DATA_DISP_2, byte&0x02!=0?HIGH:LOW);
    bcm2835_gpio_write(DATA_DISP_3, byte&0x04!=0?HIGH:LOW);
    bcm2835_gpio_write(DATA_DISP_4, byte&0x08!=0?HIGH:LOW);
    bcm2835_gpio_write(DATA_DISP_5, byte&0x10!=0?HIGH:LOW);
    bcm2835_gpio_write(DATA_DISP_6, byte&0x20!=0?HIGH:LOW);
    bcm2835_gpio_write(DATA_DISP_7, byte&0x40!=0?HIGH:LOW);
    bcm2835_gpio_write(DATA_DISP_8, byte&0x80!=0?HIGH:LOW);
	
}
//----------------------------------------------------------------------------
unsigned char read_data_display(void)
{
	unsigned char tmp;
	
	modo_entrada_display();
	
	tmp = bcm2835_gpio_lev(DATA_DISP_1)==1?0x01:0;
	tmp |= bcm2835_gpio_lev(DATA_DISP_2)==1?0x02:0;
	tmp |= bcm2835_gpio_lev(DATA_DISP_3)==1?0x04:0;
	tmp |= bcm2835_gpio_lev(DATA_DISP_4)==1?0x08:0;
	tmp |= bcm2835_gpio_lev(DATA_DISP_5)==1?0x10:0;
	tmp |= bcm2835_gpio_lev(DATA_DISP_6)==1?0x20:0;
	tmp |= bcm2835_gpio_lev(DATA_DISP_7)==1?0x40:0;
	tmp |= bcm2835_gpio_lev(DATA_DISP_8)==1?0x80:0;
	
	return tmp;
}
//----------------------------------------------------------------------------
void write_displaypx(unsigned char byte)
{
    envdata_displaypx(byte);
}
//----------------------------------------------------------------------------
void sety_displaypx(unsigned char byte)
{
    envcom_displaypx((byte&0x3f)|0x40);
}
//----------------------------------------------------------------------------
void setx_displaypx(unsigned char byte)
{
    envcom_displaypx((byte&0x7)|0xB8);
}
// ---------------------------------------------------------------------------
void envdata_displaypx(unsigned char byte)
{
    bcm2835_gpio_clr(RW_DISPLAY);
    bcm2835_gpio_set(RS_DISPLAY);
    write_data_display(byte);
	
    bcm2835_gpio_set(EN_DISPLAY);
    
    bcm2835_delayMicroseconds(100);
    
    bcm2835_gpio_clr(EN_DISPLAY);
    bcm2835_gpio_set(RW_DISPLAY);
    
    write_data_display(0xFF);
    
    busy_displaypx();
}
// ---------------------------------------------------------------------------
void envcom_displaypx(unsigned char byte)
{
    bcm2835_gpio_clr(RW_DISPLAY);
    bcm2835_gpio_clr(RS_DISPLAY);
    write_data_display(byte);
    bcm2835_gpio_set(EN_DISPLAY);

    bcm2835_delayMicroseconds(100);

    bcm2835_gpio_clr(EN_DISPLAY);
    bcm2835_gpio_set(RS_DISPLAY);
    bcm2835_gpio_set(RW_DISPLAY);
    
    write_data_display(0xFF);
    
    busy_displaypx();
}
// ---------------------------------------------------------------------------
unsigned char read_data_displaypx(void)
{
    unsigned tmp;
	
	bcm2835_gpio_set(RW_DISPLAY);
    bcm2835_gpio_set(RS_DISPLAY);
    bcm2835_gpio_set(EN_DISPLAY);

    bcm2835_delayMicroseconds(100);
	
	tmp = read_data_display();

    bcm2835_gpio_clr(EN_DISPLAY);
    
    return tmp;
}
// ---------------------------------------------------------------------------
unsigned char read_com_displaypx(void)
{
    unsigned tmp;
	
	bcm2835_gpio_set(RW_DISPLAY);
    bcm2835_gpio_clr(RS_DISPLAY);
    bcm2835_gpio_set(EN_DISPLAY);

    bcm2835_delayMicroseconds(100);
	
	tmp = read_data_display();

    bcm2835_gpio_clr(EN_DISPLAY);
    bcm2835_gpio_clr(RS_DISPLAY);
    
    return tmp;
}
// ---------------------------------------------------------------------------
void busy_displaypx(void)
{
/*	while(read_com_displaypx()&0x80)
	{
	}
*/
	bcm2835_delayMicroseconds(4000);
}
// ---------------------------------------------------------------------------
#endif
