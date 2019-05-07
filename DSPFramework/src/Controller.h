///////////////////////////////////////////////////////////
//  Controller.h
//  Implementation of the Class Controller
//  Created on:      06-aug-2014 23:31:01
//  Original author: kbe
///////////////////////////////////////////////////////////

#if !defined(CONTROLLER__INCLUDED_)
#define CONTROLLER__INCLUDED_


class Controller
{

public:

	Controller();
	virtual ~Controller();
	void pressedSwitch(short sw);

protected:
    void updateUI();
	short m_band;
};

#endif // !defined(CONTROLLER__INCLUDED_)
