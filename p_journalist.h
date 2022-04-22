/*******************************************************************
*
*  DESCRIPTION: class p_journalist (processes jobs with a specified
*               distribution)
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#ifndef __p_journalist_h
#define __p_journalist_h

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class p_journalist: public Atomic
{
public:
	p_journalist( const string &name = "p_journalist" ) ;	 // Default constructor

	~p_journalist();					// Destructor

	virtual string className() const
		{return "p_journalist";}

protected:
	Model &initFunction()
		{return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &in ;
	Port &out ;
	Distribution *dist ;
	int pid ;

	Distribution &distribution()
			{return *dist;}
};	// class p_journalist


#endif   //__p_journalist_H 
