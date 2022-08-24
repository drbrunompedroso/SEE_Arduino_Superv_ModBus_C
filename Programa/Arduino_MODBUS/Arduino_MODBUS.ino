#include <SimpleModbusSlave.h>
#define LED 13

enum
{
  VDIG,
  TENSAO,
  LED_SW,
  HOLDING_REGS_SIZE
};

unsigned int holdingRegs[HOLDING_REGS_SIZE];
unsigned int vdig;
float tensao;

void setup()
{
  modbus_configure(&Serial, 9600, SERIAL_8N2, 1, 2,HOLDING_REGS_SIZE, holdingRegs);
  modbus_update_comms(9600, SERIAL_8N1, 1);
  pinMode(LED, OUTPUT); 
}

void loop()
{
  modbus_update();

  vdig = analogRead(A0);
  tensao = vdig * 0.00488759;

  holdingRegs[VDIG] = vdig;
  holdingRegs[TENSAO] = tensao;
  digitalWrite(LED, holdingRegs[LED_SW]);
}
