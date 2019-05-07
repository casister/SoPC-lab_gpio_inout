void led_knight_rider(XGpio *pLED_GPIO, int nNumberOfTimes)
/**
* \brief       Blink a row of LEDs nNumberOfTimes times.
* \par         Details
*              The Digilent NEXYS-3 and Zedboard have 8 green LEDs located above the toggle switches.
*              This function blinks them back/forth (a bit like the KITT car from Knight Rider)
*
* \param[in]   *pLED_GPIO    	- address of the GPIO peripheral driving the LEDs in MicroBlaze memory map
* \param[in]   nNumberOfTimes   - Number of times you want to blink LEDs like Knight Rider
*
* \retval      None
*/
{
	int i=0;
	int j=0;
	u8 uchLedStatus=0;

	// Blink the LEDs back and forth nNumberOfTimes
	for(i=0;i<nNumberOfTimes;i++)
	{
		for(j=0;j<8;j++)  // Scroll the LEDs up
		{
			uchLedStatus = 1 << j;
			XGpio_DiscreteWrite(pLED_GPIO, 1, uchLedStatus);
			delay(ABOUT_ONE_SECOND / 15);
		}

		for(j=0;j<8;j++)  // Scroll the LEDs up
		{
			uchLedStatus = 8 >> j;
				XGpio_DiscreteWrite(pLED_GPIO, 1, uchLedStatus);
				delay(ABOUT_ONE_SECOND / 15);
		}
	}
}
