//----------------------------------------------------------------------------
#include <bcm2835.h>
#include <stdio.h>
//----------------------------------------------------------------------------
#include "config.h"
#include "displaypx.h"
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
void main()
{
    unsigned char i,j,h;
	
	if (!bcm2835_init())
		return;
	
    ini_displaypx();
    
    bcm2835_gpio_clr(CS1_DISPLAY);
    

    setx_displaypx(0);
    write_displaypx(0x01);
        
    setx_displaypx(1);
    write_displaypx(0x02);
        
    setx_displaypx(2);
    write_displaypx(0x03);
    
    setx_displaypx(3);
    write_displaypx(0x04);
    
    setx_displaypx(4);
    write_displaypx(0x05);
    
    setx_displaypx(5);
    write_displaypx(0x06);
    
    setx_displaypx(6);
    write_displaypx(0x07);
    
    setx_displaypx(7);
    write_displaypx(0x08);
	

    for(i=0;i<8;i++)
    {
        setx_displaypx(i);
		for(j=0;j<64;j++)
		{
			setx_displaypx(i);
			sety_displaypx(j);

			printf("%X ", (int)read_data_display());
			
			setx_displaypx(i);
			sety_displaypx(j);
			write_displaypx(0x5a);
			
			bcm2835_delayMicroseconds(100);

			setx_displaypx(i);
			sety_displaypx(j);
			printf("%X - ", (int)read_data_display());
		}
	printf("\n");
    }

    bcm2835_gpio_set(CS1_DISPLAY);
    
    bcm2835_gpio_clr(CS2_DISPLAY);
    write_displaypx(0xff);
    bcm2835_gpio_set(CS2_DISPLAY);

    for(i=0;i<10;i++) 
       printf("%d ",(int)read_com_displaypx());

	printf("\n");
    bcm2835_close();

    return;
}
//----------------------------------------------------------------------------
