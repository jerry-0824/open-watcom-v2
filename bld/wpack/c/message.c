/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2020 The Open Watcom Contributors. All Rights Reserved.
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  WHEN YOU FIGURE OUT WHAT THIS FILE DOES, PLEASE
*               DESCRIBE IT HERE!
*
****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include "wio.h"
#include "txttable.h"
#include "wpack.h"
#include "message.h"


void LogUnPacking( char *name )
//=============================
{
    Log( LookupText( NULL, TXT_UNPACK ), "\'", name, "\'", NULL );
}

void Log( char *start, ... )
//==========================
{
    char *curr = start;
    int i = 0;

    while( curr != NULL ) {
        write( STDOUT_FILENO, curr, strlen( curr ) );
        curr = ( &start )[ ++i ];
    }
    write( STDOUT_FILENO, "\n", 1 );
}

void BumpStatus( long by )
//========================
{
    by=by;
}

void getinput( char *buffer, int len1 )
    {
        while( len1 > 1 ) {
            *buffer = getchar();
            if( *buffer == '\n' ) break;
            --len1;
            ++buffer;
        }
        *buffer = '\0';
    }

int UnPackHook( char *name )
{
    name=name;
    return( 0 );
}

int OK_ToReplace( char *name )                          /* 14-sep-91 */
    {
        char    reply[10];

        printf( "A newer version of '%s' already exists.\n"
                "Do you want it replaced (y/n)? ", name );
        getinput( reply, 10 );
        return( tolower( reply[0] ) == 'y' );
    }

int OK_ReplaceRDOnly( char *name )
    {
        char    reply[10];

        printf( "The file '%s' is marked as read-only.\n"
                "Do you want it replaced (y/n)? ", name );
        getinput( reply, 10 );
        return( tolower( reply[0] ) == 'y' );
    }
