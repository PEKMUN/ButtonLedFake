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
          state->currentLedState = 0;
          state->previousButtonState = 0;
        }
        else 
        {
          turnLed(LED_ON);
          state->currentLedState = 0;
          state->previousButtonState = 1;
        }
        break;
      
      case BUTTON_PRESSED:
        if(getButtonState() == BUTTON_RELEASED)
        {
          state->currentLedState = 1;
          state->previousButtonState = 0;
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
          state->currentLedState = 1;
          state->previousButtonState = 0;
        }
        else 
        {
          state->currentLedState = 1;
          state->previousButtonState = 1;
        }
        break;
      
      case BUTTON_PRESSED:
        if(getButtonState() == BUTTON_RELEASED)
        {
          if(state->firstLedState == LED_OFF)
          {
            state->currentLedState = state->currentLedState;
            state->previousButtonState = state->previousButtonState;
          }
          else 
            turnLed(LED_OFF);
            state->currentLedState = 1;
            state->previousButtonState = 0;
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