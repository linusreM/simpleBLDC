/*
 * motor_control.h
 *
 *  Created on: Sep 27, 2019
 *      Author: remahl
 */

#ifndef INC_MOTOR_CONTROL_H_
#define INC_MOTOR_CONTROL_H_

//#include <stdint.h>

#include "comp.h"
#include "tim.h"


typedef struct{
	COMP_HandleTypeDef* compA, *compB, *compC;
	TIM_HandleTypeDef* tim;
	uint32_t high_a, high_b, high_c;
	GPIO_TypeDef* port;
	uint16_t low_a, low_b, low_c;
	uint32_t max_period;
}motor_config_t;


typedef enum{
	ABC,
	ACB,
	BCA,
	BAC,
	CAB,
	CBA
}motor_state_t;

typedef struct{
	float P;
	float I;
	float D;
	float error;
	float setpoint;
}PID_t;

typedef struct{
	motor_state_t state;
	int32_t last_commutation;
	float period;
	PID_t pid;
}motor_t;

int commutate(motor_t mot);
int commutate_irq();
int init_motor(motor_config_t conf);
void set_period(uint32_t pin, float period);
void set_motor_power(float power);
void set_low_side(uint16_t pin);
void turn_off();
void switch_comparator(COMP_HandleTypeDef* comp, uint32_t mode);
void debounce_comp(COMP_HandleTypeDef* comp);

#endif /* INC_MOTOR_CONTROL_H_ */
