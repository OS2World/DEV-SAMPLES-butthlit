/*********************************************************************
** initiated by the thread "button hilite" on CIS
** author:  Wolf Dieter Biburger - 100343,365
** date:    27.04.1995
**
** testwp.h - contains some ID's and prototypes
*/

#ifndef __MANDEL_H__
#define __MANDEL_H__

/* in the 32-bit environment the base type of the second parameter of
** window procedures has been changed from USHORT to ULONG
*/
typedef ULONG MSG_TYPE;

/* Prototypes */
MRESULT EXPENTRY wpDlg ( HWND hwnd, MSG_TYPE msg, MPARAM mp1, MPARAM mp2 );

/*  constants for the dialog
*/
#define ID_STATICS          0xffff
#define ID_DLG              4711
#define ID_LISTBOX          4712
#define ID_BUTT_1           4713
#define ID_BUTT_2           4714
#define ID_BUTT_3           4715
#define ID_BUTT_4           4716
#define ID_BUTT_5           4717

#define ID_MENU_1           4721
#define ID_MENU_2           4722
#define ID_MENU_3           4723
#define ID_MENU_4           4724
#define ID_MENU_5           4725

/* End of __MANDEL_H__ */
#endif
