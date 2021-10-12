// Carpenter Software
// File: Muth.h (Tesing version)
// Date: 20211010
// Test: FS-i6X (TX) & FS-iA6B (RX) Transceivers.
// Purpose: Review and Product Affirmation Report.
// Note: Inexpensive...
//
// MIT LICENSE
//
// See LabNotes for further information

#ifndef _UNO_MUTH_H_
#define _UNO_MUTH_H_

namespace uno {
  template<typename T>
  class Muth {
  private:
  
  public:
  // Constructor
    Muth() {}
  // Implementation
    T map (T const& x, T const& x1, T const& x2, T const& y1, T const& y2)
    {
      // Assume linear functions
      // m = (y2 - y1)/(x2 - x1)
      // (y - y1) = m(x - x1)
      return (y2 - y1) * (x - x1) / (x2 - x1) + y1;
    }
    
    // MORE TO COME - FIXME
  };
}
#endif
