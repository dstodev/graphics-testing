#ifndef STYLE_TEMPLATE_H
#define STYLE_TEMPLATE_H

template <typename T>
class StyleTemplate
{
public:
	// Canonical methods
	StyleTemplate() = default;
	virtual ~StyleTemplate() = default;
	StyleTemplate(const StyleTemplate & copy) = default;
	StyleTemplate & operator=(const StyleTemplate & copy) = default;
	StyleTemplate(StyleTemplate && move) = default;
	StyleTemplate & operator=(StyleTemplate && move) = default;

	// Parameterized constructors
	StyleTemplate(T value);

	// Operators
	operator bool() const;

	// Setters/getters
	T get_value() const;

	// Methods
	void invoke();

private:
	T _value;
};

template <typename T>
StyleTemplate<T>::StyleTemplate(T value) : _value(value)
{}

template <typename T>
StyleTemplate<T>::operator bool() const
{
	return _value != 0;
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
