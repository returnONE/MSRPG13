#ifndef FONTMANAGER_H_
#define FONTMANAGER_H_

#include "DynamicList.h"
#include "ListManager.h"
#include "RenderManager.h"
#include "Constants.h"

#include <fstream>
#include <string>
#include <sstream>

#include <windows.h>
#include <GL/glu.h>

using namespace std;

class FontManager
{
public:
	static class FontManager *s_FontManager;
	static FontManager *GetFontManager (void);

	bool ParseFont(ifstream& Stream, int _charsetCode);
	//bool ParseFont( string _fileName, int _charsetCode);

	DynamicList<Charset>* GetMyCharsetList() const;
	void CreateMyCharsetList();
	void NewFontToTheList( string _fileName, int _fontCode );

private:

	DynamicList<Charset>* myCharsetList;

	bool done;

};

#endif
