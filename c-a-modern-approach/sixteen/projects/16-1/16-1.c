/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 16-1.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun May 17 06:42:50 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
  // Asks a user to enter an international dialing code, then looks
  // it up in the country_codes array. If it finds the code, it should
  // display the name of the countr; if not, print an error message
  
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdbool.h>

struct dialing_code {
	char *country;
	int code;
};

const struct dialing_code country_codes[] =
	{{"Argentina",            54}, {"Bangladesh",      880},
	 {"Brazil",               55}, {"Burma (Myanmar)",  95},
	 {"China",                86}, {"Colombia",         57},
	 {"Congo, Dem. Rep. of", 243}, {"Egypt",            20},
     {"Ethiopia", 			 251}, {"France",          331},
	 {"Germany",              49}, {"India",            91},
	 {"Indonesia",            62}, {"Iran",             98},
	 {"Italy",                39}, {"Japan",            81},
	 {"Mexico",               52}, {"Nigeria",         234},
	 {"Pakistan",             92}, {"Philippines",      63},
     {"Poland",               48}, {"Russia",            7},
	 {"South Africa",         27}, {"South Korea",      82},
     {"Spain",                34}, {"Sudan",           249},
	 {"Thailand",             66}, {"Turkey",           90},
	 {"Ukraine",             380}, {"United Kingdom",   44},
	 {"United States",         1}, {"Vietnam",          84}};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	int x = 0;
	int nCode;
	bool codeFound;

	printf("Enter an international dialing code: ");
	scanf("%d", &nCode);

	// Since no country has a code of "0", we can simply run this loop until we get a blank value
	// probably not best practice, but this is a controlled environment :)
	while (country_codes[x].code) {
		
		if (country_codes[x].code  == nCode) {
			printf("Country: %s\n", country_codes[x].country);
			codeFound = true;
		}
		x++;
	}

	if (codeFound == false) {
		printf("ERROR: Code not found.\n");
	}

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
