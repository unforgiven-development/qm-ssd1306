/***********************************************************************************************************************
 * ssd1306.h
 * -- SSD1306 OLED driver for Intel QMSI
 *
 ***********************************************************************************************************************
 *
 * Copyright (c) 2017, Gerad Munsch <gmunsch@unforgivendevelopment.com>
 * Copyright (c) 2017, Sergey Kiselev
 * All rights reserved.
 *
 ***********************************************************************************************************************
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * 1.	Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *		disclaimer.
 * 2.	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *		following disclaimer in the documentation and/or other materials provided with the distribution.
 * 3.	Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote
 *		products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **********************************************************************************************************************/

/**
 * SSD1306 interface type
 *
 * SSD1306_I2C == 1 - use I2C
 * SSD1306_I2C == 0 - use SPI
 */
#define SSD1306_I2C						0


/**
 * Display resolution: modify according to the specific display being used. Some examples are included below.
 *
 * Adafruit 1.3" OLED: 128 WIDTH x 64 HEIGHT
 * MikroElektronika OLED Click: 96 WIDTH x 39 HEIGHT (defined as 40)
 *
 * Also common: 128 WIDTH x 32 HEIGHT
 */
#define SSD1306_LCD_WIDTH				128
#define SSD1306_LCD_HEIGHT				64


/**
 * I2C settings:
 *
 * I2C address: typical values are 0x3C or 0x3D
 * I2C retry count: default value = 5
 */
#define SSD1306_I2C_ADDR				0x3C
#define SSD1306_I2C_RETRY_COUNT			5


/**
 * SPI settings:
 *
 * SPI bus: define which SPI bus to use
 * SPI SS: define the SPI slave select pin to use
 */
#define SSD1306_SPI_BUS					QM_SPI_MST_0
#define SSD1306_SPI_SS					QM_SPI_SS_0


/**
 * GPIO settings (if required):
 *
 * NOTE: These pins are only found on a limited amount of devices.
 *
 * RESET pin: define which GPIO to use for the SSD1306 "RESET" function
 * DC pin: define which GPIO to use for the SSD1306 "DC" (data/command register select) function
 */
#define SSD1306_GPIO_RST				9	/* D2000 - F9	| D2000 CRB pin #8 */
#define SSD1306_GPIO_DC					24	/* D2000 - F24	| D2000 CRB pin #9 */


/**
 * Set command/data mode
 */
#define SSD1306_MODE_CMD				0x80
#define SSD1306_MODE_DATA				0x40


/**
 * Define SSD1306 commands
 */
#define SSD1306_CMD_ADDR_MODE			0x20
#define SSD1306_CMD_SET_COLUMN_ADDR		0x21
#define SSD1306_CMD_SET_PAGE_ADDR		0x22
#define SSD1306_CMD_SET_START_LINE		0x40
#define SSD1306_CMD_SET_CONTRAST		0x81
#define SSD1306_CMD_SET_CHARGEPUMP		0x8D
#define SSD1306_CMD_SET_SEGMENT_REMAP	0xA1
#define SSD1306_CMD_DISPLAY_ALL_ON_RES	0xA4
#define SSD1306_CMD_NORMAL				0xA6
#define SSD1306_CMD_SET_MUX				0xA8
#define SSD1306_CMD_DISPLAY_OFF			0xAE
#define SSD1306_CMD_DISPLAY_ON			0xAF
#define SSD1306_CMD_SET_COM_SCAN_INC	0xC0
#define SSD1306_CMD_SET_COM_SCAN_DEC	0xC8
#define SSD1306_CMD_SET_OFFSET			0xD3
#define SSD1306_CMD_SET_CLK_DIV			0xD5
#define SSD1306_CMD_SET_PRECHARGE		0xD9
#define SSD1306_CMD_SET_COM_PINS		0xDA
#define SSD1306_CMD_SET_VCOM_DESELECT	0xDB
#define SSD1306_CMD_PAGE_START_ADDR		0xB0
#define SSD1306_CMD_COLUMN_LOW_ADDR		0x00
#define SSD1306_CMD_COLUMN_HIGH_ADDR	0x10


/**
 * Define SSD1306 addressing modes
 */
#define SSD1306_ADDR_MODE_HORIZ			0
#define SSD1306_ADDR_MODE_VERT			1
#define SSD1306_ADDR_MODE_PAGE			2


/**
 * Initialize SSD1306 device
 */
int ssd1306_init();

/**
 * Set the addressing mode used by the SSD1306
 */
int ssd1306_set_addr_mode(uint8_t);

/**
 * Position the cursor on the SSD1306
 */
int ssd1306_set_cursor(uint8_t row, uint8_t column);

/**
 * Clear the screen
 */
int ssd1306_clear();

/**
 * Write a character to the SSD1306, at the current cursor position
 */
int ssd1306_putc(uint8_t c);

/**
 * Write a string (character array) to the SSD1306, at the current cursor position
 */
int ssd1306_puts(char string[]);
