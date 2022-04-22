/*******************************************************************
*
*  DESCRIPTION: Atomic Model printer
*
*******************************************************************/

#ifndef __printer_h
#define __printer_h

#include <list>
#include "atomic.h"     // class Atomic

class printer : public Atomic
{
public:
	printer( const string &name = "printer" );	//Default constructor

	virtual string className() const ;
	double keyvalue; 
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	Port &out;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;

	Time timeLeft;

};	// class Printer

// ** inline ** // 
inline
string printer::className() const
{
	return "printer" ;
}

#endif
