#ifndef Vision_H
#define Vision_H

#include <Commands/Subsystem.h>

class Vision : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Vision();
	void InitDefaultCommand();
	void testPixy1();


};

// Class to define debug levels in sendableChooser.
// Needed to pass objects vs ints.
class debugLevel {
public:
	debugLevel(int i) : m_val(i) {}

	operator int() const {
		return m_val;
	}
private:
	int m_val;
};

#endif  // Vision_H
