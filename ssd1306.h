/**
 * \file ssd1306.h	Header file for the SSD1306 OLED driver for Intel QMSI
 *
 * \author	Gerad Munsch <gmunsch@unforgivendevelopment.com>
 * \author	Sergey Kiselev
 * \date	2017
 *
 * \copyright All rights reserved.
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
 */

/**
 * SSD1306 interface type
 *
 * \def SSD1306_I2C	Define this as \p 1 for an I2C display, or as \p 0 for an SPI display.
 */
#define SSD1306_I2C						0


/**
 * Display resolution
 * \note Modify according to the specific display being used. Some examples are included below.
 *
 * \li <B>Adafruit 1.3" OLED:</B> \p 128 WIDTH x \p 64 HEIGHT
 * \li <B>MikroElektronika OLED Click:</B> \p 96 WIDTH x \p 39 HEIGHT (defined as \p 40)
 * \li <B>Generic 0.96" OLED displays from Amazon, etc:</B> Typically \p 128 WIDTH x \p 64 HEIGHT
 * \li <B>Additional common display resolution:</B> \p 128 WIDTH x \p 32 HEIGHT
 *
 * \def SSD1306_LCD_WIDTH	Define the width of the display, in pixels.
 * \def SSD1306_LCD_HEIGHT	Define the height of the display, in pixels.
 */
#define SSD1306_LCD_WIDTH				128
#define SSD1306_LCD_HEIGHT				64


/**
 * I2C settings
 * \note Typical I2C addresses for SSD1306 OLED displays are \c 0x3C or \c 0x3D
 *
 * \def SSD1306_I2C_ADDR		Define the I2C address of the SSD1306 display
 * \def SSD1306_I2C_RETRY_COUNT	Define the amount of times an I2C transaction will be retried (DEFAULT: \p 5)
 */
#define SSD1306_I2C_ADDR				0x3C
#define SSD1306_I2C_RETRY_COUNT			5


/**
 * SPI settings
 *
 * \def SSD1306_SPI_BUS	Define which SPI bus to use
 * \def SSD1306_SPI_SS	Define the SPI slave select pin to use
 */
#define SSD1306_SPI_BUS					QM_SPI_MST_0
#define SSD1306_SPI_SS					QM_SPI_SS_0


/**
 * GPIO settings (if required)
 * \note These pins are only found on a limited amount of devices.
 *
 * \def SSD1306_GPIO_RST	Define which GPIO to use for the SSD1306 "RESET" function.
 *							DEFAULT: D2000 - GPIO 9 (CRB Pin #8)
 * \def SSD1306_GPIO_DC		Define which GPIO to use for the SSD1306 "DC" (data/command register select) function.
 *							DEFAULT: D2000 - GPIO 24 (CRB Pin #9)
 */
#define SSD1306_GPIO_RST				9
#define SSD1306_GPIO_DC					24


/**
 * Set command/data mode
 * \brief Define the opcodes to set the device into \b command or \b data mode
 */
#define SSD1306_MODE_CMD				0x80	/*!< The opcode to set the device into \b command mode */
#define SSD1306_MODE_DATA				0x40	/*!< The opcode to set the device into \b data mode */


/**
 * Define SSD1306 commands
 * \brief Define the opcodes for a variety of the SSD1306 device commands.
 */
#define SSD1306_CMD_ADDR_MODE			0x20	/*!< The opcode for settings the memory addressing mode  */
#define SSD1306_CMD_SET_COLUMN_ADDR		0x21	/*!< The opcode  */
#define SSD1306_CMD_SET_PAGE_ADDR		0x22	/*!< The opcode  */
#define SSD1306_CMD_SET_START_LINE		0x40	/*!< The opcode  */
#define SSD1306_CMD_SET_CONTRAST		0x81	/*!< The opcode  */
#define SSD1306_CMD_SET_CHARGEPUMP		0x8D	/*!< The opcode  */
#define SSD1306_CMD_SET_SEGMENT_REMAP	0xA1	/*!< The opcode  */
#define SSD1306_CMD_DISPLAY_ALL_ON_RES	0xA4	/*!< The opcode  */
#define SSD1306_CMD_NORMAL				0xA6	/*!< The opcode  */
#define SSD1306_CMD_SET_MUX				0xA8	/*!< The opcode  */
#define SSD1306_CMD_DISPLAY_OFF			0xAE	/*!< The opcode  */
#define SSD1306_CMD_DISPLAY_ON			0xAF	/*!< The opcode  */
#define SSD1306_CMD_SET_COM_SCAN_INC	0xC0	/*!< The opcode  */
#define SSD1306_CMD_SET_COM_SCAN_DEC	0xC8	/*!< The opcode  */
#define SSD1306_CMD_SET_OFFSET			0xD3	/*!< The opcode  */
#define SSD1306_CMD_SET_CLK_DIV			0xD5	/*!< The opcode  */
#define SSD1306_CMD_SET_PRECHARGE		0xD9	/*!< The opcode  */
#define SSD1306_CMD_SET_COM_PINS		0xDA	/*!< The opcode  */
#define SSD1306_CMD_SET_VCOM_DESELECT	0xDB	/*!< The opcode  */
#define SSD1306_CMD_PAGE_START_ADDR		0xB0	/*!< The opcode  */
#define SSD1306_CMD_COLUMN_LOW_ADDR		0x00	/*!< The opcode  */
#define SSD1306_CMD_COLUMN_HIGH_ADDR	0x10	/*!< The opcode  */


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
