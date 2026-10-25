/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 25-2.c (copy of 25-1, as I already did this there!)
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
char *display_locale_info(char *cur_locale);

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

	display_locale_info(cur_locale);

	
	// Set locale to C
	cur_locale = setlocale(LC_ALL, "C");
	strcpy(c_locale,cur_locale);

	display_locale_info(cur_locale);

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
char *display_locale_info(char *cur_locale) {

	struct lconv *locale_info;

	locale_info = localeconv();
	printf(" Formatting Values for %s\n", cur_locale);
	printf("------------------------------------\n");
	printf("  decimal_point:\t%s\n", locale_info->decimal_point);
	printf("  thousands_sep:\t%s\n", locale_info->thousands_sep);
	printf("  grouping:\t%s\n\n", locale_info->grouping);

	printf("  mon_decimal_point:\t%s\n", locale_info->mon_decimal_point);
	printf("  mon_thousands_sep:\t%s\n", locale_info->mon_thousands_sep);
	printf("  mon_grouping:\t%s\n", locale_info->mon_grouping);
	printf("  positive_sign:\t%s\n", locale_info->positive_sign);
	printf("  negative_sign:\t%s\n\n", locale_info->negative_sign);

	printf("  currency symbol:\t%s\n", locale_info->currency_symbol);
	printf("  frac_digits:\t\t%d\n", (unsigned char) locale_info->frac_digits);
	printf("  p_cs_precedes:\t%d\n", (unsigned char) locale_info->p_cs_precedes);
	printf("  n_cs_precedes:\t%d\n", (unsigned char) locale_info->n_cs_precedes);
	printf("  p_sep_by_space:\t%d\n", (unsigned char) locale_info->p_sep_by_space);
	printf("  n_sep_by_space:\t%d\n", (unsigned char) locale_info->n_sep_by_space);
	printf("  p_sign_posn:\t\t%d\n", (unsigned char) locale_info->p_sign_posn);
	printf("  n_sign_posn:\t\t%d\n\n", (unsigned char) locale_info->n_sign_posn);

	printf("  int_curr_symbol:\t%s\n\n", locale_info->int_curr_symbol);
	printf("  int_frac_digits:\t%d\n\n", (unsigned char) locale_info->int_frac_digits);
	printf("  int_p_cs_precedes:\t%d\n", (unsigned char) locale_info->int_p_cs_precedes);
	printf("  int_n_cs_precedes:\t%d\n", (unsigned char) locale_info->int_n_cs_precedes);
	printf("  int_p_sep_by_space:\t%d\n", (unsigned char) locale_info->int_p_sep_by_space);
	printf("  int_n_sep_by_space:\t%d\n", (unsigned char) locale_info->int_n_sep_by_space);
	printf("  int_p_sign_posn:\t%d\n", (unsigned char) locale_info->int_p_sign_posn);
	printf("  int_n_sign_posn:\t%d\n\n", (unsigned char) locale_info->int_n_sign_posn);

}
