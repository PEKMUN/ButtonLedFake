#include "unity.h"
#include "LedController.h"
#include "mock_Button.h"
#include "mock_Led.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_doTapTurnOnTapTurnOffLed_given_led_is_off_and_button_is_pressed_and_released_expect_led_is_turned_on(void)
{ 
  LedButtonInfo info = {LED_OFF, BUTTON_RELEASED, LED_OFF};
  
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  doTapTurnOnTapTurnOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLed_Expect(LED_ON);
  doTapTurnOnTapTurnOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  doTapTurnOnTapTurnOffLed(&info);
  
  TEST_ASSERT_EQUAL(LED_ON, info.currentLedState);
}

void test_doTapTurnOnTapTurnOffLed_given_led_is_on_and_button_is_pressed_and_released_expect_led_is_turned_off(void)
{ 
  LedButtonInfo info = {LED_ON, BUTTON_RELEASED, LED_ON};
  
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  doTapTurnOnTapTurnOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  doTapTurnOnTapTurnOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  doTapTurnOnTapTurnOffLed(&info);
  turnLed_Expect(LED_OFF);
  
  TEST_ASSERT_EQUAL(LED_OFF, info.currentLedState);
}

/*void test_doTapTurnOnTapTurnOffLed_given_led_is_off_and_button_is_pressed_and_pressed_and_pressed_expect_led_is_turned_on(void)
{ 
  LedButtonInfo info = {LED_ON, BUTTON_RELEASED};
  
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  doTapTurnOnTapTurnOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLed_Expect(LED_ON);
  doTapTurnOnTapTurnOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  doTapTurnOnTapTurnOffLed(&info);
  
  TEST_ASSERT_EQUAL(LED_ON, info.currentLedState);
}

void test_doTapTurnOnTapTurnOffLed_given_led_is_on_and_button_is_released_and_released_and_released_expect_led_is_turned_off(void)
{ 
  LedButtonInfo info = {LED_OFF, BUTTON_PRESSED};
  
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  doTapTurnOnTapTurnOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  doTapTurnOnTapTurnOffLed(&info);
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  doTapTurnOnTapTurnOffLed(&info);
  turnLed_Expect(LED_OFF);
  
  TEST_ASSERT_EQUAL(LED_OFF, info.currentLedState);
}

void test_turnOnLedIfButtonIsPressed_given_button_is_pressed_expect_led_is_turned_on(void)
{
  getButtonState_ExpectAndReturn(BUTTON_PRESSED);
  turnLed_Expect(LED_ON);

  turnOnLedIfButtonIsPressed();
}

void test_turnOnLedIfButtonIsPressed_given_button_is_not_pressed_expect_led_is_turned_off(void)
{ 
  getButtonState_ExpectAndReturn(BUTTON_RELEASED);
  turnLed_Expect(LED_OFF);

  turnOnLedIfButtonIsPressed();  
}*/

