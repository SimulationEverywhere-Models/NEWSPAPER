/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR:
*
*  DATE: 15/10/2001
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "p_journalist.h"      // class p_journalist
#include "t_journalist.h"      // class t_journalist
#include "printer.h"           // class printer
#include "editor.h"            // class editor
#include "makeup.h"            // class makeup
#include "chiefEditor.h"       // class chiefEditor


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<p_journalist>() , "p_journalist" ) ; 
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<p_journalist>() , "t_journalist" ) ; 
 	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<editor>() ,       "editor" ) ; 
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<makeup>() ,       "makeup" ) ;
 	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<chiefEditor>() ,  "chiefEditor" ) ; 
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<printer>() ,      "printer" ) ;     
}

