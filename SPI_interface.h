/*
 * SPI_interface.h
 *
 * Created: 3/5/2024 
 *  Author: Roqaia Khalid
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidInitMaster(void);
void SPI_voidInitSlave(void);

void SPI_u8Transieve(u8 copy_u8TxData,u8* copy_pu8RxData);



#endif /* SPI_INTERFACE_H_ */
