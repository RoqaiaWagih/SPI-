
# Atmega32 SPI Driver

This repository contains a SPI (Serial Peripheral Interface) driver for the Atmega32 microcontroller.

## Overview

The Serial Peripheral Interface (SPI) is a synchronous serial communication interface used for short-distance communication between devices. This driver provides functions to initialize and configure the SPI peripheral on the Atmega32 microcontroller, as well as transmit and receive data.

## Features

- Initialization and configuration of SPI peripheral
- Transmitting and receiving data over SPI bus
- Configurable clock polarity and phase
- Configurable data order (MSB first or LSB first)

## Usage

1. Initialize the SPI peripheral using `SPI_init()` function.

2. Configure SPI settings such as clock polarity, phase, and data order if needed using `SPI_configure()` function.

3. Transmit data using `SPI_transmit()` function.

4. Receive data using `SPI_receive()` function.

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

### SPDR (SPI Data Register)

This register holds the data to be transmitted or received via SPI.

### Data Sheet

## Functions

### `void SPI_init()`

Initializes the SPI peripheral by configuring SPI control registers.

### `void SPI_configure(uint8_t mode, uint8_t clock_divider, uint8_t data_order)`

Configures SPI settings such as mode (clock polarity and phase), clock divider, and data order.

- `mode`: Specifies the SPI mode (0, 1, 2, or 3).
- `clock_divider`: Specifies the clock divider for SPI clock rate selection.
- `data_order`: Specifies the data order (MSB first or LSB first).

### `void SPI_transmit(uint8_t data)`

Transmits a byte of data over the SPI bus.

- `data`: The data byte to be transmitted.

### `uint8_t SPI_receive()`

Receives a byte of data over the SPI bus and returns it.

## Example

```c
#include <avr/io.h>
#include "spi.h"

int main() {
    // Initialize SPI
    SPI_init();
    
    // Configure SPI settings
    SPI_configure(SPI_MODE_0, SPI_CLOCK_DIV_16, SPI_MSB_FIRST);
    
    // Transmit data
    SPI_transmit(0x55);
    
    // Receive data
    uint8_t receivedData = SPI_receive();
    
    // Do something with received data
    
    return 0;
}
```

## Example Project

Here's an example project demonstrating SPI communication between a master and a slave device.

### Master Configuration

```c
#include <avr/io.h>
#include "spi.h"

int main() {
    // Initialize SPI as master
    SPI_init_master();
    
    // Configure SPI settings
    SPI_configure_master(SPI_MODE_0, SPI_CLOCK_DIV_16, SPI_MSB_FIRST);
    
    // Enable SPI
    SPI_enable();
    
    // Send data
    uint8_t sendData = 0x55;
    SPI_master_transmit(sendData);
    
    // Receive data
    uint8_t receivedData = SPI_master_receive();
    
    // Do something with received data
    
    return 0;
}
```

### Slave Configuration

```c
#include <avr/io.h>
#include "spi.h"

int main() {
    // Initialize SPI as slave
    SPI_init_slave();
    
    // Enable SPI
    SPI_enable();
    
    // Wait for SPI data reception
    while (!SPI_is_received());
    
    // Receive data
    uint8_t receivedData = SPI_slave_receive();
    
    // Process received data
    
    return 0;
}
```

## Contributing

Contributions are welcome. For major changes, please open an issue first to discuss what you would like to change.

## Acknowledgments
```
- This driver is inspired by the Atmega32 datasheet and other open-source SPI drivers.
  ```




