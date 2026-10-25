/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 25-1.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat Oct 24 05:52:16 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
char *fetch_locale_info(char *locale);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	struct lconv *locale_info;
	char *cur_locale;
	char native_locale[50], c_locale[50];

	printf("\n        Locale Information\n");
	printf("------------------------------------\n");

	// Check starting locale (default)
	cur_locale = setlocale(LC_ALL, NULL);
	printf("Default locale:\t\t%s\n", cur_locale);

	// Set locale to native
	cur_locale = setlocale(LC_ALL, "");
	strcpy(native_locale,cur_locale);
	printf( "Native locale:\t\t%s\n\n\n", cur_locale);


	//---------------------
	
	locale_info = localeconv();
	printf(" Formatting Values for %s\n", cur_locale);
	printf("------------------------------------\n");
	printf("  decimal_point:\t%s\n", locale_info->decimal_point);
	printf("  thousands_sep:\t%s\n", locale_info->thousands_sep);
	printf("  grouping:\t%s\n", locale_info->grouping);
	printf("  currency symbol:\t%s\n\n", locale_info->currency_symbol);

	// Set locale to C
	cur_locale = setlocale(LC_ALL, "C");
	strcpy(c_locale,cur_locale);

	locale_info = localeconv();
	printf("     Formatting Values for %s\n", cur_locale);
	printf("------------------------------------\n");
	printf("  decimal_point:\t%s\n", locale_info->decimal_point);
	printf("  thousands_sep:\t%s\n", locale_info->thousands_sep);
	printf("  grouping:\t%s\n", locale_info->grouping);
	printf("  currency symbol:\t%s\n", locale_info->currency_symbol);

	printf("\n");
	if ((strcmp(native_locale, c_locale)) == 0) {
		printf("The native locale (%s) is identical to the C locale (%s) %s\n", native_locale, c_locale);
		return 0;
	} else {
		printf("The native locale (%s) is NOT identical to the C locale (%s)\n\n", native_locale, c_locale);
	}



	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
