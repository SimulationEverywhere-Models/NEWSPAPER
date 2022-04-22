/*******************************************************************
*
*  DESCRIPTION: class makeup (processes jobs with a specified
*               distribution)
*
*******************************************************************/

#ifndef __makeup_h
#define __makeup_h

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class makeup: public Atomic
{
public:
	makeup( const string &name = "makeup" ) ;	 // Default constructor

	~makeup();					// Destructor

	virtual string className() const
		{return "makeup";}

protected:
	Model &initFunction()
		{
                    passivate();
                    availableMan = 2;
                    delayCount = 0;
                    totalPapers = 0;
                    return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &in ;
	Port &out ;
	Distribution *dist ;
	int pid ;
        int availableMan, delayCount, totalPapers;

	Distribution &distribution()
			{return *dist;}
};	// class makeup

#endif   //__makeup_h
