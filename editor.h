/*******************************************************************
*
*  DESCRIPTION: Atomic Model editor
*
*  AUTHOR: zhen
*
*  DATE: 14/10/2001
*
*******************************************************************/
#ifndef __editor_h
#define __editor_h
// like a queue
#include <list>
#include "atomic.h"     // class Atomic

class editor : public Atomic
{
public:
	editor( const string &name = "editor" );//Default constructor
	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
private:
	const Port &in   ;  //in from p_journalist ,t_journalist
	Port &done ;
	Port &out ;
	Time preparationTime ;
	typedef list<Value> ElementList ;
	ElementList elements ;

	Time timeLeft ;

};	// class editor

// ** inline ** // 
inline
string editor::className() const
{
	return "editor" ;
}

#endif   //__editor_h
