## DHT11 Driver for EFM/EFR32 Devices

This repository contains a driver for interfacing with the DHT11 temperature and humidity sensor on EFM/EFR32 devices. The driver utilizes timer input capture functionality for accurate data acquisition.

## Features
    1. Utilizes timer input capture for accurate timing
    2. Compatible with EFM/EFR32 devices
    3. Simple and easy-to-use API

## Usage
    1. Clone this repository to your project directory.
    2. Import the project using the .sls file in the Simplicity Studio folder.
    3. Initialize the DHT11 sensor and configure the timer input capture.
    4. Read temperature and humidity data using the provided functions.


```c 
void app_init(void)
{

  // Chip errata
  CHIP_Init();

  initCMU();
  initGPIO();
  initTIMER0();

  uint8_t indx = 2;
  uint8_t i,j;
  sl_udelay_wait(10000);

if(buffer[1] == (uint32_t)5){

    for(i = 0; i < 5; i++){
        for(j =0; j<8; j++){
            if(buffer[indx] > (uint32_t)3){
                temp[i] |= (1<<(7-j));
            }else {
                temp[i] &= ~(1<<(7-j));
            }
            indx++;
        }
    }
}else{
    printf("Init failed\r\n");
}

printf("Humidity: %u.%u\r\n", temp[0], temp[1]);
printf("Temperature %u.%u\r\n", temp[2], temp[3]);

}
```

## Compatibility
This driver is compatible with EFM/EFR32 devices and is designed specifically for the DHT11 sensor.

## Feedback and Contributions
Feedback, bug reports, and contributions are welcome! Feel free to open an issue or submit a pull request.