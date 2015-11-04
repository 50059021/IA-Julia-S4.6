#ifndef LOCALIZE_H
#define LOCALIZE_H

class Localization
{
	public:		
		Localization();
		~Localization();  
	
		FILE* m_File;
		bool m_FileEmpty;

		void Init();
		char* Localize(char *pString);
};

extern Localization cLocalization;

#endif