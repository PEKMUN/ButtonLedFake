#ifndef _LEDCONTROLLER_H
#define _LEDCONTROLLER_H

#include "Led.h"
#include "Button.h"

typedef struct LedButtonInfo LedButtonInfo;
struct LedButtonInfo
{
  LedState currentLedState;
  ButtonState previousButtonState;
};

void turnOnLedIfButtonIsPressed();
void doTapTurnOnTapTurnOffLed(LedButtonInfo *state);
void doTurnOneLedOnButtonPressedAndHoldController();
void doTapTapLedController();

#endif // _LEDCONTROLLER_H
