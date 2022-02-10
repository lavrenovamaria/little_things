import re
def disemvowel(string_):
	return (re.sub("[aeiouAEIOU]","",string_))