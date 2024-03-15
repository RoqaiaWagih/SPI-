/*
 * SPI_program.c
 *
 * Created: 3/5/2024 11:44:44 AM
 *  Author: Dr. Roqaia Khalid
 */ 
#include "STD.h"
#include "BIT_MATH.h"


#include "SPI_interface.h"
#include "SPI_register.h"

void SPI_voidInitMaster(void){
	
	// Interrupt disable
	CLR_BIT( SPI_REGS->SPCR_REG, SPIE);
	//Data Order Configuration LSB
	SET_BIT( SPI_REGS->SPCR_REG, DORD);
	//Master Mode Configuration
	SET_BIT( SPI_REGS->SPCR_REG, MSTR);
	//Clock Polarity and Phase Configuration
	SET_BIT( SPI_REGS->SPCR_REG, CPOL);
	SET_BIT( SPI_REGS->SPCR_REG, CPHA);
	
	//Clock Speed Configuration
	CLR_BIT( SPI_REGS->SPCR_REG, SPR0);
	SET_BIT( SPI_REGS->SPCR_REG, SPR1);
	CLR_BIT( SPI_REGS->SPSR_REG, SPI2X);
	
	//Enable SPI
	//IN THE END BECAUSE IT CAN CAUSE A ERROR
	SET_BIT(SPI_REGS->SPCR_REG,SPE);
}

void SPI_voidInitSlave(void){
	
	// Interrupt disable
	CLR_BIT(SPI_REGS->SPCR_REG,SPIE);
	//Data Order Configuration LSB
	SET_BIT(SPI_REGS->SPCR_REG,DORD);
	//Slave Mode Configuration
	CLR_BIT(SPI_REGS->SPCR_REG,MSTR);
	//Clock Polarity and Phase Configuration
	SET_BIT(SPI_REGS->SPCR_REG,CPOL);
	SET_BIT(SPI_REGS->SPSR_REG,CPHA);
	
	
	
	//Enable SPI
	//IN THE END BECAUSE IT CAN CAUSE A ERROR
	SET_BIT(SPI_REGS->SPCR_REG,SPE);
}
//return 
void SPI_u8Transieve(u8 copy_u8TxData,u8* copy_pu8RxData){

if(copy_pu8RxData!=NULL)
{
	
	//trigger TX
	SPI_REGS->SPDR_REG =copy_u8TxData;
	
	//BUSY WAIT for SPI Flag
	while (0 == GET_BIT(SPI_REGS->SPSR_REG,SPIF));
	*copy_pu8RxData =SPI_REGS->SPDR_REG;
	
}
else{
	//return error state
}
}

