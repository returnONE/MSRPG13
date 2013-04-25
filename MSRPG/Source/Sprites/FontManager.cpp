#include "FontManager.h"

//using namespace std;

FontManager* FontManager::s_FontManager = 0;

FontManager* FontManager::GetFontManager (void) 
{

	if (s_FontManager == 0)
	{
		s_FontManager = new FontManager;
		s_FontManager->CreateMyCharsetList();
	}
	return s_FontManager;
}

bool FontManager::ParseFont( ifstream& Stream, int _charsetCode )
//bool FontManager::ParseFont( string _fileName, int _fontCode )
{
	//std::ifstream filestr;
	//filestr.open(_fileName.c_str());

	string Line;
	string Read, Key, Value;
	size_t i;

	Charset* localCharset = new Charset;

	while( !Stream.eof() )
	{
		stringstream LineStream;
		getline( Stream, Line );
		LineStream << Line;

		//read the line's type
		LineStream >> Read;
		if( Read == "common" )
		{
			//this holds common data
			while( !LineStream.eof() )
			{
				stringstream Converter;
				LineStream >> Read;
				i = Read.find( '=' );
				Key = Read.substr( 0, i );
				Value = Read.substr( i + 1 );

				//assign the correct value
				Converter << Value;
				if( Key == "lineHeight" )
					Converter >> localCharset->LineHeight;
				else if( Key == "base" )
					Converter >> localCharset->Base;
				else if( Key == "scaleW" )
					Converter >> localCharset->Width;
				else if( Key == "scaleH" )
					Converter >> localCharset->Height;
				else if( Key == "pages" )
					Converter >> localCharset->Pages;
			}
		}
		else if( Read == "char" )
		{
			//this is data for a specific char
			unsigned short CharID = 0;

			while( !LineStream.eof() )
			{
				stringstream Converter;
				LineStream >> Read;
				i = Read.find( '=' );
				Key = Read.substr( 0, i );
				Value = Read.substr( i + 1 );

				//assign the correct value
				Converter << Value;
				if( Key == "id" )
					Converter >> CharID;
				else if( Key == "x" )
					Converter >> localCharset->Chars[CharID].x;
				else if( Key == "y" )
					Converter >> localCharset->Chars[CharID].y;
				else if( Key == "width" )
					Converter >> localCharset->Chars[CharID].Width;
				else if( Key == "height" )
					Converter >> localCharset->Chars[CharID].Height;
				else if( Key == "xoffset" )
					Converter >> localCharset->Chars[CharID].XOffset;
				else if( Key == "yoffset" )
					Converter >> localCharset->Chars[CharID].YOffset;
				else if( Key == "xadvance" )
					Converter >> localCharset->Chars[CharID].XAdvance;
				else if( Key == "page" )
					Converter >> localCharset->Chars[CharID].Page;
			}
		}
	}

	GetMyCharsetList()->NewNode( new Node<Charset>(_charsetCode, localCharset ));

	//implementar verificação de erro
	return true;
}

DynamicList<Charset>* FontManager::GetMyCharsetList() const
{
	return myCharsetList;
}

void FontManager::CreateMyCharsetList()
{
	myCharsetList = new DynamicList<Charset>(NULL);
}

void FontManager::NewFontToTheList( string _fileName, int _fontCode )
{
	string fntFileName = _fileName + ".fnt";
	string pngFileName = _fileName + ".png";

	ifstream filestr;
	filestr.open(fntFileName.c_str());

	ParseFont( filestr, _fontCode );

	ListManager::GetListManager()->NewImageToTheList( RenderManager::GetRenderManager()->LoadTexture(pngFileName.c_str()), IMAGE_FONT_CENTURY_GOTHIC );
	GetMyCharsetList()->GetNode(FONT_CENTURY_GOTHIC)->GetNodeData()->image = ListManager::GetListManager()->GetMyImageList()->GetNode(IMAGE_FONT_CENTURY_GOTHIC)->GetNodeData()->GetImage();

}
