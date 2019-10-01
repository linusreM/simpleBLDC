/*
 * motor_control.c
 *
 *  Created on: Sep 27, 2019
 *      Author: remahl
 */


#include "motor_control.h"

motor_t motor;	//Private state variable
motor_config_t config;

int init_motor(motor_config_t conf){
	config = conf;
	motor.period = 0;
	motor.state = ABC;
	HAL_TIM_Base_Start(config.tim);
	HAL_TIM_PWM_Start(config.tim, config.high_a);
	HAL_TIM_PWM_Start(config.tim, config.high_b);
	HAL_TIM_PWM_Start(config.tim, config.high_c);

	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	DWT->CYCCNT = 0;
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;


	return 1;
}

int commutate(motor_t mot){
	//Set all low
	switch(motor.state){
		case ABC:
			debounce_comp(config.compA);
			turn_off();
			set_low_side(config.low_b);
			set_period(config.high_a, motor.period);
			switch_comparator(config.compC, COMP_TRIGGERMODE_IT_FALLING);
			motor.state = ACB;
			break;
		case ACB:
			debounce_comp(config.compC);
			turn_off();
			set_low_side(config.low_c);
			set_period(config.high_a, motor.period);
			switch_comparator(config.compB, COMP_TRIGGERMODE_IT_RISING);
			motor.state = BCA;
			break;
		case BCA:
			debounce_comp(config.compB);
			turn_off();
			set_low_side(config.low_c);
			set_period(config.high_b, motor.period);
			switch_comparator(config.compA, COMP_TRIGGERMODE_IT_FALLING);
			motor.state = BAC;
			break;
		case BAC:
			debounce_comp(config.compA);
			turn_off();
			set_low_side(config.low_a);
			set_period(config.high_b, motor.period);
			switch_comparator(config.compC, COMP_TRIGGERMODE_IT_RISING);
			motor.state = CAB;
			break;
		case CAB:
			debounce_comp(config.compC);
			turn_off();
			set_low_side(config.low_a);
			set_period(config.high_c, motor.period);
			switch_comparator(config.compB, COMP_TRIGGERMODE_IT_FALLING);
			motor.state = CBA;
			break;
		case CBA:
			debounce_comp(config.compB);
			turn_off();
			set_low_side(config.low_b);
			set_period(config.high_c, motor.period);
			switch_comparator(config.compA, COMP_TRIGGERMODE_IT_RISING);
			motor.state = ABC;
			break;
		default:
			break;
	}
	//record time
	return 1;
}

int commutate_irq(){
	commutate(motor);
	return 1;
}

void set_period(uint32_t pin, float period){
	int iperiod = ((float)config.max_period * period);
	__HAL_TIM_SET_COMPARE(config.tim, pin, iperiod);
}

void set_low_side(uint16_t pin){
	HAL_GPIO_WritePin(config.port, pin, 1);
}

void set_motor_power(float power){
	motor.period = power;
}

void turn_off(){
	__HAL_TIM_SET_COMPARE(config.tim, config.high_a, 0);
	__HAL_TIM_SET_COMPARE(config.tim, config.high_b, 0);
	__HAL_TIM_SET_COMPARE(config.tim, config.high_c, 0);
	HAL_GPIO_WritePin(config.port, config.low_a | config.low_b | config.low_c, 0);
}

void switch_comparator(COMP_HandleTypeDef* comp, uint32_t mode){
	if(comp != config.compA) HAL_COMP_Stop_IT(config.compA);
	if(comp != config.compB) HAL_COMP_Stop_IT(config.compB);
	if(comp != config.compC) HAL_COMP_Stop_IT(config.compC);
	config.compA->Init.TriggerMode = COMP_TRIGGERMODE_NONE;
	config.compB->Init.TriggerMode = COMP_TRIGGERMODE_NONE;
	config.compC->Init.TriggerMode = COMP_TRIGGERMODE_NONE;
	HAL_COMP_Init(config.compA);
	HAL_COMP_Init(config.compB);
	HAL_COMP_Init(config.compC);
	comp->Init.TriggerMode = mode;
	HAL_COMP_Init(comp);
	HAL_COMP_Start_IT(comp);
}

void debounce_comp(COMP_HandleTypeDef* comp){
	//HAL_COMP_Stop_IT(comp);
	//HAL_COMP_Start(comp);
	for(int i = 0; i < 30; i += 3) {
	    if(comp->Init.TriggerMode == COMP_TRIGGERMODE_IT_RISING)
	    {
	      if(!HAL_COMP_GetOutputLevel(comp)) i -= 4;
	    }
	    else
	    {
	      if(HAL_COMP_GetOutputLevel(comp))  i -= 4;
	    }
	  }
}

