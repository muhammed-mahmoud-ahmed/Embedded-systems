#ifndef KEY_PAD_H_
#define KEY_PAD_H_

#include "DIO.h"
#include "button.h"
#include "Key_pad_config.h"

#define KEY_PAD_CLR_SCR '%' /*any ascii to clear the screen*/
#define KEY_PAD_NOT_PRESSED 0xFF

/* Key_pad initialization function */
void key_pad_initialize(void); 

/* Key_pad read function */
unsigned char key_pad_read_u8Read(void);

#endif /* KEY_PAD_H_ */