#ifndef _BUTTON_H
#define _BUTTON_H

typedef enum {
  BUTTON_RELEASED=0,
  BUTTON_PRESSED=1,
} ButtonState;

/**
 * Return non-zero if button is pressed; zero otherwise.
 */
ButtonState getButtonState(void);

#endif // _BUTTON_H
