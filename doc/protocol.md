# AltSpectra serial protocol

The serial protocol uses a request/reply pattern between a host application and the device.

The host application issues commands that are comprised of a request header that identifies the command and an optional request payload (depending on the command)

    <header>[<data>]

The device replies with a reply header that indicates the request status followed by a data payload

    <header><data>

## Device Commands

### Init

Initialises the device

Request data: none <BR>
Reply status: OK/NOK <BR>
Reply data: firmware version <BR>

### Set Timestamp

Sets the internal timestamp

Request data: new timestamp in Julian Day with only the day part, and the time part = 0,500000
Reply status: OK/NOK
Reply data: internaltime

### Get Spectrum Sample 

Get a spectrum sample from the sensor

Request data: exposure time in milliseconds
Reply status: OK/NOK
Reply data: sample timestamp, temperature readings (sensor and heatsink), data samples

### Halt Spectrum Sample

instructs device to Halt exposure.

Request data: none
Reply status: OK/NOK
Reply data: None

### Get Temperature Sample

Get the temperature values from the device

Request data: none
Reply status: OK/NOK
Reply data: temperature readings (sensor and heatsink)

### Set Temperature

Set the temperature values for the device

Request data: Temperature in Signed Decimal Format with 1 Decimal Digit
Reply status: OK/NOK
Reply data: temperature readings (sensor and heatsink)

### Set Cooling ON/OFF

Set the cooler on or OFF

Request data: "AS+F ON/OFF"
Reply status: OK/NOK
Reply data: Cooling Status {ON/OFF};

### Get Cooling Status

Get the Cooler Status ON/OFF

Request data: None
Reply status: OK/NOK
Reply data: Cooling Status TRUE:FALSE;

###Set Fan

Sets the Fan ON or OFF

Request data: ON/OFF
Reply status: OK/NOK
Reply data: Fan ON/OFF;


## Text Encoding

### Init

Request: "AS+A"

Reply: "OK firmware version CR "

### Set Timestamp

Request: "AS+B <timestamp>"
Reply: "OK <timestamp> <CR>"

### Get Spectrum Sample

Request: "AS+C <exposure time>"
Reply: "OK <timestamp> <sensor temperature> <heatsink temperature> <exposure> <data0> <data1> ... <data_n> <CR>"

### Get Temperature Sample

Request: "AS+D"
Reply: "OK <timestamp> <sensor temperature> <heatsink temperature> <CR>"


### Set Temperature

Request: "AS+E <sensor temperature>"
Reply status: OK <sensor temperature>
Reply data: "OK <sensor temperature> <heatsink temperature> <CR>"

### Set Cooling ON/OFF

Request data: "<AS+F ON/OFF>"
Reply status: OK/NOK
Reply data: "OK <sensor temperature> <heatsink temperature> <CR>"


## Binary Encoding

### Init

Request: 0xA501
Reply: 0xA511 (OK) | 0xA510 (NOK) <firmware version (char / 1 byte)>

### Set Timestamp

Request: 0xA502 <timestamp (long int / 4 bytes)>
Reply: 0xA521 (OK) | 0xA520 (NOK)

### Get Spectrum Sample

Request: 0xA503 <exposure time (long int / 4 bytes)>
Reply: 0xA531 (OK) | 0xA5 (NOK) <timestamp (long int / 4 bytes)> <sensor temperature (short int / 2 bytes)> <heatsink temperature (short int / 2 bytes)> <data0 (short int / 2 bytes)> ... <data_n (short int / 2 bytes)>

### Get Temperature Sample


Request: 0xA504 
Reply: 0xA541 (OK) | 0xA540 (NOK) <sensor temperature (short int / 2 bytes)> <heatsink temperature (short int / 2 bytes)>


### Set Temperature

Request: 0xA505 <sensor temperature>"
Reply status: OK <sensor temperature>
Reply data: "OK <sensor temperature> <heatsink temperature> <CR>"

### Set Cooling ON/OFF

Request data: 0xA506 
Reply status: OK/NOK
Reply data: "OK <sensor temperature> <heatsink temperature> <CR>"
