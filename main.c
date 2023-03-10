/************************************/
/*	Author		: Eslam_Hosny		*/
/*	SWC			: LIGHT				*/
/*	Layer		: APP				*/
/*	Version   	: 1.0				*/
/*	Date	  	: December, 2, 2022	*/
/*	Last Edit 	: N/A				*/
/************************************/
#define F_CPU	8000000UL
#include <util/delay.h>
#include "LSTD_types.h"
#include "PORT_interface.h"
#include "MDIO_interface.h"
#include "CLCD_interface.h"
#include "MADC_interface.h"
#include "MGIE_interface.h"

void ADC_Notif(void);
u16 L_u16RChannal;
u32 L_u32MillVol;

int main (void)
{
	PORT_voidInit();
	MADC_voidInit();
	CLCD_voidInit();
	CLCD_voidClear();
	MGIE_voidEnableGIE();


	while(1)
	{
		MADC_u8StartConversionASynch(0, &L_u16RChannal, &L_u32MillVol, &ADC_Notif);

	}

	return 0;
}

void ADC_Notif(void)
{
	MDIO_u8SetPortValue(MDIO_PORTB, L_u16RChannal);
	CLCD_voidWriteNumber(L_u16RChannal);
	CLCD_voidClear();
}

