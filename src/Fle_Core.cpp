/*********************************************************************************
created:	2017/01/28   03:26AM
filename: 	Fle_Core.h
file base:	Fle_Core
file ext:	h
author:		Furqan Ullah (Post-doc, Ph.D.)
website:    http://real3d.pk
CopyRight:	All Rights Reserved

purpose:	Core functionalities of Fle lib.

/**********************************************************************************
FL-ESSENTIALS (FLE) - FLTK Utility Widgets
Copyright (C) 2017 REAL3D

This file and its content is protected by a software license.
You should have received a copy of this license with this file.
If not, please contact Dr. Furqan Ullah immediately:
**********************************************************************************/

#include "Fle_Core.h"

#include <FL/Fl.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/glut.H>            // needed for OpenGL

#include <iostream>

using namespace R3D;

int __update_system_colors(int _event) // WIN32 only, so far
{
#ifdef WIN32
	DWORD color;
	BYTE *pColor = (BYTE*)&color;

	color = GetSysColor(COLOR_WINDOW);
	Fl::background2(pColor[0], pColor[1], pColor[2]);

	color = GetSysColor(COLOR_WINDOWTEXT);
	Fl::foreground(pColor[0], pColor[1], pColor[2]);

	color = GetSysColor(COLOR_BTNFACE);
	Fl::background(pColor[0], pColor[1], pColor[2]);

	color = GetSysColor(COLOR_HIGHLIGHT);
	Fl::set_color(FL_SELECTION_COLOR, pColor[0], pColor[1], pColor[2]);
#endif
	return 1;
}

int __disable_escape_key(int _event)
{
	if (_event == FL_SHORTCUT && Fl::event_key(FL_Escape)) { return 1; }
	return 0;
}

void Fle_Core::init()
{
	/************************************************************************/
	// FLTK default initialization.
	Fl::scheme("gleam");						// theme of FLTK widgets.
	Fl::visual(FL_DOUBLE | FL_RGB8  | FL_INDEX | FL_ALPHA | FL_MULTISAMPLE);
	Fl::gl_visual(FL_DOUBLE | FL_RGB8 | FL_DEPTH | FL_ACCUM | FL_ALPHA | FL_STENCIL | FL_MULTISAMPLE);
	Fl::use_high_res_GL(1);
	fl_register_images();						// Initialize FLTK image lib (essential)
	Fl::set_color(FL_BLACK, 50, 50, 50);		// change the black color of FLTK widgets to dark gray.
	__update_system_colors(1);
	Fl::box_color(FL_GRAY);
	Fl::set_box_color(FL_GRAY);
	Fl::visible_focus(0);						// disable dotted rectangle to focused widget.
	Fl::set_font(0, "Segoe UI");				// default windows font
	Fl::add_handler(__disable_escape_key);
	/************************************************************************/
}

int Fle_Core::exec()
{
	return Fl::run();
}