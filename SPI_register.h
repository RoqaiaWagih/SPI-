/*
 * SPI_register.h
 *
 * Created: 3/5/2024 
 *  Author: Roqaia Khalid
 */ 


#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

typedef struct{
	
	u8 SPCR_REG;
	u8 SPSR_REG;
	u8 SPDR_REG;
	
	} SPI_type;
	
#define  SPI_REGS ((volatile SPI_type*) 0x2D)
	/* spi_regs -> spdr_reg
	  (*spi_regs) .spdr_reg
	*/
	
	
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI Control Register - SPCR */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0
	
#define ENABLE_INTERRUPT   5
#define DISABLE_INTERRUPT   9

#define LSB_FIRST    8
#define MSB_FIRST    11

#define MASTER  0
#define SLAVE   3

#define IDLE_LOW   2
#define IDLE_HIGH  5


#define ZERO   0
#define ONE    6


#define QUARTER_FREQ   2
#define HALF_FREQ  6	






#endif /* SPI_REGISTER_H_ */
