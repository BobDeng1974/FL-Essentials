#pragma once
#ifndef Fle_FloatInputSlider_h__
#define Fle_FloatInputSlider_h__

/*********************************************************************************
created:	2017/01/29   02:58AM
filename: 	Fle_FloatInputSlider.h
file base:	Fle_FloatInputSlider
file ext:	h
author:		Furqan Ullah (Post-doc, Ph.D.)
website:    http://real3d.pk
CopyRight:	All Rights Reserved

purpose:	customized FLTK float slider with an input widget.

/**********************************************************************************
FL-ESSENTIALS (FLE) - FLTK Utility Widgets
Copyright (C) 2017 REAL3D

This file and its content is protected by a software license.
You should have received a copy of this license with this file.
If not, please contact Dr. Furqan Ullah immediately:
**********************************************************************************/
/*********************************************************************************
Usage example:

Fle_FloatInputSlider* s = new Fle_FloatInputSlider(10, 10, 300, 25, "Slider");
s->box(FL_UP_BOX);
s->type(FL_HOR_SLIDER);
s->value(1);
s->step(0.1);
s->bounds(0, 1);
s->tooltip("This slider gives you float values.");
s->set_callback(slider_cb);
**********************************************************************************/

#include <FLE/Fle_Export.h>

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Slider.H>

namespace R3D
{

/************************************************************************/
/* Class to create a slider with an input widget for handling float type*/
/************************************************************************/
class FL_ESSENTIALS_EXPORT Fle_FloatInputSlider : public Fl_Group
{

public:
	// Description:
	// Constructor to create a new slider widget using the position, size, and label string.
	// _textbox_width is the width of the input/text widget.
	Fle_FloatInputSlider(int _x, int _y, int _w, int _h, const char* _l = 0, int _textbox_width = 50);

	// Description:
	// Function to set the box type.
	// Default value is FL_UP_BOX.
	void box(Fl_Boxtype _type);
	// Description:
	// Function to get the box type.
	// Default value is FL_UP_BOX.
	Fl_Boxtype box() const;
	// Description:
	// Function to set the type of the slider.
	// Default value is FL_HOR_SLIDER.
	void type(uchar _t);
	// Description:
	// Function to set the type of the slider.
	// Default value is FL_HOR_SLIDER.
	uchar type() const;
	// Description:
	// Function to set the value.
	// Default value is 0.
	void value(double _val);
	// Description:
	// Function to get the value.
	// Default value is 0.
	double value() const;
	// Description:
	// Function to set the incremental step value.
	void step(double _step);
	// Description:
	// Function to set the minimum value.
	// Default value is 0.
	void minimum(double _val);
	// Description:
	// Function to get the minimum value.
	// Default value is 0.
	double  minimum() const;
	// Description:
	// Function to set the maximum value.
	// Default value is 0.
	void maximum(double _val);
	// Description:
	// Function to get the maximum value.
	// Default value is 0.
	double  maximum() const;
	// Description:
	// Function to set the bounds of the slider.
	void bounds(double _min, double _max);

	// Description:
	// Function to set the slider's color.
	void color(Fl_Color _c);
	// Description:
	// Function to get the slider's color.
	Fl_Color color() const;
	// Description:
	// Function to set color to the moving piece of slider.
	void selection_color(Fl_Color _c);
	// Description:
	// Function to get color of the moving piece of slider.
	Fl_Color selection_color() const;
	// Description:
	// Function to set color to the input text.
	void textcolor(Fl_Color _c);
	// Description:
	// Function to get color of the input text.
	Fl_Color textcolor() const;
	// Description:
	// Function to set input text's size.
	void textsize(int _size);
	// Description:
	// Function to get input text's size.
	int textsize() const;

	// Description:
	// Function to set callback function that should be called 
	// whenever the slider's or input value is changed.
	void set_callback(void(*_f)(double, void*), void*);

	// Description:
	// Function to get a pointer to slider.
	Fl_Slider* getSlider() const;
	// Description:
	// Function to get a pointer to input widget.
	Fl_Float_Input* getInput() const;

private:
	// Description:
	// Function to process slider's value.
	void slider_cb();
	// Description:
	// Static function to process slider's callback.
	static void slider_cb_(Fl_Widget* _w, void* _p);
	// Description:
	// Function to process input's value.
	void input_cb();
	// Description:
	// Static function to process input's callback.
	static void input_cb_(Fl_Widget* _w, void* _p);

	Fl_Slider* p_slider;
	Fl_Float_Input* p_input;
	typedef void(*funcptr)(double _v, void* _p);

#if (_MSC_VER > 1600)
	funcptr p_func = nullptr;		// Note: never forget to initialize it with nullptr, otherwise there will be an exception in vs2017.
	void* p_ptr = nullptr;
#else
	funcptr p_func;
	void* p_ptr;
#endif
};

}

#endif // Fle_FloatInputSlider_h__