/* Copyright (c) 2015 Takafumi Naka. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

/** @file
* @defgroup spi_ws2812b_main main.c
* @{
* @ingroup spi_ws2812b
*
* @brief WS2812B drive by SPI Master sample main file.
*
* This file contains the source code for a sample application using SPI.
*
*/

#include "nrf_delay.h"
#include "app_error.h"
#include "app_util_platform.h"
#include "nrf_drv_spi.h"
#include "bsp.h"
#include "app_timer.h"
#include "nordic_common.h"

const uint8_t leds_list[LEDS_NUMBER] = LEDS_LIST;


#define APP_TIMER_PRESCALER      0                      ///< Value of the RTC1 PRESCALER register.
#define APP_TIMER_MAX_TIMERS     BSP_APP_TIMERS_NUMBER  ///< Maximum number of simultaneously created timers.
#define APP_TIMER_OP_QUEUE_SIZE  2                      ///< Size of timer operation queues.

#define DELAY_MS                 1000                   ///< Timer Delay in milli-seconds.

/** @def  TX_RX_MSG_LENGTH
 * number of bytes to transmit and receive. This amount of bytes will also be tested to see that
 * the received bytes from slave are the same as the transmitted bytes from the master */
#define TX_RX_MSG_LENGTH0         ((12)*20)
#define TX_RX_MSG_LENGTH         ((12)*20)
#define TX_RX_MSG_LENGTH2         ((12)*20)

#if (SPI0_ENABLED == 1)

static uint8_t m_tx_data_spi[TX_RX_MSG_LENGTH]; ///< SPI master TX buffer.
static uint8_t m_tx_data_spi2[TX_RX_MSG_LENGTH2]; ///< SPI master TX buffer 2.
static uint8_t m_tx_data_spi0[TX_RX_MSG_LENGTH0]; ///< SPI master TX buffer 2.
static uint8_t m_rx_data_spi[TX_RX_MSG_LENGTH]; ///< SPI master RX buffer.

static volatile bool m_transfer_completed = true;

#if (SPI0_ENABLED == 1)
static const nrf_drv_spi_t m_spi_master_1 = NRF_DRV_SPI_INSTANCE(0);
#endif




/**@brief The function initializes TX buffer to values to be sent and clears RX buffer.
 *
 * @note Function initializes TX buffer to values from 0 to (len - 1).
 *       and clears RX buffer (fill by 0).
 *
 * @param[out] p_tx_data    A pointer to a buffer TX.
 * @param[out] p_rx_data    A pointer to a buffer RX.
 * @param[in] len           A length of the data buffers.
 */
static void init_buf(uint8_t * const p_tx_buf,
                     uint8_t * const p_rx_buf,
                     const uint16_t  len)
{
    uint16_t i;
	
    for (i = 0; i < len; i++)
    {
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x8e;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
			
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x8e;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x8e;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				
//				i++;
//				p_tx_buf[i] = 0x00;
				
    }
		p_tx_buf[len-1] = 0x82;
}


/**@brief The function initializes TX buffer to values to be sent and clears RX buffer.
 *
 * @note Function initializes TX buffer to values from 0 to (len - 1).
 *       and clears RX buffer (fill by 0).
 *
 * @param[out] p_tx_data    A pointer to a buffer TX.
 * @param[out] p_rx_data    A pointer to a buffer RX.
 * @param[in] len           A length of the data buffers.
 */
static void init_buf2(uint8_t * const p_tx_buf,
                     uint8_t * const p_rx_buf,
                     const uint16_t  len)
{
    uint16_t i;

		for (i = 0; i < len; i++)
    {
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0xe8;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
			
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				
//				i++;
//				p_tx_buf[i] = 0x00;
				
    }


		p_tx_buf[len-1] = 0x82;
	
}


/**@brief The function initializes TX buffer to values to be sent and clears RX buffer.
 *
 * @note Function initializes TX buffer to values from 0 to (len - 1).
 *       and clears RX buffer (fill by 0).
 *
 * @param[out] p_tx_data    A pointer to a buffer TX.
 * @param[out] p_rx_data    A pointer to a buffer RX.
 * @param[in] len           A length of the data buffers.
 */
static void init_buf0(uint8_t * const p_tx_buf,
                     uint8_t * const p_rx_buf,
                     const uint16_t  len)
{
    uint16_t i;

    for (i = 0; i < len; i++)
    {
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
			
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				i++;
        p_tx_buf[i] = 0x88;
				
				// i++;
				// p_tx_buf[i] = 0x00;
				
    }

		p_tx_buf[len-1] = 0x82;
	
}


#if (SPI0_ENABLED == 1)
/**@brief Handler for SPI0 master events.
 *
 * @param[in] event SPI master event.
 */
void spi_master_1_event_handler(nrf_drv_spi_evt_t event)
{
		m_transfer_completed = true;
}
#endif // (SPI0_ENABLED == 1)


/**@brief Function for initializing a SPI master driver.
 *
 * @param[in] p_instance    Pointer to SPI master driver instance.
 * @param[in] lsb           Bits order LSB if true, MSB if false.
 */
