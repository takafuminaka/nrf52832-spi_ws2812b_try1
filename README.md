これは、nRF52832のeasyDMAを使ってWS2812B LED アレイを制御するプログラムのサンプルです。

Nordic nRF5 SDK 11.0.0-2.alpha_bc3f6a0 と nRF52-DK (PCA-10040) (CPU version は Engineering B (QFAA-BA0))の組み合わせで動作を確認しています.
SDKパスの下のexamplesの下に、フォルダを作成し、spi_ws2812b_try1フォルダを展開してください。
例：C:\nRF52832\nRF5_SDK_11.0.0-2.alpha_bc3f6a0\examples\my_work\spi_ws2812b_try1\main.c

LEDアレイと5V電源、そして3.3V→5V変換の信号レベル変換が必要です。
WS2812Bベースの(240個からなる)LEDテープを使っています。
https://www.switch-science.com/catalog/2100/ 
Adafruit社のneopixel LEDと互換性がある筈です。
信号レベル変換にはTXB0104ベースのものを使っています。
https://www.switch-science.com/catalog/1466/
https://www.sparkfun.com/products/11771

P0.03に出力されたMOSI信号をTXB0104の入力に、TXB0104の出力をLEDアレイのDIに接続して下さい。

WS2812BベースのすべてのLEDアレイで動作するとは思いません。なぜなら、現在のバージョンは公式仕様を外れているからです。

--------------------------------------------------------------

 This is a sample program to drive WS2812B LED array by Nordic Semiconductor nRF52832 with easyDMA based SPIM.

It works with Nordic nRF5 SDK 11.0.0-2.alpha_bc3f6a0 and nRF52-DK (PCA-10040) with CPU version Engineering B (QFAA-BA0).
Make a folder under "example" in SDK installed path. ANd extract spi_ws2812b_try1 folder in this folder.
Example：C:\nRF52832\nRF5_SDK_11.0.0-2.alpha_bc3f6a0\examples\my_work\spi_ws2812b_try1\main.c

I also used LED array, 5V power supply and (3.3V to 5V) signal level converter.
The LED array is WS2812B based 240 LEDs array purchased from Switch-Science, Inc.
https://www.switch-science.com/catalog/2100/ 
It will compatible with Adafruit neopixel LED array.
The signal level converter is TXB0104 based.
https://www.switch-science.com/catalog/1466/
https://www.sparkfun.com/products/11771

Connect MOSI signal line on P0.03 to signal buffer input and connect signal buffer output to control line DI of LED array. 

It may not work with all WS2812B based array, because current version is not meet with official spec.



