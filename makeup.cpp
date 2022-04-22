/*******************************************************************
*
*  DESCRIPTION: Atomic Model makeup (use a distributin)
*
*******************************************************************/

/** include files **/
#include <math.h>          // fabs( ... )
#include "makeup.h"        // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: makeup
* Description: constructor
********************************************************************/
makeup::makeup( const string &name )
: Atomic( name )
,  in( addInputPort(  "in" ) )
, out( addOutputPort( "out" ) )
{
	try
	{
		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );

		MASSERT( dist );

		for ( register int i = 0 ; i < dist->varCount() ; i++ )
		{
			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar(i) ) ) ;
			dist->setVar( i, str2float( parameter ) ) ;
		}
	} catch( InvalidDistribution &e )
	{
		e.addText( "The model " + description() + " has distribution problems!" ) ;
		e.print(cerr);
		MTHROW( e ) ;
	} catch( MException &e )
	{
		MTHROW( e ) ;
	}
}

/*******************************************************************
* Function Name: externalFunction
* Description: the makeup receives one job
********************************************************************/
Model &makeup::externalFunction( const ExternalMessage &msg )
{
        totalPapers++;

        if(availableMan == 0)
         {
            delayCount++;
            Time t(0,0,0,0);
            holdIn(active,t);
         }  
        else
         {
            availableMan--;
            pid = static_cast< int >( msg.value() );
            holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) )) ; 
         } 
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &makeup::internalFunction( const InternalMessage & )
{
        availableMan++;
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &makeup::outputFunction( const InternalMessage &msg )
{
            sendOutput( msg.time(), out, pid );
            return *this;

}
/*******************************************************************
* Function Name:   destructor
********************************************************************/

makeup::~makeup() 
{
	delete dist;
}
