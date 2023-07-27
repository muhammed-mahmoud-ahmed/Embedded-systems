#ifndef seven_segment_autoSar_h
#define seven_segment_autoSar_h

//7-seg initialize
void seven_segment_vIinitialize(unsigned char port_name);

//7-seg write
void seven_segment_vWrite(unsigned char port_name,unsigned char value);

//7-seg initialize bcd decoder
void seven_segment_bcd_vIniialize(unsigned char port_name ,unsigned char start_pin);


//7-seg write bcd decoder
void seven_segment_bcd_vWrite(unsigned char port_name,unsigned char start_pin,unsigned char value);


#endif
