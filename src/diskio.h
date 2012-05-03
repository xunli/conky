/* -*- mode: c; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*-
 *
 * Conky, a system monitor, based on torsmo
 *
 * Any original torsmo code is licensed under the BSD license
 *
 * All code written since the fork of torsmo is licensed under the GPL
 *
 * Please see COPYING for details
 *
 * Copyright (c) 2004, Hannu Saransaari and Lauri Hakkarainen
 * Copyright (c) 2005-2012 Brenden Matthews, Philip Kovacs, et. al.
 * (see AUTHORS)
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef DISKIO_H_
#define DISKIO_H_

struct diskio_stat {
	struct diskio_stat *next;
	char *dev;
	double sample[15];
	double sample_read[15];
	double sample_write[15];
	double current;
	double current_read;
	double current_write;
	double last;
	double last_read;
	double last_write;
};

extern struct diskio_stat stats;

struct diskio_stat *prepare_diskio_stat(const char *);
int update_diskio(void);
void clear_diskio_stats(void);
void update_diskio_values(struct diskio_stat *, unsigned int, unsigned int);

void parse_diskio_arg(struct text_object *, const char *);
void print_diskio(struct text_object *, char *, int);
void print_diskio_read(struct text_object *, char *, int);
void print_diskio_write(struct text_object *, char *, int);
#ifdef X11
void parse_diskiograph_arg(struct text_object *, const char *);
void print_diskiograph(struct text_object *, char *, int);
void print_diskiograph_read(struct text_object *, char *, int);
void print_diskiograph_write(struct text_object *, char *, int);
#endif /* X11 */

#endif /* DISKIO_H_ */
