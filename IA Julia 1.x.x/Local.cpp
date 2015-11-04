#include "StdAfx.h"
#include "Local.h"
#include "Configs.h"
#include "Logger.h"
#include "Prodef.h"

Localization cLocalization;

Localization::Localization()
{
	/**/
}

Localization::~Localization()
{
	/**/
}		

void Localization::Init()
{
	Configs.IsLocalization = Configs.GetInt(0, 1, 1, "Localization", "Translation", IAJuliaCommon);
	GetPrivateProfileString("Localization","Language","EN.txt", Configs.LocalizationFile, 25, IAJuliaCommon);
}

char* Localization::Localize(char *pString)
{
	m_FileEmpty = false;
														
	char TempFolder[64];
	sprintf_s(TempFolder, "..\\IA Julia\\Translations\\%s", Configs.LocalizationFile);
	
	if(((m_File = fopen(TempFolder, "r")) == NULL) || (Configs.IsLocalization == 0))
	{
		m_FileEmpty = true;					 
	}

	if(m_FileEmpty)
	{
		return pString;
	}

    rewind(m_File);
	char Buff[255];
	bool Found = false;

    while(!feof(m_File))
    {							
		Buff[0] = 0;
		fgets (Buff, 255, m_File);

		if(Buff[0] != '"' && Buff[0] != '=')
		{
            continue;
		}

		if((Found && Buff[0] == '=') && (Buff[1] == '=') && (Buff[2] == ' ') && (Buff[3] == '"'))  
		{
			char Temp[255];
			sscanf(Buff, "== \"%255[^\"]\"",Temp);

			rewind(m_File);		
			fclose(m_File); 

			if((Buff[0] == '=') && (Buff[1] == '=') && (Buff[2] == ' ') && (Buff[3] == '"') && (Buff[4] == '"'))
			{
				return pString;
			}

			return Temp;
		}
						
		char Temp1[255];	
		sscanf(Buff, "\"%255[^\"]\"",Temp1);

		if(strncmp(pString, Temp1, strlen(pString)) == 0)
		{
			Found = true;
		}
	}	

    rewind(m_File);
	fclose(m_File);

	return pString;
}	