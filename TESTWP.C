/*********************************************************************
** initiated by the thread "button hilite" on CIS
** author:  Wolf Dieter Biburger - 100343,365
** date:    27.04.1995
**
** testwp.c - contains a simple dialog procedure, which handles just
**      the messages
**
**          WM_INITDLG - loading the menu and may do further init
**          WM_COMMAND - need not telling
**          WM_CLOSE   - clean up the mess, here identically to default
**
**      any other message is handled by
**
**          WinDefDlgProc
*/

#define INCL_PM
#include <os2.h>

/* my own headerfile... */
#include "test.h"

MRESULT APIENTRY wpDlg (
    HWND hwnd,
    MSG_TYPE msg,
    MPARAM mp1,
    MPARAM mp2)
{ /* wpDlg Start */
    MRESULT Result = 0;

    switch (msg)
    { /* switch (msg) START */
    case WM_INITDLG:
        { /* WM_INITDLG Start */
            HWND hwndMenu;
            ULONG id;

            /* load the menu, since currently it seems to be impossible
            ** to get the menu otherwise during startup of the dialog
            */
            id = WinQueryWindowUShort (hwnd, (ULONG) QWS_ID);
            hwndMenu = WinLoadMenu (hwnd, (HMODULE) 0, id);
        } /* WM_INITDLG End */
        break;

    case WM_COMMAND:
        { /* WM_COMMAND Start */
            switch (LOUSHORT(mp1))
            {
            case ID_MENU_1:
                {
                    WinAlarm (HWND_DESKTOP, (ULONG) WA_ERROR);
                    WinAlarm (HWND_DESKTOP, (ULONG) WA_NOTE);
                    WinAlarm (HWND_DESKTOP, (ULONG) WA_ERROR);
                    WinAlarm (HWND_DESKTOP, (ULONG) WA_NOTE);
                }
                break;

            case DID_OK:
                { /* do anything... */
                }
                break;

            default:
                Result = WinDefDlgProc ( hwnd, msg, mp1, mp2 );
                break;
            }
        } /* WM_COMMAND End */
        break;

    case WM_CLOSE:
    default:
        /* any other message will be handled here,
        ** also the button problem...
        */
        Result = WinDefDlgProc ( hwnd, msg, mp1, mp2 );
        break;
    } /* switch (msg) END */

    return (Result);
} /* wpDlg End */
