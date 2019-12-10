/*
 * trim.c
 *
 *     This file implements an expression trimmer library.
 *
 *     Copyright (C) 2013 Roberto Luiz Souza Monteiro.
 *
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program; if not, write to the Free Software
 *     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * RCS: @(#) $Id: trim.c,v 1.0 2013/06/03 08:14:00 monteiro Exp $
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trim.h"

/*
 * void Trim_TrimLeft(char *destiny, char *source, char *character)
 *
 *     Trim an expression extremities from specified characters.
 *
 * Arguments:
 *     destiny      the trimmed expression.
 *     source       the expression to trim.
 *     separator    a list of characters to match when trimming the string.
 *
 * Retults:
 *     The function trim an expression extremities from specified characters.
 */
void Trim_TrimLeft(char *destiny, char *source, char *character)
{
    char *s;
    char *d;
    char *start;
    
    /* Get the expression start. */
    s = source;
    d = destiny;
    
    /* Find expression extremities. */
    
    /* Expression start. */
    while (*s) {
        if (strchr(character, *s) != NULL) {
            s++;
        } else {
            break;
        }
    }
    start = s;
    
    /* Copy expression. */
    s = start;
    while (*s) {
        *d = *s;
        s++;
        d++;
    }
    
    /* Mark the expression end. */
    *d = '\0';
}

/*
 * void Trim_TrimRight(char *destiny, char *source, char *character)
 *
 *     Trim an expression extremities from specified characters.
 *
 * Arguments:
 *     destiny      the trimmed expression.
 *     source       the expression to trim.
 *     separator    a list of characters to match when trimming the string.
 *
 * Retults:
 *     The function trim an expression extremities from specified characters.
 */
void Trim_TrimRight(char *destiny, char *source, char *character)
{
    char *s;
    char *d;
    char *end;
    
    /* Get the expression start. */
    s = source;
    d = destiny;
    
    /* Find expression extremities. */
    
    /* Expression end. */
    while (*s) {
        s++;
    }
    s--;
    while (*s) {
        if (strchr(character, *s) != NULL) {
            s--;
        } else {
            break;
        }
    }
    end = s;
    
    /* Copy expression. */
    s = source;
    while (*s) {
        *d = *s;
        s++;
        d++;
        if (s == end) {
            *d = *s;
            d++;
            break;
        }
    }
    
    /* Mark the expression end. */
    *d = '\0';
}

/*
 * void Trim_Trim(char *destiny, char *source, char *character)
 *
 *     Trim an expression extremities from specified characters.
 *
 * Arguments:
 *     destiny      the trimmed expression.
 *     source       the expression to trim.
 *     separator    a list of characters to match when trimming the string.
 *
 * Retults:
 *     The function trim an expression extremities from specified characters.
 */
void Trim_Trim(char *destiny, char *source, char *character)
{
    char *s;
    char *d;
    char *start;
    char *end;
    
    /* Get the expression start. */
    s = source;
    d = destiny;
    
    /* Find expression extremities. */
    
    /* Expression start. */
    while (*s) {
        if (strchr(character, *s) != NULL) {
            s++;
        } else {
            break;
        }
    }
    start = s;
    
    /* Expression end. */
    while (*s) {
        s++;
    }
    s--;
    while (*s) {
        if (strchr(character, *s) != NULL) {
            s--;
        } else {
            break;
        }
    }
    end = s;
    
    /* Copy expression. */
    s = start;
    while (*s) {
        *d = *s;
        s++;
        d++;
        if (s == end) {
            *d = *s;
            d++;
            break;
        }
    }
    
    /* Mark the expression end. */
    *d = '\0';
}

