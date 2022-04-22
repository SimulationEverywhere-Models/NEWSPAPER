/*******************************************************************
*
*  DESCRIPTION: Atomic Model chiefEditor (use a distributin)
*
*******************************************************************/

/** include files **/
#include <math.h>          // fabs( ... )
#include "chiefEditor.h"   // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: chiefEditor
* Description: constructor
********************************************************************/
chiefEditor::chiefEditor( const string &name )
: Atomic( name )
,   in( addInputPort(  "in" ) )
,  out( addOutputPort( "out" ) )

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
* Description: the chiefEditor receives one job
********************************************************************/
Model &chiefEditor::externalFunction( const ExternalMessage &msg )
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
Model &chiefEditor::internalFunction( const InternalMessage & )
{
        availableMan++;
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &chiefEditor::outputFunction( const InternalMessage &msg )
{
            sendOutput( msg.time(), out, pid );
            return *this;

}
/*******************************************************************
* Function Name:   destructor
********************************************************************/

chiefEditor::~chiefEditor() 
{
	delete dist;
}
