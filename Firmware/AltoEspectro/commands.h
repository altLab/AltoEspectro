#ifndef commands_h
#define commands_h
#endif


//acknowledge Commands
#define ACK "OK"
#define NACK "NOK"

#define CR 13
#define LF 10
#define SPACE 32

//commands header
#define COMMAND_START 60
#define COMMAND_END 62

#define INIT_T 65
#define SET_TIMESTAMP_T 66
#define GET_SPECTRUMSAMPLE_T 67
#define HALT_SPECTRUM_SAMPLE_T 68
#define GET_TEMPERATURE_SAMPLE_T 69
#define SET_TEMPERATURE_T 70
#define SET_COOLING_T 71
#define GET_COOLING_T 72
#define SET_FAN_T 73
#define SET_MODE_T 74

#define INIT_B 0xA502
#define SET_TIMESTAMP_B 0xA503
#define GET_SPECTRUMSAMPLE_B 0xA504
#define HALT_SPECTRUM_SAMPLE_B 0xA505
#define GET_TEMPERATURE_SAMPLE_B 0xA506
#define SET_TEMPERATURE_B 0xA507
#define SET_COOLING_B 0xA508
#define GET_COOLING_B 0xA509
#define SET_FAN_B 0xA50A
#define SET_MODE_B 0xA50B

