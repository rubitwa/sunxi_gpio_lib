#ifndef _GPIO_TABLE_H_
#define _GPIO_TABLE_H_

#include "../sunxi_gpio_lib.h"

// Physical pin table based on schames from:
// http://www.orangepi.org/downloadresources/
// http://linux-sunxi.org/index.php?search=schematic&go=Go&title=Special%3ASearch

#if defined(ORANGEPI_PC)
// OPI PC: https://drive.google.com/file/d/0BwQT0FP7IkTbRFJQamNwWTAzWms/view
// OPI PC 2: https://linux-sunxi.org/File:ORANGE_PI-PC2-V1_2_schematic.pdf
// OPI PC Plus: https://mega.nz/#!cksQEZYA!_2Rciru3V71yVfw20M0t3W5jnOw1hi-XHTFPW56sfeA

#define	SUNXI_GPIO_PIN_01 -1
#define	SUNXI_GPIO_PIN_02 -1
#define	SUNXI_GPIO_PIN_03 SUNXI_GPA(12)
#define	SUNXI_GPIO_PIN_04 -1
#define	SUNXI_GPIO_PIN_05 SUNXI_GPA(11)
#define	SUNXI_GPIO_PIN_06 -1
#define	SUNXI_GPIO_PIN_07 SUNXI_GPA(06)
#define	SUNXI_GPIO_PIN_08 SUNXI_GPA(13)
#define	SUNXI_GPIO_PIN_09 -1
#define	SUNXI_GPIO_PIN_10 SUNXI_GPA(14)
#define	SUNXI_GPIO_PIN_11 SUNXI_GPA(01)
#define	SUNXI_GPIO_PIN_12 SUNXI_GPD(14)
#define	SUNXI_GPIO_PIN_13 SUNXI_GPA(00)
#define	SUNXI_GPIO_PIN_14 -1
#define	SUNXI_GPIO_PIN_15 SUNXI_GPA(03)
#define	SUNXI_GPIO_PIN_16 SUNXI_GPC(04)
#define	SUNXI_GPIO_PIN_17 -1
#define	SUNXI_GPIO_PIN_18 SUNXI_GPC(07)
#define	SUNXI_GPIO_PIN_19 SUNXI_GPC(00)
#define	SUNXI_GPIO_PIN_20 -1
#define	SUNXI_GPIO_PIN_21 SUNXI_GPC(01)
#define	SUNXI_GPIO_PIN_22 SUNXI_GPA(02)
#define	SUNXI_GPIO_PIN_23 SUNXI_GPC(02)
#define	SUNXI_GPIO_PIN_24 SUNXI_GPC(03)
#define	SUNXI_GPIO_PIN_25 -1
#define	SUNXI_GPIO_PIN_26 SUNXI_GPA(21)
#define	SUNXI_GPIO_PIN_27 SUNXI_GPA(19)
#define	SUNXI_GPIO_PIN_28 SUNXI_GPA(18)
#define	SUNXI_GPIO_PIN_29 SUNXI_GPA(07)
#define	SUNXI_GPIO_PIN_30 -1
#define	SUNXI_GPIO_PIN_31 SUNXI_GPA(08)
#define	SUNXI_GPIO_PIN_32 SUNXI_GPG(08)
#define	SUNXI_GPIO_PIN_33 SUNXI_GPA(09)
#define	SUNXI_GPIO_PIN_34 -1
#define	SUNXI_GPIO_PIN_35 SUNXI_GPA(10)
#define	SUNXI_GPIO_PIN_36 SUNXI_GPG(09)
#define	SUNXI_GPIO_PIN_37 SUNXI_GPA(20)
#define	SUNXI_GPIO_PIN_38 SUNXI_GPG(06)
#define	SUNXI_GPIO_PIN_39 -1
#define	SUNXI_GPIO_PIN_40 SUNXI_GPG(07)

#elif defined(ORANGEPI_WIN)
// OPI Win: http://linux-sunxi.org/images/1/11/ORANGEPI-WIN-V1_1.pdf
// OPI Win Plus: http://linux-sunxi.org/images/6/6c/ORANGEPI-Winplus-V1_3.pdf

#define	SUNXI_GPIO_PIN_01 -1
#define	SUNXI_GPIO_PIN_02 -1
#define	SUNXI_GPIO_PIN_03 SUNXI_GPH(03)
#define	SUNXI_GPIO_PIN_04 -1
#define	SUNXI_GPIO_PIN_05 SUNXI_GPH(02)
#define	SUNXI_GPIO_PIN_06 -1
#define	SUNXI_GPIO_PIN_07 SUNXI_GPL(10)
#define	SUNXI_GPIO_PIN_08 SUNXI_GPL(02)
#define	SUNXI_GPIO_PIN_09 -1
#define	SUNXI_GPIO_PIN_10 SUNXI_GPL(03)
#define	SUNXI_GPIO_PIN_11 SUNXI_GPH(05)
#define	SUNXI_GPIO_PIN_12 SUNXI_GPD(04)
#define	SUNXI_GPIO_PIN_13 SUNXI_GPH(04)
#define	SUNXI_GPIO_PIN_14 -1
#define	SUNXI_GPIO_PIN_15 SUNXI_GPH(07)
#define	SUNXI_GPIO_PIN_16 SUNXI_GPL(09)
#define	SUNXI_GPIO_PIN_17 -1
#define	SUNXI_GPIO_PIN_18 SUNXI_GPC(04)
#define	SUNXI_GPIO_PIN_19 SUNXI_GPD(02)
#define	SUNXI_GPIO_PIN_20 -1
#define	SUNXI_GPIO_PIN_21 SUNXI_GPD(03)
#define	SUNXI_GPIO_PIN_22 SUNXI_GPH(06)
#define	SUNXI_GPIO_PIN_23 SUNXI_GPD(01)
#define	SUNXI_GPIO_PIN_24 SUNXI_GPD(00)
#define	SUNXI_GPIO_PIN_25 -1
#define	SUNXI_GPIO_PIN_26 SUNXI_GPD(06)
#define	SUNXI_GPIO_PIN_27 SUNXI_GPE(15)
#define	SUNXI_GPIO_PIN_28 SUNXI_GPE(14)
#define	SUNXI_GPIO_PIN_29 SUNXI_GPB(04)
#define	SUNXI_GPIO_PIN_30 -1
#define	SUNXI_GPIO_PIN_31 SUNXI_GPB(05)
#define	SUNXI_GPIO_PIN_32 SUNXI_GPB(02)
#define	SUNXI_GPIO_PIN_33 SUNXI_GPB(06)
#define	SUNXI_GPIO_PIN_34 -1
#define	SUNXI_GPIO_PIN_35 SUNXI_GPB(07)
#define	SUNXI_GPIO_PIN_36 SUNXI_GPB(03)
#define	SUNXI_GPIO_PIN_37 SUNXI_GPD(05)
#define	SUNXI_GPIO_PIN_38 SUNXI_GPB(00)
#define	SUNXI_GPIO_PIN_39 -1
#define	SUNXI_GPIO_PIN_40 SUNXI_GPB(01)

#else
#error "Please select gpio pin's table!"
#endif

#endif