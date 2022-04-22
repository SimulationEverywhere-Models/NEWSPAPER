/*******************************************************************
*
*  DESCRIPTION: class t_journalist (processes jobs with a specified
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

#ifndef __t_journalist_h
#define __t_journalist_h

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class t_journalist: public Atomic
{
public:
	t_journalist( const string &name = "t_journalist" ) ;	 // Default constructor

	~t_journalist();					// Destructor

	virtual string className() const
		{return "t_journalist";}

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
};	// class t_journalist


#endif   //__t_journalist_H 
