
# Atmega32 SPI Driver

This repository contains a SPI (Serial Peripheral Interface) driver for the Atmega32 microcontroller.

## Overview

The Serial Peripheral Interface (SPI) is a synchronous serial communication interface used for short-distance communication between devices. This driver provides functions to initialize and configure the SPI peripheral on the Atmega32 microcontroller, as well as transmit and receive data.


## Pins Configuration

The SPI pins on Atmega32 are as follows:

- `MISO` (Master In Slave Out): Data output from the slave to the master.
- `MOSI` (Master Out Slave In): Data output from the master to the slave.
- `SCK` (Serial Clock): Clock signal provided by the master for synchronizing data transmission.
- `SS` (Slave Select): Signal used by the master to select a specific slave device for communication.

## Registers
## Registers Configuration

The SPI peripheral on the Atmega32 is controlled through several registers:

- `SPCR` (SPI Control Register): Controls SPI operation modes, clock rate, and interrupt enable.
- `SPSR` (SPI Status Register): Contains status flags indicating the status of SPI transmission.
- `SPDR` (SPI Data Register): Data register for data transmission and reception.

### SPCR (SPI Control Register)

This register controls the operation of the SPI.

| Bit | Name      | Description                                                  |
| --- | --------- | ------------------------------------------------------------ |
| 7   | SPIE      | SPI Interrupt Enable                                         |
| 6   | SPE       | SPI Enable                                                   |
| 5   | DORD      | Data Order (0 - MSB first, 1 - LSB first)                   |
| 4   | MSTR      | Master/Slave Select (1 - Master mode, 0 - Slave mode)        |
| 3   | CPOL      | Clock Polarity (0 - SCK low when idle, 1 - SCK high when idle) |
| 2   | CPHA      | Clock Phase (0 - sample on leading edge, 1 - sample on trailing edge) |
| 1:0 | SPR1:SPR0 | SPI Clock Rate Select (00 - fosc/4, 01 - fosc/16, 10 - fosc/64, 11 - fosc/128) |

### SPSR (SPI Status Register)

This register contains the status of the SPI.

| Bit | Name  | Description                              |
| --- | ----- | ---------------------------------------- |
| 7   | SPIF  | SPI Interrupt Flag                       |
| 6   | WCOL  | Write Collision Flag (indicates that a write operation occurred while a previous write operation was in progress) |
| 4   | SPI2X | Double SPI Speed (for Master mode only)  |

Sure, let's explain each function in detail:

### `SPI_voidInitMaster()`

This function initializes the SPI (Serial Peripheral Interface) module as a master device. It configures the SPI control registers to set up the communication parameters such as data order, clock polarity, phase, and speed.

- **Parameters:** None
- **Return Value:** None
- **Usage Example:**
  ```c
  SPI_voidInitMaster();
  ```

#### Detailed Explanation:
1. **Interrupt Configuration:**
   - Disables SPI interrupt by clearing the SPIE bit in the SPCR register.

2. **Data Order Configuration:**
   - Sets the DORD bit in the SPCR register to configure data order as LSB (Least Significant Bit) first.

3. **Master Mode Configuration:**
   - Sets the MSTR bit in the SPCR register to configure SPI as a master device.

4. **Clock Polarity and Phase Configuration:**
   - Sets the CPOL and CPHA bits in the SPCR register to configure clock polarity and phase.
   - These configurations determine when data is sampled and when it is shifted.

5. **Clock Speed Configuration:**
   - Sets the SPR0 and SPR1 bits in the SPCR register to configure clock speed.
   - Additionally, sets the SPI2X bit in the SPSR register for double speed operation.

6. **Enable SPI:**
   - Sets the SPE (SPI Enable) bit in the SPCR register to enable SPI communication.

### `SPI_voidInitSlave()`

This function initializes the SPI module as a slave device. It configures the SPI control registers to set up the communication parameters such as data order, clock polarity, and phase.

- **Parameters:** None
- **Return Value:** None
- **Usage Example:**
  ```c
  SPI_voidInitSlave();
  ```

#### Detailed Explanation:
1. **Interrupt Configuration:**
   - Disables SPI interrupt by clearing the SPIE bit in the SPCR register.

2. **Data Order Configuration:**
   - Sets the DORD bit in the SPCR register to configure data order as LSB (Least Significant Bit) first.

3. **Slave Mode Configuration:**
   - Clears the MSTR bit in the SPCR register to configure SPI as a slave device.

4. **Clock Polarity and Phase Configuration:**
   - Sets the CPOL bit and CPHA bit in the SPCR and SPSR registers to configure clock polarity and phase.

5. **Enable SPI:**
   - Sets the SPE (SPI Enable) bit in the SPCR register to enable SPI communication.

### `SPI_u8Transceive(u8 copy_u8TxData, u8* copy_pu8RxData)`

This function transmits data over SPI and receives data if provided with a valid pointer to a receive buffer. It waits until the transmission is complete before returning.

- **Parameters:**
  - `copy_u8TxData`: The data to be transmitted over SPI.
  - `copy_pu8RxData`: Pointer to a variable where received data will be stored. Pass `NULL` if no data needs to be received.
- **Return Value:** None
- **Usage Example:**
  ```c
  u8 receivedData;
  SPI_u8Transceive(0xFF, &receivedData);
  ```

#### Detailed Explanation:
1. **Transmission:**
   - The function writes the data to be transmitted (`copy_u8TxData`) into the SPI Data Register (SPDR_REG).
   
2. **Wait for Transmission Completion:**
   - It enters a busy-wait loop until the SPIF (SPI Interrupt Flag) bit in the SPSR register is set, indicating that the transmission is complete.
   
3. **Data Reception:**
   - If `copy_pu8RxData` is not NULL, it reads the received data from the SPDR_REG and stores it at the memory location pointed by `copy_pu8RxData`.
   
4. **Error Handling:**
   - If `copy_pu8RxData` is NULL, it does not perform data reception and may implement error handling or return an error state if needed.

This function facilitates bidirectional data transfer over SPI and ensures synchronization between the master and slave devices.


## Contributing

Contributions are welcome. For major changes, please open an issue first to discuss what you would like to change.

## Acknowledgments
```
- This driver is inspired by the Atmega32 datasheet and other open-source SPI drivers.
  ```




