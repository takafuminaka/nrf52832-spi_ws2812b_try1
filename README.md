����́AnRF52832��easyDMA���g����WS2812B LED �A���C�𐧌䂷��v���O�����̃T���v���ł��B

Nordic nRF5 SDK 11.0.0-2.alpha_bc3f6a0 �� nRF52-DK (PCA-10040) (CPU version �� Engineering B (QFAA-BA0))�̑g�ݍ��킹�œ�����m�F���Ă��܂�.
SDK�p�X�̉���examples�̉��ɁA�t�H���_���쐬���Aspi_ws2812b_try1�t�H���_��W�J���Ă��������B
��FC:\nRF52832\nRF5_SDK_11.0.0-2.alpha_bc3f6a0\examples\my_work\spi_ws2812b_try1\main.c

LED�A���C��5V�d���A������3.3V��5V�ϊ��̐M�����x���ϊ����K�v�ł��B
WS2812B�x�[�X��(240����Ȃ�)LED�e�[�v���g���Ă��܂��B
https://www.switch-science.com/catalog/2100/ 
Adafruit�Ђ�neopixel LED�ƌ݊��������锤�ł��B
�M�����x���ϊ��ɂ�TXB0104�x�[�X�̂��̂��g���Ă��܂��B
https://www.switch-science.com/catalog/1466/
https://www.sparkfun.com/products/11771

P0.03�ɏo�͂��ꂽMOSI�M����TXB0104�̓��͂ɁATXB0104�̏o�͂�LED�A���C��DI�ɐڑ����ĉ������B

WS2812B�x�[�X�̂��ׂĂ�LED�A���C�œ��삷��Ƃ͎v���܂���B�Ȃ��Ȃ�A���݂̃o�[�W�����͌����d�l���O��Ă��邩��ł��B

--------------------------------------------------------------

 This is a sample program to drive WS2812B LED array by Nordic Semiconductor nRF52832 with easyDMA based SPIM.

It works with Nordic nRF5 SDK 11.0.0-2.alpha_bc3f6a0 and nRF52-DK (PCA-10040) with CPU version Engineering B (QFAA-BA0).
Make a folder under "example" in SDK installed path. ANd extract spi_ws2812b_try1 folder in this folder.
Example�FC:\nRF52832\nRF5_SDK_11.0.0-2.alpha_bc3f6a0\examples\my_work\spi_ws2812b_try1\main.c

I also used LED array, 5V power supply and (3.3V to 5V) signal level converter.
The LED array is WS2812B based 240 LEDs array purchased from Switch-Science, Inc.
https://www.switch-science.com/catalog/2100/ 
It will compatible with Adafruit neopixel LED array.
The signal level converter is TXB0104 based.
https://www.switch-science.com/catalog/1466/
https://www.sparkfun.com/products/11771

Connect MOSI signal line on P0.03 to signal buffer input and connect signal buffer output to control line DI of LED array. 

It may not work with all WS2812B based array, because current version is not meet with official spec.



