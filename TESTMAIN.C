/*********************************************************************
** initiated by the thread "button hilite" on CIS
** author:  Wolf Dieter Biburger - 100343,365
** date:    27.04.1995
**
** testmain.c - the main routine
**
** this routine just works with WinDlgBox instead of building up
** a standard window. the menu is loaded during initialization of the
** dialog (testwp.c). the default handling of WinDefDlgProc is used
** to avoid a lot of tricky focus handling, which normally seems to
** take 80% of programming time....8-)
*/
#define INCL_PM
#include <os2.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"


int main ( int argc, char *argv[], char *envp[] )
{
    int Ret = -1;
    ULONG ulDlgResult;
    HAB hab;
    HMQ hmq;

    while ( 1 )
    {
        hab = WinInitialize ( 0 );
        if ( hab == (HAB) 0 )
        {
            fprintf ( stderr, "%s: got no HAB !\n", argv[0] );
            break;
        } /* endif */

        hmq = WinCreateMsgQueue ( hab, (LONG) 10240 );
        if ( hmq == (HMQ) 0 )
        {
            fprintf ( stderr, "%s: got no HMQ !\n", argv[0] );
            WinTerminate ( hab );
            break;
        } /* endif */

        /* just work with dialogs...
        */
        ulDlgResult = WinDlgBox(
            HWND_DESKTOP, HWND_DESKTOP,
            wpDlg,
            (HMODULE) 0,
            (ULONG) ID_DLG,
            (PVOID) 0);

        WinDestroyMsgQueue ( hmq );
        WinTerminate ( hab );

        /* all went well so far...
        ** !!!!!    DONT REMOVE THE BREAK   !!!!!
        */
        Ret = 0;
        break;
    } /* endwhile */

    return ( Ret );
} /* End of main */
