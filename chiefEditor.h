/*******************************************************************
*
*  DESCRIPTION: class (processes jobs with a specified
*               distribution)
*
*******************************************************************/

#ifndef __chiefEditor_h
#define __chiefEditor_h

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class chiefEditor: public Atomic
{
public:
	chiefEditor( const string &name = "chiefEditor" ) ;	// Default constructor

	~chiefEditor();					// Destructor

	virtual string className() const
		{return "chiefEditor";}

protected:
	Model &initFunction()
		{
                    passivate();
                    availableMan = 2; // 2 man in office
                    delayCount   = 0;
                    totalPapers  = 0;
                    return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &in ;  // only  1 in
	Port &out ;
	Distribution *dist ;
	int pid ;
        int availableMan, delayCount, totalPapers;

	Distribution &distribution()
			{return *dist;}
};	// class m


#endif   //__chiefEditor_h 
