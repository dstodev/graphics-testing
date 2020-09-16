#ifndef STYLE_TEMPLATE_H
#define STYLE_TEMPLATE_H

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     Author: Daniel Stotts

     This file serves to describe a generic class using recommended project style.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// Forward declarations
class OtherClassA;
class OtherClassB;

template <typename T>
class StyleTemplate
{
	// Friends; classes first
	friend class OtherClassA;
	friend void OtherClassB::ExampleMethod();

public:
	// Canonical methods (special member functions)
	StyleTemplate() = default;
	StyleTemplate(const StyleTemplate & copy) = default;
	StyleTemplate(StyleTemplate && move) = default;
	StyleTemplate & operator=(const StyleTemplate & copy) = default;
	StyleTemplate & operator=(StyleTemplate && move) = default;
	virtual ~StyleTemplate() = default;

	// Parameterized constructors
	StyleTemplate(T value);

	// Operators
	operator bool() const;

	// Setters/getters
	void set_value(T value);
	T get_value() const;

	// Methods
	void invoke();

private:
	// Declarations from the public field follow the same order in the private field, if applicable.

	// Data members
	T _value;
};

// For template classes, definitions are written in the same header file. For concrete classes, definitions are
// written in a related implementation (.cxx) file.

template <typename T>
StyleTemplate<T>::StyleTemplate(T value) : _value(value)
{}

template <typename T>
StyleTemplate<T>::operator bool() const
{
	// Maybe the type of _value isn't comparable with (int) 0.
	// This is a style example, so this probably doesn't matter lmao
	return (_value != 0);
}

template <typename T>
void StyleTemplate<T>::set_value(T value)
{
	_value = value;
}

template <typename T>
T StyleTemplate<T>::get_value() const
{
	return _value;
}

template <typename T>
void StyleTemplate<T>::invoke()
{}

#endif
