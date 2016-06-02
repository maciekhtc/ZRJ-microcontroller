/*
 * Motion.h
 *
 *  Created on: 7 cze 2015
 *      Author: Maciej
 */

#ifndef MOTION_H_
#define MOTION_H_


uint16_t moc_max; //wartosc aktualnie ustalonej przez uzytkownika predkosci
/*!< Current maximum power percent set by user, can be changed by signal from wireless module and reduced by diffs */
uint16_t drive_direction;	//0-stop; 12-cw; 21-ccw;
/*!< Current drive direction set by user, can be changed by signal from wireless module
 * !< 0 - stop, 21 - forwards, 12 - backwards */
uint16_t l_diff;	//uchyb mocy lewej strony, roznica od max, procentowo
/*!< Current left power reduce ratio in percents, set by user, can be changed by signal from wireless module */
uint16_t r_diff;	//uchyb mocy prawej strony, roznica od max, procentowo
/*!< Current right power reduce ratio in percents, set by user, can be changed by signal from wireless module */


/*!
 * \brief Setting physical right motors power by PWM on appropriate output pins, also it sets the lightness of LED (informational)
 * \param input participate in calculation of 16bit proportional value as it is in lower range
 */
void set_right(uint16_t input);

/*!
 * \brief Setting physical left motors power by PWM on appropriate output pins, also it sets the lightness of LED (informational)
 * \param input participate in calculation of 16bit proportional value as it is in lower range
 */
void set_left(uint16_t input);

/*!
 * \brief Setting physical left motors rotation direction
 * \param dir informs function about currently set device left side driving direction
 */
void l_direction(uint16_t dir);

/*!
 * \brief Setting physical right motors rotation direction
 * \param dir informs function about currently set device right side driving direction
 */
void r_direction(uint16_t dir);

/*!
 * \brief Blinking BLUE LED to inform user about device state
 * \param powodzenie choosing between two types of informational blink (0 - one blink, 1 - blink twice)
 */
static void info(bool powodzenie);

/*!
 * \brief Setting l_diff to input value, uses special algorithm to safely modify motor power
 * \param input New value of left deviation to gradually set
 */
void set_l_diff(uint16_t input);

/*!
 * \brief Setting r_diff to input value, uses special algorithm to safely modify motor power
 * \param input New value of right deviation to gradually set
 */
void set_r_diff(uint16_t input);

/*!
 * \brief Setting moc_max to input value, uses special algorithm to safely modify motor power
 * \param input New value of power to gradually set
 */
 void set_moc_max(uint16_t input);

/*!
 * \brief Interpreting values from transmission module by motion module
 * \param mocIn New value of power to set in percent
 * \param ldiffIn New value of left power reduce percent to set
 * \param rdiffIn New value of right power reduce percent to set
 * \param dirIn New value of driving direction to set
 */
void driveByVars(uint8_t mocIn,uint8_t ldiffIn,uint8_t rdiffIn,uint8_t dirIn);


#endif /* MOTION_H_ */
