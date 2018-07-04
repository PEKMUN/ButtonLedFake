#include "LedController.h"
#include "Button.h"
#include "Led.h"

void turnOnLedIfButtonIsPressed(void)
{
  if (getButtonState())
  {
    turnLed(LED_ON);
  }
  else
    turnLed(LED_OFF);
}

void doTapTurnOnTapTurnOffLed(LedButtonInfo *state)
{
  int button = state->previousButtonState;
  if(state->currentLedState == LED_OFF)
  {
    switch(button)
    {
      case BUTTON_RELEASED:
        if(getButtonState() == BUTTON_RELEASED)
        {
          state->currentLedState = LED_OFF;
          state->previousButtonState = BUTTON_RELEASED;
        }
        else 
        {
          turnLed(LED_ON);
          state->currentLedState = LED_OFF;
          state->previousButtonState = BUTTON_PRESSED;
        }
        break;
      
      case BUTTON_PRESSED:
        if(getButtonState() == BUTTON_RELEASED)
        {
          state->currentLedState = LED_ON;
          state->previousButtonState = BUTTON_RELEASED;
        }
        else
        {
          state->currentLedState = LED_OFF;
          state->previousButtonState = BUTTON_PRESSED;
        }
        break;
      
      default:
        state->currentLedState = state->currentLedState;
        state->previousButtonState = state->previousButtonState;
    }
  }
  
  else if(state->currentLedState == LED_ON)
  {
    switch(button)
    {
      case BUTTON_RELEASED:
        if(getButtonState() == BUTTON_RELEASED)
        {
          state->currentLedState = LED_ON;
          state->previousButtonState = BUTTON_RELEASED;
        }
        else 
        {
          state->currentLedState = LED_ON;
          state->previousButtonState = BUTTON_PRESSED;
        }
        break;
      
      case BUTTON_PRESSED:
        if(getButtonState() == BUTTON_RELEASED)
        {
          turnLed(LED_OFF);
          state->currentLedState = LED_OFF;
          state->previousButtonState = BUTTON_RELEASED;
        }
        else
        {
          state->currentLedState = LED_ON;
          state->previousButtonState = BUTTON_PRESSED;
        }
        break;
      
      default:
        state->currentLedState = state->currentLedState;
        state->previousButtonState = state->previousButtonState;
    }
  }
}

void doTurnOneLedOnButtonPressedAndHoldController()
{
  while(1)
  {
    turnOnLedIfButtonIsPressed();
  }
}

void doTapTapLedController()
{
  LedState currentLedState;
  
  while(1)
  {
    //doTapTurnOnTapTurnOffLed(&currentLedState);
  }
}