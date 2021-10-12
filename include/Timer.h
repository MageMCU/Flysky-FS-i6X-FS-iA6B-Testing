//
// Carpenter Software
// File: Timer.h (release version)
// Updated: 20210910
// Date: 20210830
// Folder: bluBot_02_Release_Version
// Purpose: Github Depository (MageMCU)
//
// Student Use...
//
// Hardware (For further information, see Debug Version)
//
// RAM : [] 3.6 % (used 73 bytes from 2048 bytes)
// Flash : [==] 15.6 % (used 5038 bytes from 32256 bytes)
//
// MIT LICENSE
//

#ifndef __UNO_TIMER_H__
#define __UNO_TIMER_H__

#include <Arduino.h>
// Using Adruino Uno

namespace uno
{
  class Timer
  {
  private:
    bool _once;
    long _elapsedTime;
    long _lastMillisecond;
    bool _isTimer(int incrementedTime);

  public:
    Timer();
    void ResetTimer();
    void ResetOneTimeEvent();
    bool OneTimeEvent();
    bool IsTimer(int incrementedTime);
  };

  Timer::Timer()
  {
    _once = true;
    _elapsedTime = -1;
    _lastMillisecond = 0;
  }

  void Timer::ResetOneTimeEvent()
  {
    _once = true;
  }

  bool Timer::OneTimeEvent()
  {
    if (_once)
    {
      _once = false;
      return true;
    }
    return false;
  }

  void Timer::ResetTimer()
  {
    _elapsedTime = -1;
  }

  boolean Timer::IsTimer(int incrementedTime)
  {
    return _isTimer(incrementedTime);
  }

  boolean Timer::_isTimer(int incrementedTime)
  {
    long currentTime = millis();
    if (_elapsedTime == -1)
    {
      _elapsedTime = currentTime + (long)incrementedTime;
    }
    else if (currentTime > _elapsedTime)
    {
      _elapsedTime = currentTime + (long)incrementedTime;
      return true;
    }
    return false;
  }
}
#endif
