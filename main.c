#include <CoreServices/CoreServices.h>

int main (int argc, const char * argv[]) {
    
	if (argv[1] != NULL)
	{
		CFDataRef data;
		CFStringRef searchterm = CFStringCreateWithCString(NULL, argv[1],
														   kCFStringEncodingMacRoman);
		CFRange searchRange = CFRangeMake(0, CFStringGetLength(searchterm));
		CFStringRef dictResult = DCSCopyTextDefinition(NULL, searchterm, searchRange);
		CFRelease(searchterm);

		if (dictResult != NULL) {
			data = CFStringCreateExternalRepresentation(NULL, dictResult, CFStringGetSystemEncoding(), '?');
			CFRelease(dictResult);

		}
		if (data != NULL) {
			printf ("%.*s\n\n", (int)CFDataGetLength(data), CFDataGetBytePtr(data));
			CFRelease(data);
		}
		else {
			printf("Could not find word in Dictionary.app.\n");
		}

		return 0;
	}
	else {
		printf("Usage: dictlookup \"word\"\n");
		return 1;
	}

}
