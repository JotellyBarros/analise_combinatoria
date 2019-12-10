/*
 * trim.h
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
 * RCS: @(#) $Id: trim.h,v 1.0 2013/06/03 08:14:00 monteiro Exp $
 * 
 */

/*
 * Function prototypes.
 */
void Trim_TrimLeft(char *destiny, char *source, char *character);
void Trim_TrimRight(char *destiny, char *source, char *character);
void Trim_Trim(char *destiny, char *source, char *character);