static void spi_master_init(nrf_drv_spi_t const * p_instance, bool lsb)
{
    uint32_t err_code = NRF_SUCCESS;

    nrf_drv_spi_config_t config =
    {
        .ss_pin       = NRF_DRV_SPI_PIN_NOT_USED,
        .irq_priority = APP_IRQ_PRIORITY_HIGH,
        .orc          = 0xff,
        .frequency    = NRF_DRV_SPI_FREQ_4M,
        .mode         = NRF_DRV_SPI_MODE_3,
        .bit_order    = (lsb ?
            NRF_DRV_SPI_BIT_ORDER_LSB_FIRST : NRF_DRV_SPI_BIT_ORDER_MSB_FIRST),
    };
    
		

    #if (SPI0_ENABLED == 1)
    if (p_instance == &m_spi_master_1)
    {
        config.sck_pin  = SPIM1_SCK_PIN;
        config.mosi_pin = SPIM1_MOSI_PIN;
        config.miso_pin = NULL; // SPIM1_MISO_PIN;
        err_code = nrf_drv_spi_init(p_instance, &config,
            spi_master_1_event_handler);
    }
    else
    #endif // (SPI0_ENABLED == 1)


    {}

    // APP_ERROR_CHECK(err_code);
}


/**@brief Function for sending and receiving data.
 *
 * @param[in]   p_instance   Pointer to SPI master driver instance.
 * @param[in]   p_tx_data    A pointer to a buffer TX.
 * @param[out]  p_rx_data    A pointer to a buffer RX.
 * @param[in]   len          A length of the data buffers.
 */
static void spi_send_recv(nrf_drv_spi_t const * p_instance,
                          uint8_t * p_tx_data,
                          uint8_t * p_rx_data,
                          uint16_t  len)
{
  
	m_transfer_completed = false;
  uint32_t err_code = nrf_drv_spi_transfer(p_instance,
        p_tx_data, len, NULL, 0);
    // APP_ERROR_CHECK(err_code);
	
}


#endif // (SPI0_ENABLED == 1) || (SPI1_ENABLED == 1) || (SPI2_ENABLED == 1)



/** @brief Function for main application entry.
 */
int main(void)
{
	
    // Configure LED-pins as outputs.
    LEDS_CONFIGURE(LEDS_MASK);


    nrf_drv_spi_t const * p_instance;

    p_instance = &m_spi_master_1;
	
	  // spi_send_recv(p_instance, m_tx_data_spi, m_rx_data_spi, TX_RX_MSG_LENGTH);

		init_buf(m_tx_data_spi, m_rx_data_spi,TX_RX_MSG_LENGTH);
		init_buf2(m_tx_data_spi2, m_rx_data_spi,TX_RX_MSG_LENGTH2);
		init_buf0(m_tx_data_spi0, m_rx_data_spi,TX_RX_MSG_LENGTH0);

		spi_master_init(p_instance, false);
		nrf_spim_shorts_enable(p_instance->p_registers,true);	
	
	  nrf_drv_spi_xfer_desc_t xfer_desc0;


	  xfer_desc0.p_tx_buffer = m_tx_data_spi0;
		xfer_desc0.p_rx_buffer = NULL;
		xfer_desc0.tx_length   = TX_RX_MSG_LENGTH0;
		xfer_desc0.rx_length   = 0;
	
		nrf_drv_spi_xfer_desc_t xfer_desc;
		xfer_desc.p_tx_buffer = m_tx_data_spi;
		xfer_desc.p_rx_buffer = NULL;
		xfer_desc.tx_length   = TX_RX_MSG_LENGTH;
		xfer_desc.rx_length   = 0;
			
		nrf_drv_spi_xfer_desc_t xfer_desc2;
		xfer_desc2.p_tx_buffer = m_tx_data_spi2;
		xfer_desc2.p_rx_buffer = NULL;
		xfer_desc2.tx_length   = TX_RX_MSG_LENGTH2;
		xfer_desc2.rx_length   = 0;


		for (;;)
		{
			LEDS_ON(1 << leds_list[0]);
			LEDS_ON(1 << leds_list[1]);
			LEDS_ON(1 << leds_list[2]);
			LEDS_ON(1 << leds_list[3]);

			LEDS_INVERT(1 << leds_list[0]);
			
				//nrf_gpio_pin_write(SPIM1_MOSI_PIN,0);
        //nrf_delay_ms(1);
				// spi_send_recv(p_instance, m_tx_data_spi, m_rx_data_spi, TX_RX_MSG_LENGTH);

			for(int j=0;j<4;j++)
			{
				for(int i=0;i<12;i++)
				{
					nrf_drv_spi_xfer(p_instance, &xfer_desc0, 0);
					m_transfer_completed = false;
					while (! m_transfer_completed) {}
				}
			}

      nrf_delay_ms(DELAY_MS);
			
			for(int j=0;j<4;j++)
			{
				for(int i=0;i<6;i++)
				{
					// 0-19
					nrf_drv_spi_xfer(p_instance, &xfer_desc, 0); // NRF_DRV_SPI_FLAG_NO_XFER_EVT_HANDLER);
					m_transfer_completed = false;
					while (! m_transfer_completed) {}
					// 20-39
					nrf_drv_spi_xfer(p_instance, &xfer_desc2, 0); // NRF_DRV_SPI_FLAG_REPEATED_XFER);
					m_transfer_completed = false;
					while (! m_transfer_completed) {}
				}
			}
			
      nrf_delay_ms(DELAY_MS);
    }
}

/** @} */
