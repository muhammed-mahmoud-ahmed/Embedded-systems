/*
 *  file name: Common_Macros.h
 *
 *  Created: 2/1/2023 7:03:21 PM
 *  Author: muhammed mahmoud
 */

#ifndef STD_MACROS_H_
#define STD_MACROS_H_

/*Set a bit in any register*/
#define SET_BIT(reg, bit) (reg |= (1 << bit))

/*Reset a bit in any register*/
#define RESET_BIT(reg, bit) (reg &= (~(1 << bit)))

/*Toggle a bit in any register*/
#define TOGGLE_BIT(reg, bit) (reg ^= (1 << bit))

#endif /* STD_MACROS_H_ */