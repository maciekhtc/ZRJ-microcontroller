/*
 * Application.h
 *
 *      Author: Maciej
 */
#ifndef APPLICATION_H_
#define APPLICATION_H_


uint8_t mojBufor[100];
/*!< Received chars buffer array */

uint8_t licznik = 0;
/*!< Array movement indicator, made to remember current char location in buffer */

uint8_t moc, ldiff, rdiff, dir;
/*!< Numerical representations of input values */


/*!
 * \brief Processing the data received by module, it reads the asynchronous buffer
 * and does the equation of it's content.
 * While prepared series of chars is found in buffer then another interpreting function is called
 */
static void WebProcess(void);

/*!
 * \brief Processing the prepared scrap received by module,
 * it's dividing it into small pieces and converting each one to numerical value,
 * made up numbers are forwarded to motion section
 */
void parserDanych(uint8_t licz);

/*!
 * \brief Application main routine
 */
void APP_Run(void);

#endif /* APPLICATION_H_ */
